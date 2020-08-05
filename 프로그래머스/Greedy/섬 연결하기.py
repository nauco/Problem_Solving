def solution(n, costs):
    answer = 0
    costs.sort()
    roots = [costs[0][0]]
    
    while len(roots) != n:
        mincost = -1
        minidx = 0
        for i in costs:
            x, y, z = i
            if x in roots and y in roots:
                continue
            if x in roots or y in roots:
                if  mincost == -1 or mincost > z:
                    mincost = z
                    minidx = costs.index(i)
        answer += mincost
        roots.append(costs[minidx][0])
        roots.append(costs[minidx][1])
        roots = list(set(roots))
        costs.pop(minidx)

    return answer
