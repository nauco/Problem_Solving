from itertools import permutations
def isprime(n):
    if(n <= 1):
        return False
    if(n<=3):
        return True
    
    if(n%2 == 0 or n%3 == 0):
        return False    
        
    i = 5
    while(i*i <=n):
        if(n%i == 0 or n%(i+2) == 0):
            return False
        i = i + 6
    return True

def solution(numbers):
    pset = set()
    for j in range(len(numbers)):
        for i in set(permutations(numbers, j+1)):
            num = int(''.join(map(str,i)))
            if(isprime(num)):
                pset.add(num)
    return len(pset)
