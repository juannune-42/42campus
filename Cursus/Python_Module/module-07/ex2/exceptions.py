"""Dedicated exception for invalid Creature-strategy combinations."""


class InvalidStrategyError(Exception):
    """Raised when a strategy is used on an incompatible Creature."""
