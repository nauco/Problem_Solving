def match(a, b):
    diff = 0
    for i, j in zip(a, b):
        if(i != j):
            diff += 1
    return True if diff == 1 else False
         
def solution(begin, target, words):
    answer = []
    if not target in words:
        return 0
        
    visit = [0] * len(words)
    
    def dfs(word, depth):
        if word == target:
            answer.append(depth)
            return
        else:
            for idx, w in enumerate(words):
                if visit[idx] != 0:
                    continue
                    
                if(match(w, word)):
                    visit[idx] = 1
                    dfs(w, depth+1)
                    visit[idx] = 0
    
    dfs(begin, 0)
    return min(answer)
