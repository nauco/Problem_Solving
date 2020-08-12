n = int(input())
board = [[0]*(n+1) for _ in range(n+1)]

k = int(input())
for i in range(k):
    x, y = map(int, input().split())
    board[x][y] = 1

dx = [0, -1, 0, 1]
dy = [1, 0, -1, 0]
q = []
q.append((1, 1))

end = False
now, d = 0, 0
x, y = 1, 1
def move(t, c):
    global now, d, x, y, end
    if now == t:
        if c == 'L':
            d = (d+1) % 4
        elif c == 'D':
            d = (d+3) % 4
    
    while now <= t:
        nx = x + dx[d]
        ny = y + dy[d]

        if nx>= 1 and nx <=n and ny >=1 and ny <= n:
            if (nx, ny) in q:
                now += 1
                end = True
                break
            
            if board[nx][ny] == 1:
                board[nx][ny] = 0
            else:
                q.pop(0)
            q.append((nx, ny))
            x = nx
            y = ny

            if now + 1 == t:
                if c == 'L':
                    d = (d+1) % 4
                elif c == 'D':
                    d = (d+3) % 4
            now += 1
        else:
            now += 1
            end = True
            break
    return            

l = int(input())
for i in range(l):
    time, char = input().split()
    move(int(time), char)
    if end:
        print(now)
        break

if not end:
    move(now+n, 'N')
    print(now)
