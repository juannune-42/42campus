"""tournament.py: exercises the ex2 abstract strategy pattern."""

from ex0 import AquaFactory, CreatureFactory, FlameFactory
from ex1 import HealingCreatureFactory, TransformCreatureFactory
from ex2 import (
    AggressiveStrategy,
    BattleStrategy,
    DefensiveStrategy,
    InvalidStrategyError,
    NormalStrategy,
)

Opponent = tuple[CreatureFactory, BattleStrategy]


def battle(opponents: list[Opponent]) -> None:
    """Make every opponent fight every other opponent, exactly once."""
    print("*** Tournament ***")
    print(f"{len(opponents)} opponents involved")
    creatures = [
        (factory.create_base(), strategy) for factory, strategy in opponents
    ]
    for index, (creature_a, strategy_a) in enumerate(creatures):
        for creature_b, strategy_b in creatures[index + 1:]:
            print()
            print("* Battle *")
            print(creature_a.describe())
            print("vs.")
            print(creature_b.describe())
            print("now fight!")
            try:
                strategy_a.act(creature_a)
                strategy_b.act(creature_b)
            except InvalidStrategyError as error:
                print(f"Battle error, aborting tournament: {error}")
                return


def main() -> None:
    """Run three tournament scenarios: basic, error, and multiple."""
    flame_factory = FlameFactory()
    aqua_factory = AquaFactory()
    healing_factory = HealingCreatureFactory()
    transform_factory = TransformCreatureFactory()

    normal = NormalStrategy()
    aggressive = AggressiveStrategy()
    defensive = DefensiveStrategy()

    scenarios: list[tuple[str, str, list[Opponent]]] = [
        (
            "Tournament 0 (basic)",
            "[ (Flameling+Normal), (Healing+Defensive) ]",
            [(flame_factory, normal), (healing_factory, defensive)],
        ),
        (
            "Tournament 1 (error)",
            "[ (Flameling+Aggressive), (Healing+Defensive) ]",
            [(flame_factory, aggressive), (healing_factory, defensive)],
        ),
        (
            "Tournament 2 (multiple)",
            "[ (Aquabub+Normal), (Healing+Defensive), "
            "(Transform+Aggressive) ]",
            [
                (aqua_factory, normal),
                (healing_factory, defensive),
                (transform_factory, aggressive),
            ],
        ),
    ]

    for index, (title, summary, opponents) in enumerate(scenarios):
        if index:
            print()
        print(title)
        print(summary)
        battle(opponents)


if __name__ == "__main__":
    main()
