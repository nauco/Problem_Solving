import math
def solution(progresses, speeds):
    answer = []
    stack = []
    for i, j in zip(progresses, speeds):
        k = math.ceil((100-i) / j)
        if stack and stack[0] < k:
            answer.append(len(stack))
            stack.clear()
        stack.append(k)
    answer.append(len(stack))
        
    return answer
