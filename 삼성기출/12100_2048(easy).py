n = int(input())
board = [list(map(int, input().split())) for _ in range(n)]
answer = 0

def up(arr):
    bd = [[0]*n for _ in range(n)]
    q = []
    for i in range(n):
        for j in range(0, n):
            if arr[j][i] != 0:
                q.append(arr[j][i])
        idx = 0
        while q:
            block = q.pop(0)
            if q and block == q[0]:
                bd[idx][i] = block * 2
                q.pop(0)
            else:
                bd[idx][i] = block
            idx += 1
    return bd

def down(arr):
    bd = [[0]*n for _ in range(n)]
    q = []
    for i in range(n):
        for j in range(n-1, -1, -1):
            if arr[j][i] != 0:
                q.append(arr[j][i])
        idx = n-1
        while q:
            block = q.pop(0)
            if q and block == q[0]:
                bd[idx][i] = block * 2
                q.pop(0)
            else:
                bd[idx][i] = block
            idx -= 1
    return bd

def left(arr):
    bd = [[0]*n for _ in range(n)]  
    q = []
    for i in range(n):
        for j in range(0, n):
            if arr[i][j] != 0:
                q.append(arr[i][j])
        idx = 0
        while q:
            block = q.pop(0)
            if q and block == q[0]:
                bd[i][idx] = block * 2
                q.pop(0)
            else:
                bd[i][idx] = block
            idx += 1
    return bd

def right(arr):
    bd = [[0]*n for _ in range(n)]
    q = []
    for i in range(n):
        for j in range(n-1, -1, -1):
            if arr[i][j] != 0:
                q.append(arr[i][j])
        idx = n-1
        while q:
            block = q.pop(0)
            if q and block == q[0]:
                bd[i][idx] = block * 2
                q.pop(0)
            else:
                bd[i][idx] = block
            idx -= 1
    return bd

def move(depth, bd):
    global answer
    if depth == 5:
        answer = max(max(map(max, bd)), answer)
    else: 
        move(depth+1, up(bd))
        move(depth+1, down(bd))
        move(depth+1, left(bd))
        move(depth+1, right(bd))

move(0, board)
print(answer)
