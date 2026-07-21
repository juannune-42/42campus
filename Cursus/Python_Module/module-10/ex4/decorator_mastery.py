"""decorator_mastery.py: decorators and staticmethod in the Master's Tower."""

import time
from collections.abc import Callable
from functools import wraps


def spell_timer(func: Callable) -> Callable:
    """Time how long a spell takes to cast."""

    @wraps(func)
    def wrapper(*args: object, **kwargs: object) -> object:
        print(f"Casting {func.__name__}...")
        start = time.perf_counter()
        result = func(*args, **kwargs)
        elapsed = time.perf_counter() - start
        print(f"Spell completed in {elapsed:.3f} seconds")
        return result

    return wrapper


def power_validator(min_power: int) -> Callable:
    """Only run the decorated spell if its power meets the minimum.

    By the shared spell contract, power is always the last positional
    argument -- (target, power) for standalone spells, and
    (self, spell_name, power) for MageGuild.cast_spell.
    """

    def decorator(func: Callable) -> Callable:
        @wraps(func)
        def wrapper(*args: object, **kwargs: object) -> object:
            power = kwargs.get("power", args[-1] if args else 0)
            if power < min_power:
                return "Insufficient power for this spell"
            return func(*args, **kwargs)

        return wrapper

    return decorator


def retry_spell(max_attempts: int) -> Callable:
    """Retry a failing spell up to max_attempts times."""

    def decorator(func: Callable) -> Callable:
        @wraps(func)
        def wrapper(*args: object, **kwargs: object) -> object:
            for attempt in range(1, max_attempts + 1):
                try:
                    return func(*args, **kwargs)
                except Exception:
                    if attempt == max_attempts:
                        break
                    print(
                        f"Spell failed, retrying... "
                        f"(attempt {attempt}/{max_attempts})"
                    )
            return f"Spell casting failed after {max_attempts} attempts"

        return wrapper

    return decorator


class MageGuild:
    """A guild that validates mage names and casts member spells."""

    @staticmethod
    def validate_mage_name(name: str) -> bool:
        """A valid mage name is 3+ characters of letters and spaces only."""
        return len(name) >= 3 and all(
            character.isalpha() or character == " " for character in name
        )

    @power_validator(min_power=10)
    def cast_spell(self, spell_name: str, power: int) -> str:
        """Cast a spell if this guild member has enough power."""
        return f"Successfully cast {spell_name} with {power} power"


def main() -> None:
    """Demonstrate every decorator and static method in the Tower."""
    print("Testing spell timer...")

    @spell_timer
    def fireball(target: str) -> str:
        time.sleep(0.1)
        return "Fireball cast!"

    result = fireball("Dragon")
    print(f"Result: {result}")

    print()
    print("Testing retrying spell...")

    @retry_spell(max_attempts=3)
    def unstable_spell() -> str:
        raise RuntimeError("The spell backfired")

    print(unstable_spell())

    print()
    print("Testing MageGuild...")
    print(MageGuild.validate_mage_name("Gandalf"))
    print(MageGuild.validate_mage_name("Al"))
    guild = MageGuild()
    print(guild.cast_spell("Lightning", 15))
    print(guild.cast_spell("Spark", 5))


if __name__ == "__main__":
    main()
