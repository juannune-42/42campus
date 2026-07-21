"""Alembic 2: reach alchemy/elements.py directly with 'import ...'."""

import alchemy.elements


def main() -> None:
    """Create earth using alchemy's elements module."""
    print("=== Alembic 2 ===")
    print("Accessing alchemy/elements.py using 'import ...' structure")
    print(f"Testing create_earth: {alchemy.elements.create_earth()}")


if __name__ == "__main__":
    main()
