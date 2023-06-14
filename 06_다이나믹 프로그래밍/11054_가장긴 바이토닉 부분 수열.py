'''
수열 S가 어떤 수 Sk를 기준으로 S1 < S2 < ... Sk-1 < Sk > Sk+1 > ... SN-1 > SN을 만족한다면, 
그 수열을 바이토닉 수열이라고 한다.

예를 들어, {10, 20, 30, 25, 20}과 {10, 20, 30, 40}, {50, 40, 25, 10} 은 바이토닉 수열이지만, 
{1, 2, 3, 2, 1, 2, 3, 2, 1}과 {10, 20, 30, 40, 20, 30} 은 바이토닉 수열이 아니다.

수열 A가 주어졌을 때, 그 수열의 부분 수열 중 바이토닉 수열이면서 
가장 긴 수열의 길이를 구하는 프로그램을 작성하시오.
'''

from bisect import bisect_left

n = int(input())
arr = list(map(int,input().split()))

maxlen = 0

def LIS(dp, arr):
  dp.append(arr[0])
  for l in range(1,len(arr)):
    if dp[-1] < arr[l]: dp.append(arr[l])
    else:
      idx = bisect_left(dp,arr[l])
      dp[idx] = arr[l]

for left_end in range(n+1):
  increase,decrease = [], []
  # 증가 구역과 감소 구역을 나눠서 계산하기
  left = arr[:left_end]
  right = arr[left_end:]
  area = 0

  if len(left) > 0: 
    LIS(increase, left)
    area += 1
    
  if len(right) > 0: 
    LIS(decrease, list(reversed(right)))
    area += 1

  total = len(increase)+len(decrease)
  # 첫 오답이유: 고원이 탄생하면 안됨 (같은 높이의 중간 꼭짓점인 경우 -1해주기)
  if area == 2 and decrease[-1] == increase[-1]: total -= 1
  maxlen = max(maxlen, total)


print(maxlen)
  