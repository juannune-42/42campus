class Plant:
    def __init__(self, name: str, height: float, days: int) -> None:
        self.name = name
        self.height = height
        self.days = days

    def show(self) -> None:
        print(f"{self.name}: {self.height}cm, {self.days} days old")


if __name__ == "__main__":
    print("=== Plant Factory Output ===")
    plants_data: list[tuple[str, float, int]] = [
        ("Rose", 25.0, 30),
        ("Oak", 200.0, 365),
        ("Cactus", 5.0, 90),
        ("Sunflower", 80.0, 45),
        ("Fern", 15.0, 120),
    ]

    plants: list[Plant] = [
        Plant(name, height, days) for name, height, days in plants_data
    ]

    for plant in plants:
        print("Created: ", end="")
        plant.show()
