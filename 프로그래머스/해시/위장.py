def solution(clothes):
    answer = 0
    hash_table = {}
    for c, t in clothes:
        if t in hash_table:
            hash_table[t] += 1
        else:
            hash_table[t] = 2
    
    result = 1
    for i in hash_table:
        result *= hash_table[i]
    
    return result-1
