"""Transmutation 2: import the alchemy module only."""

import alchemy


def main() -> None:
    """Transmute lead into gold via the alchemy package only."""
    print("=== Transmutation 2 ===")
    print("Import alchemy module only")
    recipe = alchemy.transmutation.lead_to_gold()
    print(f"Testing lead to gold: {recipe}")


if __name__ == "__main__":
    main()
