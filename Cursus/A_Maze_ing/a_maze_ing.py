"""A-Maze-ing: maze generator with ASCII terminal display.

Usage:
    python3 a_maze_ing.py config.txt
"""

import os
import sys
from typing import Optional

from mazegen import MazeGenerator, N, E, S, W, DELTA

# ---------------------------------------------------------------------------
# ANSI colour helpers
# ---------------------------------------------------------------------------

COLORS: list[str] = [
    "\033[37m",   # white
    "\033[33m",   # yellow
    "\033[32m",   # green
    "\033[36m",   # cyan
    "\033[35m",   # magenta
    "\033[31m",   # red
]
RESET: str = "\033[0m"
COLOR_PATH: str = "\033[96m"   # bright cyan for solution path
COLOR_ENTRY: str = "\033[95m"  # bright magenta
COLOR_EXIT: str = "\033[91m"   # bright red
COLOR_42: str = "\033[93m"     # bright yellow for "42" pattern


def clear() -> None:
    """Clear the terminal screen."""
    os.system("cls" if os.name == "nt" else "clear")


# ---------------------------------------------------------------------------
# Configuration parsing
# ---------------------------------------------------------------------------

class Config:
    """Holds maze generation configuration loaded from a file.

    Attributes:
        width: Maze width.
        height: Maze height.
        entry: (x, y) entry cell.
        exit_: (x, y) exit cell.
        output_file: Path to write the hex maze output.
        perfect: Whether to generate a perfect maze.
        seed: Optional random seed.
    """

    REQUIRED_KEYS: list[str] = [
        "WIDTH", "HEIGHT", "ENTRY", "EXIT", "OUTPUT_FILE", "PERFECT",
    ]

    def __init__(
        self,
        width: int,
        height: int,
        entry: tuple[int, int],
        exit_: tuple[int, int],
        output_file: str,
        perfect: bool,
        seed: Optional[int] = None,
    ) -> None:
        """Initialise config with all required fields."""
        self.width = width
        self.height = height
        self.entry = entry
        self.exit_ = exit_
        self.output_file = output_file
        self.perfect = perfect
        self.seed = seed

    @classmethod
    def from_file(cls, path: str) -> "Config":
        """Parse a KEY=VALUE configuration file.

        Args:
            path: Path to the config file.

        Returns:
            A populated Config instance.

        Raises:
            FileNotFoundError: If the file does not exist.
            ValueError: If required keys are missing or values are invalid.
        """
        if not os.path.isfile(path):
            raise FileNotFoundError(f"Config file not found: {path}")

        data: dict[str, str] = {}
        with open(path, "r") as fh:
            for lineno, line in enumerate(fh, 1):
                line = line.strip()
                if not line or line.startswith("#"):
                    continue
                if "=" not in line:
                    raise ValueError(
                        f"Line {lineno}: expected KEY=VALUE, got: {line!r}"
                    )
                key, _, value = line.partition("=")
                data[key.strip().upper()] = value.strip()

        missing = [k for k in cls.REQUIRED_KEYS if k not in data]
        if missing:
            raise ValueError(f"Missing required keys: {', '.join(missing)}")

        try:
            width = int(data["WIDTH"])
            height = int(data["HEIGHT"])
        except ValueError:
            raise ValueError("WIDTH and HEIGHT must be integers.")

        if width < 2 or height < 2:
            raise ValueError("WIDTH and HEIGHT must be at least 2.")

        def parse_coords(raw: str, label: str) -> tuple[int, int]:
            parts = raw.split(",")
            if len(parts) != 2:
                raise ValueError(
                    f"{label} must be 'x,y', got: {raw!r}"
                )
            try:
                return int(parts[0]), int(parts[1])
            except ValueError:
                raise ValueError(
                    f"{label} coordinates must be integers, got: {raw!r}"
                )

        entry = parse_coords(data["ENTRY"], "ENTRY")
        exit_ = parse_coords(data["EXIT"], "EXIT")

        if not (0 <= entry[0] < width and 0 <= entry[1] < height):
            raise ValueError(f"ENTRY {entry} is outside maze bounds.")
        if not (0 <= exit_[0] < width and 0 <= exit_[1] < height):
            raise ValueError(f"EXIT {exit_} is outside maze bounds.")
        if entry == exit_:
            raise ValueError("ENTRY and EXIT must be different cells.")

        output_file = data["OUTPUT_FILE"]
        if not output_file:
            raise ValueError("OUTPUT_FILE cannot be empty.")

        perfect_raw = data["PERFECT"].lower()
        if perfect_raw not in ("true", "false"):
            raise ValueError("PERFECT must be 'True' or 'False'.")
        perfect = perfect_raw == "true"

        seed: Optional[int] = None
        if "SEED" in data:
            try:
                seed = int(data["SEED"])
            except ValueError:
                raise ValueError("SEED must be an integer.")

        return cls(
            width=width,
            height=height,
            entry=entry,
            exit_=exit_,
            output_file=output_file,
            perfect=perfect,
            seed=seed,
        )


# ---------------------------------------------------------------------------
# Output file writer
# ---------------------------------------------------------------------------

def write_output(gen: MazeGenerator, path: str) -> None:
    """Write the maze to the output file in hex format.

    Format:
        - One row per line of hex digits (no spaces).
        - An empty line.
        - Entry coordinates: x,y
        - Exit coordinates: x,y
        - Solution path: string of N/E/S/W characters.

    Args:
        gen: A MazeGenerator that has already run generate().
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
# ASCII renderer
# ---------------------------------------------------------------------------

def _path_cells(
    gen: MazeGenerator,
) -> set[tuple[int, int]]:
    """Return the set of (x, y) cells on the solution path."""
    cells: set[tuple[int, int]] = set()
    x, y = gen.entry
    cells.add((x, y))
    dir_map: dict[str, int] = {"N": N, "E": E, "S": S, "W": W}
    for ch in gen.solution:
        d = dir_map[ch]
        dx, dy = DELTA[d]
        x += dx
        y += dy
        cells.add((x, y))
    return cells


def render_ascii(
    gen: MazeGenerator,
    wall_color: str = COLORS[0],
    show_path: bool = False,
    show_42: bool = True,
) -> str:
    """Render the maze as an ASCII string with ANSI colours.

    Each cell is drawn as a 2x2 block of characters in the output grid.
    Top-left corner is always a wall post (+).

    Args:
        gen: Populated MazeGenerator.
        wall_color: ANSI escape code for wall colour.
        show_path: Whether to highlight the solution path.
        show_42: Whether to colour the "42" pattern cells.

    Returns:
        A multi-line string ready to print.
    """
    W_CHAR = "█"
    H_CHAR = "█"
    SPACE = " "
    PATH_CHAR = "·"

    path_cells: set[tuple[int, int]] = (
        _path_cells(gen) if show_path else set()
    )

    # Output grid dimensions in characters
    rows_ch = gen.height * 2 + 1
    cols_ch = gen.width * 2 + 1

    # Build character grid
    cg: list[list[str]] = [[SPACE] * cols_ch for _ in range(rows_ch)]

    # Draw corner posts
    for row in range(0, rows_ch, 2):
        for col in range(0, cols_ch, 2):
            cg[row][col] = W_CHAR

    # Draw walls
    for y in range(gen.height):
        for x in range(gen.width):
            cell = gen.grid[y][x]
            cr = y * 2
            cc = x * 2
            if cell & N:
                cg[cr][cc + 1] = H_CHAR
            if cell & S:
                cg[cr + 2][cc + 1] = H_CHAR
            if cell & W:
                cg[cr + 1][cc] = W_CHAR
            if cell & E:
                cg[cr + 1][cc + 2] = W_CHAR

    # Draw path
    if show_path:
        for (px, py) in path_cells:
            if (px, py) == gen.entry:
                continue
            if (px, py) == gen.exit:
                continue
            cg[py * 2 + 1][px * 2 + 1] = PATH_CHAR

    # Draw entry/exit markers
    ex, ey = gen.entry
    cg[ey * 2 + 1][ex * 2 + 1] = "E"
    xx, xy = gen.exit
    cg[xy * 2 + 1][xx * 2 + 1] = "X"

    # Convert to coloured string
    lines: list[str] = []
    for row_idx, row in enumerate(cg):
        line_parts: list[str] = []
        for col_idx, ch in enumerate(row):
            if ch == W_CHAR or ch == H_CHAR:
                # Check if this is a "42" wall post area
                cx = col_idx // 2
                cy = row_idx // 2
                if show_42 and (cx, cy) in gen.forty_two_cells:
                    line_parts.append(COLOR_42 + ch + RESET)
                else:
                    line_parts.append(wall_color + ch + RESET)
            elif ch == "E":
                line_parts.append(COLOR_ENTRY + ch + RESET)
            elif ch == "X":
                line_parts.append(COLOR_EXIT + ch + RESET)
            elif ch == PATH_CHAR:
                line_parts.append(COLOR_PATH + ch + RESET)
            else:
                line_parts.append(ch)
        lines.append("".join(line_parts))

    return "\n".join(lines)


# ---------------------------------------------------------------------------
# Interactive terminal menu
# ---------------------------------------------------------------------------

def run_interactive(cfg: Config) -> None:
    """Main interactive loop: render, interact, regenerate.

    Args:
        cfg: Parsed configuration.
    """
    color_idx: int = 0
    show_path: bool = False
    seed: Optional[int] = cfg.seed

    def make_gen() -> MazeGenerator:
        g = MazeGenerator(
            width=cfg.width,
            height=cfg.height,
            entry=cfg.entry,
            exit_=cfg.exit_,
            seed=seed,
        )
        g.generate(perfect=cfg.perfect)
        write_output(g, cfg.output_file)
        return g

    gen = make_gen()

    while True:
        clear()
        print(render_ascii(
            gen,
            wall_color=COLORS[color_idx % len(COLORS)],
            show_path=show_path,
        ))
        print()
        print("=== A-Maze-ing ===")
        print("1. Re-generate a new maze")
        print("2. Show/Hide path from entry to exit")
        print("3. Rotate maze wall colors")
        print("4. Quit")
        choice = input("Choice? (1-4): ").strip()

        if choice == "1":
            seed = None  # New random seed each time
            gen = make_gen()
            show_path = False
        elif choice == "2":
            show_path = not show_path
        elif choice == "3":
            color_idx += 1
        elif choice == "4":
            print("Bye!")
            break
        else:
            print("Invalid choice. Press Enter to continue.")
            input()


# ---------------------------------------------------------------------------
# Entry point
# ---------------------------------------------------------------------------

def main() -> None:
    """Parse args, load config, generate maze, run interactive display."""
    if len(sys.argv) != 2:
        print(
            "Usage: python3 a_maze_ing.py config.txt",
            file=sys.stderr,
        )
        sys.exit(1)

    config_path = sys.argv[1]
    try:
        cfg = Config.from_file(config_path)
    except (FileNotFoundError, ValueError) as exc:
        print(f"Error: {exc}", file=sys.stderr)
        sys.exit(1)

    try:
        run_interactive(cfg)
    except KeyboardInterrupt:
        print("\nInterrupted.")
        sys.exit(0)
    except Exception as exc:  # pragma: no cover
        print(f"Unexpected error: {exc}", file=sys.stderr)
        sys.exit(1)


if __name__ == "__main__":
    main()
