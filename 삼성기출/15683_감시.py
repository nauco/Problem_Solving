import copy
N, M = list(map(int, input().split()))
arr = [list(map(int, input().split())) for _ in range(N)]

dx = [-1, 0, 1, 0]
dy = [0, 1, 0, -1]

cctv = []
minBlindSpot = N*M

for i in range(N):
    for j in range(M):
        if arr[i][j] == 0 or arr[i][j] == 6:
            continue
        cctv.append((i, j, arr[i][j]))

def monitor(x, y, dir, l):
    nx = x + dx[dir]
    ny = y + dy[dir]
    while(nx>=0 and nx<N and ny>=0 and ny<M):
        if l[nx][ny] == 0:
            l[nx][ny] = -1
        elif l[nx][ny] == 6:
            break
        else:
            nx += dx[dir]
            ny += dy[dir]
    return l

def func(depth, l):
    global minBlindSpot
    if depth == len(cctv):
        minBlindSpot = min(minBlindSpot,  sum(row.count(0) for row in l))
    else:
        x, y, z = cctv[depth]

        if z == 1:
            for i in range(4):
                func(depth+1, monitor(x, y, i, copy.deepcopy(l)))
        elif z == 2:
            func(depth+1, monitor(x, y, 2, monitor(x, y, 0, copy.deepcopy(l))))
            func(depth+1, monitor(x, y, 3, monitor(x, y, 1, copy.deepcopy(l))))
        elif z == 3:
            func(depth+1, monitor(x, y, 0, monitor(x, y, 1, copy.deepcopy(l))))
            func(depth+1, monitor(x, y, 1, monitor(x, y, 2, copy.deepcopy(l))))
            func(depth+1, monitor(x, y, 2, monitor(x, y, 3, copy.deepcopy(l))))
            func(depth+1, monitor(x, y, 3, monitor(x, y, 0, copy.deepcopy(l))))
        elif z == 4:
            func(depth+1, monitor(x, y, 0, monitor(x, y, 1, monitor(x, y, 2, copy.deepcopy(l)))))
            func(depth+1, monitor(x, y, 1, monitor(x, y, 2, monitor(x, y, 3, copy.deepcopy(l)))))
            func(depth+1, monitor(x, y, 2, monitor(x, y, 3, monitor(x, y, 0, copy.deepcopy(l)))))
            func(depth+1, monitor(x, y, 3, monitor(x, y, 0, monitor(x, y, 1, copy.deepcopy(l)))))
        elif z == 5:
            func(depth+1, monitor(x, y, 0, monitor(x, y, 1, monitor(x, y, 2, monitor(x, y, 3, copy.deepcopy(l))))))

    return

func(0, arr)
print(minBlindSpot)
        
