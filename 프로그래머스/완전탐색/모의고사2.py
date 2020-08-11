def solution(answers):
    answer = []
    pick = [[1, 2, 3, 4, 5],
            [2, 1, 2, 3, 2, 4, 2, 5],
            [3, 3, 1, 1, 2, 2, 4, 4, 5, 5]]
    
    correct = [0, 0, 0]
       
    for i, ans in enumerate(answers):
        for j, p in enumerate(pick):
            if(ans == p[i%len(p)]):
                correct[j] += 1
    
    for i, v in enumerate(correct):
        if(v == max(correct)):
            answer.append(i+1)
    return answer
