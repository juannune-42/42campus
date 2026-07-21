"""DefensiveStrategy: attack, then heal."""

from ex0 import Creature
from ex1 import HealCapability

from .battle_strategy import BattleStrategy
from .exceptions import InvalidStrategyError


class DefensiveStrategy(BattleStrategy):
    """Make a healing Creature attack, then patch itself up."""

    def is_valid(self, creature: Creature) -> bool:
        """Only Creature with a healing capability are suitable."""
        return isinstance(creature, HealCapability)

    def act(self, creature: Creature) -> None:
        """Attack, then heal."""
        if not isinstance(creature, HealCapability):
            raise InvalidStrategyError(
                f"Invalid Creature '{creature.name}' for this "
                "defensive strategy"
            )
        print(creature.attack())
        print(creature.heal())
