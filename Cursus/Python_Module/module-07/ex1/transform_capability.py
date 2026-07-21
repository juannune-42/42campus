"""Transform capability: a temporary, stronger battle form.

It intentionally does NOT inherit from Creature, so it stays reusable.
"""

from abc import ABC, abstractmethod


class TransformCapability(ABC):
    """Grant the power to shift into a temporary battle form.

    The ``transformed`` flag is the persistent state mentioned in the
    subject: it is meant to be read by ``attack()`` in whichever class
    mixes this capability in, so the attack changes while transformed.
    """

    def __init__(self) -> None:
        self._transformed: bool = False

    @property
    def transformed(self) -> bool:
        """Return whether the battle form is currently active."""
        return self._transformed

    @abstractmethod
    def transform(self) -> str:
        """Enter the temporary battle form."""

    @abstractmethod
    def revert(self) -> str:
        """Leave the temporary battle form."""
