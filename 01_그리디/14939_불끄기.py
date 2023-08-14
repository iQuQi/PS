
'''
그리디 알고리즘 & 브루트포스 알고리즘 & 비트마스킹

전구 100개가 10×10 정사각형 모양으로 늘어서 있다. 전구에 달린 스위치를 누르면 그 전구와 위, 아래, 왼쪽, 오른쪽에 있는 전구의 상태도 바뀐다. 전구 100개의 상태가 주어지면 모든 전구를 끄기 위해 최소한으로 눌러야 하는 스위치의 개수를 출력하라 (불가능 하면 -1 출력)
'''
''' [못품 - 풀이]
첫번째 줄에서 나올 수 있는 (전구 누르는) 모든 경우의 수(1024개)에 대해서
1-1. 현재 경우의 수에 대한 전구를 세팅해준다.
1-2. 두번째 줄부터는 각 열마다 순회하면서, 현재 위치 한칸 위에 칸에 전구가 켜져있으면 현재 위치의 전구를 press 한다.
1-3. 마지막 줄까지 다 확인했으면, 맨 마지막 줄에 전구 켜진게 없으면 성공! 있으면 실패!
최소로 누른 값을 출력
'''

# 진법 변환
# 2,8,16진법을 10진법으로 변환 => int('aa',16),int('56',8),int('10',2)
# 10진법을 2,8,16진법으로 변환 => bin(30),oct(n),hex(n)

import sys
import copy
input = sys.stdin.readline
# sys.setrecursionlimit(10 ** 8) => pypy3 외 사용시 적어주기
dy = [1, 0, -1, 0]
dx = [0, 1, 0, -1]

# O는 켜진 전구, #는 꺼진 전구, 이외에는 안들어옴
board = []
for _ in range(10):
    board.append(list(map(int,
                          input()[:-1].replace('#', '0').replace('O', '1'))))


def press(board, y, x):
    # 오답노트: board가 문자열 배열일 때,
    # board[y][x] = '#' 문자열은 immutable이므로 중간에 하나를 수정못함
    # 인덱스를 지정해서 바꾸고 싶으면 arr=list(str) 후에 arr[idx]로 접근
    board[y][x] = (board[y][x] + 1) % 2
    for t in range(4):
        ny, nx = y + dy[t], x + dx[t]
        if (0 <= ny and ny < 10 and 0 <= nx and nx < 10):
            board[ny][nx] = (board[ny][nx] + 1) % 2


def isSuccess(board):
    for i in range(10):
        if board[9][i] == 1:
            return False
    return True


def solution():
    min_press = 1e9

    # 윗줄을 누르는 모든 경우의 수
    for case in range(1024):  # for case in range(1 << 10): 로도 가능
        count = 0
        copiedBoard = copy.deepcopy(board)

        # 경우에 따라 맨 윗줄 눌러놓기
        paddingCase = bin(case)[2:].rjust(10, '0')  # 오른쪽에 채우는게 아니라 오른쪽 정렬임!
        for idx, i in enumerate(paddingCase):
            if i == '1':
                press(copiedBoard, 0, int(idx))
                count += 1

        # 그 아랫줄 부터 바로 윗줄을 확인하고 켜져있으면 누른다
        for i in range(1, 10):
            for j in range(10):
                if copiedBoard[i - 1][j] == 1:
                    press(copiedBoard, i, j)
                    count += 1

        if isSuccess(copiedBoard):  # 윗줄은 다 끄고 왔으니 마지막줄만 확인하면됨! 오..
            min_press = min(count, min_press)

    return min_press


answer = solution()

if answer == 1e9:
    print(-1)
else:
    print(answer)
