"""Distillation 0: direct access to alchemy/potions.py."""

from alchemy.potions import healing_potion, strength_potion


def main() -> None:
    """Brew both potions using direct module access."""
    print("=== Distillation 0 ===")
    print("Direct access to alchemy/potions.py")
    print(f"Testing strength_potion: {strength_potion()}")
    print(f"Testing healing_potion: {healing_potion()}")


if __name__ == "__main__":
    main()
