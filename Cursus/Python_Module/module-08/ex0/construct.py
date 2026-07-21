"""construct.py: detect and describe the current Python environment."""

import os
import site
import sys


def in_virtual_env() -> bool:
    """Return True when running inside a virtual environment."""
    return sys.prefix != sys.base_prefix


def virtual_env_name() -> str:
    """Return the virtual environment's directory name."""
    return os.path.basename(os.path.normpath(sys.prefix))


def site_packages_path() -> str:
    """Return the active interpreter's site-packages directory."""
    try:
        packages = site.getsitepackages()
        return packages[0] if packages else "unknown"
    except (AttributeError, OSError, IndexError):
        return "unknown"


def show_outside_matrix() -> None:
    """Explain that no virtual environment is active, and how to fix it."""
    print("MATRIX STATUS: You're still plugged in")
    print()
    print(f"Current Python: {sys.executable}")
    print("Virtual Environment: None detected")
    print()
    print("WARNING: You're in the global environment!")
    print("The machines can see everything you install.")
    print()
    print("To enter the construct, run:")
    print("python -m venv matrix_env")
    print("source matrix_env/bin/activate # On Unix")
    print("matrix_env\\Scripts\\activate  # On Windows")
    print()
    print("Then run this program again.")


def show_inside_matrix() -> None:
    """Describe the currently active virtual environment."""
    print("MATRIX STATUS: Welcome to the construct")
    print()
    print(f"Current Python: {sys.executable}")
    print(f"Virtual Environment: {virtual_env_name()}")
    print(f"Environment Path: {sys.prefix}")
    print()
    print("SUCCESS: You're in an isolated environment!")
    print("Safe to install packages without affecting")
    print("the global system.")
    print()
    print("Package installation path:")
    print(site_packages_path())


def main() -> None:
    """Detect the current environment and report accordingly."""
    try:
        if in_virtual_env():
            show_inside_matrix()
        else:
            show_outside_matrix()
    except Exception as error:
        print(f"MATRIX STATUS: signal lost ({error})")


if __name__ == "__main__":
    main()
