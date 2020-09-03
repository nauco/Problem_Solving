def solution(string):
    answer = len(string)
    
    for j in range(1, (answer//2) +1): 
        unit, cnt, z, i = string[:j], 0, '', 0
        
        while i+j <= len(string):
            if string[i:i+j] == unit:
                cnt += 1
            else:
                if cnt == 1:
                    z += unit
                else:
                    z += str(cnt) + unit
                cnt = 1
                unit = string[i:i+j]
            i += j
            
        if cnt == 1:
            z += unit
        else:
            z += str(cnt) + unit
        if i+j > len(string):
            z += string[i:]
        answer = min(answer, len(z))
    
    return answer
