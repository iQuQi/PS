'''
도현이는 우주의 신이다. 이제 도현이는 아무렇게나 널브러져 있는 n개의 별들을 이어서 
별자리를 하나 만들 것이다. 별자리의 조건은 다음과 같다.

별자리를 이루는 선은 서로 다른 두 별을 일직선으로 이은 형태이다.
모든 별들은 별자리 위의 선을 통해 서로 직/간접적으로 이어져 있어야 한다.
별들이 2차원 평면 위에 놓여 있다. 선을 하나 이을 때마다 두 별 사이의 거리만큼의 
비용이 든다고 할 때, 별자리를 만드는 최소 비용을 구하시오.
'''
import sys
import math
input = sys.stdin.readline
INF = int(1e9)


def find_parent(parent, x):
    if parent[x] != x:  # 루트 노드가 아닐경우
        parent[x] = find_parent(parent, parent[x])
    return parent[x]


def union_parent(parent, a, b):
    pa = find_parent(parent, a)
    pb = find_parent(parent, b)

    if pa > pb:
        parent[pb] = pa
    elif pb > pa:
        parent[pa] = pb


n = int(input())
parent = [i for i in range(n)]
star = []
cost = [[INF]*n for _ in range(n)]
edges = []

for i in range(n):
    x, y = map(float, input().split())
    star.append((x, y))


# n개의 별 -> n개의 별로 가는 모든 edges에 대한 계산해주기
for i in range(n):
    for j in range(n):
        if i == j:
            continue

        if cost[j][i] != INF:
            cost[i][j] = cost[j][i]

        else:
            x1, y1 = star[i]
            x2, y2 = star[j]
            cost[i][j] = math.sqrt(abs(x1-x2)**2 + abs(y1-y2)**2)

for i in range(n):
    for j in range(n):
        if i == j:
            continue
        if (cost[j][i], j, i) not in edges:
            edges.append((cost[i][j], i, j))

edges.sort()
total = 0

for c, s1, s2 in edges:
    if find_parent(parent, s1) != find_parent(parent, s2):
        union_parent(parent, s1, s2)
        total += c

print(round(total, 2))
