"""Dark validator: check ingredients against the dark spellbook."""

from .dark_spellbook import dark_spell_allowed_ingredients


def validate_ingredients(ingredients: str) -> str:
    """Validate ingredients against the allowed dark ingredients."""
    allowed = dark_spell_allowed_ingredients()
    lowered = ingredients.lower()
    is_valid = any(ingredient in lowered for ingredient in allowed)
    status = "VALID" if is_valid else "INVALID"
    return f"{ingredients} - {status}"
