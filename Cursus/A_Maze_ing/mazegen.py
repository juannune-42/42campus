"""mazegen - Reusable maze generation module.

This module provides the MazeGenerator class for generating mazes using the
recursive backtracker (DFS) algorithm. It can produce both perfect mazes
(single path between any two cells) and imperfect mazes.

Example usage::

    from mazegen import MazeGenerator

    # Basic usage
    gen = MazeGenerator(width=20, height=15, seed=42)
    gen.generate(perfect=True)

    # Access the maze grid
    grid = gen.grid          # list[list[int]], hex wall bitmask per cell
    solution = gen.solution  # list[str] of 'N','E','S','W' steps

    # Access entry/exit
    entry = gen.entry        # (x, y)
    exit_ = gen.exit         # (x, y)

Wall bitmask encoding (one hex digit per cell):
    Bit 0 (1) = North wall closed
    Bit 1 (2) = East  wall closed
    Bit 2 (4) = South wall closed
    Bit 3 (8) = West  wall closed

Custom parameters::

    gen = MazeGenerator(
        width=30,
        height=20,
        entry=(0, 0),
        exit_=(29, 19),
        seed=1337,
    )
    gen.generate(perfect=True)
    print(gen.solution)
"""

import random
from collections import deque
from typing import Optional

# Wall bit constants
N: int = 0b0001  # bit 0
E: int = 0b0010  # bit 1
S: int = 0b0100  # bit 2
W: int = 0b1000  # bit 3

# Opposite wall for each direction
OPPOSITE: dict[int, int] = {N: S, S: N, E: W, W: E}

# Direction deltas (dx, dy)
DELTA: dict[int, tuple[int, int]] = {
    N: (0, -1),
    E: (1, 0),
    S: (0, 1),
    W: (-1, 0),
}

# Pattern "4" pixel art (relative cells, value 1 = solid/closed)
# Each digit is 5 wide x 7 tall
DIGIT_4: list[tuple[int, int]] = [
    (0, 0), (0, 1), (0, 2), (0, 3),
    (1, 3), (2, 3), (3, 3), (4, 3),
    (2, 0), (2, 1), (2, 2),
    (4, 0), (4, 1), (4, 2), (4, 4), (4, 5), (4, 6),
]

DIGIT_2: list[tuple[int, int]] = [
    (0, 0), (1, 0), (2, 0), (3, 0),
    (4, 1),
    (0, 2), (1, 2), (2, 2), (3, 2), (4, 2),
    (0, 3),
    (0, 4), (1, 4), (2, 4), (3, 4), (4, 4),
]

DIGIT_HEIGHT: int = 7
DIGIT_WIDTH: int = 5
DIGIT_GAP: int = 2   # columns between digits
PATTERN_MIN_W: int = DIGIT_WIDTH * 2 + DIGIT_GAP + 2  # margins
PATTERN_MIN_H: int = DIGIT_HEIGHT + 2


class MazeGenerator:
    """Generates a maze using the recursive backtracker (DFS) algorithm.

    Attributes:
        width: Number of columns.
        height: Number of rows.
        entry: (x, y) coordinates of the entry cell.
        exit: (x, y) coordinates of the exit cell.
        grid: 2-D list of wall bitmasks (row-major: grid[y][x]).
        solution: List of direction characters ('N','E','S','W') from entry
            to exit along the shortest path (BFS). Available after generate().
        forty_two_cells: Set of (x, y) cells used for the "42" pattern.
    """

    def __init__(
        self,
        width: int = 20,
        height: int = 15,
        entry: tuple[int, int] = (0, 0),
        exit_: tuple[int, int] = (19, 14),
        seed: Optional[int] = None,
    ) -> None:
        """Initialise the generator.

        Args:
            width: Maze width in cells (>= 5).
            height: Maze height in cells (>= 5).
            entry: (x, y) of the entry cell.
            exit_: (x, y) of the exit cell.
            seed: Random seed for reproducibility. None = non-deterministic.

        Raises:
            ValueError: If dimensions or coordinates are invalid.
        """
        if width < 2 or height < 2:
            raise ValueError("Maze must be at least 2x2 cells.")
        if not (0 <= entry[0] < width and 0 <= entry[1] < height):
            raise ValueError(f"Entry {entry} is outside maze bounds.")
        if not (0 <= exit_[0] < width and 0 <= exit_[1] < height):
            raise ValueError(f"Exit {exit_} is outside maze bounds.")
        if entry == exit_:
            raise ValueError("Entry and exit must be different cells.")

        self.width: int = width
        self.height: int = height
        self.entry: tuple[int, int] = entry
        self.exit: tuple[int, int] = exit_
        self._seed: Optional[int] = seed
        self._rng: random.Random = random.Random(seed)

        # Grid: grid[y][x] = bitmask of CLOSED walls (N/E/S/W)
        self.grid: list[list[int]] = [
            [0] * width for _ in range(height)
        ]
        self.solution: list[str] = []
        self.forty_two_cells: set[tuple[int, int]] = set()

    # ------------------------------------------------------------------
    # Public API
    # ------------------------------------------------------------------

    def generate(self, perfect: bool = True) -> None:
        """Generate the maze.

        Args:
            perfect: If True, generate a perfect maze (spanning tree, single
                path between any two cells). If False, add extra openings to
                create loops.
        """
        self._reset()
        self._place_42_pattern()
        self._carve_dfs(perfect)
        self._enforce_borders()
        self._open_entry_exit()
        self._enforce_max_open_area()
        self.solution = self._bfs_solution()

    @property
    def grid_hex(self) -> list[str]:
        """Return each row as a string of hex digits (no spaces)."""
        return [
            "".join(format(cell, "X") for cell in row)
            for row in self.grid
        ]

    # ------------------------------------------------------------------
    # Private helpers
    # ------------------------------------------------------------------

    def _reset(self) -> None:
        """Reset the grid: all walls closed."""
        self.grid = [
            [N | E | S | W] * self.width for _ in range(self.height)
        ]

    def _in_bounds(self, x: int, y: int) -> bool:
        return 0 <= x < self.width and 0 <= y < self.height

    def _remove_wall(self, x: int, y: int, direction: int) -> None:
        """Open a wall between (x,y) and its neighbour in direction."""
        self.grid[y][x] &= ~direction
        dx, dy = DELTA[direction]
        nx, ny = x + dx, y + dy
        if self._in_bounds(nx, ny):
            self.grid[ny][nx] &= ~OPPOSITE[direction]

    def _place_42_pattern(self) -> None:
        """Mark cells for the "42" pattern (will stay fully walled)."""
        self.forty_two_cells = set()
        if (self.width < PATTERN_MIN_W or self.height < PATTERN_MIN_H):
            print(
                "Warning: maze is too small to display the '42' pattern."
            )
            return

        # Centre the pattern
        total_w = DIGIT_WIDTH * 2 + DIGIT_GAP
        total_h = DIGIT_HEIGHT
        ox = (self.width - total_w) // 2
        oy = (self.height - total_h) // 2

        for dx, dy in DIGIT_4:
            cx, cy = ox + dx, oy + dy
            if self._in_bounds(cx, cy):
                self.forty_two_cells.add((cx, cy))

        offset_2 = DIGIT_WIDTH + DIGIT_GAP
        for dx, dy in DIGIT_2:
            cx, cy = ox + offset_2 + dx, oy + dy
            if self._in_bounds(cx, cy):
                self.forty_two_cells.add((cx, cy))

    def _carve_dfs(self, perfect: bool) -> None:
        """Recursive backtracker DFS maze carving."""
        visited: set[tuple[int, int]] = set(self.forty_two_cells)
        directions = [N, E, S, W]

        stack: list[tuple[int, int]] = []
        sx, sy = self.entry
        visited.add((sx, sy))
        stack.append((sx, sy))

        while stack:
            x, y = stack[-1]
            self._rng.shuffle(directions)
            carved = False
            for d in directions:
                dx, dy = DELTA[d]
                nx, ny = x + dx, y + dy
                if self._in_bounds(nx, ny) and (nx, ny) not in visited:
                    self._remove_wall(x, y, d)
                    visited.add((nx, ny))
                    stack.append((nx, ny))
                    carved = True
                    break
            if not carved:
                stack.pop()

        # Connect any unreachable non-42 cells to their neighbours
        all_cells = {
            (x, y)
            for y in range(self.height)
            for x in range(self.width)
            if (x, y) not in self.forty_two_cells
        }
        unvisited = all_cells - visited
        for cx, cy in unvisited:
            self._rng.shuffle(directions)
            for d in directions:
                dx, dy = DELTA[d]
                nx, ny = cx + dx, cy + dy
                if (
                    self._in_bounds(nx, ny)
                    and (nx, ny) not in self.forty_two_cells
                    and (nx, ny) in visited
                ):
                    self._remove_wall(cx, cy, d)
                    visited.add((cx, cy))
                    break

        if not perfect:
            # Add ~10 % extra openings to create loops
            extra = max(1, (self.width * self.height) // 10)
            for _ in range(extra):
                x = self._rng.randint(0, self.width - 2)
                y = self._rng.randint(0, self.height - 2)
                if (x, y) not in self.forty_two_cells:
                    d = self._rng.choice([E, S])
                    dx, dy = DELTA[d]
                    nx, ny = x + dx, y + dy
                    if (nx, ny) not in self.forty_two_cells:
                        self._remove_wall(x, y, d)

    def _enforce_borders(self) -> None:
        """Ensure all border cells have their outer walls closed."""
        for x in range(self.width):
            self.grid[0][x] |= N
            self.grid[self.height - 1][x] |= S
        for y in range(self.height):
            self.grid[y][0] |= W
            self.grid[y][self.width - 1] |= E

    def _open_entry_exit(self) -> None:
        """Open one outer wall at the entry and exit."""
        ex, ey = self.entry
        if ex == 0:
            self.grid[ey][ex] &= ~W
        elif ex == self.width - 1:
            self.grid[ey][ex] &= ~E
        elif ey == 0:
            self.grid[ey][ex] &= ~N
        else:
            self.grid[ey][ex] &= ~S

        xx, xy = self.exit
        if xx == 0:
            self.grid[xy][xx] &= ~W
        elif xx == self.width - 1:
            self.grid[xy][xx] &= ~E
        elif xy == 0:
            self.grid[xy][xx] &= ~N
        else:
            self.grid[xy][xx] &= ~S

    def _enforce_max_open_area(self) -> None:
        """Ensure no 3x3 (or larger) fully open area exists.

        Scans for 3x3 blocks where all internal walls are open and adds a
        wall to break them up.
        """
        for y in range(self.height - 2):
            for x in range(self.width - 2):
                if self._is_open_3x3(x, y):
                    # Add the south wall of the top-left cell
                    cx, cy = x + 1, y + 1
                    if (cx, cy) not in self.forty_two_cells:
                        self.grid[cy][cx] |= S
                        self.grid[cy + 1][cx] |= N

    def _is_open_3x3(self, ox: int, oy: int) -> bool:
        """Return True if the 3x3 block at (ox,oy) has no interior walls."""
        for y in range(oy, oy + 3):
            for x in range(ox, ox + 3):
                cell = self.grid[y][x]
                # Check E wall (except last column of block)
                if x < ox + 2 and (cell & E):
                    return False
                # Check S wall (except last row of block)
                if y < oy + 2 and (cell & S):
                    return False
        return True

    def _bfs_solution(self) -> list[str]:
        """BFS shortest path from entry to exit.

        Returns:
            List of direction characters ('N','E','S','W').
        """
        sx, sy = self.entry
        gx, gy = self.exit
        queue: deque[tuple[int, int, list[str]]] = deque()
        queue.append((sx, sy, []))
        visited: set[tuple[int, int]] = {(sx, sy)}

        dir_names: dict[int, str] = {N: "N", E: "E", S: "S", W: "W"}

        while queue:
            x, y, path = queue.popleft()
            if (x, y) == (gx, gy):
                return path
            for d in [N, E, S, W]:
                if not (self.grid[y][x] & d):  # wall is open
                    dx, dy = DELTA[d]
                    nx, ny = x + dx, y + dy
                    if self._in_bounds(nx, ny) and (nx, ny) not in visited:
                        visited.add((nx, ny))
                        queue.append((nx, ny, path + [dir_names[d]]))
        return []
