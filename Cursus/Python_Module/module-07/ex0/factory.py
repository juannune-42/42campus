"""CreatureFactory: the abstract factory pattern for Creature families."""

from abc import ABC, abstractmethod

from .creature import Creature


class CreatureFactory(ABC):
    """Build the base and evolved Creature of a single family."""

    @abstractmethod
    def create_base(self) -> Creature:
        """Create the base form of this family."""

    @abstractmethod
    def create_evolved(self) -> Creature:
        """Create the evolved form of this family."""
