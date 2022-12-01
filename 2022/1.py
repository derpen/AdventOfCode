with open("input", "r") as f:
    # part 1
    score_now = 0
    highest_all_time = 0
    big_calories = []
    test = []
    while True:
        calories = f.readline()
        if not calories:
            break
        if calories not in "\n":
            score_now += int(calories)
        else:
            if score_now > highest_all_time:
                highest_all_time = score_now
            big_calories.append(score_now)
            score_now = 0

    # print(highest_all_time)

    # part 2
    big_calories.sort()
    ordered = big_calories[-3:]
    total = 0
    for i in range(0,len(ordered)):
        total += ordered[i]
    print(total)
