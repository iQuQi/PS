# 💡 다양한 그래프 알고리즘

1. DFS/BFS와 최단 경로 모두 그래프 알고리즘의 한 유형
2. 이외에도 다양한 그래프 알고리즘 존재(출제 빈도 ⬇️, but 알아두기) 
- [서로소 집합](#-서로소-집합) (Disjoint Set)
- [크루스칼](#-크루스칼-알고리즘)
- [위상정렬](#-위상-정렬) (Topology Sort)
3. "서로 다른 개체가 연결되어 있다" => 그래프 알고리즘 떠올리기
4. 그래프 vs 트리( = 그래프 자료구조의 일부)

    | |  그래프  |  트리 
    | - | ----| ----|
    방향성| 방향 혹은 무방향 | 방향 (일반적인 수학에서는 무방향으로 간주)
    순환성 | 순환 및 비순환 | 비순환
    루트 노드 존재 여부| 없음 | 있음
    부모자식 관계 | 없음 | 있음
    모델의 종류 | 네트워크 모델 | 계층 모델


<br><br>
<br><br>

# 👨‍👩‍👦‍👦 서로소 집합
> 공통 원소가 없는 두 집합

<br>

## 🔎 서로소 집합 자료구조

1. **UNION**과 **FIND** 연산으로 이루어짐
- union: 2개의 원소가 포함된 집합을 하나의 집합으로 합치는 '합집합' 연산
- find: 특정 원소가 속한 집합이 어떤 집합인지 알려주는 연산
2. **트리구조**를 사용해서 집합 표현
3. 일반적으로 **더 번호가 작은 원소가 부모 노드**가 됨
4. 코드 - ⭐️ **find의 [경로 압축] 개선 확인** ⭐️
    ```python
    # 특정 원소가 속한 집합을 찾기
    def find_parent(parent, x):
        # 루트 노드가 아니라면, 루트 노드를 찾을 때까지 재귀적으로 호출

        # 개선 전 버전 - O(VM), V는 노드개수 M은 연산수
            # if parent[x] != x:
            #    return find_parent(parent, parent[x]
            # return x

        # 개선 후 버전 -> 경로 압축 (Path Compression) - 대략 O(V+MlogV)
        if parent[x] != x:
            parent[x] = find_parent(parent, parent[x])
        return parent[x]

    # 두 원소가 속한 집합을 합치기
    def union_parent(parent, a, b):
        p_a = find_parent(parent, a)
        p_b = find_parent(parent, b)
        if p_a < p_b:
            parent[p_b] = p_a
        else:
            parent[p_a] = p_b

    # 노드의 개수와 간선(Union 연산)의 개수 입력 받기
    v, e = map(int, input().split())
    parent = [0] * (v + 1) # 부모 테이블 초기화하기

    # 부모 테이블상에서, 부모를 자기 자신으로 초기화
    for i in range(1, v + 1):
        parent[i] = i

    # Union 연산을 각각 수행
    for i in range(e):
        a, b = map(int, input().split())
        union_parent(parent, a, b)

    # 각 원소가 속한 집합 출력하기
    print('각 원소가 속한 집합: ', end='')
    for i in range(1, v + 1):
        print(find_parent(parent, i), end=' ')

    print()

    # 부모 테이블 내용 출력하기
    print('부모 테이블: ', end='')
    for i in range(1, v + 1):
        print(parent[i], end=' ')
    ```

<br>

## 🔄 사이클 판별

1. **무방향** 그래프에서만 적용 가능 
2. **방향** 그래프의 사이클 판별은 **dfs**로 가능하나 다루지 않음
3. **동작과정**
- 그래프에 포함되어 있는 모든 간선에 대해 union & find 
- 루트 노드가 서로 같다면 사이클 발생
4. 코드
    ```python
    # find/union,입력/초기화는 위 코드와 동일

    cycle = False # 사이클 발생 여부

    for i in range(e): # 모든 간선에 대해
        a, b = map(int, input().split())
        # 사이클이 발생한 경우 종료
        if find_parent(parent, a) == find_parent(parent, b):
            cycle = True
            break
        # 사이클이 발생하지 않았다면 합집합(Union) 연산 수행
        else:
            union_parent(parent, a, b)

    if cycle:
        print("사이클이 발생했습니다.")
    else:
        print("사이클이 발생하지 않았습니다.")
    ```

<br><br>
<br><br>

# 🌲 크루스칼 알고리즘
> 대표적인 최소(비용) 신장 트리 알고리즘

<br>

## 신장 트리 (스패닝 트리)
> 하나의 그래프가 있을 때, 모든 노드를 포함하면서 사이클이 존재하지 않는 부분 그래프

<br>

1. 모든 노드가 포함 & 서로 연결 & 사이클 X = 트리 성립 조건
2. 신장 트리에 포함되는 간선의 개수는 항상 노드 개수 - 1
3. 즉, **가장 거리가 짧은 간선부터 차례로 집합에 추가**하면 최소 비용 보장 => **그리디** 알고리즘
    
    (단, 사이클을 발생시키는 간선은 제외)

<br>

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

<br><br>
<br><br>

# 📚 위상 정렬
> 방향 그래프의 모든 노드를 '방향성에 거스르지 않도록 순서대로 나열'하는 알고리즘

<br>

1. **대표적인 문제**: 선수과목을 고려한 학습 순서 결정
2. **진입차수** = 특정 노드로 들어오는 간선의 개수
3. **동작 과정**
- 진입 차수가 0인 노드를 큐에 넣는다
- 큐가 빌 때까지 다음 과정 반복
    - 큐에서 원소를 꺼내서 해당 노드에서 출발하는 간선을 그래프에서 제거
    - 새롭게 진입차수가 0이 된 노드를 큐에 넣는다
4. **사이클**
- 모든 원소를 방문하기 전 큐가 빈다면 사이클 존재
- 사이클이 존재하는 경우, 사이클이 포함되어 있는 원소 중 어떠한 원소도 큐에 들어가지 못하기 때문
- 기본적으로 위상 정렬 문제는 사이클을 잘 다루지 않긴함
5. **코드**
    ```python
    from collections import deque

    # 노드의 개수와 간선의 개수를 입력 받기
    v, e = map(int, input().split())
    # 모든 노드에 대한 진입차수는 0으로 초기화
    indegree = [0] * (v + 1)
    # 각 노드에 연결된 간선 정보를 담기 위한 연결 리스트 초기화
    graph = [[] for i in range(v + 1)]

    # 방향 그래프의 모든 간선 정보를 입력 받기
    for _ in range(e):
        a, b = map(int, input().split())
        graph[a].append(b) # 정점 A에서 B로 이동 가능
        # 진입 차수를 1 증가
        indegree[b] += 1

    # 위상 정렬 함수
    def topology_sort():
        result = [] # 알고리즘 수행 결과를 담을 리스트
        q = deque() # 큐 기능을 위한 deque 라이브러리 사용

        # 처음 시작할 때는 진입차수가 0인 노드를 큐에 삽입
        for i in range(1, v + 1):
            if indegree[i] == 0:
                q.append(i)

        # 큐가 빌 때까지 반복
        while q:
            # 큐에서 원소 꺼내기
            now = q.popleft()
            result.append(now)
            # 해당 원소와 연결된 노드들의 진입차수에서 1 빼기
            for i in graph[now]:
                indegree[i] -= 1
                # 새롭게 진입차수가 0이 되는 노드를 큐에 삽입
                if indegree[i] == 0:
                    q.append(i)

        # 위상 정렬을 수행한 결과 출력
        for i in result:
            print(i, end=' ')

    topology_sort()
    ```
6. 큐에서 **빠져나간 순서대로** 출력하면 위상 정렬 결과 -> **여러가지** 답이 존재할 수 있음
7. 시간 복잡도 - **O(V+E)** (차례대로 모든 노드를 확인하면 그 노드에서 출발하는 간선을 삭제)

<br><br>
