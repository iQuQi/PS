'''
미세먼지를 제거하기 위해 구사과는 공기청정기를 설치하려고 한다. 공기청정기의 성능을 테스트하기 위해 구사과는 집을 크기가 R×C인 격자판으로 나타냈고, 1×1 크기의 칸으로 나눴다. 구사과는 뛰어난 코딩 실력을 이용해 각 칸 (r, c)에 있는 미세먼지의 양을 실시간으로 모니터링하는 시스템을 개발했다. (r, c)는 r행 c열을 의미한다.

공기청정기는 항상 1번 열에 설치되어 있고, 크기는 두 행을 차지한다. 공기청정기가 설치되어 있지 않은 칸에는 미세먼지가 있고, (r, c)에 있는 미세먼지의 양은 Ar,c이다.

1초 동안 아래 적힌 일이 순서대로 일어난다.

1. 미세먼지가 확산된다. 확산은 미세먼지가 있는 모든 칸에서 동시에 일어난다.
- (r, c)에 있는 미세먼지는 인접한 네 방향으로 확산된다.
- 인접한 방향에 공기청정기가 있거나, 칸이 없으면 그 방향으로는 확산이 일어나지 않는다.
- 확산되는 양은 Ar,c/5이고 소수점은 버린다.
- (r, c)에 남은 미세먼지의 양은 Ar,c - (Ar,c/5)×(확산된 방향의 개수) 이다.
2. 공기청정기가 작동한다.
- 공기청정기에서는 바람이 나온다.
- 위쪽 공기청정기의 바람은 반시계방향으로 순환하고, 아래쪽 공기청정기의 바람은 시계방향으로 순환한다.
- 바람이 불면 미세먼지가 바람의 방향대로 모두 한 칸씩 이동한다.
- 공기청정기에서 부는 바람은 미세먼지가 없는 바람이고, 공기청정기로 들어간 미세먼지는 모두 정화된다.

방의 정보가 주어졌을 때, T초가 지난 후 구사과의 방에 남아있는 미세먼지의 양을 구해보자.
'''
import sys
import copy

input = sys.stdin.readline
# 오답이유: 문제 제대로 안읽고 R*R로 생각함
R, C, T = map(int, input().split())  # (6 ≤ R, C ≤ 50, 1 ≤ T ≤ 1,000)
dx = [1, 0, -1, 0]
dy = [0, 1, 0, -1]
room = []
dust = []
air_pos = []


# 미세먼지 확산
def expand(copyroom, now):
    y, x = now
    amount = copyroom[y][x] // 5

    for i in range(4):
        ny, nx = y + dy[i], x + dx[i]
        if ny < 0 or ny >= R or nx < 0 or nx >= C:
            continue
        if copyroom[ny][nx] == -1:
            continue

        room[ny][nx] += amount
        # 오답이유: findDust로 모든 확장 작업 이후에 dust를 수정했어야했는데, 여기서 바로 append, remove 작업을 함
        room[y][x] -= amount


def findDust():
    global dust
    dust = []
    for i in range(R):
        for j in range(C):
            if room[i][j] > 0:
                dust.append((i, j))


# 공기청정기 작동
def clean(air_pos):
    up, down = air_pos

    for i in range(up - 2, -1, -1):
        room[i + 1][0] = room[i][0]
    for j in range(1, C):
        room[0][j - 1] = room[0][j]
    for i in range(1, up + 1):
        room[i - 1][C - 1] = room[i][C - 1]
    for j in range(C - 2, 0, -1):
        room[up][j + 1] = room[up][j]

    for i in range(down + 2, R):
        room[i - 1][0] = room[i][0]
    for j in range(1, C):
        room[R - 1][j - 1] = room[R - 1][j]
    for i in range(R - 2, down - 1, -1):
        room[i + 1][C - 1] = room[i][C - 1]
    for j in range(C - 2, 0, -1):
        room[down][j + 1] = room[down][j]

    # 오답이유: 당기기만 당기고 맨 마지막 먼지위치 초기화 안함
    room[up][1] = 0
    room[down][1] = 0


for i in range(R):
    room.append(list(map(int, input().split())))
    for j in range(C):
        if room[i][j] == -1:
            air_pos.append(i)
        elif room[i][j] > 0:
            dust.append((i, j))

for t in range(T):
    copyroom = copy.deepcopy(room)
    for d in dust:
        # print('now',d,'------')
        expand(copyroom, d)
        # print(room)
    clean(air_pos)
    # print('end\n',room)
    findDust()

total = 0
for i in range(R):
    for j in range(C):
        if room[i][j] > 0:
            total += room[i][j]

print(total)
