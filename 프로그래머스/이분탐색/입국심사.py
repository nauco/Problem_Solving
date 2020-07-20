def solution(n, times):
    answer = 0
    times.sort()
    left = min(times)
    right = n * left

    while(left <= right):
        mid = (left + right) // 2
        t = 0
        for i in times:
            t += (mid // i)
        if(t >= n):
            answer = mid
            right = mid-1
        elif(t < n):
            left = mid+1
    return answer
