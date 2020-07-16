def solution(array, commands):
    answer = []    
    for i in commands:
        sub = array[:]
        sub = sorted(sub[i[0]-1:i[1]])
        answer.append(sub[i[2]-1])
    return answer
