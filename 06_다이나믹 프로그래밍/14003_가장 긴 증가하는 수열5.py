'''
수열 A가 주어졌을 때, 가장 긴 증가하는 부분 수열을 구하는 프로그램을 작성하시오.

예를 들어, 수열 A = {10, 20, 10, 30, 20, 50} 인 경우에 
가장 긴 증가하는 부분 수열은 A = {10, 20, 10, 30, 20, 50} 이고, 길이는 4이다.

첫째 줄에 수열 A의 가장 긴 증가하는 부분 수열의 길이를 출력한다.
둘째 줄에는 정답이 될 수 있는 가장 긴 증가하는 부분 수열을 출력한다.

[못품] 아이디어
input 값을 앞에서부터 읽어준다.
input[i]을 dp 맨 마지막 값과 비교해준다.
2.1. 만약 input[i]가 더 크다면 dp 맨 마지막에 append 해준다.
2.2. 만약 input[i]가 더 작거나 같다면 dp 내 적절한 위치에 삽입해준다.
  --- 여기까지는 동일

< input[i]가 dp[j]에 들어갔다면 total에 (input[i], j)를 append 해준다. >
'''
import sys
from bisect import bisect_left
input = sys.stdin.readline

n = int(input())  # (1 ≤ N ≤ 1,000,000)
# (-1,000,000,000 ≤ Ai ≤ 1,000,000,000)
numbers = list(map(int, input().split()))

# 최장 증가 부분 수열 저장
LIS = [arr[0]]
dp = [(0, arr[0])]  # dp에는 LIS에 들어간 인덱스를 저장해둔다.

# 출력 1
for i in range(1, n):
    if arr[i] > LIS[-1]:
        LIS.append(arr[i])
        dp.append((len(LIS)-1, arr[i]))  # 달라진 부분1

    else:
        idx = binarySearch(arr[i])
        LIS[idx] = arr[i]
        dp.append((idx, arr[i]))  # 달라진 부분2

print(len(LIS))

# 출력 2 - 역추적
last_idx = len(LIS) - 1
res = []
for i in range(len(dp)-1, -1, -1):
    # i번째 값의 index와 마지막 인덱스값과 같다면
    if dp[i][0] == last_idx:
        res.append(dp[i][1])
        last_idx -= 1

print(*res[::-1])  # unpacking - [1,2,3,4] => 1 2 3 4로 출력해줌
