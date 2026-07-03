import sys
import typing


def read_file(file_name: str) -> None:
    print("=== Cyber Archives Recovery ===")
    print(f"Accessing file '{file_name}'")
    file: typing.IO | None = None
    try:
        file = open(file_name, "r")
        print("---\n")
        print(file.read(), end="")
        print("\n---")
        print(f"File '{file_name}' closed.")
    except (FileNotFoundError, PermissionError) as e:
        print(f"Error opening file '{file_name}': {e}")
    finally:
        if file is not None:
            file.close()


def main() -> None:
    if len(sys.argv) != 2:
        print("Usage: ft_ancient_text.py <file>")
        return
    read_file(sys.argv[1])


if __name__ == "__main__":
    main()
