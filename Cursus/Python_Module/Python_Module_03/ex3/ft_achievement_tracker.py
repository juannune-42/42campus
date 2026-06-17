import random

ALL_ACHIEVEMENTS = [
    "First Steps", "Speed Runner", "Boss Slayer", "Collector Supreme",
    "Master Explorer", "Survivor", "Strategist", "World Savior",
    "Untouchable", "Unstoppable", "Treasure Hunter", "Sharp Mind",
    "Crafting Genius", "Hidden Path Finder",
]

PLAYERS = ["Alice", "Bob", "Charlie", "Dylan"]


def gen_player_achievements() -> set[str]:
    count = random.randint(4, 10)
    return set(random.sample(ALL_ACHIEVEMENTS, count))


def main() -> None:
    print("=== Achievement Tracker System ===")
    player_achievements: dict[str, set[str]] = {
        player: gen_player_achievements() for player in PLAYERS
    }
    for player, achievements in player_achievements.items():
        print(f"Player {player}: {achievements}")

    all_achievements: set[str] = set()
    for a in player_achievements.values():
        all_achievements = all_achievements.union(a)
    print(f"\nAll distinct achievements: {all_achievements}")

    common = player_achievements[PLAYERS[0]]
    for a in player_achievements.values():
        common = common.intersection(a)
    print(f"Common achievements: {common}")

    for player, achievements in player_achievements.items():
        others: set[str] = set()
        for other, other_ach in player_achievements.items():
            if other != player:
                others = others.union(other_ach)
        unique = achievements.difference(others)
        print(f"Only {player} has: {unique}")

    for player, achievements in player_achievements.items():
        missing = all_achievements.difference(achievements)
        print(f"{player} is missing: {missing}")


if __name__ == "__main__":
    main()
