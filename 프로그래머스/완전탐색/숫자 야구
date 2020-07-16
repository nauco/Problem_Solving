from itertools import permutations
  
def solution(baseball):
    answer = 0
    for j in baseball:
        j[0] = [int(k) for k in str(j[0])]    
    for i in permutations(list(range(1,10)), 3):
        for j in baseball:
            s, b = j[1], j[2]
            ss, bb = 0, 0
            for x in range(3):
                for y in range(3):
                    if  (x == y and i[x] == j[0][y]):
                        ss += 1
                    elif (x != y and i[x] == j[0][y]):
                        bb += 1
            if s != ss or b != bb:
                break
            if j == baseball[-1]:
                answer += 1
                        
    return answer
