from abc import ABC, abstractmethod
from typing import Any, List, Tuple, Sequence


# Abstract base class
class DataProcessor(ABC):
    """Base class defining the common interface for all data processors."""
    def __init__(self) -> None:
        self.data: list[Tuple[int, str]] = []
        self.next: int = 0

    @abstractmethod
    def validate(self, data: Any) -> bool:
        """Check whether data is valid for this processor."""
        pass

    @abstractmethod
    def ingest(self, data: Any) -> None:
        """Process and store data internally."""
        pass

    def output(self) -> tuple[int, str]:
        """Return the oldest stored item."""
        if not self.data:
            raise IndexError("No data available")
        return self.data.pop(0)


# Number processor
class NumericProcessor(DataProcessor):
    """Processor for numeric data (int, float and lists of both)."""
    def validate(self, data: Any) -> bool:
        """Check if data is an int/float or a list of int/float."""
        return isinstance(data, (int, float)) or (
            isinstance(data, list) and all(
                isinstance(_, (int, float)) for _ in data)
        )

    def ingest(
            self,
            data: int | float | Sequence[int | float]
            ) -> None:
        """Validate and store numeric data as strings."""
        if not self.validate(data):
            raise ValueError("Improper numeric data")
        items = data if isinstance(data, list) else [data]
        try:
            for item in items:
                self.data.append((self.next, str(item)))
                self.next += 1
        except Exception as e:
            raise RuntimeError(f"Numeric data corruption (fatal crash): {e}")


# Text processor
class TextProcessor(DataProcessor):
    """Processor for text data (str and list of str)."""
    def validate(self, data: Any) -> bool:
        """Check if data is a str or a list of str."""
        return isinstance(data, str) or (
            isinstance(data, list) and all(
                isinstance(_, str) for _ in data)
        )

    def ingest(self, data: str | List[str]) -> None:
        """Validate and store text data."""
        if not self.validate(data):
            raise ValueError("Improper text data")
        items = data if isinstance(data, list) else [data]
        try:
            for item in items:
                self.data.append((self.next, item))
                self.next += 1
        except Exception as e:
            raise RuntimeError(f"Text ingestion error: {e}")


# Logs processor
class LogProcessor(DataProcessor):
    """Processor for log entries (dict[str, str] and lists of them)."""
    def _is_log(self, data: Any) -> bool:
        """Check if data is a dict with str key and str values."""
        return isinstance(data, dict) and all(
                isinstance(k, str) and isinstance(v, str)
                for k, v in data.items()
                )

    def validate(self, data: Any) -> bool:
        """Check if data is valid log entry or a list of them."""
        return self._is_log(data) or (
            isinstance(data, list) and all(
                self._is_log(_) for _ in data)
            )

    def ingest(self, data: dict[str, str] | list[dict[str, str]]) -> None:
        """Validate and store log entries formatted as 'LEVEL: message'."""
        if not self.validate(data):
            raise ValueError("Improper text data")
        items = data if isinstance(data, list) else [data]
        try:
            for item in items:
                level = item.get("log_level", "UNKNOWN")
                message = item.get("log_message", "No data available")
                self.data.append((self.next, f"{level}: {message}"))
                self.next += 1
        except Exception as e:
            raise RuntimeError(f"log ingestion error: {e}")


if __name__ == "__main__":
    print("=== Code Nexus - Data Processor ===\n")

    # Tests of numeric processor
    num_processor = NumericProcessor()
    print("Testing Numeric Processor...")
    print(f"Trying to validate input '42': {num_processor.validate(42)}")
    print(
        f"Trying to validate input 'Hello': "
        f"{num_processor.validate('Hello')}"
    )
    print("Test invalid ingestion of string 'foo' without prior validation:")
    try:
        num_processor.ingest("foo")
    except Exception as e:
        print(f"Got exception: {e}")
    list_nums = [1, 2, 3, 4, 5]
    try:
        num_processor.ingest(list_nums)
    except Exception as e:
        print(f"Got exception: {e}")
    print(f"Processing data: {list_nums}")
    print("Extracting 3 values...")
    for i in range(3):
        key, value = num_processor.output()
        print(f"Numeric value: {key}: {value}")

    # Tests of text processor
    text_processor = TextProcessor()
    print("\nTesting Text Processor...")
    print(f"Trying to validate input '42': {text_processor.validate(42)}")
    list_strings = ['Hello', 'Nexus', 'World']
    try:
        text_processor.ingest(list_strings)
    except Exception as e:
        print(f"Got exception: {e}")
    print(f"Processing data: {list_strings}")
    print("Extracting 1 value...")
    key, value = text_processor.output()
    print(f"Text value {key}: {value}")

    # Tests of log processor
    log_processor = LogProcessor()
    print("\nTesting Log Processor...")
    print(
        f"Trying to validate input 'Hello': "
        f"{log_processor.validate('Hello')}")
    list_logs = [
        {'log_level': 'NOTICE', 'log_message': 'Connection to sever'},
        {'log_level': 'ERROR', 'log_message': 'Unauthorized access!!'}
    ]
    print(f"Processing data: {list_logs}")
    try:
        log_processor.ingest(list_logs)
    except Exception as e:
        print(f"Got exception: {e}")
    print("Extracting 2 values...")
    for i in range(2):
        key, value = log_processor.output()
        print(f"Log entry {key}: {value}")
