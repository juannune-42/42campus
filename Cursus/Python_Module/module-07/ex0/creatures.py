"""Concrete Creature families: Flame and Aqua, base and evolved forms.

These classes stay private to the ex0 package: only the abstract
Creature/CreatureFactory and the concrete factories are exposed
publicly, see ex0/__init__.py.
"""

from .creature import Creature


class Flameling(Creature):
    """The base form of the Flame family."""

    def __init__(self) -> None:
        super().__init__("Flameling", "Fire")

    def attack(self) -> str:
        """Burn the opponent with a small ember."""
        return f"{self.name} uses Ember!"


class Pyrodon(Creature):
    """The evolved form of the Flame family."""

    def __init__(self) -> None:
        super().__init__("Pyrodon", "Fire/Flying")

    def attack(self) -> str:
        """Engulf the opponent in a wave of fire."""
        return f"{self.name} uses Flamethrower!"


class Aquabub(Creature):
    """The base form of the Aqua family."""

    def __init__(self) -> None:
        super().__init__("Aquabub", "Water")

    def attack(self) -> str:
        """Spray the opponent with pressurized water."""
        return f"{self.name} uses Water Gun!"


class Torragon(Creature):
    """The evolved form of the Aqua family."""

    def __init__(self) -> None:
        super().__init__("Torragon", "Water")

    def attack(self) -> str:
        """Blast the opponent with a torrent of water."""
        return f"{self.name} uses Hydro Pump!"
