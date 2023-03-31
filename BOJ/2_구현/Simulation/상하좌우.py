
# 시작점은 1,1
# R L U D 입력에 맞게 위치를 이동시키고 최종 목적지를 구하자
# => 일련의 명령에 따라서 개체를 차례로 이동시키는 문제이므로 '시뮬레이션'에 해당


N = int(input())
plan_list = input().split()
dy = [0,1,0,-1] # 위 오 아래 왼
dx = [-1,0,1,0]
now = [1,1]
move = {'R': 1, 'L':3 , 'U':0, 'D':2}

for plan in plan_list:
  next = [now[0] + dx[move[plan]],now[1] + dy[move[plan]]]
  if next[0] > N or next[1] > N or next[0] < 1 or next[1] < 1 :
    continue
  now = next

print(now[0], now[1])
