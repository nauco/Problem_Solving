import copy
def solution(tickets):
    answer = []
    visit = [0] * len(tickets)
    tickets.sort(key = lambda x:(x[0], x[1]))
    
    def dfs(start, root):
        #print(start, root, visit)
        if(len(root) == len(tickets)):
            root.append(start)
            answer.append(root[:])
            return
        else:
            for i, j in enumerate(tickets):
                if j[0] == start and visit[i] == 0:
                    root.append(j[0])
                    visit[i] = 1
                    dfs(j[1], root)
                    root.pop()
                    visit[i] = 0
                    
                    
    for i, j in enumerate(tickets):
        if j[0] == "ICN":
            visit[i] = 1
            dfs(j[1], ["ICN"])
            if answer and len(answer[0]) == len(tickets)+1:
                return answer[0]
            else:
                visit[i] = 0
