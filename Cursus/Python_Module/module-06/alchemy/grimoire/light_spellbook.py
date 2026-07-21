"""Light spellbook: record light spells using earth, air, fire and water."""


def light_spell_allowed_ingredients() -> list[str]:
    """Return the list of allowed ingredients for light magic."""
    return ["earth", "air", "fire", "water"]


def light_spell_record(spell_name: str, ingredients: str) -> str:
    """Record a light spell if its ingredients are valid.

    The validator is imported locally, inside the function, instead of
    at module level. This defers the import until the module has
    fully finished loading, which is one way to break a circular
    dependency with light_validator.py (see ft_kaboom_0.py).
    """
    from .light_validator import validate_ingredients

    result = validate_ingredients(ingredients)
    if "INVALID" in result:
        return f"Spell rejected: {spell_name} ({result})"
    return f"Spell recorded: {spell_name} ({result})"
