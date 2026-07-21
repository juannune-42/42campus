"""Heal capability: an ability that, one day, might not be Creature-only.

It intentionally does NOT inherit from Creature, so it stays reusable.
"""

from abc import ABC, abstractmethod


class HealCapability(ABC):
    """Grant the power to heal, independently from the Creature world."""

    @abstractmethod
    def heal(self, target: "object | None" = None) -> str:
        """Heal a target, or self if no target is given."""
