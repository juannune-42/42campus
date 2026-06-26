import random

PLAYERS_RAW = ["Alice", "bob", "Charlie", "dylan", "Emma",
               "Gregory", "john", "kevin", "Liam"]


def main() -> None:
    print("=== Game Data Alchemist ===")
    print()
    print(f"Initial list of players: {PLAYERS_RAW}")

    all_capitalized = [name.capitalize() for name in PLAYERS_RAW]
    print(f"New list with all names capitalized: {all_capitalized}")

    already_capitalized = [
        name for name in PLAYERS_RAW if name == name.capitalize()
    ]
    print(f"New list of capitalized names only: {already_capitalized}")

    score_dict = {name: random.randint(1, 1000) for name in all_capitalized}
    print(f"Score dict: {score_dict}")

    avg = round(sum(score_dict.values()) / len(score_dict), 2)
    print(f"Score average is {avg}")

    high_scores = {k: v for k, v in score_dict.items() if v > avg}
    print(f"High scores: {high_scores}")


if __name__ == "__main__":
    main()
