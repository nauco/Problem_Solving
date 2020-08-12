n = int(input())
arr = list(map(int, input().split()))
b, c = list(map(int, input().split()))
answer = 0

arr = list(map(lambda x: x-b, arr))
answer += len(arr)
for i in arr:
    if i <= 0:
        continue
    if i % c == 0:
        answer += i//c
    else:
        answer += (i//c + 1)
print(answer)
