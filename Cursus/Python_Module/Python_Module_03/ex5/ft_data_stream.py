import random
from typing import Generator

PLAYERS = ["alice", "bob", "charlie", "dylan"]
ACTIONS = ["run", "jump", "climb", "swim", "grab", "use",
           "move", "sleep", "eat", "release"]


def gen_event() -> Generator[tuple[str, str], None, None]:
    while True:
        yield (random.choice(PLAYERS), random.choice(ACTIONS))


def consume_event(
    events: list[tuple[str, str]]
) -> Generator[tuple[str, str], None, None]:
    while events:
        item = random.choice(events)
        events.remove(item)
        yield item


def main() -> None:
    print("=== Game Data Stream Processor ===")
    event_gen = gen_event()
    for i in range(1000):
        name, action = next(event_gen)
        print(f"Event {i}: Player {name} did action {action}")

    event_gen2 = gen_event()
    event_list = [next(event_gen2) for _ in range(10)]
    print(f"Built list of 10 events: {event_list}")

    for event in consume_event(event_list):
        print(f"Got event from list: {event}")
        print(f"Remains in list: {event_list}")


if __name__ == "__main__":
    main()
