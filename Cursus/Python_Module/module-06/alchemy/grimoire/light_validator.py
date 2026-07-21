"""Light validator: check ingredients against the light spellbook."""

from .light_spellbook import light_spell_allowed_ingredients


def validate_ingredients(ingredients: str) -> str:
    """Validate ingredients against the allowed light ingredients."""
    allowed = light_spell_allowed_ingredients()
    lowered = ingredients.lower()
    is_valid = any(ingredient in lowered for ingredient in allowed)
    status = "VALID" if is_valid else "INVALID"
    return f"{ingredients} - {status}"
