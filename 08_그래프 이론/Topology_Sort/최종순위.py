# N 명의 팀이 대회에 참가한다
# 올해의 팀과 작년의 팀이 놀랍게도 동일!
# 순위 전체를 공개하는 대신, 작년의 순위와 달라진 경우에 대해서만 알려줌
# 예를들어 작년에 13번팀이 6번팀보다 높은 순위였는데 올해 더 낮아졌다면 (6,13) 이라고 공지
# 작년 정보와 상대적 순위정보만을 갖고 올해 순위를 만들려고 한다
# 만약 확실한 순위를 만들 수 없다면 ?를 출력하고 모순된 데이터가 있는 경우 IMPOSSIBLE 출력

# ========= 사이클이 존재하는 위상정렬 문제 ===========
'''
정해진 우선 순위에 맞게 전체 팀들의 순서를 나열해야한다 = 위상정렬 알고리즘

우선 작년 정보로 토폴리지 완성 시키기 (모든 노드 <-> 모든 노드 - 인접 행렬 활용)
상대우선 순위가 바뀐 화살표만 방향을 바꿔주면 된다

1. ?: 여러 케이스가 존재하는 경우 = 특정 시점에 노드가 큐에 한꺼번에 들어가는 경우
2. IMPOSSIBLE: 사이클이 존재하는 경우 = 노드가 n개가 나오기전에 큐가 빈다면 사이클 존재
3. 정상결과: 오직 하나의 케이스로 나오는 경우

즉 매 시점마다 큐의 원소가 0개이거나 2개인지 체크
'''
# =============================================
from collections import deque

# 테스트 케이스(Test Case)만큼 반복
for tc in range(int(input())):
    # 노드의 개수 입력 받기
    n = int(input())
    # 모든 노드에 대한 진입차수는 0으로 초기화
    indegree = [0] * (n + 1)
    # 각 노드에 연결된 간선 정보를 담기 위한 인접 행렬 초기화
    graph = [[False] * (n + 1) for i in range(n + 1)]

    # 작년 순위 정보 입력
    data = list(map(int, input().split()))
    # 방향 그래프의 간선 정보 초기화
    for i in range(n):
        for j in range(i + 1, n):
            graph[data[i]][data[j]] = True
            indegree[data[j]] += 1

    # 올해 변경된 순위 정보 입력
    m = int(input())
    for i in range(m):
        a, b = map(int, input().split())
        # 간선의 방향 뒤집기
        if graph[a][b]:
            graph[a][b] = False
            graph[b][a] = True
            indegree[a] += 1
            indegree[b] -= 1
        else:
            graph[a][b] = True
            graph[b][a] = False
            indegree[a] -= 1
            indegree[b] += 1

    # 위상 정렬(Topology Sort) 시작
    result = []  # 알고리즘 수행 결과를 담을 리스트
    q = deque()  # 큐 기능을 위한 deque 라이브러리 사용

    # 처음 시작할 때는 진입차수가 0인 노드를 큐에 삽입
    for i in range(1, n + 1):
        if indegree[i] == 0:
            q.append(i)

    certain = True  # 위상 정렬 결과가 오직 하나인지의 여부
    cycle = False  # 그래프 내 사이클이 존재하는지 여부

    # 정확히 노드의 개수만큼 반복
    for i in range(n):
        # 큐가 비어 있다면 사이클이 발생했다는 의미
        if len(q) == 0:
            cycle = True
            break
        # 큐의 원소가 2개 이상이라면 가능한 정렬 결과가 여러 개라는 의미
        if len(q) >= 2:
            certain = False
            break
        # 큐에서 원소 꺼내기
        now = q.popleft()
        result.append(now)
        # 해당 원소와 연결된 노드들의 진입차수에서 1 빼기
        for j in range(1, n + 1):
            if graph[now][j]:
                indegree[j] -= 1
                # 새롭게 진입차수가 0이 되는 노드를 큐에 삽입
                if indegree[j] == 0:
                    q.append(j)

    # 사이클이 발생하는 경우(일관성이 없는 경우)
    if cycle:
        print("IMPOSSIBLE")
    # 위상 정렬 결과가 여러 개인 경우
    elif not certain:
        print("?")
    # 위상 정렬을 수행한 결과 출력
    else:
        for i in result:
            print(i, end=' ')
        print()
