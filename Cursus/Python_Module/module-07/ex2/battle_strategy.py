"""BattleStrategy: the abstract strategy pattern for Creature actions."""

from abc import ABC, abstractmethod

from ex0 import Creature


class BattleStrategy(ABC):
    """Decide how a Creature acts during a single tournament battle."""

    @abstractmethod
    def is_valid(self, creature: Creature) -> bool:
        """Return whether this strategy can be applied to this Creature."""

    @abstractmethod
    def act(self, creature: Creature) -> None:
        """Make the Creature act, printing each step of its turn."""
