# with open("input3", "r") as f:
    # part 1
    # lett = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"
    # alphabets = [letter for letter in lett]
    # total_value = 0
    # while True:
        # inp = f.readline()
        # if not inp:
            # break
        # half = int(len(inp) / 2)
        # p1 = inp[:half]
        # p2 = inp[half:]
        # for x in p1:
            # if x in p2:
                # # print("Real is :" + inp)
                # # print(f"Left side is: {p1}, while Right side is: {p2}")
                # # print(x)

                # value = alphabets.index(x)

                # # print(f"Value of {x} is {value + 1}")

                # total_value += value + 1

                # # print("----------------------")
                # break

    # print(total_value)

with open("input3", "r") as f:
    # part 2
    lett = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"
    alphabets = [letter for letter in lett]
    total_value = 0
    x = 0
    groups = []
    while True:
        inp = f.readline()
        if not inp:
            break
        groups.append(inp)
        x += 1
        if x >= 3:
            rucksack = groups[0]
            for badge in rucksack:
                if badge in groups[1] and badge in groups[2]:
                    value = alphabets.index(badge)
                    total_value += value + 1
                    break
            groups = []
            x = 0

    print(total_value)
