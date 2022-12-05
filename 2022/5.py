a = ["N", "C", "R", "T", "M", "Z", "P"]
b = ["D", "N", "T", "S", "B", "Z"]
c = ["M", "H", "Q", "R", "F", "C", "T", "G"]
d = ["G", "R", "Z"]
e = ["Z", "N", "R", "H"]
f = ["F", "H", "S", "W", "P", "Z", "L", "D"]
g = ["W", "D", "Z", "R", "C", "G", "M"]
h = ["S", "J", "F", "L", "H", "W", "Z", "Q"]
i = ["S", "Q", "P", "W", "N"]
to_nums = {
    1 : a,
    2 : b,
    3 : c,
    4 : d,
    5 : e,
    6 : f,
    7 : g,
    8 : h,
    9 : i
}
#         [G]         [D]     [Q]    
# [P]     [T]         [L] [M] [Z]    
# [Z] [Z] [C]         [Z] [G] [W]    
# [M] [B] [F]         [P] [C] [H] [N]
# [T] [S] [R]     [H] [W] [R] [L] [W]
# [R] [T] [Q] [Z] [R] [S] [Z] [F] [P]
# [C] [N] [H] [R] [N] [H] [D] [J] [Q]
# [N] [D] [M] [G] [Z] [F] [W] [S] [S]
#  1   2   3   4   5   6   7   8   9
with open("input5", "r") as file:
    # part 1
    while True:
        line = file.readline()
        if not line:
            break
        crate = line.split()
        before = to_nums[int(crate[3])]
        after = to_nums[int(crate[5])]
        for x in range(0, int(crate[1])):
            elements = before.pop()
            after.append(elements)

    print(a[-1], b[-1], c[-1], d[-1], e[-1], f[-1], g[-1], h[-1], i[-1])


a = ["N", "C", "R", "T", "M", "Z", "P"]
b = ["D", "N", "T", "S", "B", "Z"]
c = ["M", "H", "Q", "R", "F", "C", "T", "G"]
d = ["G", "R", "Z"]
e = ["Z", "N", "R", "H"]
f = ["F", "H", "S", "W", "P", "Z", "L", "D"]
g = ["W", "D", "Z", "R", "C", "G", "M"]
h = ["S", "J", "F", "L", "H", "W", "Z", "Q"]
i = ["S", "Q", "P", "W", "N"]
to_nums = {
    1 : a,
    2 : b,
    3 : c,
    4 : d,
    5 : e,
    6 : f,
    7 : g,
    8 : h,
    9 : i
}

with open("input5", "r") as file:
    # part 2
    while True:
        line = file.readline()
        if not line:
            break
        crate = line.split()
        before = to_nums[int(crate[3])]
        after = to_nums[int(crate[5])]
        ori_len = len(after)
        for x in range(0, int(crate[1])):
            elements = before.pop()
            after.insert(ori_len, elements)

    print(a[-1], b[-1], c[-1], d[-1], e[-1], f[-1], g[-1], h[-1], i[-1])