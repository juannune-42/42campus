"""space_station.py: basic Pydantic v2 model for space station telemetry."""

from datetime import datetime

from pydantic import BaseModel, Field, ValidationError


class SpaceStation(BaseModel):
    """A single, validated space station telemetry report."""

    station_id: str = Field(..., min_length=3, max_length=10)
    name: str = Field(..., min_length=1, max_length=50)
    crew_size: int = Field(..., ge=1, le=20)
    power_level: float = Field(..., ge=0.0, le=100.0)
    oxygen_level: float = Field(..., ge=0.0, le=100.0)
    last_maintenance: datetime
    is_operational: bool = True
    notes: str | None = Field(default=None, max_length=200)


def first_error_message(error: ValidationError) -> str:
    """Return the first validation error's message, stripped of noise.

    Pydantic prefixes messages raised from custom validators with
    "Value error, " -- built-in Field constraint errors (like the
    crew_size check below) never carry that prefix, so stripping it
    here is safe either way.
    """
    message = error.errors()[0]["msg"]
    prefix = "Value error, "
    return message.removeprefix(prefix)


def display_station(station: SpaceStation) -> None:
    """Print a station's key statistics in a human-readable format."""
    print("Valid station created:")
    print(f"ID: {station.station_id}")
    print(f"Name: {station.name}")
    print(f"Crew: {station.crew_size} people")
    print(f"Power: {station.power_level}%")
    print(f"Oxygen: {station.oxygen_level}%")
    status = "Operational" if station.is_operational else "Offline"
    print(f"Status: {status}")


def main() -> None:
    """Demonstrate a valid space station and an invalid one."""
    print("Space Station Data Validation")
    print("=" * 40)

    # Pydantic accepts an ISO-8601 string here and converts it to a
    # real datetime automatically -- no manual parsing required.
    station = SpaceStation(
        station_id="ISS001",
        name="International Space Station",
        crew_size=6,
        power_level=85.5,
        oxygen_level=92.3,
        last_maintenance="2024-01-15T10:00:00",
    )
    display_station(station)

    print()
    print("=" * 40)
    print("Expected validation error:")
    try:
        SpaceStation(
            station_id="ISS002",
            name="Overcrowded Station",
            crew_size=25,  # violates crew_size's le=20 constraint
            power_level=80.0,
            oxygen_level=90.0,
            last_maintenance="2024-01-15T10:00:00",
        )
    except ValidationError as error:
        print(first_error_message(error))


if __name__ == "__main__":
    main()
