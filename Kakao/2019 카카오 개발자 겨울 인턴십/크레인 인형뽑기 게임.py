def solution(board, moves):
    answer = 0
    st = []
    for i in moves:
        for j in board:
            if j[i-1] == 0:
                continue
            else:
                if st and st[-1] == j[i-1]:
                    st.pop()
                    answer += 2
                else:
                    st.append(j[i-1])
                j[i-1] = 0
                break
            
    return answer
