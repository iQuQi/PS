'''
루빅스 큐브는 삼차원 퍼즐이다. 보통 루빅스 큐브는 3×3×3개의 작은 정육면체로 이루어져 있다. 
퍼즐을 풀려면 각 면에 있는 아홉 개의 작은 정육면체의 색이 동일해야 한다.

큐브는 각 면을 양방향으로 90도 만큼 돌릴 수 있도록 만들어져 있다. 회전이 마친 이후에는, 
다른 면을 돌릴 수 있다. 이렇게 큐브의 서로 다른 면을 돌리다 보면, 색을 섞을 수 있다.

이 문제에서는 루빅스 큐브가 모두 풀린 상태에서 시작한다. 
윗 면은 흰색, 아랫 면은 노란색, 앞 면은 빨간색, 뒷 면은 오렌지색, 
왼쪽 면은 초록색, 오른쪽 면은 파란색이다.

루빅스 큐브를 돌린 방법이 순서대로 주어진다. 
이때, 모두 돌린 다음에 가장 윗 면의 색상을 구하는 프로그램을 작성하시오.
첫 번째 줄에는 뒷 면과 접하는 칸의 색을 출력하고, 두 번째, 세 번째 줄은 순서대로 출력하자.
흰색은 w, 노란색은 y, 빨간색은 r, 오렌지색은 o, 초록색은 g, 파란색은 b.
'''
import sys
# U: 윗 면, D: 아랫 면, F: 앞 면, B: 뒷 면, L: 왼쪽 면, R: 오른쪽 면
# +인 경우에는 시계 방향 (그 면을 바라봤을 때가 기준), -인 경우에는 반시계 방향
# 진짜 문제...후..
input = sys.stdin.readline

t = int(input())  # 테스트 케이스 최대 100개
U = D = F = B = L = R = []


def init():
    global U, D, F, B, L, R
    U = [['w'] * 3 for _ in range(3)]
    D = [['y'] * 3 for _ in range(3)]
    F = [['r'] * 3 for _ in range(3)]
    B = [['o'] * 3 for _ in range(3)]
    L = [['g'] * 3 for _ in range(3)]
    R = [['b'] * 3 for _ in range(3)]


def getCol(arr, col):
    return [arr[0][col], arr[1][col], arr[2][col]]


def setCol(arr, col, newVal):
    for i in range(3):
        arr[i][col] = newVal[i]


def printU():
    for i in range(3):
        for j in range(3):
            print(U[i][j], end='')
        print()


def rotate_matrix_by_90_degree(arr, dir):
    row_length = len(arr)
    column_length = len(arr[0])

    res = [[0] * row_length for _ in range(column_length)]

    for r in range(row_length):
        for c in range(column_length):
            if dir == '+':
                res[c][row_length - 1 - r] = arr[r][c]
            else:
                res[column_length - c - 1][r] = arr[r][c]

    return res


def rotatePlane(plane, dir):
    global U, D, F, B, L, R
    if plane == 'U':
        U = rotate_matrix_by_90_degree(U, dir)
    if plane == 'D':
        D = rotate_matrix_by_90_degree(D, dir)
    if plane == 'F':
        F = rotate_matrix_by_90_degree(F, dir)
    if plane == 'B':
        B = rotate_matrix_by_90_degree(B, dir)
    if plane == 'L':
        L = rotate_matrix_by_90_degree(L, dir)
    if plane == 'R':
        R = rotate_matrix_by_90_degree(R, dir)


def rotateSide(plane, direction):
    global U, D, F, B, L, R
    idx = 0 if plane == 'U' else 2
    d_idx = 2 if plane == 'F' or plane == 'R' else 0
    e_idx = 0 if plane == 'F' or plane == 'R' else 2
    if (direction == '+' and plane == 'U') or (direction == '-'
                                               and plane == 'D'):
        saveF = F[idx]
        F[idx] = R[idx]
        R[idx] = B[idx]
        B[idx] = L[idx]
        L[idx] = saveF
    elif (direction == '-' and plane == 'U') or (direction == '+'
                                                 and plane == 'D'):
        saveF = F[idx]
        F[idx] = L[idx]
        L[idx] = B[idx]
        B[idx] = R[idx]
        R[idx] = saveF
    elif (direction == '+' and plane == 'F') or (direction == '-'
                                                 and plane == 'B'):
        saveU = U[d_idx]
        U[d_idx] = getCol(L, d_idx)[::-1]
        # reversed보다 이방식이 좋음. reversed의 결과에 대한 인덱스 시 iteration 어쩌구 에러뜸
        setCol(L, d_idx, D[e_idx])
        D[e_idx] = getCol(R, e_idx)[::-1]
        setCol(R, e_idx, saveU)
    elif (direction == '-' and plane == 'F') or (direction == '+'
                                                 and plane == 'B'):
        saveU = U[d_idx]
        U[d_idx] = getCol(R, e_idx)
        setCol(R, e_idx, D[e_idx][::-1])
        D[e_idx] = getCol(L, d_idx)
        setCol(L, d_idx, saveU[::-1])

    elif (direction == '+' and plane == 'L') or (direction == '-'
                                                 and plane == 'R'):
        saveU = getCol(U, d_idx)
        setCol(U, d_idx, getCol(B, e_idx)[::-1])
        setCol(B, e_idx, getCol(D, d_idx)[::-1])
        setCol(D, d_idx, getCol(F, d_idx))
        setCol(F, d_idx, saveU)

    elif (direction == '-' and plane == 'L') or (direction == '+'
                                                 and plane == 'R'):
        saveU = getCol(U, d_idx)
        setCol(U, d_idx, getCol(F, d_idx))
        setCol(F, d_idx, getCol(D, d_idx))
        setCol(D, d_idx, getCol(B, e_idx)[::-1])
        setCol(B, e_idx, saveU[::-1])

# 오답노트1: 옆면만 돌리는걸 생각했는데 자신도 90도 회전해야함 -> rotatePlane 함수 추가
# 오답노트2: 각 면에서 어디가 0번 인덱스고 어디가 2번인덱스인지 & row 혹은 col의 증가방향이 어딘지 정확하게 그려놓기


for _ in range(t):
    init()
    n = int(input())  # (1 ≤ n ≤ 1000)
    rotations = list(input().split())

    for rot in rotations:
        [plane, direction] = list(rot)
        rotateSide(plane, direction)
        rotatePlane(plane, direction)
        # print(U,D,F,B,L,R)

    printU()
