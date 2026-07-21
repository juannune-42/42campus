"""Alembic 0: reach elements.py directly with 'import ...'."""

import elements


def main() -> None:
    """Create fire using the root elements module."""
    print("=== Alembic 0 ===")
    print("Using: 'import ...' structure to access elements.py")
    print(f"Testing create_fire: {elements.create_fire()}")


if __name__ == "__main__":
    main()
