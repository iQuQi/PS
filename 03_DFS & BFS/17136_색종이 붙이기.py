'''
<그림 1>과 같이 정사각형 모양을 한 다섯 종류의 색종이가 있다. 
색종이의 크기는 1×1, 2×2, 3×3, 4×4, 5×5로 총 다섯 종류가 있으며, 각 종류의 색종이는 5개씩 가지고 있다.

<그림 1>

색종이를 크기가 10×10인 종이 위에 붙이려고 한다. 종이는 1×1 크기의 칸으로 나누어져 있으며, 
각각의 칸에는 0 또는 1이 적혀 있다. 1이 적힌 칸은 모두 색종이로 덮여져야 한다. 
색종이를 붙일 때는 종이의 경계 밖으로 나가서는 안되고, 겹쳐도 안 된다. 
또, 칸의 경계와 일치하게 붙여야 한다. 0이 적힌 칸에는 색종이가 있으면 안 된다.

종이가 주어졌을 때, 1이 적힌 모든 칸을 붙이는데 필요한 색종이의 최소 개수를 구해보자.
'''

import sys
input = sys.stdin.readline
paper = [[] for i in range(10)]
INF = 1e9
min_color = INF
total_color = 0
remain = [5] * 6

# 입력 받기 & 색종이가 올라갈 칸수 세기
for i in range(10):
    paper[i] = list(map(int, input().split()))
    for p in paper[i]:
        if p == 1:
            total_color += 1

# 백트래킹 체크 함수


def possible(t, graph, y, x):
    for i in range(t):
        for j in range(t):
            if y+i >= 10 or x+j >= 10:
                return False
            if graph[y+i][x+j] == 0:
                return False
    return True


def endCheck(color_count, color_1):
    global min_color
    if total_color == color_1:
        min_color = min(min_color, color_count)

# DFS


def dfs(graph, start, color_count, color_1):
    y, x = start
    endCheck(color_count, color_1)

    if graph[y][x] == 0:
        if x+1 < 10:
            dfs(graph, (y, x+1), color_count, color_1)
        elif y+1 < 10:
            dfs(graph, (y+1, 0), color_count, color_1)
        else:
            endCheck(color_count, color_1)

    elif graph[y][x] == 1:
        for t in range(5, 0, -1):
            if remain[t] == 0:
                continue
            if not possible(t, graph, y, x):
                continue
            remain[t] -= 1
            # 색종이를 붙이기
            for i in range(t):
                for j in range(t):
                    graph[y+i][x+j] = 0

            # 다음칸으로 이동
            if x+1 < 10:
                dfs(graph, (y, x+1), color_count + 1, color_1 + t*t)
            elif y+1 < 10:
                dfs(graph, (y+1, 0), color_count + 1, color_1 + t*t)
            else:
                endCheck(color_count+1, color_1+t*t)

            remain[t] += 1
            # 색종이 다시 떼기
            for i in range(t):
                for j in range(t):
                    graph[y+i][x+j] = 1


dfs(paper, (0, 0), 0, 0)
if min_color == INF:
    print(-1)
else:
    print(min_color)
