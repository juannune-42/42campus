"""AggressiveStrategy: transform, attack, then revert."""

from ex0 import Creature
from ex1 import TransformCapability

from .battle_strategy import BattleStrategy
from .exceptions import InvalidStrategyError


class AggressiveStrategy(BattleStrategy):
    """Make a transforming Creature fight in its boosted battle form."""

    def is_valid(self, creature: Creature) -> bool:
        """Only Creature with a transform capability are suitable."""
        return isinstance(creature, TransformCapability)

    def act(self, creature: Creature) -> None:
        """Transform, attack, then revert."""
        if not isinstance(creature, TransformCapability):
            raise InvalidStrategyError(
                f"Invalid Creature '{creature.name}' for this "
                "aggressive strategy"
            )
        print(creature.transform())
        print(creature.attack())
        print(creature.revert())
