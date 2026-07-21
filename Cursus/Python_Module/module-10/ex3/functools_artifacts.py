"""functools_artifacts.py: functools treasures in the Ancient Library."""

import operator
from collections.abc import Callable
from functools import lru_cache, partial, reduce, singledispatch
from typing import Any


def spell_reducer(spells: list[int], operation: str) -> int:
    """Reduce a list of spell powers into a single value."""
    if not spells:
        return 0
    operations: dict[str, Callable[[int, int], int]] = {
        "add": operator.add,
        "multiply": operator.mul,
        "max": max,
        "min": min,
    }
    try:
        combine = operations[operation]
    except KeyError as error:
        raise ValueError(f"Unknown operation: {operation}") from error
    return reduce(combine, spells)


def partial_enchanter(base_enchantment: Callable) -> dict[str, Callable]:
    """Create 3 specialized enchantments via functools.partial.

    Each one pre-fills power=50 and a fixed element, leaving only the
    target to be supplied later.
    """
    return {
        "fire": partial(base_enchantment, power=50, element="fire"),
        "ice": partial(base_enchantment, power=50, element="ice"),
        "lightning": partial(
            base_enchantment, power=50, element="lightning"
        ),
    }


@lru_cache(maxsize=None)
def memoized_fibonacci(n: int) -> int:
    """Return the nth Fibonacci number, memoized via functools.lru_cache."""
    if n < 2:
        return n
    return memoized_fibonacci(n - 1) + memoized_fibonacci(n - 2)


def spell_dispatcher() -> Callable[[Any], str]:
    """Build a functools.singledispatch spell system and return it."""

    @singledispatch
    def cast(spell: Any) -> str:
        return "Unknown spell type"

    @cast.register
    def _(spell: int) -> str:
        return f"{spell} damage"

    @cast.register
    def _(spell: str) -> str:
        return spell

    @cast.register
    def _(spell: list) -> str:
        return f"{len(spell)} spells"

    return cast


def main() -> None:
    """Demonstrate every functools artifact in the Ancient Library."""
    spells = [10, 20, 30, 40]
    print("Testing spell reducer...")
    print(f"Sum: {spell_reducer(spells, 'add')}")
    print(f"Product: {spell_reducer(spells, 'multiply')}")
    print(f"Max: {spell_reducer(spells, 'max')}")
    try:
        spell_reducer(spells, "unknown_op")
    except ValueError as error:
        print(f"Reducer error handled: {error}")

    print()
    print("Testing partial enchanter...")

    def enchant(power: int, element: str, target: str) -> str:
        return f"{target} enchanted with {element} ({power} power)"

    enchantments = partial_enchanter(enchant)
    print(enchantments["fire"](target="Sword"))
    print(enchantments["lightning"](target="Bow"))

    print()
    print("Testing memoized fibonacci...")
    print(f"Fib(0): {memoized_fibonacci(0)}")
    print(f"Fib(1): {memoized_fibonacci(1)}")
    print(f"Fib(10): {memoized_fibonacci(10)}")
    print(f"Fib(15): {memoized_fibonacci(15)}")
    print(memoized_fibonacci.cache_info())

    print()
    print("Testing spell dispatcher...")
    cast = spell_dispatcher()
    print(f"Damage spell: {cast(42)}")
    print(f"Enchantment: {cast('fireball')}")
    print(f"Multi-cast: {cast(['fireball', 'heal', 'shield'])}")
    print(cast(3.14))


if __name__ == "__main__":
    main()
