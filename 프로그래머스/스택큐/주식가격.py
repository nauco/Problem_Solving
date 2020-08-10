def solution(prices):
    answer = [0] * len(prices)
    stack = []
    
    for time, price in enumerate(prices):
        while stack and stack[-1][1] > price:
            t, p = stack.pop()
            answer[t] = time - t
        stack.append((time, price))
        
    while stack:
        t, p = stack.pop()
        answer[t] = len(prices) - 1 - t
    
    return answer
