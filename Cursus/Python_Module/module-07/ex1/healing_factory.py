"""HealingCreatureFactory: builds the Sprout family."""

from ex0 import CreatureFactory

from .healing_creatures import Bloomelle, Sproutling


class HealingCreatureFactory(CreatureFactory):
    """Build the Sprout family: Sproutling, then Bloomelle."""

    def create_base(self) -> Sproutling:
        """Create a fresh Sproutling."""
        return Sproutling()

    def create_evolved(self) -> Bloomelle:
        """Create a fresh Bloomelle."""
        return Bloomelle()
