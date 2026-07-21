"""higher_magic.py: higher-order functions in the Higher Realm.

Every spell in this file follows the shared contract:
    def spell(target: str, power: int) -> str
"""

from collections.abc import Callable


def fireball(target: str, power: int) -> str:
    """A basic damage spell."""
    return f"Fireball hits {target} for {power} damage"


def heal(target: str, power: int) -> str:
    """A basic restoration spell."""
    return f"Heals {target} for {power} HP"


def spell_combiner(spell1: Callable, spell2: Callable) -> Callable:
    """Combine two spells: cast both, return a tuple of both results."""
    if not callable(spell1) or not callable(spell2):
        raise TypeError("spell_combiner requires two callable spells")

    def combined(target: str, power: int) -> tuple[str, str]:
        return (spell1(target, power), spell2(target, power))

    return combined


def power_amplifier(base_spell: Callable, multiplier: int) -> Callable:
    """Return a spell that multiplies power before casting."""

    def amplified(target: str, power: int) -> str:
        return base_spell(target, power * multiplier)

    return amplified


def conditional_caster(condition: Callable, spell: Callable) -> Callable:
    """Return a spell that only casts when the condition holds."""

    def maybe_cast(target: str, power: int) -> str:
        if condition(target, power):
            return spell(target, power)
        return "Spell fizzled"

    return maybe_cast


def spell_sequence(spells: list[Callable]) -> Callable:
    """Return a spell that casts every spell in the list, in order."""
    if not all(callable(spell) for spell in spells):
        raise TypeError("spell_sequence requires a list of callables")

    def cast_all(target: str, power: int) -> list[str]:
        return [spell(target, power) for spell in spells]

    return cast_all


def main() -> None:
    """Demonstrate every higher-order spell modifier."""
    print("Testing spell combiner...")
    combined = spell_combiner(fireball, heal)
    fire_result, heal_result = combined("Dragon", 20)
    print(f"Combined spell result: {fire_result}, {heal_result}")

    print()
    print("Testing power amplifier...")
    mega_fireball = power_amplifier(fireball, 3)
    original_power = 10
    print(f"Original: {original_power}, Amplified: {original_power * 3}")
    print(mega_fireball("Dragon", original_power))

    print()
    print("Testing conditional caster...")
    guarded_fireball = conditional_caster(
        lambda target, power: power >= 15, fireball
    )
    print(guarded_fireball("Goblin", 20))
    print(guarded_fireball("Goblin", 5))

    print()
    print("Testing spell sequence...")
    sequence = spell_sequence([fireball, heal, mega_fireball])
    for result in sequence("Dragon", 10):
        print(result)


if __name__ == "__main__":
    main()
