class Plant:
    def __init__(
        self,
        name: str,
        height: float,
        age: int,
        growth_rate: float
    ) -> None:
        self.name = name
        self._height: float = 0.0
        self._age: int = 0
        self.growth_rate = growth_rate
        if height >= 0:
            self._height = height
        else:
            print(f"{self.name}: Error, height can't be negative")
        if age >= 0:
            self._age = age
        else:
            print(f"{self.name}: Error, age can't be negative")
<<<<<<< HEAD
        print(
            f"Plant created: {self.name}: "
            f"{self._height:.1f}cm, {self._age} days old"
        )
=======

        print(f"Plant created: {self.name}: "
              f"{self._height:.1f}cm, {self._age} days old")
>>>>>>> a21dbef (A_maze_ing)

    def show(self) -> None:
        print(f"{self.name}: {self._height:.1f}cm, {self._age} days old")

    def get_height(self) -> float:
        return self._height

    def set_height(self, value: float) -> None:
        if value >= 0:
            self._height = value
            print(f"Height updated: {self._height:g}cm")
        else:
            print(f"{self.name}: Error, height can't be negative")
            print("Height update rejected")

    def get_age(self) -> int:
        return self._age

    def set_age(self, value: int) -> None:
        if value >= 0:
            self._age = value
            print(f"Age updated: {self._age} days")
        else:
            print(f"{self.name}: Error, age can't be negative")
            print("Age update rejected")


if __name__ == "__main__":
    print("=== Garden Security System ===")
    plant1 = Plant("Rose", 15.0, 10, 0.1)
    print()
    plant1.set_height(25)
    plant1.set_age(30)
    print()
    plant1.set_height(-5)
    plant1.set_age(-8)
    print()
    print(
        f"Current state: {plant1.name}: "
        f"{plant1.get_height():.1f}cm, {plant1.get_age()} days old"
    )
