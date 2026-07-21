"""Concrete factories: the only public way to obtain a Creature."""

from .creatures import Aquabub, Flameling, Pyrodon, Torragon
from .factory import CreatureFactory


class FlameFactory(CreatureFactory):
    """Build the Flame family: Flameling, then Pyrodon."""

    def create_base(self) -> Flameling:
        """Create a fresh Flameling."""
        return Flameling()

    def create_evolved(self) -> Pyrodon:
        """Create a fresh Pyrodon."""
        return Pyrodon()


class AquaFactory(CreatureFactory):
    """Build the Aqua family: Aquabub, then Torragon."""

    def create_base(self) -> Aquabub:
        """Create a fresh Aquabub."""
        return Aquabub()

    def create_evolved(self) -> Torragon:
        """Create a fresh Torragon."""
        return Torragon()
