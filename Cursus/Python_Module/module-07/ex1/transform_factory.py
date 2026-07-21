"""TransformCreatureFactory: builds the Shift family."""

from ex0 import CreatureFactory

from .transform_creatures import Morphagon, Shiftling


class TransformCreatureFactory(CreatureFactory):
    """Build the Shift family: Shiftling, then Morphagon."""

    def create_base(self) -> Shiftling:
        """Create a fresh Shiftling."""
        return Shiftling()

    def create_evolved(self) -> Morphagon:
        """Create a fresh Morphagon."""
        return Morphagon()
