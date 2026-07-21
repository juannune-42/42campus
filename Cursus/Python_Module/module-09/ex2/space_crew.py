"""space_crew.py: nested Pydantic v2 models for space mission crews."""

from datetime import datetime
from enum import Enum

from pydantic import BaseModel, Field, ValidationError, model_validator


class Rank(str, Enum):
    """Military-style rank of a crew member."""

    CADET = "cadet"
    OFFICER = "officer"
    LIEUTENANT = "lieutenant"
    CAPTAIN = "captain"
    COMMANDER = "commander"


class CrewMember(BaseModel):
    """A single, validated crew member."""

    member_id: str = Field(..., min_length=3, max_length=10)
    name: str = Field(..., min_length=2, max_length=50)
    rank: Rank
    age: int = Field(..., ge=18, le=80)
    specialization: str = Field(..., min_length=3, max_length=30)
    years_experience: int = Field(..., ge=0, le=50)
    is_active: bool = True


class SpaceMission(BaseModel):
    """A mission, with a validated crew roster (a nested model list)."""

    mission_id: str = Field(..., min_length=5, max_length=15)
    mission_name: str = Field(..., min_length=3, max_length=100)
    destination: str = Field(..., min_length=3, max_length=50)
    launch_date: datetime
    duration_days: int = Field(..., ge=1, le=3650)
    crew: list[CrewMember] = Field(..., min_length=1, max_length=12)
    mission_status: str = "planned"
    budget_millions: float = Field(..., ge=1.0, le=10000.0)

    @model_validator(mode="after")
    def check_safety_rules(self) -> "SpaceMission":
        """Enforce mission-wide safety rules across the whole crew.

        Note: if a CrewMember in the input data is itself invalid,
        Pydantic rejects it (and reports it) while building the list,
        before this mission-level validator ever runs.
        """
        if not self.mission_id.startswith("M"):
            raise ValueError("Mission ID must start with 'M'")

        command_ranks = {Rank.COMMANDER, Rank.CAPTAIN}
        if not any(member.rank in command_ranks for member in self.crew):
            raise ValueError(
                "Mission must have at least one Commander or Captain"
            )

        if self.duration_days > 365:
            experienced = sum(
                1 for member in self.crew if member.years_experience >= 5
            )
            if experienced < len(self.crew) / 2:
                raise ValueError(
                    "Long missions (> 365 days) need 50% experienced "
                    "crew (5+ years)"
                )

        if not all(member.is_active for member in self.crew):
            raise ValueError("All crew members must be active")

        return self


def first_error_message(error: ValidationError) -> str:
    """Return the first validation error's message, stripped of noise.

    Pydantic prefixes messages raised from @model_validator functions
    with "Value error, "; every error surfaced by this file comes from
    check_safety_rules, so we always strip that prefix here.
    """
    message = error.errors()[0]["msg"]
    prefix = "Value error, "
    return message.removeprefix(prefix)


def display_mission(mission: SpaceMission) -> None:
    """Print a mission's key details and its crew roster."""
    print("Valid mission created:")
    print(f"Mission: {mission.mission_name}")
    print(f"ID: {mission.mission_id}")
    print(f"Destination: {mission.destination}")
    print(f"Duration: {mission.duration_days} days")
    print(f"Budget: ${mission.budget_millions}M")
    print(f"Crew size: {len(mission.crew)}")
    print("Crew members:")
    for member in mission.crew:
        print(
            f"- {member.name} ({member.rank.value}) - "
            f"{member.specialization}"
        )


def build_valid_crew() -> list[CrewMember]:
    """Build a small, valid crew: a commander plus two officers."""
    return [
        CrewMember(
            member_id="CM001",
            name="Sarah Connor",
            rank=Rank.COMMANDER,
            age=42,
            specialization="Mission Command",
            years_experience=15,
        ),
        CrewMember(
            member_id="CM002",
            name="John Smith",
            rank=Rank.LIEUTENANT,
            age=35,
            specialization="Navigation",
            years_experience=8,
        ),
        CrewMember(
            member_id="CM003",
            name="Alice Johnson",
            rank=Rank.OFFICER,
            age=29,
            specialization="Engineering",
            years_experience=4,
        ),
    ]


def main() -> None:
    """Demonstrate a valid mission and an invalid one."""
    print("Space Mission Crew Validation")
    print("=" * 40)

    mission = SpaceMission(
        mission_id="M2024_MARS",
        mission_name="Mars Colony Establishment",
        destination="Mars",
        launch_date="2024-06-01T09:00:00",
        duration_days=900,
        budget_millions=2500.0,
        crew=build_valid_crew(),
    )
    display_mission(mission)

    print()
    print("=" * 40)
    print("Expected validation error:")
    try:
        SpaceMission(
            mission_id="M2024_FAIL",
            mission_name="Doomed Expedition",
            destination="Europa",
            launch_date="2024-07-01T09:00:00",
            duration_days=200,
            budget_millions=500.0,
            # No Commander or Captain in this crew -> should fail.
            crew=[
                CrewMember(
                    member_id="CM010",
                    name="Bob Rookie",
                    rank=Rank.CADET,
                    age=20,
                    specialization="Support",
                    years_experience=1,
                ),
            ],
        )
    except ValidationError as error:
        print(first_error_message(error))


if __name__ == "__main__":
    main()
