# 캐릭터가 있는 맵은 N * M 크기의 직사각형
# 각각의 칸은 육지 = 0 또는 바다 = 1. 바다는 갈 수 없음
# 캐릭터는 동서남북 중 한 곳을 바로 보고, 아래의 메뉴얼 대로 움직임
# 1. 현재 방향을 기준으로 왼쪽 방향 부터 차례로 갈 곳을 선정
# 2. 그 방향에 아직 가보지 않은 칸이 있다면 회전 후 한칸 전진, 
#    가보지 않은 칸이 아니라면 회전만 하고 1단계로 돌아감
# 3. 네 방향 모두 간 곳이거나 바다인 경우, 방향은 유지한 채 한칸 뒤로 가고 1단계로 돌아감
# 4. 뒤쪽 방향이 바다라서 갈 수 없는 경우 움직임을 멈춤

# ===============================

# N, M을 공백을 기준으로 구분하여 입력받기
n, m = map(int, input().split())

# 방문한 위치를 저장하기 위한 맵을 생성하여 0으로 초기화
d = [[0] * m for _ in range(n)]
# 현재 캐릭터의 X 좌표, Y 좌표, 방향을 입력받기
x, y, direction = map(int, input().split())
d[x][y] = 1 # 현재 좌표 방문 처리

# 전체 맵 정보를 입력받기
array = []
for i in range(n):
    array.append(list(map(int, input().split())))

# 북, 동, 남, 서 방향 정의
dx = [-1, 0, 1, 0]
dy = [0, 1, 0, -1]

# 왼쪽으로 회전
def turn_left():
    global direction
    direction -= 1
    if direction == -1:
        direction = 3

# 시뮬레이션 시작
count = 1
turn_time = 0
while True:
    # 왼쪽으로 회전
    turn_left()
    nx = x + dx[direction]
    ny = y + dy[direction]
    # 회전한 이후 정면에 가보지 않은 칸이 존재하는 경우 이동
    if d[nx][ny] == 0 and array[nx][ny] == 0:
        d[nx][ny] = 1
        x = nx
        y = ny
        count += 1
        turn_time = 0
        continue
    # 회전한 이후 정면에 가보지 않은 칸이 없거나 바다인 경우
    else:
        turn_time += 1
    # 네 방향 모두 갈 수 없는 경우
    if turn_time == 4:
        nx = x - dx[direction]
        ny = y - dy[direction]
        # 뒤로 갈 수 있다면 이동하기
        if array[nx][ny] == 0:
            x = nx
            y = ny
        # 뒤가 바다로 막혀있는 경우
        else:
            break
        turn_time = 0

# 정답 출력
print(count)


'''
[내 코드]

N, M = map(int, input().split())
STOP = 1
GO = 0
visited = 1
dx = [-1, 0, 1, 0]  # 왼쪽 아래 오른쪽 위
dy = [0, 1, 0, -1]

# 캐릭터 입력 받기
x, y, d = map(int, input().split())  # d: 0-위 1-오른 2-아래 3-왼
now = [y, x]

# 맵 입력 받기
MAP = []
for i in range(N):
  MAP.append(list(map(int, input().split())))

# 더 이상 갈곳이 없을 때까지 루프를 돈다
while True:
  # 1단계
  firstIndex = (d - 1) % 4
  next = []

  for i in range(4):
    moveIndex = -((firstIndex + i - 1) % 4)
    next = [now[0] + dy[moveIndex], now[1] + dx[moveIndex]]

    # 2단계
    if MAP[next[0]][next[1]] == GO:
      MAP[now[0]][now[1]] = STOP
      now = next
      d = -moveIndex - 1
      visited += 1
      break

  # 3단계
  if not (next[0] == now[0] and next[1] == now[1]):
    back = -((d -2 -1) % 4)
    next = [now[0] + dy[back], now[1] + dx[back]]
    if MAP[next[0]][next[1]] == STOP: break
    now = next

print(visited)
'''
