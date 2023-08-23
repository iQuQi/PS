'''
B100 요원, 요란한 옷차림을 한 서커스 예술가 한 쌍이 한 도시의 거리들을 이동하고 있다. 
너의 임무는 그들이 어디로 가고 있는지 알아내는 것이다. 
우리가 알아낸 것은 그들이 s지점에서 출발했다는 것, 
그리고 목적지 후보들 중 하나가 그들의 목적지라는 것이다. 
그들이 급한 상황이기 때문에 목적지까지 우회하지 않고 최단거리로 갈 것이라 확신한다. 

어휴! 듀오가 어디에도 보이지 않는다. 다행히도 당신은 후각이 개만큼 뛰어나다. 
이 후각으로 그들이 g와 h 교차로 사이에 있는 도로를 지나갔다는 것을 알아냈다.

이 듀오는 대체 어디로 가고 있는 것일까?

예제 입력의 두 번째 케이스를 시각화한 것이다. 
이 듀오는 회색 원에서 두 검은 원 중 하나로 가고 있고 점선으로 표시된 도로에서 냄새를 맡았다. 
따라서 그들은 6으로 향하고 있다.
'''

# 오답이유: 최단경로가 여러개일때도 고려해야 함 -> 경로가 여러개라도 '비용'은 동일하다는 걸 잊지말자

''' 못품
[풀이]
출발지점 -> g -> h -> 도착지점 혹은
출발지점 -> h -> g -> 도착지점 이 될 수 있다.
이 두가지의 최단 거리를 구해주고 그 최단거리중 하나가
출발지점 -> 도착지점의 최단거리와 같다면 도착지점을 저장해준다.
'''

from heapq import heappop, heappush
import sys
input = sys.stdin.readline
INF = int(1e9)

T = int(input())


def dijkstra(start):
    q = []
    distance = [INF] * (n + 1)

    # 시작 노드 초기화
    heappush(q, (0, start))
    distance[start] = 0

    while q:  # 큐가 비어있지 않다면
        dist, now = heappop(q)

        if distance[now] < dist:
            continue

        for next, c in graph[now]:
            nc = dist + c
            if nc < distance[next]:
                distance[next] = nc
                heappush(q, (nc, next))

    return distance


# 다익스트라 알고리즘을 수행
answer = [[] for _ in range(T)]
for i in range(T):

    n, m, t = map(int, input().split())  # 정점, 간선 , 목적지 후보 개수
    s, g, h = map(int, input().split())  # s = 출발지

    graph = [[] for _ in range(n + 1)]
    destination = []

    # 지름길 입력받기
    for _ in range(m):
        a, b, d = map(int, input().split())
        graph[a].append((b, d))
        graph[b].append((a, d))

    # 목적지 후보
    for _ in range(t):
        destination.append(int(input()))

    start_ = dijkstra(s)
    h_ = dijkstra(h)
    g_ = dijkstra(g)

    # 가능한 목적지를 공백으로 분리해서 오름차순 출력하기
    # g-h 길을 지나갔는지 탐지하는 코드 **
    for d in destination:
        if start_[g] + g_[h] + h_[d] == start_[d] or start_[h] + h_[g] + g_[d] == start_[d]:
            answer[i].append(d)

    answer[i].sort()

for i in answer:
    for j in i:
        # a는 int이므로 ' '로 바로 결합 안됨!
        print(str(j) + ' ', end='')
    print()
