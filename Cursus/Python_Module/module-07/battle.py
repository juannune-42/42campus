"""battle.py: exercises the ex0 abstract factory pattern."""

from ex0 import AquaFactory, CreatureFactory, FlameFactory


def test_factory(factory: CreatureFactory) -> None:
    """Create, describe and attack with both forms of a family."""
    print("Testing factory")
    base = factory.create_base()
    print(base.describe())
    print(base.attack())
    evolved = factory.create_evolved()
    print(evolved.describe())
    print(evolved.attack())


def test_battle(
    factory_a: CreatureFactory, factory_b: CreatureFactory
) -> None:
    """Make the base Creature of two families fight each other."""
    print("Testing battle")
    creature_a = factory_a.create_base()
    creature_b = factory_b.create_base()
    print(creature_a.describe())
    print("vs.")
    print(creature_b.describe())
    print("fight!")
    print(creature_a.attack())
    print(creature_b.attack())


def main() -> None:
    """Run the factory and battle scenarios."""
    flame_factory = FlameFactory()
    aqua_factory = AquaFactory()
    test_factory(flame_factory)
    print()
    test_factory(aqua_factory)
    print()
    test_battle(flame_factory, aqua_factory)


if __name__ == "__main__":
    main()
