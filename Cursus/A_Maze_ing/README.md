*This project has been created as part of the 42 curriculum by juannune, rodrigoa.*

# A-Maze-ing

## Description

Maze generator in Python. Takes a config file, generates a maze using the
recursive backtracker algorithm, writes it to a hex output file, and displays
it in the terminal with ASCII block art and ANSI colours.

## Instructions

```bash
make install          # install dependencies
make run              # run with default config.txt
make run CONFIG=x.txt # run with custom config
make debug            # run with pdb debugger
make clean            # remove caches and output files
make lint             # flake8 + mypy
make build            # build mazegen pip package
```

## Configuration file format

`KEY=VALUE` pairs, one per line. Lines starting with `#` are comments.

| Key           | Description                          | Example              |
|---------------|--------------------------------------|----------------------|
| `WIDTH`       | Number of columns (integer >= 2)     | `WIDTH=20`           |
| `HEIGHT`      | Number of rows (integer >= 2)        | `HEIGHT=15`          |
| `ENTRY`       | Entry cell as `x,y`                  | `ENTRY=0,0`          |
| `EXIT`        | Exit cell as `x,y`                   | `EXIT=19,14`         |
| `OUTPUT_FILE` | Output hex file path                 | `OUTPUT_FILE=maze.txt` |
| `PERFECT`     | `True` = single path, `False` = loops | `PERFECT=True`      |
| `SEED`        | *(optional)* integer for replay      | `SEED=42`            |

## Output file format

```
<hex row 0>
...
<hex row HEIGHT-1>

<entry_x>,<entry_y>
<exit_x>,<exit_y>
<NESW path>
```

Wall bitmask: bit 0 = North, bit 1 = East, bit 2 = South, bit 3 = West.
Bit = 1 means wall closed.

**Example**: the digit A is 1010 in binary → bit 1 (East) and bit 3 (West) are set → that cell has its East and West walls closed, North and South open.

## Maze generation algorithm

**Recursive backtracker (iterative DFS)**

Starts at the entry cell and carves passages to random unvisited neighbours,
backtracking when stuck. Produces a perfect maze (spanning tree). Extra
openings are added when `PERFECT=False`.

Chosen because it produces long winding corridors, is simple to implement
iteratively (no recursion limit), and naturally generates perfect mazes.

## Reusable module — mazegen

### Install
```bash
pip install mazegen-2.1.6-py3-none-any.whl
```

### Usage
```python
from mazegen import MazeGenerator

gen = MazeGenerator(width=20, height=15, seed=42)
gen.generate(perfect=True)

print(gen.grid)             # list[list[int]] — wall bitmasks
print(gen.grid_hex())       # list[str]       — hex rows
print(gen.solution)         # list[str]       — ['S','E','N',...]
print(gen.entry)            # (0, 0)
print(gen.exit)             # (19, 14)
print(gen.forty_two_cells)  # set of (x,y) cells forming "42"
```

### Build from source
```bash
python3 -m venv venv && source venv/bin/activate
pip install build
python3 -m build --outdir .
```

## Resources

- [Maze generation algorithms Wikipedia](https://en.wikipedia.org/wiki/Maze_generation_algorithm)
- [Buckblog maze series](https://weblog.jamisbuck.org/2011/2/7/maze-generation-algorithm-recap)
- Python `random` and `collections.deque` docs

### AI usage

IA was used to gather background information, suggest type hints,
and help draft this README.

## Team and project management

### Roles
| Member    | Role                                              |
|-----------|---------------------------------------------------|
| juannune  | Algorithm, output format, terminal render         |
| rodrigoa  | README.md, .gitignore, pyproject.toml, Algorithm  |


### Planning
- Day 1: algorithm + output file
- Day 2: renderer + interactive menu
- Day 3: packaging, linting, README

### What worked well
Separating `mazegen.py` from `a_maze_ing.py` made everything easier to test.

### What could be improved
A graphical display (MLX/pygame) would look better.

### Tools used
VSCode, flake8, mypy.
