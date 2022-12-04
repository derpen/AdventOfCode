with open("input4", "r") as f:
    # Part 1
    Total = 0
    while True:
        something = f.readline().replace('\n','')
        if not something:
            break
        something = something.split(",")
        p1 = [int(x) for x in something[0].split("-")]
        p2 = [int(x) for x in something[1].split("-")]
        if p1[0] <= p2[0] and p1[1] >= p2[1]:
            Total +=1
        elif p2[0] <= p1[0] and p2[1] >= p1[1]:
            Total += 1
    
    print(f"Overlapped on part 1 are :{Total}")

with open("input4", "r") as f:
    # Part 2
    Total = 0
    while True:
        something = f.readline().replace('\n','')
        if not something:
            break
        something = something.split(",")
        p1 = [int(x) for x in something[0].split("-")]
        p2 = [int(x) for x in something[1].split("-")]
        if p1[1] < p2[0]:
            Total +=1
        elif p2[1] < p1[0]:
            Total += 1
    
    # Accidently wrote code for non-overlapping xd
    Total = 1000 - Total
    
    print(f"Overlapped on part 2 are :{Total}")