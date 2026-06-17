def input_temperature(temp_str: str) -> None:
    try:
        temp = int(temp_str)
        if temp > 40:
            print(f"Caught input_temperature error: "
                  f"{temp}°C is too hot for plants (max 40°C)")
        elif temp < 0:
            print(f"Caught input_temperature error: "
                  f"{temp}°C is too cold for plants (min 0°C)")
        else:
            print(f"Temperature is now {temp}°C")
    except ValueError as e:
        print(f"Caught input_temperature error: {e}")
    print()


def test_temperature() -> None:
    print("=== Garden Temperature ===")
    print()
    temp_str: str = "25"
    print(f"Input data is '{temp_str}'")
    input_temperature(temp_str)
    temp_str = "abc"
    print(f"Input data is '{temp_str}'")
    input_temperature(temp_str)
    temp_str = "100"
    print(f"Input data is '{temp_str}'")
    input_temperature(temp_str)
    temp_str = "-50"
    print(f"Input data is '{temp_str}'")
    input_temperature(temp_str)
    print("All tests completed - program didn't crash!")


if __name__ == "__main__":
    test_temperature()
