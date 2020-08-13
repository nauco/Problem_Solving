N = int(input())
arr = [0] * N

for i in range(N):
    arr[i] = list(map(int, input().split()))

answer = 0

def func(depth, p):
    global answer
    if depth > N:
        return
    if depth == N:
        answer = max(answer, p)
    else:
        nt, np = arr[depth]
        func(depth+nt, p+np)
        func(depth+1, p)

    return

func(0, 0)

print(answer)
