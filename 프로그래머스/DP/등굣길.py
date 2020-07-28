def solution(m, n, puddles):
    answer = [[0] * (n+1) for _ in range(m+1)]
    
    answer[1][1] = 1
        
    for x in range(1, m+1):
        for y in range(1, n+1):
            if x == 1 and y == 1:
                continue
            if [x, y] in puddles:
                answer[x][y] = 0
            else:                  
                answer[x][y] = (answer[x-1][y] + answer[x][y-1]) %1000000007

    print(answer)
    return answer[m][n]
