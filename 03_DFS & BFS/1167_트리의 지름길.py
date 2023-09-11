'''
트리의 지름이란, 트리에서 임의의 두 점 사이의 거리 중 가장 긴 것을 말한다. 
트리의 지름을 구하는 프로그램을 작성하시오.
'''

'''
[다른 풀이]
- 트리에서 아무 노드나 잡고 그 노드에 대한 가장 먼 노드를 구하고 이 노드를 n1이라고 하자.
- n1 에대한 가장 먼 노드를 한번 더 구한다. 이 노드를 n2라고 하자.
- 이제 n1과 n2 사이의 거리가 트리의 지름이 된다.

증명: https://koosaga.com/14
'''

import sys
input = sys.stdin.readline


def dfs(now, graph, visited):
    global save
    visited[now] = True
    isEnd = True

    for v, dist in graph[now]:
        if not visited[v]:
            # 팁: max(seasons, key=len) 이런식으로 min max에 정렬 키 설정 가능
            save[now].append(dfs(v, graph, visited) + dist)
            isEnd = False

    # 말단 도착
    if isEnd:
        return 0
    return max(save[now])


v = int(input())  # (2 ≤ V ≤ 100,000)
graph = [[] for _ in range(v + 1)]
visited = [False for _ in range(v + 1)]
save = [[] for _ in range(v + 1)]

for _ in range(v):
    info = list(map(int, input().split()))  # 주어지는 거리 <= 10000
    for i in range(1, len(info) - 1, 2):
        graph[info[0]].append((info[i], info[i + 1]))

dfs(1, graph, visited)

for idx, i in enumerate(save):
    i.sort(reverse=True)  # 오답이유... reverse 안함ㅠ

    if len(i) == 0:
        save[idx] = 0
    elif len(i) == 1:
        save[idx] = i[0]
    else:
        save[idx] = i[0] + i[1]

print(max(save))
