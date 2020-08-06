def solution(n, results):
    answer = n
    d = [[111]*(n+1) for i in range(n+1)]
    
    for i in results:
        d[i[0]][i[1]] = 1
    
    v = list(range(1, n+1))
    for k in v:
        for i in v:
            for j in v:
                if d[i][j] > d[i][k] + d[k][j]:
                    d[i][j] = d[i][k] + d[k][j]
    
    for i in v:
        for j in v:
            if i == j:
                continue
            if d[i][j] == 111 and d[j][i] == 111:
                answer -= 1
                break

    return answer
