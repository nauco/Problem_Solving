#더 좋은 풀이가 있음, 다시풀기
def solution(citations):
    answer = len(citations)
    citations.sort()
    for i in reversed(range(len(citations))):
        if(len(citations)-i == citations[i]):
            return citations[i]
        elif(len(citations)-i > citations[i]):
            for j in reversed(range(0,len(citations)+1)):
                if(len(citations)-i-1 == j):
                    return j
    return answer
