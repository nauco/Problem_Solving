def solution(n, computers):
    visit = [0] * n
    
    q = []
    for i in range(n):
        if visit[i] != 0:
            continue
        q.append(i)
        while q:
            x = q.pop(0)
            visit[x] = i+1
            for j in range(n):
                if computers[x][j] == 1 and visit[j] == 0:
                    q.append(j)
                         
    return len(set(visit))
