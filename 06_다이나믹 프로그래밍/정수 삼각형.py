# n 크기의 삼각형이 있을때,
# 맨 위 꼭짓점에서부터 대각선 오른쪽/왼쪽 중 하나의 길을 선택해서 내려온다
# 경로에 있는 각 칸의 수의 합계가 최대가 되도록 하는 경로를 구하자

n = int(input())
dp = []  # 다이나믹 프로그래밍을 위한 DP 테이블 초기화

for _ in range(n):
    dp.append(list(map(int, input().split())))

# 다이나믹 프로그래밍으로 2번째 줄부터 내려가면서 확인
for i in range(1, n):
    for j in range(i + 1):
        # 왼쪽 위에서 내려오는 경우
        if j == 0:
            up_left = 0
        else:
            up_left = dp[i - 1][j - 1]
        # 바로 위에서 내려오는 경우
        if j == i:
            up = 0
        else:
            up = dp[i - 1][j]
        # 최대 합을 저장
        dp[i][j] = dp[i][j] + max(up_left, up)

print(max(dp[n - 1]))
