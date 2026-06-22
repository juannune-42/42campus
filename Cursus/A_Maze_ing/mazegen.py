"""Reusable maze generation library.

This module exposes :class:`MazeGenerator`, a self-contained class that
builds a rectangular maze using the recursive backtracker algorithm
(iterative DFS), encodes it as a wall bitmask grid, and computes the
shortest path between an entry and an exit cell with a BFS.

Basic example
-------------
>>> from mazegen import MazeGenerator
>>> gen = MazeGenerator(width=20, height=15, seed=42)
>>> gen.generate(perfect=True)
>>> gen.grid_hex()[0]            # hexadecimal wall encoding, first row
>>> gen.solution                # list of 'N'/'E'/'S'/'W' moves
>>> gen.entry, gen.exit         # entry/exit coordinates
"""

import random
from collections import deque
from typing import Optional

N: int = 0b0001
E: int = 0b0010
S: int = 0b0100
W: int = 0b1000

OPPOSITE: dict[int, int] = {N: S, S: N, E: W, W: E}
DELTA: dict[int, tuple[int, int]] = {
    N: (0, -1), E: (1, 0), S: (0, 1), W: (-1, 0)
    }

DIGIT_42: list[tuple[int, int]] = [
    (0, 0), (0, 1), (0, 2),
    (1, 2),
    (2, 2), (2, 3), (2, 4),
    (4, 0), (4, 2), (4, 3), (4, 4),
    (5, 0), (5, 2), (5, 4),
    (6, 0), (6, 1), (6, 2), (6, 4),
]
PATTERN_W: int = 7
PATTERN_H: int = 6


class MazeGenerator:
    """Generate, store, and solve a rectangular maze.

    The maze is represented internally as a grid of wall bitmasks
    (one int per cell, see module-level ``N``/``E``/``S``/``W``
    constants). It can be a perfect maze (a spanning tree, single
    path between any two cells) or a non-perfect one with extra
    loops, and always contains a visible "42" pattern of fully
    closed cells unless the maze is too small to fit it.

    Attributes:
        width: Number of columns.
        height: Number of rows.
        entry: Entry cell as (x, y).
        exit: Exit cell as (x, y).
        grid: Wall bitmask per cell, indexed as grid[y][x].
        solution: Shortest path from entry to exit as a list of
            'N'/'E'/'S'/'W' moves, populated after `generate`.
        forty_two_cells: Set of (x, y) cells forming the "42" pattern.
    """

    def __init__(
        self,
        width: int = 20,
        height: int = 15,
        entry: tuple[int, int] = (0, 0),
        exit_: tuple[int, int] = (19, 14),
        seed: Optional[int] = None,
    ) -> None:
        """Initialize an empty maze and validate its parameters.

        Args:
            width: Number of columns, must be >= 2.
            height: Number of rows, must be >= 2.
            entry: Entry coordinates (x, y), must be inside bounds.
            exit_: Exit coordinates (x, y), must be inside bounds and
                different from `entry`.
            seed: Optional seed for the random generator, used to
                reproduce the exact same maze across runs.

        Raises:
            ValueError: If the size is too small, entry/exit are out
                of bounds, or entry equals exit.
        """
        if width < 2 or height < 2:
            raise ValueError("Maze must be at least 2x2.")
        if not (0 <= entry[0] < width and 0 <= entry[1] < height):
            raise ValueError(f"Entry {entry} out of bounds.")
        if not (0 <= exit_[0] < width and 0 <= exit_[1] < height):
            raise ValueError(f"Exit {exit_} out of bounds.")
        if entry == exit_:
            raise ValueError("Entry and exit must differ.")

        self.width = width
        self.height = height
        self.entry = entry
        self.exit = exit_
        self._rng: random.Random = random.Random(seed)

        self.grid: list[list[int]] = [[0] * width for _ in range(height)]
        self.solution: list[str] = []
        self.forty_two_cells: set[tuple[int, int]] = set()

    def generate(self, perfect: bool = True) -> None:
        """Build the maze and compute its solution.

        Runs the full pipeline: reset the grid, place the "42"
        pattern, carve passages, close the external borders, open
        entry/exit, remove any oversized open area, and solve with
        BFS. Safe to call again on the same instance to regenerate.

        Args:
            perfect: If True, the maze is a perfect maze (exactly one
                path between any two cells). If False, extra
                passages are carved to create loops.
        """
        self._reset()
        self._place_42()
        if self.entry in self.forty_two_cells:
            raise ValueError(f"Entry {self.entry} overlaps with '42' pattern.")
        if self.exit in self.forty_two_cells:
            raise ValueError(f"Exit {self.exit} overlaps with '42' pattern.")
        self._carve(perfect)
        self._close_borders()
        self._open_entry_exit()
        self._fix_open_areas()
        self.solution = self._bfs()

    def grid_hex(self) -> list[str]:
        """Return the maze as one uppercase hex digit per cell, per row."""
        return ["".join(format(c, "X") for c in row) for row in self.grid]

    def _reset(self) -> None:
        """Reset the grid so every cell has all four walls closed."""
        self.grid = [[N | E | S | W] * self.width for _ in range(self.height)]

    def _in(self, x: int, y: int) -> bool:
        """Return True if (x, y) lies inside the maze bounds."""
        return 0 <= x < self.width and 0 <= y < self.height

    def _open_wall(self, x: int, y: int, d: int) -> None:
        """Open wall `d` for cell (x, y)
            and the matching wall in its neighbour.

        Args:
            x: Column of the cell.
            y: Row of the cell.
            d: Direction to open (one of N, E, S, W).
        """
        self.grid[y][x] &= ~d
        dx, dy = DELTA[d]
        nx, ny = x + dx, y + dy
        if self._in(nx, ny):
            self.grid[ny][nx] &= ~OPPOSITE[d]

    def _place_42(self) -> None:
        """Mark the cells that form the centred "42" pattern.

        These cells are excluded from carving, so they stay fully
        closed and visually draw "42" in the rendered maze. If the
        maze is too small to fit the pattern, it is skipped and a
        warning is printed, as allowed by the subject.
        """
        self.forty_two_cells = set()
        if self.width < PATTERN_W + 2 or self.height < PATTERN_H + 2:
            print("Warning: maze too small for '42' pattern.")
            return
        ox = (self.width - PATTERN_W) // 2
        oy = (self.height - PATTERN_H) // 2
        for dx, dy in DIGIT_42:
            cx, cy = ox + dx, oy + dy
            if self._in(cx, cy):
                self.forty_two_cells.add((cx, cy))

    def _carve(self, perfect: bool) -> None:
        """Carve passages with an iterative recursive-backtracker DFS.

        Builds a spanning tree starting from `entry` over every cell
        that is not part of the "42" pattern, guaranteeing full
        connectivity. A fallback pass attaches any cell the main walk
        could not reach. If `perfect` is False, extra random walls
        are opened afterwards to introduce loops.

        Args:
            perfect: Whether to keep the maze as a pure spanning tree.
        """
        visited: set[tuple[int, int]] = set(self.forty_two_cells)
        dirs = [N, E, S, W]
        stack = [self.entry]
        visited.add(self.entry)

        while stack:
            x, y = stack[-1]
            self._rng.shuffle(dirs)
            moved = False
            for d in dirs:
                dx, dy = DELTA[d]
                nx, ny = x + dx, y + dy
                if self._in(nx, ny) and (nx, ny) not in visited:
                    self._open_wall(x, y, d)
                    visited.add((nx, ny))
                    stack.append((nx, ny))
                    moved = True
                    break
            if not moved:
                stack.pop()

        for cy in range(self.height):
            for cx in range(self.width):
                if (cx, cy) in self.forty_two_cells or (cx, cy) in visited:
                    continue
                self._rng.shuffle(dirs)
                for d in dirs:
                    dx, dy = DELTA[d]
                    nx, ny = cx + dx, cy + dy
                    if (
                        self._in(nx, ny)
                        and (nx, ny) not in self.forty_two_cells
                        and (nx, ny) in visited
                    ):
                        self._open_wall(cx, cy, d)
                        visited.add((cx, cy))
                        break

        if not perfect:
            extra = max(1, (self.width * self.height) // 10)
            for _ in range(extra):
                x = self._rng.randint(0, self.width - 2)
                y = self._rng.randint(0, self.height - 2)
                if (x, y) not in self.forty_two_cells:
                    d = self._rng.choice([E, S])
                    dx, dy = DELTA[d]
                    if (x + dx, y + dy) not in self.forty_two_cells:
                        self._open_wall(x, y, d)

    def _close_borders(self) -> None:
        """Force every external border wall of the maze closed."""
        for x in range(self.width):
            self.grid[0][x] |= N
            self.grid[self.height - 1][x] |= S
        for y in range(self.height):
            self.grid[y][0] |= W
            self.grid[y][self.width - 1] |= E

    def _open_entry_exit(self) -> None:
        """Open a passage to the outside for entry and exit cells.

        Only cells that actually touch an external border get a wall
        removed. A cell placed strictly in the interior keeps all its
        walls intact, since there is no boundary segment to open and
        forcing one would break wall coherence with its neighbour.
        """
        for px, py in (self.entry, self.exit):
            if px == 0:
                self.grid[py][px] &= ~W
            elif px == self.width - 1:
                self.grid[py][px] &= ~E
            elif py == 0:
                self.grid[py][px] &= ~N
            elif py == self.height - 1:
                self.grid[py][px] &= ~S

    def _fix_open_areas(self) -> None:
        """Break up any open area wider than 2x2 cells.

        Scans every 2x2 block; if it is fully open (no internal E/S
        walls), a wall is added through its middle so no 3x3-or-larger
        open zone can exist, while keeping the maze connected.
        """
        for y in range(self.height - 2):
            for x in range(self.width - 2):
                if all(
                    not (self.grid[ry][rx] & E) and not (self.grid[ry][rx] & S)
                    for ry in range(y, y + 2)
                    for rx in range(x, x + 2)
                ):
                    cx, cy = x + 1, y + 1
                    if (cx, cy) not in self.forty_two_cells:
                        self.grid[cy][cx] |= S
                        self.grid[cy + 1][cx] |= N

    def _bfs(self) -> list[str]:
        """Compute the shortest path from `entry` to `exit`.

        Returns:
            The path as a list of 'N'/'E'/'S'/'W' moves, or an empty
            list if no path exists.
        """
        sx, sy = self.entry
        gx, gy = self.exit
        q: deque[tuple[int, int, list[str]]] = deque([(sx, sy, [])])
        seen: set[tuple[int, int]] = {(sx, sy)}
        names = {N: "N", E: "E", S: "S", W: "W"}
        while q:
            x, y, path = q.popleft()
            if (x, y) == (gx, gy):
                return path
            for d in (N, E, S, W):
                if not (self.grid[y][x] & d):
                    dx, dy = DELTA[d]
                    nx, ny = x + dx, y + dy
                    if self._in(nx, ny) and (nx, ny) not in seen:
                        seen.add((nx, ny))
                        q.append((nx, ny, path + [names[d]]))
        return []
