"""Alchemy package: partial public interface of the laboratory.

Only a subset of the internal functions is exposed here on purpose,
see ft_alembic_4.py for a demonstration of what stays hidden.
"""

from . import transmutation  # noqa: F401
from .elements import create_air  # noqa: F401
from .potions import healing_potion as heal  # noqa: F401
from .potions import strength_potion  # noqa: F401

__all__ = [
    "create_air",
    "heal",
    "strength_potion",
    "transmutation",
]
