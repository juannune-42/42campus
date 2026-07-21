"""Alembic 4: import the alchemy module, then hit its hidden function.

create_earth() is never imported in alchemy/__init__.py, so it is not
part of the alchemy module's public interface. Reaching for it through
'alchemy.create_earth()' raises an AttributeError at runtime and is
flagged by mypy as a missing module attribute -- both on purpose.
"""

import alchemy


def main() -> None:
    """Create air, then fail to reach the hidden create_earth."""
    print("=== Alembic 4 ===")
    print("Accessing the alchemy module using 'import alchemy'")
    print(f"Testing create_air: {alchemy.create_air()}")
    print("Now show that not all functions can be reached")
    print("This will raise an exception!")
    print(f"Testing the hidden create_earth: {alchemy.create_earth()}")


if __name__ == "__main__":
    main()
