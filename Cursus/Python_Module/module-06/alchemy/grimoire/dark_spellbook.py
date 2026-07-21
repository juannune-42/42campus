"""Dark spellbook: record dark spells using bats, frogs, arsenic, eyeball.

Unlike light_spellbook.py, the validator is imported at module level,
which creates a genuine circular dependency with dark_validator.py:
importing either file first triggers an ImportError (see ft_kaboom_1.py).
"""

from .dark_validator import validate_ingredients


def dark_spell_allowed_ingredients() -> list[str]:
    """Return the list of allowed ingredients for dark magic."""
    return ["bats", "frogs", "arsenic", "eyeball"]


def dark_spell_record(spell_name: str, ingredients: str) -> str:
    """Record a dark spell if its ingredients are valid."""
    result = validate_ingredients(ingredients)
    if "INVALID" in result:
        return f"Spell rejected: {spell_name} ({result})"
    return f"Spell recorded: {spell_name} ({result})"
