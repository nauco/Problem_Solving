import re
import itertools as it
def solution(user_id, banned_id):
    answer = 0
    ss = []
    for i in banned_id:
        p = re.compile(i.replace('*', '.'))
        s = set()
        for j in user_id:
            m = p.fullmatch(j)
            if m:
                s.add(m.group())
        ss.append(s)
    ban = set()
    def func(n, s=None):
        nonlocal ban
        if s is None:
            s = set()
        if n == len(banned_id):
            if len(s) == n:
                ban.add(tuple(sorted(s)))
        else:
            for i in it.combinations(ss[n], 1):
                if i[0] in s:
                    func(n+1, s)
                else:
                    s.add(i[0])
                    func(n+1, s)
                    s.remove(i[0])
            
            
    func(0)
    return len(ban)
