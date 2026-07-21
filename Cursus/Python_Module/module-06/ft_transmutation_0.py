"""Transmutation 0: direct access to alchemy/transmutation/recipes.py."""

import alchemy.transmutation.recipes


def main() -> None:
    """Transmute lead into gold using the recipes module directly."""
    print("=== Transmutation 0 ===")
    print("Using file alchemy/transmutation/recipes.py directly")
    recipe = alchemy.transmutation.recipes.lead_to_gold()
    print(f"Testing lead to gold: {recipe}")


if __name__ == "__main__":
    main()
