import sys


def parse_inventory(args: list[str]) -> dict[str, int]:
    inventory: dict[str, int] = {}
    for arg in args:
        if ":" not in arg:
            print(f"Error - invalid parameter '{arg}'")
            continue
        parts = arg.split(":")
        if len(parts) != 2:
            print(f"Error - invalid parameter '{arg}'")
            continue
        name, qty_str = parts
        if name in inventory:
            print(f"Redundant item '{name}' - discarding")
            continue
        try:
            inventory[name] = int(qty_str)
        except ValueError as e:
            print(f"Quantity error for '{name}': {e}")
    return inventory


def main() -> None:
    print("=== Inventory System Analysis ===")
    inventory = parse_inventory(sys.argv[1:])
    print(f"Got inventory: {inventory}")

    items = list(inventory.keys())
    print(f"Item list: {items}")

    total = sum(inventory.values())
    print(f"Total quantity of the {len(inventory)} items: {total}")

    for item, qty in inventory.items():
        pct = round(qty / total * 100, 1)
        print(f"Item {item} represents {pct}%")

    most = max(inventory, key=lambda k: list(inventory.keys()).index(k)
               if list(inventory.values()).count(inventory[k]) > 1
               else -inventory[k])
    # Simpler approach: find max value, pick first key with that value
    max_qty = max(inventory.values())
    min_qty = min(inventory.values())
    most_abundant = next(k for k in inventory if inventory[k] == max_qty)
    least_abundant = next(k for k in inventory if inventory[k] == min_qty)
    print(f"Item most abundant: {most_abundant} with quantity {max_qty}")
    print(f"Item least abundant: {least_abundant} with quantity {min_qty}")

    inventory.update({"magic_item": 1})
    print(f"Updated inventory: {inventory}")


if __name__ == "__main__":
    main()
