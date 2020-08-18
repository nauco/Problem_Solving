import copy
N, M = list(map(int, input().split()))

board = [list(map(int, input().split())) for _ in range(N)]
saftyArea = 0
dx = [-1, 0, 1, 0]
dy = [0, 1, 0, -1]

def spread(board):
    visit = [[0]*M for _ in range(N)]
    q = []
    arr = copy.deepcopy(board) 
    for i, row in enumerate(arr):
        for j, value  in enumerate(row):
            if value == 2:
                q.append((i, j))
    
    while q:
        x, y = q.pop(0)

        if visit[x][y] != 0:
            continue       

        visit[x][y] = 1
        arr[x][y] = 2

        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            if nx >= N or nx < 0 or ny >= M or ny < 0:
                continue
            if arr[nx][ny] == 0 and visit[nx][ny] == 0:
                q.append((nx, ny))
    
    return sum(row.count(0) for row in arr)

def setWall(x, y, n):
    global saftyArea, board
    if n == 3:
        saftyArea = max(saftyArea, spread(board))
    else:
        for i in range(x,N):
            for j in range(y, M):
                if board[i][j] == 0:
                    board[i][j] = 1
                    setWall(i, j, n+1)
                    board[i][j] = 0
            y = 0
    return

setWall(0, 0, 0)
print(saftyArea)
