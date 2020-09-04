def solution(n, build_frame):
    answer = []
    #0없음 1기둥 2보 3기둥+보
    arr = [[0]*(n+1) for _ in range(n+1)]
    def ok(x, y):
        for i, row in enumerate(arr):
            for j, value in enumerate(row):
                if value == 0:
                    continue
                if value & 2 == 2: #보
                    #한쪽 끝 부분이 기둥 위에 있거나, 양쪽 끝이 다른 보와 동시에 연결
                    if (arr[i-1][j] & 1 == 1) or (arr[i-1][j+1] & 1 == 1):
                        continue
                    elif (0<j<n and (arr[i][j-1] & 2 == 2) and (arr[i][j+1] & 2 == 2)):
                        continue
                    else:
                        return False
                if value & 1 == 1: #기둥
                    #기둥은 바닥 위에 있거나, 보의 한쪽 끝 부분 위에 있거나, 기둥 위에
                    if i == 0:
                        continue
                    elif j == 0 and (arr[i][j] & 2 == 2):
                        continue
                    elif j > 0 and ((arr[i][j-1]&2 == 2) or (value & 2 == 2)) :
                        continue
                    elif i > 0 and arr[i-1][j] & 1 == 1:
                        continue
                    else:
                        return False
                    
        return True
    
    for i in build_frame:
        x, y, a, b = i
        #a0 기둥 a1 보
        if b == 0: #삭제
            arr[y][x] -= (a+1)
        else: #설치
            arr[y][x] += (a+1)
        
        if not ok(x, y):
            if b == 0:
                arr[y][x] += (a+1)
            else:
                arr[y][x] -= (a+1)
        else:
            if b == 0:
                answer.remove([x, y, a])
            else:
                answer.append([x, y, a])

             
    answer = sorted(answer , key=lambda k: [k[0], k[1], k[2]])
    return answer
