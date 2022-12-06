with open("input6", "r") as file:
    #part 1
    line = file.readline()
    check = {}
    x = 0
    for letter in line:
        x += 1
        if letter not in check:
            check[letter] = letter
            if len(check) == 4:
                break
        else:
            check = {}
    print(check, x)

    #part 2
    check = {}
    index = []
    x = 0
    for letter in line:
        x += 1
        if letter not in check:
            check[letter] = letter
            index.append(x)
            if len(check) == 14:
                break
        else:
            check = {}
            index = []
    print(check, index[-1]) 