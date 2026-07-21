"""Distillation 1: import alchemy, then use its potion interface."""

import alchemy


def main() -> None:
    """Brew the strength potion and the aliased heal potion."""
    print("=== Distillation 1 ===")
    print("Using: 'import alchemy' structure to access potions")
    print(f"Testing strength_potion: {alchemy.strength_potion()}")
    print(f"Testing heal alias: {alchemy.heal()}")


if __name__ == "__main__":
    main()
