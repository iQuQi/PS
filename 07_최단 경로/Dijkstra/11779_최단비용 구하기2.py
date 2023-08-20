'''
n(1≤n≤1,000)개의 도시가 있다. 
그리고 한 도시에서 출발하여 다른 도시에 도착하는 m(1≤m≤100,000)개의 버스가 있다. 
우리는 A번째 도시에서 B번째 도시까지 가는데 드는 버스 비용을 최소화 시키려고 한다. 
그러면 A번째 도시에서 B번째 도시 까지 가는데 드는 최소비용과 경로를 출력하여라. 
항상 시작점에서 도착점으로의 경로가 존재한다.
'''
import sys
from heapq import heappop, heappush
input = sys.stdin.readline
INF = 1e9

n = int(input())  # (1≤n≤1,000)이
m = int(input())  # (1≤m≤100,000)
graph = [[] for _ in range(n+1)]
distance = [INF] * (n+1)
prev = [None] * (n+1)

for i in range(m):
    from_, to_, cost = map(int, input().split())
    graph[from_].append((to_, cost))  # 비용은 0보다 크거나 같고, 100,000보다 작은 정수

start, end = map(int, input().split())


def dijkstra(start):
    q = []
    distance[start] = 0
    heappush(q, (0, start))

    while q:
        dist, now = heappop(q)

        if distance[now] < dist:
            continue

        for t, c in graph[now]:
            cost = dist + c
            if cost < distance[t]:
                distance[t] = cost
                prev[t] = now
                heappush(q, (cost, t))


dijkstra(start)

# 출발 도시에서 도착 도시까지 가는데 드는 최소 비용을 출력
print(distance[end])

# 최소 비용을 갖는 경로에 포함되어있는 도시의 개수를 출력 (출발, 도착점 포함)
# 최소 비용을 갖는 경로를 방문하는 도시 순서대로 출력
path = [end]
now = end
while now != start:
    path.append(prev[now])
    now = prev[now]

print(len(path))
print(*path[::-1])
