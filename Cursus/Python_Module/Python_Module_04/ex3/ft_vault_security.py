def secure_archive(
    file_name: str,
    action: int | str = "read",
    content: str = ""
) -> tuple[bool, str]:
    try:
        if action == "read" or action == 0:
            with open(file_name, "r") as f:
                data = f.read()
            return (True, data)
        else:
            with open(file_name, "w") as f:
                f.write(content)
            return (True, "Content successfully written to file")
    except Exception as e:
        return (False, str(e))


def main() -> None:
    print("=== Cyber Archives Security ===")

    print("\nUsing 'secure_archive' to read from a nonexistent file:")
    print(secure_archive("/not/existing/file"))

    print("\nUsing 'secure_archive' to read from an inaccessible file:")
    print(secure_archive("/etc/shadow"))

    print("\nUsing 'secure_archive' to read from a regular file:")
    result = secure_archive("ancient_fragment.txt")
    print(result)

    print("\nUsing 'secure_archive' to write previous content to a new file:")
    print(secure_archive("new_vault.txt", "write", result[1]))


if __name__ == "__main__":
    main()
