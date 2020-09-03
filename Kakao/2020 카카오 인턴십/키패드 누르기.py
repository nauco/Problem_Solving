def solution(numbers, hand):
    answer = ''
    hand = 'R' if hand == 'right' else 'L'
    trans = [(3, 1), (0, 0), (0, 1), (0, 2), (1, 0), (1, 1), (1, 2), (2, 0), (2, 1), (2, 2), (3, 0), (3, 2)]
    L = 10
    R = 11
    def dist(l, r, target):
        lx, ly = trans[l]
        rx, ry = trans[r]
        tx, ty = trans[target]
        
        ll = abs(lx-tx) + abs(ly-ty)
        rr = abs(rx-tx) + abs(ry-ty)
        
        if ll == rr:
            return hand
        elif ll > rr:
            return 'R'
        else:
            return 'L'
            
        return

    for i in numbers:
        if i == 1 or i == 4 or i == 7:
            answer += 'L'
            L = i
        elif i == 3 or i == 6 or i == 9:
            answer += 'R'
            R = i
        elif i == 2 or i == 5 or i == 8 or i == 0:
            answer += dist(L, R, i)
            if answer[-1] == 'R':
                R = i
            else:
                L = i
            
    return answer
