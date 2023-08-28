# N개의 수로 이루어진 수열이 주어진다 - 순서 변경 불가능
# 수와 수사이에 끼어넣을 수 있는 N-1개의 연산자(+ - x ÷)가 주어짐
# 식의 계산은 연산자 우선 순위를 무시하고 앞에서부터 진행
# 나눗셈은 정수 나눗셈으로 몫만 취함
# 이때, 음수 나눗셈 = 양수로 바꾼 뒤 몫을 취하고, 그 몫을 음수로 바꾼 것
# 만들 수 있는 식의 결과가 최대인 것과 최소인 것을 구하는 프로그램

# ========================
# 순열 사용 시 Python3 언어로는 시간초과가 뜨며 PyPy3로 제출할 경우에만 통과
# 백트래킹 (Python3 통과, PyPy3도 통과)
import sys

input = sys.stdin.readline
N = int(input())
num = list(map(int, input().split()))
op = list(map(int, input().split()))  # +, -, *, //

maximum = -1e9
minimum = 1e9


def dfs(depth, total, plus, minus, multiply, divide):
    global maximum, minimum
    if depth == N:
        maximum = max(total, maximum)
        minimum = min(total, minimum)
        return

    if plus:
        dfs(depth + 1, total + num[depth], plus - 1, minus, multiply, divide)
    if minus:
        dfs(depth + 1, total - num[depth], plus, minus - 1, multiply, divide)
    if multiply:
        dfs(depth + 1, total * num[depth], plus, minus, multiply - 1, divide)
    if divide:
        dfs(depth + 1, int(total / num[depth]),
            plus, minus, multiply, divide - 1)


dfs(1, num[0], op[0], op[1], op[2], op[3])
print(maximum)
print(minimum)

''' 백트래킹 풀이

from itertools import permutations
n = int(input())
number = list(map(int, input().split()))
add, sub, mul, div = map(int, input().split());
max_result = - int(1e9)
min_result = int(1e9)

def dfs(add, sub, mul, div, sum, idx):
    global max_result, min_result
    if idx == n:
        max_result = max(max_result, sum)
        min_result = min(min_result, sum)
        return
    if add:
        dfs(add-1, sub, mul, div, sum + number[idx], idx + 1)
    if sub:
        dfs(add, sub-1, mul, div, sum - number[idx], idx + 1)
    if mul:
        dfs(add, sub, mul-1, div, sum * number[idx], idx + 1)
    if div:
        dfs(add, sub, mul, div-1, int(sum / number[idx]), idx + 1)
        
dfs(add, sub, mul, div, number[0], 1)
print(max_result)
print(min_result)

'''


'''내코드
import sys
from itertools import permutations

input = sys.stdin.readline

n = int(input())
numbers = list(map(int, input().split()))
plus, minus, mul, div = map(int, input().split())

oper = []
for i in range(plus):
  oper.append('+')
for i in range(minus):
  oper.append('-')
for i in range(mul):
  oper.append('*')
for i in range(div):
  oper.append('/')

cases = list(set(permutations(oper, n - 1)))
# 중복제거 필수 - 중복제거해도 중보계산 발생하기함
# + + - * 와 + + * - 가 있다면 백트래킹의 경우 + + 까지의 계산을 한번만 하는데 순열의 경우 아님
# min_ = 1e9
# max_ = -1e9  # 오답이유: max_ = -1 로 설정해서...
# 아니근데 순열에서만 sys.max로 해야 답이 맞는 이유는뭐임;;
max_ = -sys.maxsize
min_ = sys.maxsize

for case in cases:
  total = numbers[0]
  for idx, n in enumerate(numbers[1:]):
    if case[idx] == '+': total += n
    elif case[idx] == '-': total -= n
    elif case[idx] == '*': total *= n
    elif case[idx] == '/': total = int(total / n)
  min_ = min(min_, total)
  max_ = max(max_, total)

print(max_)
print(min_)


'''
