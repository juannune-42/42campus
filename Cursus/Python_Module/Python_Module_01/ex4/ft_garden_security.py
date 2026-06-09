class Plant:
    def __init__(self, name: str, height: int, age: int):
        self._name = name
        self._height = 0
        self._age = 0
        print(f"Plant created: {self._name}")
        self.set_height(height)
        self.set_age(age)

    def get_height(self) -> int:
        return self._height

    def set_height(self, value: int):
        if value >= 0:
            self._height = value
            print(f"Height updated: {self._height}cm [ok]")
        else:
            print(
                f"\nInvalid operation attempted: height {value}cm [REJECTED]")
            print("Security: Negative height rejected")

    def get_age(self) -> int:
        return self._age

    def set_age(self, value: int):
        if value >= 0:
            self._age = value
            print(f"Ageg updated: {self._age} days [ok]")
        else:
            print(f"\nInvalid operation attempted: age {value}days [REJECTED]")
            print("Security: Negative height rejected")

    def get_info(self):
        print(
            f"\nCurrent plant: {self.__name} "
            f"({self.__height}cm {self.__age} days))"
        )


if __name__ == "__main__":
    plant1 = Plant("Rose", 25, 30)
    plant1.set_age(-8)
    plant1.set_height(-5)
    plant1.get_info()
