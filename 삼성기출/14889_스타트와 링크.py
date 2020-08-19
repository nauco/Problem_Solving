N = int(input())

arr = [list(map(int, input().split())) for _ in range(N)]
result = 20*19*100

def stat(team):
    answer = 0
    for i, num in enumerate(team):
        for j in range(i+1, len(team)):
            x, y = num, team[j]
            answer += arr[x][y] + arr[y][x]
    return answer

def func(n, a, b):
    global result
    if n == N:
        result = min(abs(stat(a)-stat(b)), result)
    else:
        if len(a) < N/2:
            a.append(n)
            func(n+1, a, b)
            a.remove(n)
        if len(b) < N/2:
            b.append(n)
            func(n+1, a, b)
            b.remove(n)
    return

func(0, [], [])
print(result)
