# 🧭 최단 경로
> 가장 짧은 경로를 찾는 알고리즘

<br>

1. 최단 경로 문제는 보통 그래프로 표현
2. 각 지점은 노드, 도로는 간선으로 표현
3. 실제 코테에서는 경로 보다는 **최단 거리만 출력**하도록 하므로 경로는 우선 패스
4. **최소 비용 문제 = 최단 경로 문제**
5. 둘 다 사용 가능한 문제 -> 노드의 개수가 적은 경우 플로이드 & 노드와 간선의 개수가 많으면 다익스트라

<br><br>

## ↪️ 다익스트라
> 한 지점에서 다른 특정 지점까지의 최단 경로 구하기

<br>

1. 일종의 **그리디** 알고리즘 => 매번 가장 비용이 적은 노드를 선택 & 갱신
2. **음의 간선**이 없을 때 사용 가능
3. 실제 GPS 소프트웨어 기본 알고리즘!
4. **동작 과정 요약**
    1. 출발 노드 설정 & 거리 = 0
    2. 최단 거리 테이블 무한으로 모두 초기화 
    3. 방문하지 않은 노드 중에서 최단 거리가 가장 짧은 노드 선택
        - 이때 선택된 노드는 최단 거리가 확정됨!
        - 즉, 한 단계당 하나의 노드에 대한 최단거리를 확실히 찾음
    4. 해당 노드를 거쳐 다른 노드로 가는 비용을 계산하여 최단 거리 테이블 갱신
    5. 3-4번 반복
5. **간단한 다익스트라 코드** - 쉽지만 느림 **O(V^2)** (이때 V는 노드 개수)
- 느리기 때문에 노드 개수가 10000개만 넘어가도 사용하기 어려움
- 무한: 1e9를 기본적으로 실수로 처리하므로 int(1e9) 해주기
- 입력: 입력이 많을 경우 sys.stdin.readline 사용
- 초기화: n+1개로 초기화 해서 노드의 번호를 인덱스로 바로 접근하게 하기
    ```python
    import sys
    input = sys.stdin.readline
    INF = int(1e9) 

    # 노드의 개수, 간선의 개수를 입력받기
    n, m = map(int, input().split())
    # 시작 노드 번호를 입력받기
    start = int(input())
    # 각 노드에 연결되어 있는 노드에 대한 정보를 담는 리스트를 만들기
    graph = [[] for i in range(n + 1)]
    # 방문한 적이 있는지 체크하는 목적의 리스트를 만들기
    visited = [False] * (n + 1)
    # 최단 거리 테이블을 모두 무한으로 초기화
    distance = [INF] * (n + 1)

    # 모든 간선 정보를 입력받기 -> 인접 리스트
    for _ in range(m):
        a, b, c = map(int, input().split())
        # a번 노드에서 b번 노드로 가는 비용이 c라는 의미
        graph[a].append((b, c))

    # 방문하지 않은 노드 중에서, 가장 최단 거리가 짧은 노드의 번호를 반환
    def get_smallest_node():
        min_value = INF
        index = 0 # 가장 최단 거리가 짧은 노드(인덱스)
        for i in range(1, n + 1):
            if distance[i] < min_value and not visited[i]:
                min_value = distance[i]
                index = i
        return index

    def dijkstra(start):
        # 시작 노드에 대해서 초기화
        distance[start] = 0
        visited[start] = True
        for j in graph[start]:
            distance[j[0]] = j[1]
        # 시작 노드를 제외한 전체 n - 1개의 노드에 대해 반복
        for i in range(n - 1):
            # 현재 최단 거리가 가장 짧은 노드를 꺼내서, 방문 처리
            now = get_smallest_node()
            visited[now] = True
            # 현재 노드와 연결된 다른 노드를 확인
            for j in graph[now]:
                cost = distance[now] + j[1]
                # 현재 노드를 거쳐서 다른 노드로 이동하는 거리가 더 짧은 경우
                if cost < distance[j[0]]:
                    distance[j[0]] = cost

    # 다익스트라 알고리즘을 수행
    dijkstra(start)
    ```
6. **개선된 다익스트라 코드** - 좀 더 까다롭지만 빠름 **O(ElogV)** (E는 간선)
- **이거 사용!!! 무조건 암기!!!**
- 1차원 distance 배열 + 우선순위 큐 사용
- heapq는 기본적으로 최소힙 -> 그대로 사용하면 됨
- 시간 복잡도 계산
    - 힙의 삽입/삭제 모두 O(logN) -> N개의 노드를 모두 꺼냈다 빼기 O(NlogN)
    - 최대 E만큼의 노드가 삽입됨 -> O(ElogE)
    - 항상 E <= V^2 
    - 즉, O(ElogV^2) = O(2ElogV) = O(ElogV)
- (거리, 노드) -> 우선순위 기준이 될 항목을 앞쪽에 배치
- 최단경로 문제 이외에도 두루 적용되는 소스 코드 형태니 잘 봐두자 ex) 최소 신장 트리 - 프림 알고리즘
    ```python
    from heapq import heappop, heappush
    # 나머지는 위 코드와 동일 
    # 단, get_smallest_node 함수 불필요 & visited 배열 불필요

    def dijkstra(start):
        q = []
        # 시작 노드로 가기 위한 최단 경로는 0으로 설정하여, 큐에 삽입
        heappush(q, (0, start))
        distance[start] = 0
        while q: # 큐가 비어있지 않다면
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
    ```

<br><br>

## 🔀 플로이드 워셜
> 모든 지점에서 다른 모든 지점까지의 최단 경로 구하기

<br>

1. 일종의 **DP** 알고리즘 
- 점화식에 맞게 리스트 최단 거리 리스트 갱신
- **DPab = min(DPab, DPak + Dkb)**
- 즉, A에서 B로 바로 가는 거리와 K 노드를 거쳐서 가는 거리 중 더 짧은 것을 선택
- **DPab**는 A에서 B까지 가는 최단 거리를 의미
- **DPii**(대각선)는 처음에 모두 0으로 초기화, 나머지 칸은 무한으로 초기화
2. 다익스트라에 비해 소스 코드가 비교적 짧아서 구현 쉬움 - 핵심 원리를 잘 이해하자!
3. **2차원 리스트**에 최단거리 정보를 담음
4. N개의 노드에 대해 N^2(2차원배열)의 계산 = **O(N^3)**
    ```python
    INF = int(1e9) # 무한을 의미하는 값으로 10억을 설정

    # 노드의 개수 및 간선의 개수를 입력받기
    n = int(input())
    m = int(input())
    # 2차원 리스트(그래프 표현)를 만들고, 모든 값을 무한으로 초기화
    graph = [[INF] * (n + 1) for _ in range(n + 1)]

    # 자기 자신에서 자기 자신으로 가는 비용은 0으로 초기화 
    for a in range(1, n + 1):
        for b in range(1, n + 1):
            if a == b:
                graph[a][b] = 0

    # 각 간선에 대한 정보를 입력 받아, 그 값으로 초기화 -> 인접 행렬
    for _ in range(m):
        # A에서 B로 가는 비용은 C라고 설정
        a, b, c = map(int, input().split())
        graph[a][b] = c

    # 점화식에 따라 플로이드 워셜 알고리즘을 수행  --- 사실상 이 부분만 외우면 됨
    for k in range(1, n + 1):
        for a in range(1, n + 1):
            for b in range(1, n + 1):
                graph[a][b] = min(graph[a][b], graph[a][k] + graph[k][b])

    ```