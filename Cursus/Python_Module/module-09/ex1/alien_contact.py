"""alien_contact.py: custom @model_validator rules for contact reports."""

from datetime import datetime
from enum import Enum

from pydantic import BaseModel, Field, ValidationError, model_validator


class ContactType(str, Enum):
    """The channel through which an alien contact was reported."""

    RADIO = "radio"
    VISUAL = "visual"
    PHYSICAL = "physical"
    TELEPATHIC = "telepathic"


class AlienContact(BaseModel):
    """A single, validated alien contact report."""

    contact_id: str = Field(..., min_length=5, max_length=15)
    timestamp: datetime
    location: str = Field(..., min_length=3, max_length=100)
    contact_type: ContactType
    signal_strength: float = Field(..., ge=0.0, le=10.0)
    duration_minutes: int = Field(..., ge=1, le=1440)
    witness_count: int = Field(..., ge=1, le=100)
    message_received: str | None = Field(default=None, max_length=500)
    is_verified: bool = False

    @model_validator(mode="after")
    def check_business_rules(self) -> "AlienContact":
        """Enforce cross-field rules a single Field(...) can't express."""
        if not self.contact_id.startswith("AC"):
            raise ValueError("Contact ID must start with 'AC'")

        if self.contact_type is ContactType.PHYSICAL and not self.is_verified:
            raise ValueError("Physical contact reports must be verified")

        if (
            self.contact_type is ContactType.TELEPATHIC
            and self.witness_count < 3
        ):
            raise ValueError(
                "Telepathic contact requires at least 3 witnesses"
            )

        if self.signal_strength > 7.0 and not self.message_received:
            raise ValueError(
                "Strong signals (> 7.0) should include received messages"
            )

        return self


def first_error_message(error: ValidationError) -> str:
    """Return the first validation error's message, stripped of noise.

    Pydantic prefixes messages raised from @model_validator functions
    with "Value error, "; every error surfaced by this file comes from
    check_business_rules, so we always strip that prefix here.
    """
    message = error.errors()[0]["msg"]
    prefix = "Value error, "
    return message.removeprefix(prefix)


def display_contact(contact: AlienContact) -> None:
    """Print a contact report's key details."""
    print("Valid contact report:")
    print(f"ID: {contact.contact_id}")
    print(f"Type: {contact.contact_type.value}")
    print(f"Location: {contact.location}")
    print(f"Signal: {contact.signal_strength}/10")
    print(f"Duration: {contact.duration_minutes} minutes")
    print(f"Witnesses: {contact.witness_count}")
    if contact.message_received:
        print(f"Message: '{contact.message_received}'")


def main() -> None:
    """Demonstrate a valid contact report and an invalid one."""
    print("Alien Contact Log Validation")
    print("=" * 40)

    contact = AlienContact(
        contact_id="AC_2024_001",
        timestamp="2024-03-10T22:15:00",
        location="Area 51, Nevada",
        contact_type=ContactType.RADIO,
        signal_strength=8.5,
        duration_minutes=45,
        witness_count=5,
        message_received="Greetings from Zeta Reticuli",
    )
    display_contact(contact)

    print()
    print("=" * 40)
    print("Expected validation error:")
    try:
        AlienContact(
            contact_id="AC_2024_002",
            timestamp="2024-03-11T03:00:00",
            location="Roswell, New Mexico",
            contact_type=ContactType.TELEPATHIC,
            signal_strength=6.0,
            duration_minutes=20,
            witness_count=1,  # telepathic contact needs 3+ witnesses
        )
    except ValidationError as error:
        print(first_error_message(error))


if __name__ == "__main__":
    main()
