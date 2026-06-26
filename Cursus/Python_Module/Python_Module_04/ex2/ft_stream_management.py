import sys
import typing


def read_file(file_name: str) -> str | None:
    print("=== Cyber Archives Recovery & Preservation ===")
    print(f"Accessing file '{file_name}'")
    file: typing.IO | None = None
    content: str | None = None
    try:
        file = open(file_name, "r")
        content = file.read()
        print("---")
        print(content, end="")
        print("---")
        print(f"File '{file_name}' closed.")
    except Exception as e:
        sys.stderr.write(f"[STDERR] Error opening file '{file_name}': {e}\n")
        sys.stderr.flush()
    finally:
        if file is not None:
            file.close()
    return content


def transform_content(content: str) -> str:
    lines = content.splitlines()
    new_lines = [line + "#" for line in lines]
    return "\n".join(new_lines) + "\n"


def save_file(file_name: str, content: str) -> None:
    file: typing.IO | None = None
    try:
        print(f"Saving data to '{file_name}'")
        file = open(file_name, "w")
        file.write(content)
        print(f"Data saved in file '{file_name}'.")
    except Exception as e:
        sys.stderr.write(f"[STDERR] Error opening file '{file_name}': {e}\n")
        sys.stderr.flush()
        print("Data not saved.")
    finally:
        if file is not None:
            file.close()


def main() -> None:
    if len(sys.argv) != 2:
        print("Usage: ft_stream_management.py <file>")
        return

    content = read_file(sys.argv[1])
    if content is None:
        return

    new_content = transform_content(content)
    print("Transform data:")
    print("---")
    print(new_content, end="")
    print("---")

    sys.stdout.write("Enter new file name (or empty): ")
    sys.stdout.flush()
    new_name = sys.stdin.readline().rstrip("\n")

    if not new_name:
        print("Not saving data.")
    else:
        save_file(new_name, new_content)


if __name__ == "__main__":
    main()        