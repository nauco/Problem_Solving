def solution(answers):
    answer = []
    pick = [[1, 2, 3, 4, 5],
            [2, 1, 2, 3, 2, 4, 2, 5],
            [3, 3, 1, 1, 2, 2, 4, 4, 5, 5]]
    
    correct = [0, 0, 0]
    for i in range(len(answers)):
        for j in range(3):
            if(answers[i] == pick[j][i%len(pick[j])]):
                correct[j] += 1
    
    for i in range(len(correct)):
        if(correct[i] == max(correct)):
            answer.append(i+1)
    return answer
