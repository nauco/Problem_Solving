from queue import PriorityQueue as pq
def solution(board):
    dx, dy = [0, 0, 1, 0, -1], [0, 1, 0, -1, 0]
    dd = [0, 1, 2, 4, 8]
    N = len(board) - 1
    answer = 200*200
    seen = [[0] * (N+1) for _ in range(N+1)]

    def bfs():
        nonlocal answer
        q = pq()
        seen[0][0] = 1
        q.put((0, 0, 0, 1)) #length, x, y, direction
        while q.queue:
            l, x, y, d = q.get()

            if (x == N and y == N) or (x+dx[d] == N and y+dy[d] == N):
                answer = min(answer, l)
            
            for i in range(1, 5):
                nx, ny = x+dx[i], y+dy[i]
                nxx, nyy = nx+dx[d], ny+dy[d]

                if nx<0 or nx>N or ny<0 or ny>N:
                    continue
                if nxx<0 or nxx>N or nyy<0 or nyy>N:
                    continue
                if board[nx][ny] == 1 or board[nxx][nyy] == 1:
                    continue
                
                if (seen[nx][ny] & dd[d]) != dd[d]:
                    q.put((l+1, nx, ny, d))
                    seen[nx][ny] += dd[d]
                

            for i in [2, 4]:
                nd = 1+(d+i)%4
                if x+dx[nd]<0 or x+dx[nd]>N or y+dy[nd]<0 or y+dy[nd]>N:
                    continue
                if x+dx[nd]+dx[d]<0 or x+dx[nd]+dx[d]>N or y+dy[nd]+dy[d]<0 or y+dy[nd]+dy[d]>N:
                    continue
                if board[x+dx[nd]][y+dy[nd]] == 1 or board[x+dx[nd]+dx[d]][y+dy[nd]+dy[d]] == 1:
                    continue

                if (seen[x][y] & dd[nd]) != dd[nd]:
                    q.put((l+1, x, y, nd))
                    seen[x][y] += dd[nd]
                if (seen[x+dx[d]][y+dy[d]] & nd) != nd:
                    q.put((l+1, x+dx[d], y+dy[d], nd))
                    seen[x+dx[d]][y+dy[d]] += dd[nd]

        return

    bfs()
    return answer
