# N개의 수로 이루어진 수열이 주어진다 - 순서 변경 불가능
# 수와 수사이에 끼어넣을 수 있는 N-1개의 연산자(+ - x ÷)가 주어짐
# 식의 계산은 연산자 우선 순위를 무시하고 앞에서부터 진행
# 나눗셈은 정수 나눗셈으로 몫만 취함
# 이때, 음수 나눗셈 = 양수로 바꾼 뒤 몫을 취하고, 그 몫을 음수로 바꾼 것
# 만들 수 있는 식의 결과가 최대인 것과 최소인 것을 구하는 프로그램

# ========================
# 순열 사용 시 Python3 언어로는 시간초과가 뜨며 PyPy3로 제출할 경우에만 통과
n = int(input())
# 연산을 수행하고자 하는 수 리스트
data = list(map(int, input().split()))
# 더하기, 빼기, 곱하기, 나누기 연산자 개수
add, sub, mul, div = map(int, input().split())

# 최솟값과 최댓값 초기화
min_value = 1e9
max_value = -1e9

# 깊이 우선 탐색 (DFS) 메서드


def dfs(i, now):
    global min_value, max_value, add, sub, mul, div
    # 모든 연산자를 다 사용한 경우, 최솟값과 최댓값 업데이트
    if i == n:
        min_value = min(min_value, now)
        max_value = max(max_value, now)
    else:
        # 각 연산자에 대하여 재귀적으로 수행
        if add > 0:
            add -= 1
            dfs(i + 1, now + data[i])
            add += 1
        if sub > 0:
            sub -= 1
            dfs(i + 1, now - data[i])
            sub += 1
        if mul > 0:
            mul -= 1
            dfs(i + 1, now * data[i])
            mul += 1
        if div > 0:
            div -= 1
            dfs(i + 1, int(now / data[i]))  # 나눌 때는 나머지를 제거
            div += 1


# DFS 메서드 호출
dfs(1, data[0])

# 최댓값과 최솟값 차례대로 출력
print(max_value)
print(min_value)


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

from itertools import permutations

n = int(input())
A = list(map(int, input().split()))

add, sub, mul, div = map(int, input().split())

opers = ['A'] * add + ['S'] * sub + ['M'] * mul + ['D'] * div
opers = [oper for oper in opers if oper != '']

max_ = -1e9
min_ = 1e9

selections = list(permutations(opers, n - 1))

for s in selections:
  result = A[0]
  for index, oper in enumerate(s):
    if oper == 'A': result += A[index + 1]
    elif oper == 'S': result -= A[index + 1]
    elif oper == 'M': result *= A[index + 1]
    elif oper == 'D': result = int(result / A[index+1])

  max_ = max(max_, result)
  min_ = min(min_, result)

print(max_)
print(min_)

'''
