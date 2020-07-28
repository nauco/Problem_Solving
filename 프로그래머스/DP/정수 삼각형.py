def solution(triangle):    

    for i in reversed(range(len(triangle)-1)):
        for j in range(i+1):
            triangle[i][j] += max(triangle[i+1][j], triangle[i+1][j+1])      

    return triangle[0][0]
