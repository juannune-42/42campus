class GardenError(Exception):
    def __init__(self, message: str = "Unknown garden error") -> None:
        super().__init__(message)


class PlantError(GardenError):
    def __init__(self, message: str = "Unknown plant error") -> None:
        super().__init__(message)


class WaterError(GardenError):
    def __init__(self, message: str = "Unknown water error") -> None:
        super().__init__(message)


def test_plant_error() -> None:
    print("Testing PlantError...")
    try:
        raise PlantError("The tomato plant is wilting!")
    except PlantError as e:
        print(f"Caught PlantError: {e}")


def test_water_error() -> None:
    print("\nTesting WaterError...")
    try:
        raise WaterError("Not enough water in the tank!")
    except WaterError as e:
        print(f"Caught WaterError: {e}")


def test_garden_error_catches_all() -> None:
    print("\nTesting catching all garden errors...")
    for error in [
        PlantError("The tomato plant is wilting!"),
        WaterError("Not enough water in the tank!"),
    ]:
        try:
            raise error
        except GardenError as e:
            print(f"Caught GardenError: {e}")


if __name__ == "__main__":
    print("=== Custom Garden Errors Demo ===")
    print()
    test_plant_error()
    test_water_error()
    test_garden_error_catches_all()
    print("\nAll custom error types work correctly!")
