N, M = list(map(int, input().split()))
arr = [list(map(int, input().split())) for _ in range(N)]

house = []
chicken = []
minDist = 100 * 100
for i, row in enumerate(arr):
    for j, val in enumerate(row):
        if val == 1:
            house.append((i, j))
        elif val == 2:
            chicken.append((i, j))

pick = []
def func(c, m):
    global minDist, pick
    if m == M:
        chickenDist = 0
        for hx, hy in house:
            tmp = 100*100
            for x, y in pick:
                tmp = min(tmp, abs(hx-x)+abs(hy-y)) 
            chickenDist += tmp
            
        minDist = min(minDist, chickenDist)
    elif c == len(chicken):
        return
    else:
        pick.append(chicken[c])
        func(c+1, m+1)
        pick.remove(chicken[c])
        func(c+1, m)
            
    return

func(0, 0)

print(minDist)


