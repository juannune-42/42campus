*This project has been created as part of the 42 curriculum by \<your\_login\>.*

# A-Maze-ing

## Description

A-Maze-ing is a Python maze generator that creates random mazes from a
configuration file and displays them in the terminal with ASCII art and ANSI
colours. The maze is saved to a hex-encoded output file that can be validated
automatically by a Moulinette script.

Key features:
- Perfect mazes (single path, spanning tree) or imperfect mazes (loops).
- Reproducible generation via a seed.
- Embedded "42" pattern made of fully-walled cells.
- Interactive terminal display: regenerate, show/hide solution path, rotate
  wall colours.
- Reusable `mazegen` module installable via pip.

---

## Instructions

### Requirements

- Python 3.10 or later
- `flake8` and `mypy` (for linting)

### Install dependencies

```bash
make install
```

### Run

```bash
make run                    # uses config.txt by default
make run CONFIG=my_conf.txt # custom config
python3 a_maze_ing.py config.txt
```

### Debug

```bash
make debug
```

### Lint

```bash
make lint         # flake8 + mypy (standard flags)
make lint-strict  # flake8 + mypy --strict
```

### Clean

```bash
make clean
```

### Build the pip package

```bash
make build
# Produces mazegen-1.0.0-py3-none-any.whl and mazegen-1.0.0.tar.gz
```

---

## Configuration file format

The config file uses one `KEY=VALUE` pair per line. Lines starting with `#`
are comments and are ignored.

| Key           | Description                             | Example              |
|---------------|-----------------------------------------|----------------------|
| `WIDTH`       | Maze width in cells (integer ≥ 2)       | `WIDTH=20`           |
| `HEIGHT`      | Maze height in cells (integer ≥ 2)      | `HEIGHT=15`          |
| `ENTRY`       | Entry cell as `x,y` (0-indexed)         | `ENTRY=0,0`          |
| `EXIT`        | Exit cell as `x,y` (0-indexed)          | `EXIT=19,14`         |
| `OUTPUT_FILE` | Path of the output hex file             | `OUTPUT_FILE=maze.txt` |
| `PERFECT`     | `True` = single path, `False` = loops   | `PERFECT=True`       |
| `SEED`        | *(optional)* Integer seed for replay    | `SEED=42`            |

---

## Output file format

```
<hex row 0>
<hex row 1>
...
<hex row HEIGHT-1>

<entry_x>,<entry_y>
<exit_x>,<exit_y>
<NESW path string>
```

Each hex digit encodes closed walls as a 4-bit mask:

| Bit | Direction |
|-----|-----------|
| 0   | North     |
| 1   | East      |
| 2   | South     |
| 3   | West      |

---

## Maze generation algorithm

**Algorithm chosen: Recursive Backtracker (Iterative DFS)**

The algorithm starts from the entry cell and performs a depth-first search
across all non-42 cells, carving passages (removing walls) as it goes.  When
it reaches a dead end it backtracks along the stack until it finds a cell with
unvisited neighbours.

**Why this algorithm?**
- Produces high-quality, long winding corridors — visually satisfying.
- Trivially generates *perfect* mazes (the DFS visit tree is a spanning tree).
- Easy to make imperfect by adding extra wall openings after the DFS.
- Simple iterative implementation avoids Python recursion depth limits.
- O(W × H) time and space — scales to large mazes without issue.

**"42" pattern:** before the DFS runs, cells that form the digit shapes are
marked as forbidden. The DFS skips them, leaving them fully walled. After
carving, unreachable normal cells are connected to their already-visited
neighbours to maintain full connectivity.

---

## Reusable module — mazegen

The `mazegen.py` module is a standalone, pip-installable library.

### Install

```bash
pip install mazegen-1.0.0-py3-none-any.whl
```

### Basic usage

```python
from mazegen import MazeGenerator

# Create and generate a perfect 20×15 maze
gen = MazeGenerator(width=20, height=15, seed=42)
gen.generate(perfect=True)

# Access the grid (row-major list of lists of int bitmasks)
grid = gen.grid           # list[list[int]]
hex_rows = gen.grid_hex   # list[str], each row as hex digits

# Solution path from entry to exit
solution = gen.solution   # list[str] of 'N','E','S','W'

# Entry / exit
print(gen.entry)   # (0, 0)
print(gen.exit)    # (19, 14)
```

### Custom parameters

```python
gen = MazeGenerator(
    width=30,
    height=20,
    entry=(0, 0),
    exit_=(29, 19),
    seed=1337,
)
gen.generate(perfect=False)   # imperfect: adds extra openings/loops
print("Solution length:", len(gen.solution))
```

### Accessing the structure

- `gen.grid[y][x]` — integer bitmask of closed walls for cell (x, y).
- `gen.grid_hex` — list of strings (one per row) of uppercase hex digits.
- `gen.solution` — BFS shortest path as list of direction characters.
- `gen.forty_two_cells` — `set[tuple[int,int]]` of cells in the 42 pattern.

---

## Resources

- [Maze generation algorithms — Wikipedia](https://en.wikipedia.org/wiki/Maze_generation_algorithm)
- [Think Labyrinth — maze algorithms](https://www.astrolog.org/labyrnth/algrithm.htm)
- [Buckblog — maze algorithms series](https://weblog.jamisbuck.org/2011/2/7/maze-generation-algorithm-recap)
- [Python `random` module docs](https://docs.python.org/3/library/random.html)
- [BFS shortest path — GeeksforGeeks](https://www.geeksforgeeks.org/shortest-path-unweighted-graph/)

### AI usage

Claude (Anthropic) was used to assist with:
- Initial code structure and boilerplate (classes, type hints, docstrings).
- Debugging the wall-coherence enforcement and border logic.
- Drafting this README.

All generated code was reviewed, tested, and understood before inclusion.

---

## Team and project management

### Roles

| Member        | Role                                         |
|---------------|----------------------------------------------|
| \<login\>     | Maze generation algorithm, output file format |
| \<login2\>    | Terminal renderer, interactive menu           |
| \<login3\>    | Package setup, README, Makefile               |

### Planning

- **Week 1:** Algorithm design, grid data structure, DFS carving.
- **Week 2:** "42" pattern embedding, border enforcement, output file.
- **Week 3:** ASCII renderer, colour system, interactive menu.
- **Week 4:** Package setup, linting, README, peer review.

Actual timeline ran roughly one day over on the renderer due to ANSI colour
edge cases on some terminals.

### What worked well

- The iterative DFS was straightforward to debug.
- Separating `mazegen.py` from `a_maze_ing.py` made unit testing easy.
- Using a seed from the start let us reproduce bugs deterministically.

### What could be improved

- A graphical display (MLX or pygame) would be more impressive.
- More "42" font variations to support very small mazes gracefully.
- Additional algorithms (Prim's, Kruskal's) as a bonus.

### Tools used

- VSCode with the Python and mypy extensions.
- flake8 and mypy for code quality.
- Claude (Anthropic) for code assistance and documentation drafting.
