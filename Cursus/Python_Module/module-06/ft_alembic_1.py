"""Alembic 1: reach elements.py directly with 'from ... import ...'."""

from elements import create_water


def main() -> None:
    """Create water using the root elements module."""
    print("=== Alembic 1 ===")
    print("Using: 'from ... import ...' structure to access elements.py")
    print(f"Testing create_water: {create_water()}")


if __name__ == "__main__":
    main()
