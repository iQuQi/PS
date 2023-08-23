'''
매일 아침, 세준이는 학교에 가기 위해서 차를 타고 D킬로미터 길이의 고속도로를 지난다. 
이 고속도로는 심각하게 커브가 많아서 정말 운전하기도 힘들다. 
어느 날, 세준이는 이 고속도로에 지름길이 존재한다는 것을 알게 되었다. 
모든 지름길은 일방통행이고, 고속도로를 역주행할 수는 없다.

세준이가 운전해야 하는 거리의 최솟값을 출력하시오.
'''
from heapq import heappop, heappush
import sys
input = sys.stdin.readline
INF = int(1e9)

n, d = map(int, input().split())
start = 0
graph = [[] for i in range(d + 1)]
visited = [False] * (d + 1)
distance = [INF] * (d + 1)
V = []

# 지름길 입력받기
for _ in range(n):
    a, b, c = map(int, input().split())
    if b-a <= c or b > d:
        continue
    if b not in V:
        V.append(b)
    if a not in V:
        V.append(a)
    graph[a].append((b, c))

prev = 0
V.sort()
for v in V:
    if v == 0:
        continue
    graph[prev].append((v, v-prev))
    prev = v
if prev < d:
    graph[prev].append((d, d-prev))


def dijkstra(start):
    q = []
    # 시작 노드로 가기 위한 최단 경로는 0으로 설정하여, 큐에 삽입
    heappush(q, (0, start))
    distance[start] = 0
    while q:  # 큐가 비어있지 않다면
        # 가장 최단 거리가 짧은 노드에 대한 정보 꺼내기
        dist, now = heappop(q)
        # 현재 노드가 이미 처리된 적이 있는 노드라면 무시 -> speed up!
        if distance[now] < dist:
            continue
        # 현재 노드와 연결된 다른 인접한 노드들을 확인
        for i in graph[now]:
            cost = dist + i[1]
            # 현재 노드를 거쳐서, 다른 노드로 이동하는 거리가 더 짧은 경우
            if cost < distance[i[0]]:
                distance[i[0]] = cost
                heappush(q, (cost, i[0]))


# 다익스트라 알고리즘을 수행
dijkstra(start)
print(distance[d])
