N = int(input())
A = list(map(int, input().split()))
operator = list(map(int, input().split()))

maxResult = -1000000000
minResult = 1000000000

def calc(op, value, idx):
    global maxResult, minResult
    if idx == N:
        maxResult = max(maxResult, value)
        minResult = min(minResult, value)
    else:
        if op[0] > 0:
            op[0] -= 1
            calc(op, value+A[idx], idx+1)
            op[0] += 1
        if op[1] > 0:
            op[1] -= 1
            calc(op, value-A[idx], idx+1)
            op[1] += 1
        if op[2] > 0:
            op[2] -= 1
            calc(op, value*A[idx], idx+1)
            op[2] += 1
        if op[3] > 0:
            op[3] -= 1
            calc(op, int(value/A[idx]), idx+1)
            op[3] += 1
    return

calc(operator, A[0], 1)
print(maxResult)
print(minResult)
