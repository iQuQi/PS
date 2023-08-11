'''
3×N 크기의 벽을 2×1, 1×2 크기의 타일로 채우는 경우의 수를 구해보자.
'''
n = int(input())
dp = [0]*31

dp[1] = 0
dp[2] = 3
dp[3] = 0

for i in range(4, n+1):
  # 홀수줄은 채우기 불가능
  if i%2 == 1: continue

  # N개의 줄을 채울 때 사용가능한 블록은 2*3, 4*3 ... N*3 임 (2배수,그려보면 알 수 있음)
  # 2*3 블록만 예외적으로 3가지 케이스가 존재하며, 
  # 그 이상의 경우 두가지의 독립적인 경우만 존재(이전 블록들을 이어붙인 것은 포함하지 않음)

  dp[i] = 2 # N*3 블록을 2개 사용해서 한번에 채우기

  
  for j in range(1,i//2): # j*2 = x
    if j*2 == 2: dp[i] += dp[i-j*2]*3 # 마지막을 2*3블록으로 채우는 경우
    else: dp[i] += dp[i-j*2]*2 # 마지막을 x*3블록으로 채우는 경우 (2<x<N)

print(dp[n])