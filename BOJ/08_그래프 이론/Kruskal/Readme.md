# 🌲 크루스칼 알고리즘
> 대표적인 최소(비용) 신장 트리 알고리즘

<br><br>

## 신장 트리 (스패닝 트리)
> 하나의 그래프가 있을 때, 모든 노드를 포함하면서 사이클이 존재하지 않는 부분 그래프

<br>

1. 모든 노드가 포함 & 서로 연결 & 사이클 X = 트리 성립 조건
2. 신장 트리에 포함되는 간선의 개수는 항상 노드 개수 - 1
3. 즉, **가장 거리가 짧은 간선부터 차례로 집합에 추가**하면 최소 비용 보장 => **그리디** 알고리즘
    
    (단, 사이클을 발생시키는 간선은 제외)

<br><br>

## 구현
1. 코드 - ⭐️ **Disjoint Set 활용** ⭐️
    ```python
    # 특정 원소가 속한 집합을 찾기
    def find_parent(parent, x):
        # 루트 노드가 아니라면, 루트 노드를 찾을 때까지 재귀적으로 호출
        if parent[x] != x:
            parent[x] = find_parent(parent, parent[x])
        return parent[x]

    # 두 원소가 속한 집합을 합치기
    def union_parent(parent, a, b):
        a = find_parent(parent, a)
        b = find_parent(parent, b)
        if a < b:
            parent[b] = a
        else:
            parent[a] = b

    # 노드의 개수와 간선(Union 연산)의 개수 입력 받기
    v, e = map(int, input().split())
    parent = [0] * (v + 1) # 부모 테이블 초기화하기

    # 모든 간선을 담을 리스트와, 최종 비용을 담을 변수
    edges = []
    result = 0

    # 부모 테이블상에서, 부모를 자기 자신으로 초기화
    for i in range(1, v + 1):
        parent[i] = i

    # 모든 간선에 대한 정보를 입력 받기
    for _ in range(e):
        a, b, cost = map(int, input().split())
        # 비용순으로 정렬하기 위해서 튜플의 첫 번째 원소를 비용으로 설정
        edges.append((cost, a, b))

    # 간선을 비용순으로 정렬
    edges.sort()

    # 간선을 하나씩 확인하며
    for edge in edges:
        cost, a, b = edge
        # 사이클이 발생하지 않는 경우에만 집합에 포함
        if find_parent(parent, a) != find_parent(parent, b):
            union_parent(parent, a, b)
            result += cost # 각 간선의 총 합이 최종 비용

    print(result)
    ```
2. 시간 복잡도
- 간선 개수가 E일때, **O(ElogE)**
- **정렬** 작업이 가장 오래걸리기 때문
- **서로소 집합 연산**은 상대적으로 작아서 무시