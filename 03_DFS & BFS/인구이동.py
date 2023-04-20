# N L R 이 주어진다
# NxN크기의 땅이 있고, 각 영역에는 나라가 존재하며, 각 칸의 수는 각 나라의 인구수를 의미
# 인구의 차이가 L이상 R이하인 경우 국경이 열리고 인구 이동 가능
# 열린 국경을 통해서 이동할 수 있는 곳들을 합해서 연합이라고 함
# 현재 시점에서 열수있는 국경을 다 열고 이동 -> 각 칸의 인구 수 = 연합 총 인구/칸 수

# 인구이동이 총 몇회 실시 되는지 계산

# ===============

from collections import deque

# 땅의 크기(N), L, R 값을 입력받기
n, l, r = map(int, input().split())

# 전체 나라의 정보(N x N)를 입력 받기
graph = []
for _ in range(n):
    graph.append(list(map(int, input().split())))

dx = [-1, 0, 1, 0]
dy = [0, -1, 0, 1]

# 특정 위치에서 출발하여 모든 연합을 체크한 뒤에 데이터 갱신
def process(x, y, index):
    # (x, y)의 위치와 연결된 나라(연합) 정보를 담는 리스트
    united = []
    united.append((x, y))
    # 너비 우선 탐색 (BFS)을 위한 큐 라이브러리 사용
    q = deque()
    q.append((x, y))
    union[x][y] = index # 현재 연합의 번호 할당
    summary = graph[x][y] # 현재 연합의 전체 인구 수
    count = 1 # 현재 연합의 국가 수
    # 큐가 빌 때까지 반복(BFS)
    while q:
        x, y = q.popleft()
        # 현재 위치에서 4가지 방향을 확인하며
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            # 바로 옆에 있는 나라를 확인하여
            if 0 <= nx < n and 0 <= ny < n and union[nx][ny] == -1:
                # 옆에 있는 나라와 인구 차이가 L명 이상, R명 이하라면
                if l <= abs(graph[nx][ny] - graph[x][y]) <= r:
                    q.append((nx, ny))
                    # 연합에 추가하기
                    union[nx][ny] = index
                    summary += graph[nx][ny]
                    count += 1
                    united.append((nx, ny))
    # 연합 국가끼리 인구를 분배
    for i, j in united:
        graph[i][j] = summary // count

total_count = 0

# 더 이상 인구 이동을 할 수 없을 때까지 반복
while True:
    union = [[-1] * n for _ in range(n)]
    index = 0
    for i in range(n):
        for j in range(n):
            if union[i][j] == -1: # 해당 나라가 아직 처리되지 않았다면
                process(i, j, index)
                index += 1
    # 모든 인구 이동이 끝난 경우
    if index == n * n:
        break
    total_count += 1

# 인구 이동 횟수 출력
print(total_count)




'''내코드
import sys
sys.setrecursionlimit(5000) # dfs로 풀면 안되는 문제여따....

dx = [1, 0, -1, 0]
dy = [0, 1, 0, -1]

n, l, r = map(int,input().split())
maps = []
count = 0

for i in range(n): 
  maps.append(list(map(int,input().split())))


def move(maps,x,y):
  global union, total,visited
  visited[x][y] = 1

  for t in range(4):
    n_x = x + dx[t] 
    n_y = y + dy[t]

    # 영역 벗어남
    if n_x < 0 or n_x >= n or n_y < 0 or n_y >= n:
      continue

    # 이미 방문함
    if visited[n_x][n_y]: 
      continue

    # l이상 r이하 차이라면 국경이 열림
    if l <= abs(maps[x][y]-maps[n_x][n_y]) <= r:
      # 현재 연합에 넣기 & 총 인구 수에 더해주기
      union[-1].append((n_x,n_y))
      total[-1] += maps[n_x][n_y]
      
      move(maps,n_x,n_y)



while True:
  visited = [[0] * n for _ in range(n)]
  union = []
  total = []

  # 연합 계산
  for i in range(n):
    for j in range(n):
      if visited[i][j]: continue

      # 새 연합 구축
      union.append([(i,j)])
      total.append(maps[i][j])
      
      move(maps, i, j)
      

  # 인구 재배치
  for index, u in enumerate(union): 
    for x, y in u:
      maps[x][y] = total[index]//len(union[index])

  # 변화가 없다면
  if len(union) == n*n: break

  # 변화가 있다면 
  else: count += 1

print(count)


'''