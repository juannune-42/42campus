"""Alembic 5: import the alchemy module with 'from alchemy import ...'."""

from alchemy import create_air


def main() -> None:
    """Create air using the alchemy package's public interface."""
    print("=== Alembic 5 ===")
    print("Accessing the alchemy module using 'from alchemy import ...'")
    print(f"Testing create_air: {create_air()}")


if __name__ == "__main__":
    main()
