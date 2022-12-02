with open("input2", "r") as f:
    # part 1
    total_score = 0
    while True:
        strat = f.readline()
        separated = strat.split()
        if not strat:
            break
        if separated[1] == "X":
            total_score += 1
            if separated[0] == "A":
                total_score += 3
            if separated[0] == "C":
                total_score += 6

        elif separated[1] == "Y":
            total_score += 2
            if separated[0] == "B":
                total_score += 3
            if separated[0] == "A":
                total_score += 6
        else:
            total_score += 3
            if separated[0] == "C":
                total_score += 3
            if separated[0] == "B":
                total_score += 6

    print(f"Total score for this strat is : {total_score}")

with open("input2", "r") as f:
    total_score = 0
    while True:
        strat = f.readline()
        separated = strat.split()
        if not strat:
            break
        if separated[1] == "X":
            if separated[0] == "A":
                total_score += 3
            elif separated[0] == "B":
                total_score += 1
            else:
                total_score += 2
        elif separated[1] == "Y":
            total_score += 3
            if separated[0] == "A":
                total_score += 1
            elif separated[0] == "B":
                total_score += 2
            else:
                total_score += 3
        else:
            total_score += 6
            if separated[0] == "A":
                total_score += 2
            elif separated[0] == "B":
                total_score += 3
            else:
                total_score += 1


    print(f"Total score for second strat is : {total_score}")
    # part 2
