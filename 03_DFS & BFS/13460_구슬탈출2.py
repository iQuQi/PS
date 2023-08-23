''' [못품] BFS 문제
스타트링크에서 판매하는 어린이용 장난감 중에서 가장 인기가 많은 제품은 구슬 탈출이다. 
구슬 탈출은 직사각형 보드에 빨간 구슬과 파란 구슬을 하나씩 넣은 다음, 
빨간 구슬을 구멍을 통해 빼내는 게임이다.

보드의 세로 크기는 N, 가로 크기는 M이고, 편의상 1×1크기의 칸으로 나누어져 있다. 
가장 바깥 행과 열은 모두 막혀져 있고, 보드에는 구멍이 하나 있다. 
빨간 구슬과 파란 구슬의 크기는 보드에서 1×1크기의 칸을 가득 채우는 사이즈이고, 
각각 하나씩 들어가 있다. 게임의 목표는 빨간 구슬을 구멍을 통해서 빼내는 것이다. 
이때, 파란 구슬이 구멍에 들어가면 안 된다.

이때, 구슬을 손으로 건드릴 수는 없고, 중력을 이용해서 이리 저리 굴려야 한다. 
왼쪽으로 기울이기, 오른쪽으로 기울이기, 위쪽으로 기울이기, 아래쪽으로 기울이기와 같은 네 가지 동작이 가능하다.

각각의 동작에서 공은 동시에 움직인다. 빨간 구슬이 구멍에 빠지면 성공이지만, 
파란 구슬이 구멍에 빠지면 실패이다. 빨간 구슬과 파란 구슬이 동시에 구멍에 빠져도 실패이다.
빨간 구슬과 파란 구슬은 동시에 같은 칸에 있을 수 없다. 
또, 빨간 구슬과 파란 구슬의 크기는 한 칸을 모두 차지한다. 
기울이는 동작을 그만하는 것은 더 이상 구슬이 움직이지 않을 때 까지이다.

보드의 상태가 주어졌을 때, 최소 몇 번 만에 빨간 구슬을 구멍을 통해 빼낼 수 있는지 구하는 프로그램을 작성하시오.
'''

from collections import deque


def init():
    rx, ry, bx, by = 0, 0, 0, 0
    for i in range(n):
        for j in range(m):
            if graph[i][j] == 'R':
                rx, ry = i, j
            elif graph[i][j] == 'B':
                bx, by = i, j
    q.append((rx, ry, bx, by, 1))
    visited[rx][ry][bx][by] = True


def move(x, y, dx, dy):
    c = 0
    while graph[x + dx][y + dy] != '#' and graph[x][y] != 'O':
        x += dx
        y += dy
        c += 1
    return x, y, c


def bfs():
    while q:
        crx, cry, cbx, cby, cnt = q.popleft()
        if cnt > 10:
            break
        for i in range(4):
            nrx, nry, rc = move(crx, cry, *d[i])  # 빨간 구슬 굴려
            nbx, nby, bc = move(cbx, cby, *d[i])  # 파란 구슬 굴려
            if graph[nbx][nby] != 'O':  # 파란 구슬이 구멍에 빠지지 않은 경우만 확인
                if graph[nrx][nry] == 'O':  # 빨간 구슬 빠지면 성공
                    print(cnt)
                    return
                if nrx == nbx and nry == nby:  # 빨간 구슬, 파란 구슬이 같은 위치에 있다면
                    if rc > bc:  # [움직인 거리가 더 긴 것을 한 칸 전으로 옮김]
                        nrx -= d[i][0]
                        nry -= d[i][1]
                    else:
                        nbx -= d[i][0]
                        nby -= d[i][1]
                if not visited[nrx][nry][nbx][nby]:
                    visited[nrx][nry][nbx][nby] = True  # visited 4차원 배열 주목
                    q.append((nrx, nry, nbx, nby, cnt + 1))
    print(-1)  # 결국 빨간 구슬 구멍에 못 넣었으면 실패


d = [(-1, 0), (1, 0), (0, 1), (0, -1)]
q = deque()
n, m = map(int, input().split())
graph = [list(input()) for _ in range(n)]
visited = [[[[False] * m for _ in range(n)]
            for _ in range(m)] for _ in range(n)]

init()
bfs()
