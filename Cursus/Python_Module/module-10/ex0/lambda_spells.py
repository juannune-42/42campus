"""lambda_spells.py: mastering anonymous functions in the Lambda Sanctum.

Every transformation here uses a lambda expression instead of a named
helper function, as required by this exercise.
"""


def artifact_sorter(artifacts: list[dict]) -> list[dict]:
    """Sort artifacts by 'power', strongest first."""
    return sorted(
        artifacts, key=lambda artifact: artifact["power"], reverse=True
    )


def power_filter(mages: list[dict], min_power: int) -> list[dict]:
    """Keep only the mages whose power is at least min_power."""
    return list(filter(lambda mage: mage["power"] >= min_power, mages))


def spell_transformer(spells: list[str]) -> list[str]:
    """Wrap every spell name with a '* ' prefix and ' *' suffix."""
    return list(map(lambda spell: f"* {spell} *", spells))


def mage_stats(mages: list[dict]) -> dict:
    """Compute the max, min, and average power across all mages."""
    strongest = max(mages, key=lambda mage: mage["power"])
    weakest = min(mages, key=lambda mage: mage["power"])
    total_power = sum(map(lambda mage: mage["power"], mages))
    return {
        "max_power": strongest["power"],
        "min_power": weakest["power"],
        "avg_power": round(total_power / len(mages), 2),
    }


def main() -> None:
    """Demonstrate every lambda spell taught in the Sanctum."""
    artifacts = [
        {"name": "Crystal Orb", "power": 85, "type": "focus"},
        {"name": "Fire Staff", "power": 92, "type": "weapon"},
        {"name": "Shadow Cloak", "power": 60, "type": "armor"},
    ]
    print("Testing artifact sorter...")
    sorted_artifacts = artifact_sorter(artifacts)
    first, second = sorted_artifacts[0], sorted_artifacts[1]
    print(
        f"{first['name']} ({first['power']} power) comes before "
        f"{second['name']} ({second['power']} power)"
    )

    print()
    print("Testing spell transformer...")
    transformed = spell_transformer(["fireball", "heal", "shield"])
    print(" ".join(transformed))

    print()
    print("Testing power filter...")
    mages = [
        {"name": "Alex", "power": 45, "element": "fire"},
        {"name": "Jordan", "power": 80, "element": "shadow"},
        {"name": "Riley", "power": 30, "element": "water"},
    ]
    strong_mages = power_filter(mages, 40)
    strong_names = ", ".join(map(lambda mage: mage["name"], strong_mages))
    print(f"Mages with power >= 40: {strong_names}")

    print()
    print("Testing mage stats...")
    stats = mage_stats(mages)
    print(
        f"Max: {stats['max_power']}, Min: {stats['min_power']}, "
        f"Avg: {stats['avg_power']}"
    )


if __name__ == "__main__":
    main()
