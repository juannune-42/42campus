"""ex0 package: only the abstract classes and factories are public.

Concrete Creature (Flameling, Pyrodon, Aquabub, Torragon) stay private;
the only supported way to obtain a Creature is through a factory.
"""

from .creature import Creature  # noqa: F401
from .factories import AquaFactory, FlameFactory  # noqa: F401
from .factory import CreatureFactory  # noqa: F401

__all__ = [
    "AquaFactory",
    "Creature",
    "CreatureFactory",
    "FlameFactory",
]
