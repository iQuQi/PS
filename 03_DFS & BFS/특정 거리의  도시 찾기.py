# N개의 도시와 M개의 간선(거리 = 1)이 존재할 때
# x에서 출발해서 최단거리 k만에 갈 수 있는 도시들을 오름차순으로 출력
# M이 크니 입력시 시간초과 나지 않게 주의

# ==========================
from collections import deque

# 도시의 개수, 도로의 개수, 거리 정보, 출발 도시 번호
n, m, k, x = map(int, input().split())
graph = [[] for _ in range(n + 1)]

# 모든 도로 정보 입력 받기
for _ in range(m):
    a, b = map(int, input().split())
    graph[a].append(b)

# 모든 도시에 대한 최단 거리 초기화
distance = [-1] * (n + 1)
distance[x] = 0 # 출발 도시까지의 거리는 0으로 설정

# 너비 우선 탐색(BFS) 수행
q = deque([x])
while q:
    now = q.popleft()
    # 현재 도시에서 이동할 수 있는 모든 도시를 확인
    for next_node in graph[now]:
        # 아직 방문하지 않은 도시라면
        if distance[next_node] == -1:
            # 최단 거리 갱신
            distance[next_node] = distance[now] + 1
            q.append(next_node)

# 최단 거리가 K인 모든 도시의 번호를 오름차순으로 출력
check = False
for i in range(1, n + 1):
    if distance[i] == k:
        print(i)
        check = True

# 만약 최단 거리가 K인 도시가 없다면, -1 출력
if check == False:
    print(-1)




'''내코드
M이 너무 커서 입력 받을 때 시간 초과 발생 *********
=> sys.stdin.readline().rstrip() 사용

from collections import deque
import sys

def bfs(graph, start, visited, K):
  answer = []
  q = deque()
  q.append((start, 0))
  visited[start] = True

  while q:
    now_v, now_dis = q.popleft()
    if now_dis == K: answer.append(now_v)
    for i in graph[now_v]:
      if not visited[i]:
        q.append((i, now_dis + 1))
        visited[i] = True
    if now_dis > K: break

  return answer


N, M, K, X = map(int, input().split())
link = [[] for _ in range(N + 1)]
visited = [False] * (N + 1)

for _ in range(M):
  from_, to_ = map(int, sys.stdin.readline().rstrip().split())
  link[from_].append(to_)

answer = sorted(bfs(link, X, visited, K))
if answer:
  for i in answer:
    print(i)
else:
  print(-1)

'''