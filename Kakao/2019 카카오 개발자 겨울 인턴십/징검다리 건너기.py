import heapq
def solution(stones, k):
    maxheap = []

    for i in range(k):
        heapq.heappush(maxheap, (-stones[i], i))
        
    answer = -maxheap[0][0]
    
    for i, v in enumerate(stones):
        if i < k:
            continue
        heapq.heappush(maxheap, (-v, i))

        while maxheap[0][1] <= i-k:
            heapq.heappop(maxheap)

        answer = min(answer, -maxheap[0][0])
         
    return answer
