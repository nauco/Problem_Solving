def solution(citations):
    answer = 0
    citations.sort()
    for idx, h in enumerate(reversed(citations)):
        if idx < h:
            answer += 1
        else:
            break
        
    return answer
