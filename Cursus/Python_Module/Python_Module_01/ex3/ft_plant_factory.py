class Plant:
    def __init__(
        self,
        name: str,
        height: float,
        days: int,
        growth_rate: float
    ) -> None:
        self.name = name
        self.height = height
        self.days = days
        self.growth_rate = growth_rate

    def show(self) -> None:
        print(f"{self.name}: {self.height}cm, {self.days} days old")

    def grow(self) -> None:
        self.height = round(self.height + self.growth_rate, 1)

    def age(self) -> None:
        self.days += 1


if __name__ == "__main__":
    print("=== Plant Factory Output ===")
    plants_data: list[tuple[str, float, int, float]] = [
        ("Rose", 25.0, 30, 0.1),
        ("Oak", 200.0, 365, 0.2),
        ("Cactus", 5.0, 90, 0.3),
        ("Sunflower", 80.0, 45, 0.4),
        ("Fern", 15.0, 120, 0.5),
    ]
    plants: list[Plant] = [
        Plant(name, height, days, growth_rate)
        for name, height, days, growth_rate in plants_data
    ]
    for plant in plants:
        print("Created: ", end="")
        plant.show()
