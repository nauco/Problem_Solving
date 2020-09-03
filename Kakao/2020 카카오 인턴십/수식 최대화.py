import re
import copy
#using eval function
def solution(expression):
    answer = 0
    op = [[0, 1, 2], [0, 2, 1], [1, 2, 0], [2, 1, 0], [1, 0, 2], [2, 0, 1]]
    m = re.findall('\d+|[-*+]', expression)
    #m = re.findall('\d+', expression)
    for i in op:
        mm = copy.deepcopy(m)
        for j in i:
            cmd = ''
            if j == 0: #*
                cmd = '*'
            elif j == 1: #+
                cmd = '+'
            elif j == 2: #-
                cmd = '-' 

            while mm.count(cmd) != 0:

                for idx, v in enumerate(mm):
                    if v == cmd:
                        if j == 0: #*
                            mm = mm[:idx-1] + [int(mm[idx-1]) * int(mm[idx+1])] + mm[idx+2:]
                        elif j == 1: #+
                            mm = mm[:idx-1] + [int(mm[idx-1]) + int(mm[idx+1])] + mm[idx+2:]
                        elif j == 2: #-
                            mm = mm[:idx-1] + [int(mm[idx-1]) - int(mm[idx+1])] + mm[idx+2:]
                        break
                            
        answer = max(answer, abs(mm[0]))
    

    
    return answer
