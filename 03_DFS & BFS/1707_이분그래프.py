'''_
그래프의 정점의 집합을 둘로 분할하여, 
각 집합에 속한 정점끼리는 서로 인접하지 않도록 분할할 수 있을 때, 
그러한 그래프를 특별히 이분 그래프 (Bipartite Graph) 라 부른다.

그래프가 입력으로 주어졌을 때,
이 그래프가 이분 그래프인지 아닌지 판별하는 프로그램을 작성하시오

아이디어: 그래프의 정점을 두가지 색으로 칠할 때, 인접한 정점끼리는 다른 색을 가지고 있는 그래프

틀린이유: 사이클이 있으면 이분그래프가 아니라고 생각함 -> 사이클이 존재해도 위 조건만 만족하면 가능
'''
import sys

sys.setrecursionlimit(20000)
input = sys.stdin.readline


def dfs(start, group):
    global error

    # 만약 사이클이 true라면 재귀탈출
    if error:
        return

    visited[start] = group  # 해당 그룹으로 등록

    for i in graph[start]:
        if not visited[i]:
            dfs(i, -group)  # 다른 그룹으로 설정
        elif visited[start] == visited[i]:  # 인접한데 같은 그룹이라면
            error = True  # 에러값 True
            return  # 그후 재귀 리턴


T = int(input())

for _ in range(T):
    V, E = map(int, input().split())
    graph = [[] for _ in range(V + 1)]  # 빈 그래프 생성
    visited = [False] * (V + 1)  # 방문한 정점 체크
    error = False

    for _ in range(E):
        a, b = map(int, input().split())
        graph[a].append(b)
        graph[b].append(a)

    for i in range(1, V + 1):
        if not visited[i]:  # 만약 아직 방문하지 않았다면
            dfs(i, 1)  # dfs를 돈다.
            if error:  # 만약 에러가 참이라면
                break  # 탈출

    if error:
        print('NO')
    else:
        print('YES')
