# 🕸️ DFS/BFS
> 그래프를 탐색하기 위한 대표적인 알고리즘

<br/><br/>

## 그 전에 알아야 할 자료구조 기초!
1. **탐색** = 많은 양의 데이터 중에서 원하는 데이터를 찾는 과정
2. **자료구조** = 데이터를 표현하고 관리하고 처리하기 위한 구조 
- 기본적인 자료구조 => 스택,큐
- 삽입/삭제 시 언더플로와 오버플로 주의
    ```python
    import sys
    sys.setrecursionlimit(5000) # 제한 풀기 가능하나 추천 x
    ```
3. **📦 스택**
- 선입후출 구조 (박스쌓기 구조)
- 파이썬의 경우 리스트 자체의 append(),pop()로 기능 구현 
- 순서 뒤집기 => list[::-1]
4. **🚶🏻‍♀️🚶🏻 큐**
- 선입선출 구조 (대기줄 구조)
- collections 라이브러리의 deque로 구현
- deque의 append()와 popleft()로 기능 구현
- 순서 뒤집기 => queue.reversed()
- 리스트로 변경 => list(queue)
5. **♻️ 재귀함수**
- 자기 자신을 다시 호출하는 함수
- 파이썬 인터프리터는 호출 횟수에 제한이 있으므로 재귀의 최대깊이를 벗어나지 않도록 해야함
- 종료 조건을 명시하지 않으면 무한히 호출될 수 있으니 주의
- 재귀함수는 내부적으로 스택 자료구조와 동일(컴퓨터 구조) 
- 즉, 스택을 활용하는 상당수의 알고리즘은 재귀함수를 통해 간편하게 구현 가능
- 팩토리얼 예시
    ```python
    # 반복적 팩토리얼
    def factorial_1(n):
        result = 1
        for i in range(1,n+1):
            result *= 1
        return result

    # 재귀적 팩토리얼
    def factorial_2(n):
        if n <= 1: return 1 # 종료 조건
        return n * factorial_2(n-1)
    ```

<br/><br/>

## 📈 그래프 
1. **노드(= 정점)와 간선**으로 표현
2. 두 노드가 간선으로 연결되어 있다면 <b>'인접하다'</b>라고 표현
3. **그래프 표현 방법 2가지**
- 인접 행렬: 2차원 배열로 그래프의 연결관계 표현
    - 파이썬의 2차원 배열로 구현
    - 연결되지 않은 노드끼리는 무한(INF = 999999999 or 987654321) 비용으로 간주
    ```python
    INF = 987654321

    graph = [
        [0,7,5],
        [7,0,INF],
        [5,INF,0]
    ]
    ```
- 인접 리스트: 리스트로 그래프의 연결관계 표현
    - 파이썬의 경우 이것도 2차원 배열로 구현 가능 - 리스트의 append
    ```python
    graph = [[] for _ in range(3)]

    # 노드 0에 연결된 노드 정보 저장 (노드, 거리)
    graph[0].append((1,7))
    graph[0].append((2,5))

    # 노드 1에 연결된 노드 정보 저장 (노드, 거리)
    graph[1].append((0,8))
    ```
4. **인접 행렬 vs 인접 리스트**
    |  | 장점 | 단점 | 
    | ----- | ----- | -----|
    행렬| 연결 정보 접근 속도 ⬆ | 모든 관계를 저장하므로 노드 개수가 많을수록 메모리 ⬆ |
    리스트| 연결된 정보만 저장하므로 메모리 ⬇ | 연결 정보 접근 속도 ⬇ |
5. **2차원 배열에서의 탐색 문제**: 그래프 형태로 바꿔서 생각하면 풀이 방법을 쉽게 떠올릴 수 있음!

<br/><br/>

## ↕️ DFS (Depth-First Search)
> 깊이 우선 탐색으로, 그래프에서 깊은 부분을 우선적으로 탐색하는 스택 기반 알고리즘

> 스택 오버플로우 신경쓰기! 너무 깊어질 것 같으면(1000 이상) bfs 사용!! 

<br/>

### 동작 과정
1. 탐색 시작 노드를 스택에 삽입 후 방문 처리
2. 스택의 최상단 노드에 방문하지 않은 인접 노드(들)가 있다면 그 인접 노드(번호가 가장 낮은 하나)를 스택에 넣고 방문 처리
3. 방문하지 않은 인접 노드가 없다면 스택에서 최상단 노드를 꺼낸다
3. 2번 과정을 더 이상 수행할 수 없을 떄까지 반복
```python
def dfs(graph, v, visited):
    # 현재 노드를 방문 처리
    visited[v] = True
    print(v, end=' ')
    # 현재 노드와 연결된 다른 노드를 재귀적으로 방문
    for i in graph[v]:
        if not visited[i]:
            dfs(graph, i, visited)

# 각 노드가 연결된 정보를 리스트 자료형으로 표현(2차원 리스트)
graph = [
  [],
  [2, 3, 8],
  [1, 7],
  [1, 4, 5],
  [3, 5],
  [3, 4],
  [7],
  [2, 6, 8],
  [1, 7]
]

# 각 노드가 방문된 정보를 리스트 자료형으로 표현(1차원 리스트)
visited = [False] * 9

# 정의된 DFS 함수 호출
dfs(graph, 1, visited)
```

### 특징
1. 데이터 개수가 N인 경우 탐색에 **O(N)** 시간 소요
2. 스택 기반 -> 실제 구현은 **재귀 함수**로 쉽게 구현 가능

<br/><br/>

## ↔️ BFS (Breadth-First Search)
> 너비 우선 탐색으로, 가까운 노드부터 탐색하는 큐 기반 알고리즘

<br/>

### 동작 과정
1. 탐색 시작 노드를 큐에 삽입하고 방문 처리
2. 큐에서 노드를 꺼내 해당 노드의 인접 노드 중에서 방문하지 않은 노드를 모두 큐에 삽입하고 방문 처리
3. 2번의 과정을 더 이상 수행할 수 없을 떄까지 반복
```python
from collections import deque

# BFS 함수 정의
def bfs(graph, start, visited):
    # 큐(Queue) 구현을 위해 deque 라이브러리 사용
    queue = deque([start])
    # 현재 노드를 방문 처리
    visited[start] = True
    # 큐가 빌 때까지 반복
    while queue:
        # 큐에서 하나의 원소를 뽑아 출력
        v = queue.popleft()
        print(v, end=' ')
        # 해당 원소와 연결된, 아직 방문하지 않은 원소들을 큐에 삽입
        for i in graph[v]:
            if not visited[i]:
                queue.append(i)
                visited[i] = True

# 각 노드가 연결된 정보를 리스트 자료형으로 표현(2차원 리스트)
graph = [
  [],
  [2, 3, 8],
  [1, 7],
  [1, 4, 5],
  [3, 5],
  [3, 4],
  [7],
  [2, 6, 8],
  [1, 7]
]

# 각 노드가 방문된 정보를 리스트 자료형으로 표현(1차원 리스트)
visited = [False] * 9

# 정의된 BFS 함수 호출
bfs(graph, 1, visited)
```

### 특징
1. 데이터 개수가 N인 경우 탐색에 **O(N)** 시간 소요
2. 다만, 일반적으로 **실제 수행시간은 DFS보다 좋은 편!!**
2. 큐 기반 -> **deque**로 구현 가능

<br><br>

## DFS를 활용한 순열/조합 -> 실전에서는 표준 라이브러리 사용
1. 순열 - 한 개의 리스트에서 모든 순열을 구하기
    ```python
    arr = ['a', 'b', 'c']
    n = len(arr)
    visited = [0] * n
    permute = []

    def dfs(cnt, li):
        if cnt == n:
            permute.append(li[:])
            return

        for i, val in enumerate(arr):
            # 만약 방문했다면 건너 뛰기(순열을 위함)
            if visited[i] == 1: continue

            # 현재까지의 list에 값을 추가하고, 방문 표시하기
            li.append(val)
            visited[i] = 1

            dfs(cnt+1, li)

            # 방금 전 list에 추가한 값과 방문 한 것을 되돌려주기
            li.pop()
            visited[i] = 0


    dfs(0, [])
    print(permute)
    ```
2. 조합 - 한 개의 리스트에서 r개의 조합 구하기
    ```python
    arr = ['a', 'b', 'c', 'd']
    n = len(arr)
    r = 2
    combi = []

    def dfs(cnt, li):
        if len(li) == r:
            combi.append(li[:])
            return

        for i in range(cnt, n):
            dfs(i + 1, li + [arr[i]])

    dfs(0, [])
    print(combi)
    ```

<br><br>

## 🔙 백트래킹
> 길을 가다가 이 길이 아닌 것 같으면 왔던 길로 되돌아가 다른 경로로 진행하는 알고리즘

<br>


1. 보통 재귀로 구현하며 조건이 맞지 않으면 종료
2. **DFS 기반** - 다만, DFS와 달리 모든 경우의 수를 탐색하지 X
3. DFS를 사용하여 만약 조건에 맞지 않으면 그 즉시 중단하고 이전으로 돌아가며 다시 확인하는 것을 반복하면서 원하는 조건 찾기
4. **Promising**: 해당 루트가 조건에 맞는지를 검사하는 기법
5. **Pruning** (가지치기): 조건에 맞지 않으면 포기하고 다른 루트로 바로 돌아서서, 탐색의 시간을 절약하는 기법
