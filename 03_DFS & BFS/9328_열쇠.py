'''
상근이는 1층 빌딩에 침입해 매우 중요한 문서를 훔쳐오려고 한다. 
상근이가 가지고 있는 평면도에는 문서의 위치가 모두 나타나 있다. 
빌딩의 문은 모두 잠겨있기 때문에, 문을 열려면 열쇠가 필요하다. 
상근이는 일부 열쇠를 이미 가지고 있고, 일부 열쇠는 빌딩의 바닥에 놓여져 있다. 
상근이는 상하좌우로만 이동할 수 있다.

상근이가 훔칠 수 있는 문서의 최대 개수를 구하는 프로그램을 작성하시오.
'''

import sys
from collections import deque

input = sys.stdin.readline
dx = [1, 0, -1, 0]
dy = [0, 1, 0, -1]


def bfs(graph, visited, start, keys, n, m):
  y, x = start
  q = deque([(y, x)])
  visited[y][x] = True

  # 시작점 점검
  doc = 0
  # 시작점이 문서인 경우 줍는다
  if graph[y][x] == '$': 
    doc += 1
    graph[y][x] = '.'
  # 시작점이 열쇠인 경우 줍기
  elif graph[y][x].islower() and graph[y][x] not in keys: 
    keys.append(graph[y][x])
    graph[y][x] = '.'
  # 시작점이 열수있는 문인 경우
  elif graph[y][x].isupper():
    if graph[y][x].lower() not in keys: return 0
    else: graph[y][x] = '.'

  while q:
    y, x = q.popleft()

    # 상하좌우 이동
    for t in range(4):
      ny, nx = y + dy[t], x + dx[t]
      # 인덱스 체크
      if ny < 0 or ny >= n or nx < 0 or nx >= m:
        continue

      next = graph[ny][nx]
      # 아직 방문하지 않은 곳이고 벽이 아닌 경우
      if not visited[ny][nx] and next != '*':
        # 열 수 없는 문인 경우 패스
        if next.isupper() and next.lower() not in keys:
          continue
        # 문서 찾음
        if next == '$':
          doc += 1
        # 열쇠를 발견한 경우 줍기
        if next.islower() and next not in keys: 
          keys.append(next)

        # 한칸 이동 (문서를 찾거나, 열쇠를 발견했거나, 열수있는 문인경우)
        graph[ny][nx] = '.'
        visited[ny][nx] = True
        q.append((ny, nx))

  return doc


T = int(input())

for _ in range(T):
  n, m = map(int, input().rstrip().split())
  building = [[0] * m for _ in range(n)]
  start = []

  for i in range(n):
    for j, c in enumerate(list(input().rstrip())):
      building[i][j] = c
      if (i == 0 or j == 0 or i == n - 1 or j == m - 1) and c != '*':
        start.append((i, j))

  keys = list(input().rstrip())
  max_doc = 0

  while True:
    len_keys = len(keys)
    for s in start:
      visited = [[0] * m for _ in range(n)]
      max_doc += bfs(building, visited, s, keys, n, m)
    if len_keys == len(keys): break

  print(max_doc)

