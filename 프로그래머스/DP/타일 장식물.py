def solution(N):
    answer = [0, 1]
    for i in range(2, N+1):
        answer.append(answer[i-2]+answer[i-1])
         
    return 4 * answer[N] + 2 * answer[N-1]
