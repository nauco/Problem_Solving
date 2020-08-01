def solution(n, lost, reserve):
    answer = 0
    
    lost2 = list(set(lost)-set(reserve))
    reserve2 = list(set(reserve)-set(lost))
        
    for i in lost2:
        if i-1 in reserve2:
            reserve2.remove(i-1)
        elif i+1 in reserve2:
            reserve2.remove(i+1)
        else:
            answer += 1
    
    return n - answer
