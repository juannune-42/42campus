CONFIG ?= config.txt

install:
	pip install flake8 mypy build

run:
	python3 a_maze_ing.py $(CONFIG)

debug:
	python3 -m pdb a_maze_ing.py $(CONFIG)

clean:
	find . -type d \( -name __pycache__ -o -name .mypy_cache \
	  -o -name "*.egg-info" -o -name dist -o -name build \) \
	  -exec rm -rf {} + 2>/dev/null || true
	rm -f maze.txt

lint:
	flake8 .
	mypy . --warn-return-any --warn-unused-ignores \
	       --ignore-missing-imports --disallow-untyped-defs \
	       --check-untyped-defs

lint-strict:
	flake8 .
	mypy . --strict

build:
	python3 -m build --outdir .

.PHONY: install run debug clean lint lint-strict build
