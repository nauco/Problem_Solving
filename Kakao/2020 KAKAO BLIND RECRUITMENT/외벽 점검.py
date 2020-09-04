from itertools import permutations as per
def solution(n, weak, dist):
    W = len(weak)
    for i in range(len(weak)-1):
        weak.append(weak[i]+n)
    dist = sorted(dist, reverse=True)
    print(dist)
    def func(friends, weaks):
        cover, fidx = friends[0]+weaks[0], 0
        for i, weakpoint in enumerate(weaks):
            if cover >= weakpoint:
                pass
            else:
                fidx += 1
                if fidx == len(friends):
                    return False
                cover = weakpoint + friends[fidx]            
        return True
    
    for i in range(len(dist)):
        for friends in per(dist, i+1):
            print(friends)
            for k in range(W):
                w = weak[k:k+W]
                if func(friends, w):
                    return len(friends)
            
    return -1
