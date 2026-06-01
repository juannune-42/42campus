def ft_count_harvest_iterative():
    temp: int = 1
    day: int = int(input("Days until harvest: "))
    while day >= temp:
        print("Day", temp)
        temp += 1
    print("Harvest time!")
