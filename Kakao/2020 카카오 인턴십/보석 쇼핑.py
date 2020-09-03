def solution(gems):
    answer = []
    short = len(gems)+1
    G = len(set(gems))
    s, e = 0, 1
    kinds = {gems[0]:1}
    while s != len(gems) and e != len(gems)+1:
        if len(kinds) == G:
            if e-s < short:
                answer = [s+1, e]
                short = e-s
            if kinds[gems[s]] == 1:
                del kinds[gems[s]]
            else:
                kinds[gems[s]] -= 1
            s += 1
        else:
            if e == len(gems):
                break
            if gems[e] in kinds:
                kinds[gems[e]] += 1
            else:
                kinds[gems[e]] = 1
            e += 1

    return answer
