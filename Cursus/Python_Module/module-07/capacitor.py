"""capacitor.py: exercises the ex1 healing and transform capabilities."""

from ex1 import HealingCreatureFactory, TransformCreatureFactory


def test_healing(factory: HealingCreatureFactory) -> None:
    """Describe, attack, then heal both the base and evolved Creature."""
    print("Testing Creature with healing capability")
    print("base:")
    base = factory.create_base()
    print(base.describe())
    print(base.attack())
    print(base.heal())
    print("evolved:")
    evolved = factory.create_evolved()
    print(evolved.describe())
    print(evolved.attack())
    print(evolved.heal())


def test_transform(factory: TransformCreatureFactory) -> None:
    """Describe, attack, transform, attack again, then revert."""
    print("Testing Creature with transform capability")
    print("base:")
    base = factory.create_base()
    print(base.describe())
    print(base.attack())
    print(base.transform())
    print(base.attack())
    print(base.revert())
    print("evolved:")
    evolved = factory.create_evolved()
    print(evolved.describe())
    print(evolved.attack())
    print(evolved.transform())
    print(evolved.attack())
    print(evolved.revert())


def main() -> None:
    """Run both capability scenarios."""
    test_healing(HealingCreatureFactory())
    print()
    test_transform(TransformCreatureFactory())


if __name__ == "__main__":
    main()
