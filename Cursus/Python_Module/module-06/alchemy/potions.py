"""Potions: combine the four elements into healing and strength potions."""

from alchemy.elements import create_air, create_earth
from elements import create_fire, create_water


def healing_potion() -> str:
    """Brew a healing potion from earth and air."""
    earth = create_earth()
    air = create_air()
    return f"Healing potion brewed with '{earth}' and '{air}'"


def strength_potion() -> str:
    """Brew a strength potion from fire and water."""
    fire = create_fire()
    water = create_water()
    return f"Strength potion brewed with '{fire}' and '{water}'"
