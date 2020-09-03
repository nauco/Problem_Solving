def solution(key, lock):
    answer = False
    K, L = len(key), len(lock)
    t = key
    dx = [1, 0, -1, 0]
    dy = [0, 1, 0, -1]
    LL = L+ 2*(K-1)
    num = sum(row.count(0) for row in lock)
    l = [[-1] * LL for _ in range(LL)]
    for i in range(L):
        for j in range(L):
            l[K-1+i][K-1+j] = lock[i][j]

    def func(k):
        nonlocal answer
        for i in range(LL):
            for j in range(LL):
                cnt = 0
                if i >= L + K - 1 or j >= L + K - 1:
                    continue
                for x in range(K):
                    for y in range(K):
                        if l[i+x][j+y] == -1:
                            continue
                        if l[i+x][j+y] == k[x][y]:
                            break
                        elif l[i+x][j+y] == 0 and k[x][y] == 1:
                            cnt += 1
                if cnt == num:
                    answer = True
                    return
        return

    for i in range(4):
        t = list(zip(*t[::-1]))
        func(t)
        if answer:
            return answer

    return answer
