from abc import ABC, abstractmethod
from typing import Any, List, Tuple, Protocol, Sequence


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


class ExportPlugin(Protocol):
    """Structural interface for plugins that export processed data."""
    def process_output(self, data: list[tuple[int, str]]) -> None:
        ...


# Data stream router
class DataStream:
    """Routes stream items to the first registered processor possible."""
    def __init__(self) -> None:
        self.processors: List[DataProcessor] = []

    def register_processor(self, proc: DataProcessor) -> None:
        """Register a data processor to receive stream items."""
        if isinstance(proc, DataProcessor):
            self.processors.append(proc)
        else:
            print("Error: Couldn't register data processor")

    def process_stream(self, stream: list[Any]) -> None:
        """Send each stream item to the first processor that validates it."""
        for item in stream:
            found = False
            for p in self.processors:
                if p.validate(item):
                    p.ingest(item)
                    found = True
                    break
            if not found:
                print("Data Stream error - "
                      f"Can't process element in stream: {item}")

    def print_processors_stats(self) -> None:
        """Print total ingested and remaining item counts per processor."""
        print("\n== DataStream statistics ==")
        if not self.processors:
            print("No processor found, no data")
            return
        for p in self.processors:
            print(f"{type(p).__name__}: ", end="")
            print(f"total {p.next} items processed, ", end="")
            print(f"remaining {len(p.data)} on processor")

    def output_pipeline(self, nb: int, plugin: ExportPlugin) -> None:
        """Pull up to nb items from each processor and export them."""
        for p in self.processors:
            to_export: list[tuple[int, str]] = []
            for _ in range(nb):
                try:
                    to_export.append(p.output())
                except IndexError:
                    break
            if to_export:
                plugin.process_output(to_export)


class CSVPlugin:
    
    """Export plugin that prints data as a comma-separated list."""
    def process_output(self, data: list[tuple[int, str]]) -> None:
        """Print the values of data as a CSV-style line."""
        print("CSV Output:")
        values = [v for r, v in data]
        print(", ".join(values))


class JSONPlugin:
    """Export plugin that prints data as a JSON-like object."""
    def process_output(self, data: list[tuple[int, str]]) -> None:
        """Print data formatted as a flat JSON-like object."""
        print("JSON Output:")
        items = []
        for rank, value in data:
            clean_value = value.replace("\n", " ")
            items.append(f'"item_{rank}": "{clean_value}"')
        print("{" + ", ".join(items) + "}")


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
    print("=== Code Nexus - Data Pipeline ===\n")

    print("Initialize Data Stream...")

    stream = DataStream()
    stream.print_processors_stats()

    print("\nRegistering Processors\n")

    num = NumericProcessor()
    text = TextProcessor()
    log = LogProcessor()
    stream.register_processor(num)
    stream.register_processor(text)
    stream.register_processor(log)

    data = [
        'Hello world',
        [3.14, -1, 2.71],
        [
            {'log_level': 'WARNING',
             'log_message': 'Telnet access! Use ssh instead'},
            {'log_level': 'INFO', 'log_message': 'User wil is connected'}],
        42,
        ['Hi', 'five']
    ]

    print(f"Send first batch of data on stream {data}")

    stream.process_stream(data)
    stream.print_processors_stats()
    print()

    print("Send 3 processed data from each processor to a CSV plugin:")
    stream.output_pipeline(3, CSVPlugin())
    stream.print_processors_stats()
    print("")
    DATA_POOL_2 = [
        21,
        ['I love AI', 'LLMs are wonderful', 'Stay healthy'],
        [
            {'log_level': 'ERROR', 'log_message': '500 server crash'},
            {'log_level': 'NOTICE',
             'log_message': 'Certificate expires in 10 days'}
         ], [32, 42, 64, 84, 128, 168], 'World hello'
        ]

    print(f"Send another batch of data: {DATA_POOL_2}")
    stream.process_stream(DATA_POOL_2)
    stream.print_processors_stats()
    print("\nSend 5 processed data from each processor to a JSON plugin:")
    stream.output_pipeline(5, JSONPlugin())
    print("")
    stream.print_processors_stats()
