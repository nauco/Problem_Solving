import re
import collections
def solution(s):
    answer = []
    
    m = re.findall('\d+', s)
    c = collections.Counter(m)
    for k, v in c.most_common():
        answer.append(int(k))
        
    return answer
