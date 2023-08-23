# 시험관에 1~K까지의 번호를 가진 바이러스가 있다
# 매초마다 바이러스가 상하좌우로 한칸씩 번식하는데, 이때 숫자가 적은 번호를 가진 바이러스부터 번식한다
# 이미 바이러스가 존재하는 칸에는 들어갈 수 없다
# S초 후에 (X,Y)에 존재하는 바이러스 종류를 출력하자


# ============================
from collections import deque

n, k = map(int, input().split())

graph = []  # 전체 보드 정보를 담는 리스트
data = []  # 바이러스에 대한 정보를 담는 리스트

for i in range(n):
    # 보드 정보를 한 줄 단위로 입력
    graph.append(list(map(int, input().split())))
    for j in range(n):
        # 해당 위치에 바이러스가 존재하는 경우
        if graph[i][j] != 0:
            # (바이러스 종류, 시간, 위치 X, 위치 Y) 삽입
            data.append((graph[i][j], 0, i, j))

# 정렬 이후에 큐로 옮기기 (낮은 번호의 바이러스가 먼저 증식하므로)
data.sort()
q = deque(data)

target_s, target_x, target_y = map(int, input().split())

# 바이러스가 퍼져나갈 수 있는 4가지의 위치
dx = [-1, 0, 1, 0]
dy = [0, 1, 0, -1]

# 너비 우선 탐색(BFS) 진행
while q:
    virus, s, x, y = q.popleft()
    # 정확히 s초가 지나거나, 큐가 빌 때까지 반복
    if s == target_s:
        break
    # 현재 노드에서 주변 4가지 위치를 각각 확인
    for i in range(4):
        nx = x + dx[i]
        ny = y + dy[i]
        # 해당 위치로 이동할 수 있는 경우
        if 0 <= nx and nx < n and 0 <= ny and ny < n:
            # 아직 방문하지 않은 위치라면, 그 위치에 바이러스 넣기
            if graph[nx][ny] == 0:
                graph[nx][ny] = virus
                q.append((virus, s + 1, nx, ny))

print(graph[target_x - 1][target_y - 1])


'''내코드
from collections import deque

dx = [0, 1, 0, -1]
dy = [1, 0, -1, 0]


def bfs(virus, map_, n, s):
  virus_q = deque()
  for x, y, num in virus:
    virus_q.append((x, y, num, 0))

  while virus_q:
    nx, ny, num, second = virus_q.popleft()
    if second == s: return

    for i in range(4):
      next_x = nx + dx[i]
      next_y = ny + dy[i]
      if next_y >= n or next_y < 0 or next_x >= n or next_x < 0:
        continue
      if map_[next_x][next_y] == 0:
        virus_q.append((next_x, next_y, num, second + 1))
        map_[next_x][next_y] = num
  return


n, k = map(int, input().split())
map_ = []

for i in range(n):
  map_.append(list(map(int, input().split())))
s, x, y = map(int, input().split())

# 바이러스 번호대로 좌표 저장
virus = []
for i in range(n):
  for j in range(n):
    if map_[i][j] != 0:
      virus.append((i, j, map_[i][j]))
virus = sorted(virus, key=lambda x: x[2])

# bfs 돌리기
bfs(virus, map_, n, s)
print(map_[x - 1][y - 1])

'''
