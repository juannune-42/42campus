"""Main entry point for the A-Maze-ing maze generator and viewer.

Reads a configuration file, builds a maze with `mazegen.MazeGenerator`,
writes it to the configured output file, and displays it in the
terminal with ASCII block art and ANSI colours through an interactive
menu (regenerate, show/hide solution path, change wall colours)."""

import os
import sys
from typing import Optional

from mazegen import MazeGenerator, N, E, S, W, DELTA

RST = "\033[0m"
WALL_COLORS = [
    "\033[37m",   # white
    "\033[33m",   # yellow
    "\033[32m",   # green
    "\033[36m",   # cyan
    "\033[35m",   # magenta
]
C_PATH = "\033[96m"     # bright cyan
C_ENTRY = "\033[95m"    # bright magenta
C_EXIT = "\033[91m"     # bright red
C_42 = "\033[42m"       # background for "42" interiors

WALL = "█"
SPACE = " "
PATH = "·"


class Config:
    """Parsed and validated maze configuration.

    Built from a `KEY=VALUE` configuration file through `from_file`,
    which is the only supported way to construct a valid instance.

    Attributes:
        width: Maze width in cells.
        height: Maze height in cells.
        entry: Entry coordinates (x, y).
        exit_: Exit coordinates (x, y).
        output_file: Path to write the generated maze to.
        perfect: Whether the maze must be a perfect maze.
        seed: Optional seed for reproducible generation.
    """

    REQUIRED = ["WIDTH", "HEIGHT", "ENTRY", "EXIT", "OUTPUT_FILE", "PERFECT"]

    def __init__(self, width: int, height: int,
                 entry: tuple[int, int], exit_: tuple[int, int],
                 output_file: str, perfect: bool,
                 seed: Optional[int]) -> None:
        """Store already-validated configuration values.

        Args:
            width: Maze width in cells.
            height: Maze height in cells.
            entry: Entry coordinates (x, y).
            exit_: Exit coordinates (x, y).
            output_file: Path to write the generated maze to.
            perfect: Whether the maze must be a perfect maze.
            seed: Optional seed for reproducible generation.
        """
        self.width = width
        self.height = height
        self.entry = entry
        self.exit_ = exit_
        self.output_file = output_file
        self.perfect = perfect
        self.seed = seed

    @classmethod
    def from_file(cls, path: str) -> "Config":
        """Parse and validate a `KEY=VALUE` configuration file.

        Args:
            path: Path to the configuration file.

        Returns:
            A fully validated `Config` instance.

        Raises:
            FileNotFoundError: If `path` does not exist.
            ValueError: If the file is malformed, a mandatory key is
                missing, or a value fails validation (wrong type,
                out-of-bounds coordinates, equal entry/exit, etc.).
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
            """Parse an 'x,y' string into an (x, y) int tuple."""
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


def write_output(gen: MazeGenerator, path: str) -> None:
    """Write a generated maze to disk in the subject's output format.

    Args:
        gen: A maze generator whose `generate` method has run.
        path: Destination file path.
    """
    with open(path, "w") as fh:
        for row in gen.grid_hex():
            fh.write(row + "\n")
        fh.write("\n")
        fh.write(f"{gen.entry[0]},{gen.entry[1]}\n")
        fh.write(f"{gen.exit[0]},{gen.exit[1]}\n")
        fh.write("".join(gen.solution) + "\n")


def _solution_cells(gen: MazeGenerator) -> set[tuple[int, int]]:
    """Return every cell coordinate visited by the solution path."""
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
    """Render the maze as ANSI-coloured ASCII block art.

    Args:
        gen: The maze to render.
        wall_color: ANSI escape code used for wall blocks.
        show_path: Whether to highlight the entry-to-exit solution.

    Returns:
        The full multi-line rendered maze, ready to print.
    """
    path_cells = _solution_cells(gen) if show_path else set()
    rows = gen.height * 2 + 1
    cols = gen.width * 2 + 1
    cg = [[SPACE] * cols for _ in range(rows)]

    for r in range(0, rows, 2):
        for c in range(0, cols, 2):
            cg[r][c] = WALL

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

    ex, ey = gen.entry
    cg[ey * 2 + 1][ex * 2 + 1] = "E"
    xx, xy = gen.exit
    cg[xy * 2 + 1][xx * 2 + 1] = "X"

    if show_path:
        for px, py in path_cells:
            if (px, py) not in (gen.entry, gen.exit):
                cg[py * 2 + 1][px * 2 + 1] = PATH

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


def run(cfg: Config) -> None:
    """Drive the interactive terminal session for a maze configuration.

    Generates an initial maze, writes it to the configured output
    file, then loops showing a menu to regenerate, toggle the
    solution path, change wall colours, or quit.

    Args:
        cfg: A validated configuration to generate mazes from.
    """
    color_idx = 0
    show_path = False
    seed = cfg.seed

    def make() -> MazeGenerator:
        g = MazeGenerator(cfg.width, cfg.height,
                          cfg.entry, cfg.exit_, seed)
        try:
            g.generate(cfg.perfect)
        except ValueError as e:
            print(f"Error: {e}", file=sys.stderr)
            sys.exit(1)
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


def main() -> None:
    """Parse arguments, load the configuration, and run the program.

    Validates the command-line usage and the configuration file,
    printing a clear error and exiting with status 1 on any failure
    instead of letting the program crash.
    """
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
    except (KeyboardInterrupt, EOFError):
        print("\nBye!")
        sys.exit(0)


if __name__ == "__main__":
    main()
