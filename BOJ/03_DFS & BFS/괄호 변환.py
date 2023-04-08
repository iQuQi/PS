# ( 와 )로만 이루어진 문자열이 주어진다
# 균형잡힌 괄호 문자열이란 ( 와 )의 수가 동일한 문자열이다
# 올바른 괄호 문자열이란 균형잡힌 문자열 이면서 짝이 맞는 문자열이다
# 균형잡힌 괄호 문자열이 주어질때 다음 과정을 따라 올바른 괄호 문자열로 변환하자
'''
1. 입력이 빈 문자열인 경우, 빈 문자열을 반환합니다. 
2. 문자열 w를 두 "균형잡힌 괄호 문자열" u, v로 분리합니다. 단, u는 "균형잡힌 괄호 문자열"로 더 이상 분리할 수 없어야 하며, v는 빈 문자열이 될 수 있습니다. 
3. 문자열 u가 "올바른 괄호 문자열" 이라면 문자열 v에 대해 1단계부터 다시 수행합니다. 
  3-1. 수행한 결과 문자열을 u에 이어 붙인 후 반환합니다. 
4. 문자열 u가 "올바른 괄호 문자열"이 아니라면 아래 과정을 수행합니다. 
  4-1. 빈 문자열에 첫 번째 문자로 '('를 붙입니다. 
  4-2. 문자열 v에 대해 1단계부터 재귀적으로 수행한 결과 문자열을 이어 붙입니다. 
  4-3. ')'를 다시 붙입니다. 
  4-4. u의 첫 번째와 마지막 문자를 제거하고, 나머지 문자열의 괄호 방향을 뒤집어서 뒤에 붙입니다. 
  4-5. 생성된 문자열을 반환합니다.
'''

# ===========================
# "균형잡힌 괄호 문자열"의 인덱스 반환
def balanced_index(p):
    count = 0 # 왼쪽 괄호의 개수
    for i in range(len(p)):
        if p[i] == '(':
            count += 1
        else:
            count -= 1
        if count == 0:
            return i

# "올바른 괄호 문자열"인지 판단
def check_proper(p):
    count = 0 # 왼쪽 괄호의 개수
    for i in p:
        if i == '(':
            count += 1
        else:
            if count == 0: # 쌍이 맞지 않는 경우에 False 반환
                return False
            count -= 1
    return True # 쌍이 맞는 경우에 True 반환

def solution(p):
    answer = ''
    if p == '':
        return answer
    index = balanced_index(p)
    u = p[:index + 1]
    v = p[index + 1:]
    # "올바른 괄호 문자열"이면, v에 대해 함수를 수행한 결과를 붙여 반환
    if check_proper(u):
        answer = u + solution(v)
    # "올바른 괄호 문자열"이 아니라면 아래의 과정을 수행
    else:
        answer = '('
        answer += solution(v)
        answer += ')'
        u = list(u[1:-1]) # 첫 번째와 마지막 문자를 제거
        for i in range(len(u)):
            if u[i] == '(':
                u[i] = ')'
            else:
                u[i] = '('
        answer += "".join(u)
    return answer




'''내 코드

def isCorrect(p):
    # 올바른 문자열인지 테스트
    s = []
    for i in range(len(p)):
        if p[i] == '(': s.append('(')
        elif p[i] == ')': 
            pair = s.pop() if len(s) != 0 else False
            if pair == ')' or not pair: return False
            
    return len(s) == 0

def reverseP(p):
    # 괄호 뒤집기
    ret = ''
    for i in range(len(p)):
        if p[i] == '(': ret+=')'
        elif p[i] == ')': ret+='('
    return ret

def seperateP(p):
    # 문자열 w를 두 "균형잡힌 괄호 문자열" u, v로 분리. 
    left = 0
    right = 0
    u = ''
    v = ''
    for i in range(len(p)):
        if not (left == 0 and right == 0) and left == right: 
            v += p[i]
        else:
            u += p[i]
            if p[i] == '(': left += 1
            else: right += 1
            
    return (u, v)


def solution(p):
    answer = ''
    # 입력이 빈 문자열인 경우, 빈 문자열을 반환, 
    # 이미 올바른 문자열이면 그대로 반환
    if p == '' or isCorrect(p): return p
    
    v = p
    
    while True:
        u, v = seperateP(v)

        # u가 "올바른 괄호 문자열" -> v에 대해 1단계부터 다시 수행 & 수행한 결과 문자열을 u에 이어 붙인 후 반환
        if isCorrect(u): answer += u
        # u가 "올바른 괄호 문자열" x -> 아래 과정을 수행
        # solution(v) -> v 라고 해서 틀림 (문제 이해 못함...ㅠ)
        else: 
            answer += '(' + solution(v) +  ')' + reverseP(u[1:-1])
            break
        
    return answer




'''