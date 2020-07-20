def solution(budgets, M):
    answer = 0
    if(sum(budgets) <= M):
        return max(budgets)
    
    left = M // len(budgets)
    right = max(budgets)
    while(left < right):
        answer = (left + right) // 2
        use = 0
        for i in budgets:
            use += min(i, answer)
        
        if(use > M):
            right = answer
        elif(use < M):
            left = answer
            if(left +1 == right):
                return answer
        else:
            return answer
