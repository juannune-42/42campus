def input_temperature(temp_str: str) -> int:
    return int(temp_str)


def test_error() -> None:
    print("=== Garden Error Types Demo ===")
    print("Testing operation 0. . .")
    temp: str = "abc"
    try:
        temp: int = input_temperature(temp)
    except ValueError as e:
        print(f"Caught ValueError error: {e}")
    print()
    print("Testing operation 1. . .")
    try:
        temp: int = 0 / 0
    except ZeroDivisionError as e:
        print(f"Caught ValueError error: {e}")
    print()
    print("Testing operation 2. . .")
    try:
        temp: int = 0 / 0
    except FileNotFoundError as e:
        print(f"Caught ValueError error: {e}")
    print()


if __name__ == "__main__":
    test_error()

# ValueError
# ZeroDivisionError
# FileNotFoundError
# TypeError
