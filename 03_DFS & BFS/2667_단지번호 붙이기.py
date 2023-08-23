'''_
<그림 1>과 같이 정사각형 모양의 지도가 있다. 
1은 집이 있는 곳을, 0은 집이 없는 곳을 나타낸다. 
철수는 이 지도를 가지고 연결된 집의 모임인 단지를 정의하고, 
단지에 번호를 붙이려 한다. 

여기서 연결되었다는 것은 어떤 집이 좌우, 혹은 아래위로 다른 집이 있는 경우를 말한다. 
대각선상에 집이 있는 경우는 연결된 것이 아니다. 
<그림 2>는 <그림 1>을 단지별로 번호를 붙인 것이다. 
지도를 입력하여 단지수를 출력하고, 
각 단지에 속하는 집의 수를 오름차순으로 정렬하여 출력하는 프로그램을 작성하시오.
'''

from collections import deque
dx = [1, 0, -1, 0]
dy = [0, 1, 0, -1]

n = int(input())
graph = []
visited = [[False] * n for _ in range(n)]
areas = []


def bfs(graph, start, visited):
    global area
    queue = deque([start])
    i, j = start
    visited[i][j] = True

    while queue:
        i, j = queue.popleft()

        for t in range(4):
            ni, nj = (i + dy[t], j+dx[t])
            if ni < 0 or ni >= n or nj < 0 or nj >= n:
                continue
            if graph[ni][nj] == '0':
                continue

            if not visited[ni][nj]:
                queue.append((ni, nj))
                visited[ni][nj] = True
                areas[-1] += 1


for i in range(n):
    # [오답노트]
    # 이거 list(map(int,input().split())) 으로 하면
    # 0100010 이런 경우에 맨앞 0이 잘려서 들어감
    graph.append(list(input()))

for i in range(n):
    for j in range(n):
        if not visited[i][j] and graph[i][j] == '1':
            areas.append(1)
            bfs(graph, (i, j), visited)

areas.sort()
print(len(areas))
for area in areas:
    print(area)
