"""Creature: the abstract base card of the whole DataDeck game."""

from abc import ABC, abstractmethod


class Creature(ABC):
    """A base trading card: has a name, a type, and can attack."""

    def __init__(self, name: str, creature_type: str) -> None:
        self.name = name
        self.creature_type = creature_type

    @abstractmethod
    def attack(self) -> str:
        """Perform this Creature's signature attack."""

    def describe(self) -> str:
        """Return a standard description of this Creature."""
        return f"{self.name} is a {self.creature_type} type Creature"
