'''
세준이는 어떤 문자열을 팰린드롬으로 분할하려고 한다. 
예를 들어, ABACABA를 팰린드롬으로 분할하면, 
{A, B, A, C, A, B, A}, {A, BACAB, A}, {ABA, C, ABA}, {ABACABA}등이 있다.

분할의 개수의 최솟값을 출력하는 프로그램을 작성하시오.
'''

'''
[못품]
아이디어 암기: 
- is_p[i][j]: i부터 j까지가 팰린드롬이면 1을 아니면 0
- 길이가 1,2인거 구해놓기
- 길이가 3이상 구하기 
  => 처음과 끝이 같고, 그 사이가 팰린드롬이면 해당 구간 역시 팰린드롬
'''

import sys
sys.setrecursionlimit(10 ** 8)
def input(): return sys.stdin.readline().rstrip()


s = input()
L = len(s)


# 이중 dp
dp = [2500 for _ in range(L + 1)]
dp[-1] = 0
is_p = [[0 for j in range(L)] for i in range(L)]


for i in range(L):  # 길이 1 짜리 팰린드롬
    is_p[i][i] = 1

for i in range(1, L):  # 길이 2 짜리 팰린드롬 (AA, DD 같은 놈들)
    if s[i - 1] == s[i]:
        is_p[i - 1][i] = 1

for l in range(3, L + 1):  # 길이 3 ~ L 짜리 팰린드롬
    for start in range(L - l + 1):
        end = start + l - 1
        if s[start] == s[end] and is_p[start + 1][end - 1]:
            # 처음과 끝이 같고, 그 사이가 팰린드롬이면
            is_p[start][end] = 1  # start~end 도 팰린드롬

for end in range(L):  # 한글자씩 추가
    for start in range(end + 1):
        # dp[i]: i 번째까지의 최소 팰린드롬 분할 개수
        if is_p[start][end]:
            dp[end] = min(dp[end], dp[start - 1] + 1)
        else:
            dp[end] = min(dp[end], dp[end - 1] + 1)

print(dp[L - 1])
