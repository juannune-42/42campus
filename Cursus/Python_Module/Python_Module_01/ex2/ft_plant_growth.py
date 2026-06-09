class Plant:
    def __init__(self, name, height, days):
        self.name = name
        self.height = height
        self.days = days

    def show(self):
        print(f"{self.name}: {self.height}cm, {self.days} days old")

    def grow(self):
        self.height = round(self.height + 0.8, 1)

    def age(self):
        self.days += 1


if __name__ == "__main__":
    plant = Plant("Rose", 25.0, 30)
    initial_height = plant.height

    print("=== Garden Plant Growth ===")
    plant.show()
    for day in range(1, 8):
        print(f"=== Day {day} ===")
        plant.grow()
        plant.age()
        plant.show()

    growth = plant.height - initial_height
    print(f"Growth this week: {round(growth, 1)}cm\n")
