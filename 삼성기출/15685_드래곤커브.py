N = int(input())
curve = [list(map(int, input().split())) for _ in range(N)]
answer = [[0]*101 for _ in range(101)]

# 0: x좌표가 증가하는 방향 (→)
# 1: y좌표가 감소하는 방향 (↑)
# 2: x좌표가 감소하는 방향 (←)
# 3: y좌표가 증가하는 방향 (↓)
dx = [1, 0, -1, 0]
dy = [0, -1, 0, 1]

def func(dragon, depth, g):
    global answer
    if depth == g:
        x, y, d = 0, 0, 0
        for i in dragon:
            x, y, d = i
            answer[x][y] = 1
        answer[x+dx[d]][y+dy[d]] = 1
        #print(dragon)
    else:
        x, y, d = dragon[-1]

        x += dx[d]
        y += dy[d]
        d = (d+1) % 4
        dragon.append([x, y, d])

        for i in range(len(dragon)-2, 0, -1):
            dd = dragon[i][2] - dragon[i-1][2]
            x = x + dx[d]
            y = y + dy[d]
            d = (d-dd+4)%4
            dragon.append([x, y, d])
            
        func(dragon, depth+1, g)
    return

for i in curve:
    x, y, d, g = i
    func([[x, y, d]], 0, g)

ans = 0
for i in range(100):
    for j in range(100):
        if answer[i][j] == 1 and answer[i+1][j] == 1 and answer[i][j+1] == 1 and answer[i+1][j+1] == 1:
            ans += 1
print(ans)
