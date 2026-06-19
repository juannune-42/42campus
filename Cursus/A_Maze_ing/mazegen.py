"""mazegen - Reusable maze generation module.

Generates mazes using the recursive backtracker (DFS) algorithm.

Basic example::

    from mazegen import MazeGenerator

    gen = MazeGenerator(width=20, height=15, seed=42)
    gen.generate(perfect=True)

    grid     = gen.grid        # list[list[int]] wall bitmask per cell
    solution = gen.solution    # list[str] of 'N','E','S','W'
    entry    = gen.entry       # (x, y)
    exit_    = gen.exit        # (x, y)

Custom parameters::

    gen = MazeGenerator(width=30, height=20,
                        entry=(0, 0), exit_=(29, 19), seed=1337)
    gen.generate(perfect=False)

Wall bitmask (one hex digit per cell):
    bit 0 = North wall closed
    bit 1 = East  wall closed
    bit 2 = South wall closed
    bit 3 = West  wall closed
"""

import random
from collections import deque
from typing import Optional

N: int = 0b0001
E: int = 0b0010
S: int = 0b0100
W: int = 0b1000

OPPOSITE: dict[int, int] = {N: S, S: N, E: W, W: E}
DELTA: dict[int, tuple[int, int]] = {N: (0, -1), E: (1, 0), S: (0, 1), W: (-1, 0)}

# "42" pixel art, 7 wide x 6 tall, relative (x, y) coords
DIGIT_42: list[tuple[int, int]] = [
    (0, 0), (0, 1), (0, 2), (0, 3),
    (1, 3),
    (2, 3), (2, 4), (2, 5),
    (4, 0), (4, 2), (4, 3), (4, 4),
    (5, 0), (5, 2), (5, 4),
    (6, 0), (6, 1), (6, 2), (6, 4),
]
PATTERN_W: int = 7
PATTERN_H: int = 6


class MazeGenerator:
    """Maze generator using the recursive backtracker (DFS) algorithm.

    Args:
        width: Number of columns (>= 2).
        height: Number of rows (>= 2).
        entry: (x, y) entry cell.
        exit_: (x, y) exit cell.
        seed: Random seed for reproducibility.

    Raises:
        ValueError: On invalid parameters.
    """

    def __init__(
        self,
        width: int = 20,
        height: int = 15,
        entry: tuple[int, int] = (0, 0),
        exit_: tuple[int, int] = (19, 14),
        seed: Optional[int] = None,
    ) -> None:
        """Initialise the generator."""
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
        """Generate the maze.

        Args:
            perfect: True = single path (spanning tree). False = adds loops.
        """
        self._reset()
        self._place_42()
        self._carve(perfect)
        self._close_borders()
        self._open_entry_exit()
        self._fix_open_areas()
        self.solution = self._bfs()

    @property
    def grid_hex(self) -> list[str]:
        """Each row as a string of uppercase hex digits."""
        return ["".join(format(c, "X") for c in row) for row in self.grid]

    # ------------------------------------------------------------------

    def _reset(self) -> None:
        self.grid = [[N | E | S | W] * self.width for _ in range(self.height)]

    def _in(self, x: int, y: int) -> bool:
        return 0 <= x < self.width and 0 <= y < self.height

    def _open_wall(self, x: int, y: int, d: int) -> None:
        self.grid[y][x] &= ~d
        dx, dy = DELTA[d]
        nx, ny = x + dx, y + dy
        if self._in(nx, ny):
            self.grid[ny][nx] &= ~OPPOSITE[d]

    def _place_42(self) -> None:
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

        # Connect isolated non-42 cells
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
        for x in range(self.width):
            self.grid[0][x] |= N
            self.grid[self.height - 1][x] |= S
        for y in range(self.height):
            self.grid[y][0] |= W
            self.grid[y][self.width - 1] |= E

    def _open_entry_exit(self) -> None:
        for px, py in (self.entry, self.exit):
            if px == 0:
                self.grid[py][px] &= ~W
            elif px == self.width - 1:
                self.grid[py][px] &= ~E
            elif py == 0:
                self.grid[py][px] &= ~N
            else:
                self.grid[py][px] &= ~S

    def _fix_open_areas(self) -> None:
        """Break any 3x3 fully open areas."""
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
