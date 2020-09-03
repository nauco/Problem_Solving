def solution(p):
    answer = ''
    def iscorrect(w):
        n = 0
        for i in w:
            if i == '(':
                n -= 1
            elif i == ')':
                n += 1
            if n > 0:
                return False    
        return True
    
    def func(w):
        if w == '':
            return w
        for i in range(len(w)):
            u, v = w[:i+1], w[i+1:]
            if u.count('(') == u.count(')'):
                if iscorrect(u):
                    return u+func(v)
                else:
                    s = '('+func(v)+')'
                    for j in u[1:-1]:
                        if j == '(':
                            s += ')'
                        else:
                            s += '('
                    return s    

        return
    
    
    
    return func(p)
