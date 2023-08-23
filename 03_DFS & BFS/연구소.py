# 연구소에 바이러스가 유출 되었는데, 바이러스는 상 하 좌 우로 모두 퍼져나갈 수 있다.
# 바이러스 확산을 막기위해 3개의 벽을 세우려고 할때, 얻을 수 있는 안전 영역의 최댓값을 구하자

# =====================================
# BOJ에서는 [언어]를 PyPy3로 설정하여 제출해주세요.

n, m = map(int, input().split())
data = []  # 초기 맵 리스트
temp = [[0] * m for _ in range(n)]  # 벽을 설치한 뒤의 맵 리스트

for _ in range(n):
    data.append(list(map(int, input().split())))

# 4가지 이동 방향에 대한 리스트
dx = [-1, 0, 1, 0]
dy = [0, 1, 0, -1]

result = 0

# 깊이 우선 탐색(DFS)을 이용해 각 바이러스가 사방으로 퍼지도록 하기


def virus(x, y):
    for i in range(4):
        nx = x + dx[i]
        ny = y + dy[i]
        # 상, 하, 좌, 우 중에서 바이러스가 퍼질 수 있는 경우
        if nx >= 0 and nx < n and ny >= 0 and ny < m:
            if temp[nx][ny] == 0:
                # 해당 위치에 바이러스 배치하고, 다시 재귀적으로 수행
                temp[nx][ny] = 2
                virus(nx, ny)

# 현재 맵에서 안전 영역의 크기 계산하는 메서드


def get_score():
    score = 0
    for i in range(n):
        for j in range(m):
            if temp[i][j] == 0:
                score += 1
    return score

# 깊이 우선 탐색(DFS)을 이용해 울타리를 설치하면서, 매 번 안전 영역의 크기 계산


def dfs(count):
    global result
    # 울타리가 3개 설치된 경우
    if count == 3:
        for i in range(n):
            for j in range(m):
                temp[i][j] = data[i][j]
        # 각 바이러스의 위치에서 전파 진행
        for i in range(n):
            for j in range(m):
                if temp[i][j] == 2:
                    virus(i, j)
        # 안전 영역의 최대값 계산
        result = max(result, get_score())
        return
    # 빈 공간에 울타리를 설치
    for i in range(n):
        for j in range(m):
            if data[i][j] == 0:
                data[i][j] = 1
                count += 1
                dfs(count)
                data[i][j] = 0
                count -= 1


dfs(0)
print(result)


''' 내 코드
from itertools import combinations

dx = [0, 1, 0, -1]
dy = [1, 0, -1, 0]


def dfs(v, map_copy, n, m):
  ny, nx = v
  map_copy[ny][nx] = 2

  for i in range(4):
    next_x = nx + dx[i]
    next_y = ny + dy[i]
    if next_y >= n or next_y < 0 or next_x >= m or next_x < 0:
      continue
    if map_copy[next_y][next_x] == 0:
      dfs((next_y, next_x), map_copy, n, m)
  return


n, m = map(int, input().split())
MAP = []
max_safe = -1

for i in range(n):
  MAP.append(list(map(int, input().split())))

empty_ = [(y, x) for x in range(m) for y in range(n) if MAP[y][x] == 0]
virus_ = [(y, x) for x in range(m) for y in range(n) if MAP[y][x] == 2]

for case in list(combinations(empty_, 3)):
  map_copy = [arr[:] for arr in MAP]

  for coord in case:
    map_copy[coord[0]][coord[1]] = 1
  for v in virus_:
    dfs(v, map_copy, n, m)
  safe = [x for row in map_copy for x in row]
  max_safe = max(safe.count(0), max_safe)

print(max_safe)

'''
