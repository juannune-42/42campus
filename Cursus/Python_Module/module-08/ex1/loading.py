"""loading.py: analyze simulated Matrix data with pandas/numpy/matplotlib.

Demonstrates graceful handling of missing dependencies, and shows the
practical difference between pip (requirements.txt) and Poetry
(pyproject.toml + lock file) dependency management.
"""

import importlib
from typing import Any, Optional

try:
    import numpy as np
except ImportError:
    np = None  # type: ignore[assignment]

try:
    import pandas as pd
except ImportError:
    pd = None  # type: ignore[assignment]

try:
    import matplotlib
    matplotlib.use("Agg")
    import matplotlib.pyplot as plt
except ImportError:
    plt = None  # type: ignore[assignment]


REQUIRED_PACKAGES = ("pandas", "numpy", "matplotlib")

PACKAGE_DESCRIPTIONS = {
    "pandas": "Data manipulation ready",
    "numpy": "Numerical computation ready",
    "matplotlib": "Visualization ready",
}


def package_version(name: str) -> Optional[str]:
    """Return the installed version of a package, or None if missing."""
    try:
        module = importlib.import_module(name)
    except ImportError:
        return None
    return str(getattr(module, "__version__", "unknown"))


def check_dependencies() -> dict[str, Optional[str]]:
    """Check every required package and return its installed version."""
    return {name: package_version(name) for name in REQUIRED_PACKAGES}


def print_dependency_report(versions: dict[str, Optional[str]]) -> None:
    """Print an [OK]/[MISSING] line for every required package."""
    print("Checking dependencies:")
    for name, version in versions.items():
        description = PACKAGE_DESCRIPTIONS[name]
        if version is None:
            print(f"[MISSING] {name} - {description}")
        else:
            print(f"[OK] {name} ({version}) - {description}")


def print_installation_instructions(missing: list[str]) -> None:
    """Explain how to install missing packages via pip or Poetry."""
    print()
    print(f"Missing dependencies: {', '.join(missing)}")
    print()
    print("Install with pip (flat requirements.txt, installs into")
    print("whichever environment is currently active):")
    print("  pip install -r requirements.txt")
    print("  python3 loading.py")
    print()
    print("Install with Poetry (pyproject.toml + poetry.lock, manages")
    print("its own virtual environment, reproducible by design):")
    print("  poetry install")
    print("  poetry run python loading.py")


def generate_matrix_data(size: int = 1000) -> Any:
    """Simulate Matrix data using numpy, wrapped in a pandas DataFrame."""
    rng = np.random.default_rng(seed=42)
    signal = rng.normal(loc=0.0, scale=1.0, size=size)
    noise = rng.uniform(low=-0.5, high=0.5, size=size)
    return pd.DataFrame({"signal": signal, "noise": noise})


def analyze_matrix_data(data: Any) -> None:
    """Print progress and enrich the data with a derived column."""
    print(f"Processing {len(data)} data points...")
    data["combined"] = data["signal"] + data["noise"]


def visualize_matrix_data(data: Any, output_path: str) -> None:
    """Plot the simulated Matrix data and save it to disk."""
    print("Generating visualization...")
    figure, axis = plt.subplots()
    axis.plot(data["signal"], label="signal")
    axis.plot(data["noise"], label="noise")
    axis.set_title("Matrix data analysis")
    axis.legend()
    figure.savefig(output_path)
    plt.close(figure)


def main() -> None:
    """Run the full Matrix data-loading and analysis pipeline."""
    print("LOADING STATUS: Loading programs...")
    print()
    versions = check_dependencies()
    print_dependency_report(versions)
    missing = [name for name, version in versions.items() if version is None]
    if missing:
        print_installation_instructions(missing)
        return
    print()
    try:
        print("Analyzing Matrix data...")
        data = generate_matrix_data()
        analyze_matrix_data(data)
        visualize_matrix_data(data, "matrix_analysis.png")
        print()
        print("Analysis complete!")
        print("Results saved to: matrix_analysis.png")
    except Exception as error:
        print(f"ERROR: Analysis failed ({error})")


if __name__ == "__main__":
    main()
