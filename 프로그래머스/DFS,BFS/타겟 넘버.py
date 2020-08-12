def solution(numbers, target):  
    answer = 0
    def func(n, res):
        nonlocal answer
        if n == len(numbers):
            if res == target:
                answer += 1
        else:
            func(n+1, res+numbers[n])
            func(n+1, res-numbers[n])
        return

    func(0, 0)        
    return answer
