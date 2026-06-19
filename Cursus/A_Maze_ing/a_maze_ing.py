"""A-Maze-ing: maze generator with terminal display.

Usage:
    python3 a_maze_ing.py config.txt
"""

import os
import sys
from typing import Optional

from mazegen import MazeGenerator, N, E, S, W, DELTA

# ---------------------------------------------------------------------------
# ANSI colours
# ---------------------------------------------------------------------------
RST = "\033[0m"
WALL_COLORS = [
    "\033[37m",   # white
    "\033[33m",   # yellow
    "\033[32m",   # green
    "\033[36m",   # cyan
    "\033[35m",   # magenta
]
C_PATH = "\033[96m"   # bright cyan
C_ENTRY = "\033[95m"   # bright magenta
C_EXIT = "\033[91m"   # bright red
C_42 = "\033[48;5;240m"  # grey background for "42" interiors

WALL = "█"
SPACE = " "
PATH = "·"


# ---------------------------------------------------------------------------
# Config
# ---------------------------------------------------------------------------

class Config:
    """Parsed maze configuration."""

    REQUIRED = ["WIDTH", "HEIGHT", "ENTRY", "EXIT", "OUTPUT_FILE", "PERFECT"]

    def __init__(self, width: int, height: int,
                 entry: tuple[int, int], exit_: tuple[int, int],
                 output_file: str, perfect: bool,
                 seed: Optional[int]) -> None:
        """Store all config values."""
        self.width = width
        self.height = height
        self.entry = entry
        self.exit_ = exit_
        self.output_file = output_file
        self.perfect = perfect
        self.seed = seed

    @classmethod
    def from_file(cls, path: str) -> "Config":
        """Parse KEY=VALUE config file.

        Args:
            path: Path to the config file.

        Returns:
            Populated Config instance.

        Raises:
            FileNotFoundError: File does not exist.
            ValueError: Missing or invalid values.
        """
        try:
            with open(path) as fh:
                lines = fh.readlines()
        except FileNotFoundError:
            raise FileNotFoundError(f"Config file not found: {path}")

        data: dict[str, str] = {}
        for i, line in enumerate(lines, 1):
            line = line.strip()
            if not line or line.startswith("#"):
                continue
            if "=" not in line:
                raise ValueError(f"Line {i}: expected KEY=VALUE, got {line!r}")
            k, _, v = line.partition("=")
            data[k.strip().upper()] = v.strip()

        missing = [k for k in cls.REQUIRED if k not in data]
        if missing:
            raise ValueError(f"Missing keys: {', '.join(missing)}")

        try:
            w, h = int(data["WIDTH"]), int(data["HEIGHT"])
        except ValueError:
            raise ValueError("WIDTH and HEIGHT must be integers.")
        if w < 2 or h < 2:
            raise ValueError("WIDTH and HEIGHT must be >= 2.")

        def coords(raw: str, label: str) -> tuple[int, int]:
            parts = raw.split(",")
            if len(parts) != 2:
                raise ValueError(f"{label} must be x,y")
            try:
                return int(parts[0]), int(parts[1])
            except ValueError:
                raise ValueError(f"{label} coords must be integers.")

        entry = coords(data["ENTRY"], "ENTRY")
        exit_ = coords(data["EXIT"], "EXIT")
        if not (0 <= entry[0] < w and 0 <= entry[1] < h):
            raise ValueError(f"ENTRY {entry} out of bounds.")
        if not (0 <= exit_[0] < w and 0 <= exit_[1] < h):
            raise ValueError(f"EXIT {exit_} out of bounds.")
        if entry == exit_:
            raise ValueError("ENTRY and EXIT must differ.")

        out = data["OUTPUT_FILE"]
        if not out:
            raise ValueError("OUTPUT_FILE cannot be empty.")

        perf_raw = data["PERFECT"].lower()
        if perf_raw not in ("true", "false"):
            raise ValueError("PERFECT must be True or False.")

        seed: Optional[int] = None
        if "SEED" in data:
            try:
                seed = int(data["SEED"])
            except ValueError:
                raise ValueError("SEED must be an integer.")

        return cls(w, h, entry, exit_, out, perf_raw == "true", seed)


# ---------------------------------------------------------------------------
# Output file
# ---------------------------------------------------------------------------

def write_output(gen: MazeGenerator, path: str) -> None:
    """Write hex maze + entry/exit/solution to file.

    Args:
        gen: Populated MazeGenerator.
        path: Output file path.
    """
    with open(path, "w") as fh:
        for row in gen.grid_hex:
            fh.write(row + "\n")
        fh.write("\n")
        fh.write(f"{gen.entry[0]},{gen.entry[1]}\n")
        fh.write(f"{gen.exit[0]},{gen.exit[1]}\n")
        fh.write("".join(gen.solution) + "\n")


# ---------------------------------------------------------------------------
# Renderer
# ---------------------------------------------------------------------------

def _solution_cells(gen: MazeGenerator) -> set[tuple[int, int]]:
    cells: set[tuple[int, int]] = {gen.entry}
    x, y = gen.entry
    dm = {"N": N, "E": E, "S": S, "W": W}
    for ch in gen.solution:
        dx, dy = DELTA[dm[ch]]
        x += dx
        y += dy
        cells.add((x, y))
    return cells


def render(gen: MazeGenerator, wall_color: str,
           show_path: bool) -> str:
    """Render maze as coloured ASCII block art.

    Args:
        gen: Populated MazeGenerator.
        wall_color: ANSI colour for walls.
        show_path: Whether to draw solution path.

    Returns:
        Multi-line string ready to print.
    """
    path_cells = _solution_cells(gen) if show_path else set()
    rows = gen.height * 2 + 1
    cols = gen.width * 2 + 1
    cg = [[SPACE] * cols for _ in range(rows)]

    # Corner posts
    for r in range(0, rows, 2):
        for c in range(0, cols, 2):
            cg[r][c] = WALL

    # Walls
    for y in range(gen.height):
        for x in range(gen.width):
            cell = gen.grid[y][x]
            r, c = y * 2, x * 2
            if cell & N:
                cg[r][c + 1] = WALL
            if cell & S:
                cg[r + 2][c + 1] = WALL
            if cell & W:
                cg[r + 1][c] = WALL
            if cell & E:
                cg[r + 1][c + 2] = WALL

    # Entry / exit
    ex, ey = gen.entry
    cg[ey * 2 + 1][ex * 2 + 1] = "E"
    xx, xy = gen.exit
    cg[xy * 2 + 1][xx * 2 + 1] = "X"

    # Path
    if show_path:
        for px, py in path_cells:
            if (px, py) not in (gen.entry, gen.exit):
                cg[py * 2 + 1][px * 2 + 1] = PATH

    # Colour pass
    lines = []
    for ri, row in enumerate(cg):
        parts = []
        for ci, ch in enumerate(row):
            cx, cy = ci // 2, ri // 2
            in_42 = (cx, cy) in gen.forty_two_cells
            if ch == WALL:
                parts.append(wall_color + ch + RST)
            elif ch == SPACE and (ri % 2 == 1) and (ci % 2 == 1) and in_42:
                parts.append(C_42 + ch + RST)
            elif ch == "E":
                parts.append(C_ENTRY + ch + RST)
            elif ch == "X":
                parts.append(C_EXIT + ch + RST)
            elif ch == PATH:
                parts.append(C_PATH + ch + RST)
            else:
                parts.append(ch)
        lines.append("".join(parts))
    return "\n".join(lines)


# ---------------------------------------------------------------------------
# Interactive loop
# ---------------------------------------------------------------------------

def run(cfg: Config) -> None:
    """Main interactive loop.

    Args:
        cfg: Parsed configuration.
    """
    color_idx = 0
    show_path = False
    seed = cfg.seed

    def make() -> MazeGenerator:
        g = MazeGenerator(cfg.width, cfg.height,
                          cfg.entry, cfg.exit_, seed)
        g.generate(cfg.perfect)
        write_output(g, cfg.output_file)
        return g

    gen = make()

    while True:
        os.system("cls" if os.name == "nt" else "clear")
        print(
            render(gen, WALL_COLORS[color_idx % len(WALL_COLORS)], show_path)
            )
        print()
        print("=== A-Maze-ing ===")
        print("1. Re-generate a new maze")
        label = "Hide path" if show_path else "Show path"
        print(f"2. {label}")
        print("3. Change colors")
        print("4. Quit")
        choice = input("Choice? (1-4): ").strip()

        if choice == "1":
            seed = None
            gen = make()
            show_path = False
        elif choice == "2":
            show_path = not show_path
        elif choice == "3":
            color_idx += 1
        elif choice == "4":
            break


# ---------------------------------------------------------------------------
# Entry point
# ---------------------------------------------------------------------------

def main() -> None:
    """Parse arguments and run the maze program."""
    if len(sys.argv) != 2:
        print("Usage: python3 a_maze_ing.py config.txt", file=sys.stderr)
        sys.exit(1)

    try:
        cfg = Config.from_file(sys.argv[1])
    except (FileNotFoundError, ValueError) as e:
        print(f"Error: {e}", file=sys.stderr)
        sys.exit(1)

    try:
        run(cfg)
    except KeyboardInterrupt:
        print("\nBye!")
        sys.exit(0)


if __name__ == "__main__":
    main()
