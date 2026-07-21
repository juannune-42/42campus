"""Concrete Creature with a healing capability: the Sprout family."""

from ex0 import Creature

from .heal_capability import HealCapability


class Sproutling(Creature, HealCapability):
    """The base form of the Sprout family; heals for a small amount."""

    def __init__(self) -> None:
        super().__init__("Sproutling", "Grass")

    def attack(self) -> str:
        """Whip the opponent with vines."""
        return f"{self.name} uses Vine Whip!"

    def heal(self, target: "object | None" = None) -> str:
        """Heal itself for a small amount."""
        return f"{self.name} heals itself for a small amount"


class Bloomelle(Creature, HealCapability):
    """The evolved form of the Sprout family; heals a wider group."""

    def __init__(self) -> None:
        super().__init__("Bloomelle", "Grass/Fairy")

    def attack(self) -> str:
        """Dance a flurry of razor-sharp petals."""
        return f"{self.name} uses Petal Dance!"

    def heal(self, target: "object | None" = None) -> str:
        """Heal itself and others for a large amount."""
        return f"{self.name} heals itself and others for a large amount"
