tc = int(input())

c = ['w', 'r', 'y', 'o', 'b', 'g']
trans = {'B':3, 'U':0, 'F':1, 'D':2, 'L':5, 'R':4}

def turn(face, dir):
    idx = trans[face]

    for i in range(dir):
        tmp = color[idx*9]
        color[idx*9] = color[idx*9+6]
        color[idx*9+6] = color[idx*9+8]
        color[idx*9+8] = color[idx*9+2]
        color[idx*9+2] = tmp

        tmp = color[idx*9+1]
        color[idx*9+1] = color[idx*9+3]
        color[idx*9+3] = color[idx*9+7]
        color[idx*9+7] = color[idx*9+5]
        color[idx*9+5] = tmp
        # t = list(zip(*[color[idx*9:idx*9+3], color[idx*9+3:idx*9+6], color[idx*9+6:idx*9+9]][::-1]))
        # for j, k in enumerate(t):
        #     a = idx*9 + j*3
        #     color[a:a+3] = k

        q = []
        for j in side[idx]:
            q.append(color[j])

        side[idx] = side[idx][3:] + side[idx][:3]

        for j in side[idx]:
            color[j] = q.pop(0)
    return

for i in range(tc):
    n = int(input())
    arr = list(map(str, input().split()))

    side = [[33, 34, 35, 36, 39, 42, 11, 10, 9, 53, 50, 47],
        [6, 7, 8, 42, 43, 44, 20, 19, 18, 51, 52, 53],
        [15, 16, 17, 44, 41, 38, 29, 28, 27, 45, 48, 51],
        [24, 25, 26, 38, 37, 36, 2, 1, 0, 47, 46, 45],
        [8, 5, 2, 35, 32, 29, 26, 23, 20, 17, 14, 11],
        [0, 3, 6, 9, 12, 15, 18, 21, 24, 27, 30, 33]]

    color = [''] * 54

    for i in range(6):
        for j in range(9):
            color[i*9 + j] = c[i]

    for j in arr:
        if j[1] == '+':
            turn(j[0], 1)
        else:
            turn(j[0], 3)
    
    print(*color[0:3], sep='')
    print(*color[3:6], sep='')
    print(*color[6:9], sep='')

