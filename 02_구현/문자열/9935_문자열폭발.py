'''
상근이는 문자열에 폭발 문자열을 심어 놓았다. 
폭발 문자열이 폭발하면 그 문자는 문자열에서 사라지며, 남은 문자열은 합쳐지게 된다.

폭발은 다음과 같은 과정으로 진행된다.

문자열이 폭발 문자열을 포함하고 있는 경우에, 모든 폭발 문자열이 폭발하게 된다. 
남은 문자열을 순서대로 이어 붙여 새로운 문자열을 만든다.
새로 생긴 문자열에 폭발 문자열이 포함되어 있을 수도 있다.
폭발은 폭발 문자열이 문자열에 없을 때까지 계속된다.
상근이는 모든 폭발이 끝난 후에 어떤 문자열이 남는지 구해보려고 한다. 
남아있는 문자가 없는 경우가 있다. 이때는 "FRULA"를 출력한다.

폭발 문자열은 같은 문자를 두 개 이상 포함하지 않는다.

[풀이] ** 못품
1.  stack 구조를 이용해 폭발 문자열을 발견했을 때, 폭발 문자열의 길이만큼 pop() 
2.  제일 안쪽에 있는 for 문의 경우 폭발 문자열의 길이가 1~36으로 작아서 상수 시간 안에 처리가능
'''

import sys

# 입력값 처리
S = sys.stdin.readline().rstrip()
explosion_string = sys.stdin.readline().rstrip()

# stack으로 문자열 폭발 구현
stack = []
ex_len = len(explosion_string)

for i in range(len(S)):
    stack.append(S[i])
    if ''.join(stack[-ex_len:]) == explosion_string:
        for _ in range(ex_len):
            stack.pop()

# 결과 출력
if stack:
    print(''.join(stack))
else:
    print('FRULA')
