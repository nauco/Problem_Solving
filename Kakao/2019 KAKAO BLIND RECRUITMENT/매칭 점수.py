import re
def solution(word, pages):
    answer, score, url, exlink =[], [], {}, []
    
    for idx, i in enumerate(pages):
        m = re.findall('(?<=[^a-zA-Z])' + word + '(?![a-zA-Z])', i, re.I)
        score.append(len(m))
        answer.append(len(m))
        
    for idx, i in enumerate(pages):
        m = re.findall('<meta.+?content=\"https://(.+?)\"', i, re.I)
        url[m[0]] = idx

    for i in pages:
        m = re.findall('<a href=\"https://(.+?)\">', i)
        exlink.append(m)
    
    for idx, i in enumerate(exlink):
        for j in i:
            if j in url:
                answer[url[j]] += score[idx]/len(exlink[idx])
    
    m = max(answer)
    for i, v in enumerate(answer):
        if v == m:
            return i
