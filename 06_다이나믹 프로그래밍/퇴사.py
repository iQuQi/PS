# N+1일날 퇴사를 하려고 한다. N일동안 최대한 많은 돈을 벌고 나가고 싶다
# 매일 상담약속이 들어오는데, 그날부터 걸리는 상담시간과 총 얻게되는 수익이 주어진다
# 같은 날에 두개 이상의 상담을 동시에 진행할 수는 없다
# 단, N+1일까지 상담을 진행해야할 경우 약속을 잡지 못한다
# 겹치지 않게 약속을 잘 잡아서 최대 이익을 내자

# ==========================
n = int(input())  # 전체 상담 개수
t = []  # 각 상담을 완료하는데 걸리는 기간
p = []  # 각 상담을 완료했을 때 받을 수 있는 금액
dp = [0] * (n + 1)  # 다이나믹 프로그래밍을 위한 1차원 DP 테이블 초기화
max_value = 0

for _ in range(n):
    x, y = map(int, input().split())
    t.append(x)
    p.append(y)

# 리스트를 뒤에서부터 거꾸로 확인 - 뒤에서 부터 하면 상담이 끝이 나있음, 앞에서 부터 하면 상담이 아직 안끔나서 i번째날까지의 최대이익을 구할 수 없음
for i in range(n - 1, -1, -1):
    time = t[i] + i
    # 상담이 기간 안에 끝나는 경우
    if time <= n:
        # 점화식에 맞게, 현재까지의 최고 이익 계산
        dp[i] = max(p[i] + dp[time], max_value)
        max_value = dp[i]
    # 상담이 기간을 벗어나는 경우
    else:
        dp[i] = max_value

print(max_value)


'''내코드
n = int(input())
time = [0] * (n+1)
money = [0] * (n+1)
dp = [0] * (n+2) #i번째 날부터 마지막날까지 얻을 수 있는 최대이익

for i in range(1,n+1):
  t, m = map(int,input().split())
  time[i] = t
  money[i] = m 


for j in range(n,0,-1):
  # 잡지 못하는 상담 약속
  if j + time[j] > n+1:
    # dp[j] = 0 => 오답, 0이 아니라 그 직전의 최대이익 대입
    dp[j] = dp[j+1]

  # 오늘안에 끝내지 못하는 약속의 경우
  elif time[j] != 1:
    dp[j] = max(money[j] + dp[j+time[j]], dp[j+1])
  # 오늘 안에 끝낼 수 있는 약속이면 잡는다
  else:
    dp[j] = money[j] + dp[j+1]

print(dp[1])
'''
