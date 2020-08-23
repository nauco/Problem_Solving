from collections import deque

gears = [deque(list(map(int, input()))) for _ in range(4)]

def func(n, d, propagation):
    if propagation <= 0:            
        if n != 0:
            if gears[n][6] != gears[n-1][2]:
                func(n-1, -1*d, propagation-1)

    if propagation >= 0:
        if n != 3:
            if gears[n][2] != gears[n+1][6]:
                func(n+1, -1*d, propagation+1) 

    if d == 1:
        gears[n].rotate(1)
    else:
        gears[n].rotate(7)
    return

K = int(input())

for i in range(K):
    number, dir = list(map(int, input().split()))
    func(number-1, dir, 0)

print(gears[0][0] + gears[1][0]*2 + gears[2][0]*4 + gears[3][0]*8)
