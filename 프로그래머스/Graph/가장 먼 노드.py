from queue import PriorityQueue
def solution(n, edge):
    graph = [[] for i in range(n+1)]
    dist = [n+1] * (n+1)
    
    for i, j in edge:
        graph[i].append(j)
        graph[j].append(i)
    #print(graph)

    q = PriorityQueue()
    q.put((0, 1))
    dist[1] = 0; 

    while q.queue:
        d, v = q.get()
        for i in graph[v]:
            if dist[i] > dist[v] + 1 or dist[i] == n+1:
                dist[i] = dist[v]+1
                q.put((dist[i], i))
                
    del dist[0]
    dist.sort(reverse=True)
    #print(dist)

    return dist.count(dist[0])
