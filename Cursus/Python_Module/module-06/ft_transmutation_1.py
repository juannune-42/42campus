"""Transmutation 1: import the transmutation module directly."""

import alchemy.transmutation


def main() -> None:
    """Transmute lead into gold via the transmutation subpackage."""
    print("=== Transmutation 1 ===")
    print("Import transmutation module directly")
    recipe = alchemy.transmutation.lead_to_gold()
    print(f"Testing lead to gold: {recipe}")


if __name__ == "__main__":
    main()
