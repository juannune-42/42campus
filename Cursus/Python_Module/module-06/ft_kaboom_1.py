"""Kaboom 1: secretly reach dark_spellbook.py and trigger the explosion."""


def main() -> None:
    """Trigger the dark grimoire's circular import explosion."""
    print("=== Kaboom 1 ===")
    print("Access to alchemy/grimoire/dark_spellbook.py directly")
    print("Test import now - THIS WILL RAISE AN UNCAUGHT EXCEPTION")
    from alchemy.grimoire.dark_spellbook import dark_spell_record

    print(dark_spell_record("Doom", "bats and frogs"))


if __name__ == "__main__":
    main()
