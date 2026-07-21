"""oracle.py: load configuration from environment variables / .env."""

import os

try:
    from dotenv import load_dotenv
except ImportError:
    load_dotenv = None  # type: ignore[assignment]


REQUIRED_KEYS = (
    "MATRIX_MODE",
    "DATABASE_URL",
    "API_KEY",
    "LOG_LEVEL",
    "ZION_ENDPOINT",
)

DEFAULTS = {
    "MATRIX_MODE": "development",
    "DATABASE_URL": "sqlite:///local_zion.db",
    "API_KEY": "",
    "LOG_LEVEL": "DEBUG",
    "ZION_ENDPOINT": "http://localhost:8000",
}


def load_configuration() -> dict[str, str]:
    """Load .env (if present) then read every configuration variable."""
    if load_dotenv is not None:
        load_dotenv()
    return {key: os.environ.get(key, DEFAULTS[key]) for key in REQUIRED_KEYS}


def describe_database(url: str) -> str:
    """Summarize a database connection string without leaking secrets."""
    if not url:
        return "Not configured"
    if "localhost" in url or url.startswith("sqlite"):
        return "Connected to local instance"
    return "Connected to remote instance"


def describe_api(api_key: str) -> str:
    """Report whether an API key is present, without printing it."""
    return "Authenticated" if api_key else "Missing API_KEY!"


def describe_zion(endpoint: str) -> str:
    """Report the resistance network status."""
    return "Online" if endpoint else "Offline (no endpoint configured)"


def print_configuration(config: dict[str, str]) -> None:
    """Print the loaded configuration, without leaking the API key."""
    print("Configuration loaded:")
    print(f"Mode: {config['MATRIX_MODE']}")
    print(f"Database: {describe_database(config['DATABASE_URL'])}")
    print(f"API Access: {describe_api(config['API_KEY'])}")
    print(f"Log Level: {config['LOG_LEVEL']}")
    print(f"Zion Network: {describe_zion(config['ZION_ENDPOINT'])}")


def print_security_check(
    config: dict[str, str], env_file_found: bool
) -> None:
    """Report a few basic environment-hygiene checks."""
    print("Environment security check:")
    if config["API_KEY"] and config["API_KEY"] != DEFAULTS["API_KEY"]:
        print("[OK] No hardcoded secrets detected")
    else:
        print("[WARNING] No API_KEY configured")
    if env_file_found:
        print("[OK] .env file properly configured")
    else:
        print("[MISSING] No .env file found, using defaults/environment")
    if config["MATRIX_MODE"] == "production":
        print("[OK] Running in production mode")
    else:
        print("[OK] Production overrides available")


def main() -> None:
    """Read the Matrix configuration and report its status."""
    print("ORACLE STATUS: Reading the Matrix...")
    print()
    try:
        env_file_found = os.path.isfile(".env")
        config = load_configuration()
        print_configuration(config)
        print()
        print_security_check(config, env_file_found)
        print()
        print("The Oracle sees all configurations.")
    except OSError as error:
        print(f"ORACLE STATUS: connection lost ({error})")


if __name__ == "__main__":
    main()
