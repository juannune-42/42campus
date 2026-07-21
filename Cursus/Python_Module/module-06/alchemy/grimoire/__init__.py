"""Grimoire subpackage: public interface for light magic only.

Dark magic is intentionally not exposed here; reaching it requires
importing alchemy.grimoire.dark_spellbook directly (see ft_kaboom_1.py).
"""

from .light_spellbook import light_spell_record  # noqa: F401

__all__ = ["light_spell_record"]
