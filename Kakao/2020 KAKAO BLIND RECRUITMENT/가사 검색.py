class Trie():
    def __init__(self):
        self.next = dict()
        self.value = 0

def solution(words, queries):
    answer = []
    m = max(words, key= lambda x:len(x))
    tree = [[] for _ in range(10001)]
    revtree = [[] for _ in range(10001)]
    for word in words:
        if not tree[len(word)]:
            tree[len(word)].append(Trie())
        
        subtree = tree[len(word)][0]
        for idx, val in enumerate(word):
            subtree.value += 1
            if val not in subtree.next:
                subtree.next[val] = Trie()
            subtree = subtree.next[val]
            if idx == len(word) -1:
                subtree.value += 1
                
    for word in words:
        if not revtree[len(word)]:
            revtree[len(word)].append(Trie())
        
        subtree = revtree[len(word)][0]
        for idx, val in enumerate(reversed(word)):
            subtree.value += 1
            if val not in subtree.next:
                subtree.next[val] = Trie()
            subtree = subtree.next[val]
            if idx == len(word) -1:
                subtree.value += 1
    
    for query in queries:
        q = len(query)
        if query[0] == '?':
            tr = revtree
            query = reversed(query)
        else:
            tr = tree
        
        if not tr[q]:
            answer.append(0)
            continue
            
        subtree = tr[q][0]
        counts = 0
        for idx, val in enumerate(query):
            if val == '?':
                answer.append(subtree.value)
                break
            elif val not in subtree.next:
                answer.append(0)
                break
            else:
                subtree = subtree.next[val]
                counts += 1
        
            
    return answer
