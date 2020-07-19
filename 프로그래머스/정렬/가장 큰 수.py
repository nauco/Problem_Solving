from functools import cmp_to_key
def solution(numbers):
    answer = ''
    for i in sorted(numbers, key=cmp_to_key(lambda x, y: int(str(y)+str(x)) - int(str(x)+str(y)))):
        answer += str(i)
    return str(int(answer))
