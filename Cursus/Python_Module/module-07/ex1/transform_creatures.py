"""Concrete Creature with a transform capability: the Shift family."""

from ex0 import Creature

from .transform_capability import TransformCapability


class Shiftling(Creature, TransformCapability):
    """The base form of the Shift family; can shift into a sharper form."""

    def __init__(self) -> None:
        Creature.__init__(self, "Shiftling", "Normal")
        TransformCapability.__init__(self)

    def attack(self) -> str:
        """Attack normally, or with a boost if transformed."""
        if self.transformed:
            return f"{self.name} performs a boosted strike!"
        return f"{self.name} attacks normally."

    def transform(self) -> str:
        """Shift into a sharper, more aggressive form."""
        self._transformed = True
        return f"{self.name} shifts into a sharper form!"

    def revert(self) -> str:
        """Return to a normal, calm form."""
        self._transformed = False
        return f"{self.name} returns to normal."


class Morphagon(Creature, TransformCapability):
    """The evolved form of the Shift family; morphs into a dragon form."""

    def __init__(self) -> None:
        Creature.__init__(self, "Morphagon", "Normal/Dragon")
        TransformCapability.__init__(self)

    def attack(self) -> str:
        """Attack normally, or with a morph strike if transformed."""
        if self.transformed:
            return f"{self.name} unleashes a devastating morph strike!"
        return f"{self.name} attacks normally."

    def transform(self) -> str:
        """Morph into a dragonic battle form."""
        self._transformed = True
        return f"{self.name} morphs into a dragonic battle form!"

    def revert(self) -> str:
        """Stabilize back into a normal form."""
        self._transformed = False
        return f"{self.name} stabilizes its form."
