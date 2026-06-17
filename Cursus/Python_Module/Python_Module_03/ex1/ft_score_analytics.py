import sys


def parse_scores(args: list[str]) -> list[int]:
    scores: list[int] = []
    for arg in args:
        try:
            scores.append(int(arg))
        except ValueError:
            print(f"Invalid parameter: '{arg}'")
    return scores


def main() -> None:
    print("=== Player Score Analytics ===")
    args = sys.argv[1:]
    scores = parse_scores(args)
    if not scores:
        print(
            "No scores provided. Usage: python3 "
            "ft_score_analytics.py <score1> <score2> ..."
        )
        return
    total = sum(scores)
    average = total / len(scores)
    print(f"Scores processed: {scores}")
    print(f"Total players: {len(scores)}")
    print(f"Total score: {total}")
    print(f"Average score: {average}")
    print(f"High score: {max(scores)}")
    print(f"Low score: {min(scores)}")
    print(f"Score range: {max(scores) - min(scores)}")


if __name__ == "__main__":
    main()
