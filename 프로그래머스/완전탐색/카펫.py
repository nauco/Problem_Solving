def solution(brown, yellow):
    for i in range(1, brown//2):
        for j in range(1, i+1):
            if(i*j == brown+yellow and (i-2)*(j-2) == yellow):
                return [i,j]
