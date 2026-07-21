"""Recipes: transmute lead into gold with air, fire and a strength potion.

Demonstrates both an absolute import (alchemy.elements) and a relative
import (..potions) reaching into the rest of the alchemy package.
"""

from alchemy.elements import create_air
from elements import create_fire

from ..potions import strength_potion


def lead_to_gold() -> str:
    """Transmute lead into gold."""
    air = create_air()
    potion = strength_potion()
    fire = create_fire()
    return (
        f"Recipe transmuting Lead to Gold: brew '{air}' "
        f"and '{potion}' mixed with '{fire}'"
    )
