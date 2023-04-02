# 자물쇠는 N x N, 열쇠는 M x M 이며 항상 N >= M
# 열쇠는 회전과 이동이 가능 & 열쇠의 돌기 부분이 자물쇠의 모든 홈 부분에 딱 맞으면 풀림
# 자물쇠 영역에서 벗어난 열쇠 부분은 영향 X
# 열 수 있는지 알아보자
# N과 M 모두 20이하의 자연수이므로 brute force 가능

# =========================================
# 2차원 리스트 90도 회전하기
def rotate_a_matrix_by_90_degree(a):
    n = len(a) # 행 길이 계산
    m = len(a[0]) # 열 길이 계산
    result = [[0] * n for _ in range(m)] # 결과 리스트
    for i in range(n):
        for j in range(m):
            result[j][n - i - 1] = a[i][j]
    return result

# 자물쇠의 중간 부분이 모두 1인지 확인
def check(new_lock):
    lock_length = len(new_lock) // 3
    for i in range(lock_length, lock_length * 2):
        for j in range(lock_length, lock_length * 2):
            if new_lock[i][j] != 1:
                return False
    return True

def solution(key, lock):
    n = len(lock)
    m = len(key)
    # 자물쇠의 크기를 기존의 3배로 변환
    new_lock = [[0] * (n * 3) for _ in range(n * 3)]
    # 새로운 자물쇠의 중앙 부분에 기존의 자물쇠 넣기
    for i in range(n):
        for j in range(n):
            new_lock[i + n][j + n] = lock[i][j]

    # 4가지 방향에 대해서 확인
    for rotation in range(4):
        key = rotate_a_matrix_by_90_degree(key) # 열쇠 회전
        for x in range(n * 2):
            for y in range(n * 2):
                # 자물쇠에 열쇠를 끼워 넣기
                for i in range(m):
                    for j in range(m):
                        new_lock[x + i][y + j] += key[i][j]
                # 새로운 자물쇠에 열쇠가 정확히 들어 맞는지 검사
                if check(new_lock) == True:
                    return True
                # 자물쇠에서 열쇠를 다시 빼기
                for i in range(m):
                    for j in range(m):
                        new_lock[x + i][y + j] -= key[i][j]
    return False

''' 내 코드
# Custom Library
def rotate_matrix_by_90_degree(arr):
    row_length = len(arr)
    column_length = len(arr[0])

    res = [[0] * row_length for _ in range(column_length)]

    for r in range(row_length):
        for c in range(column_length):
            res[c][row_length -1 -r] = arr[r][c]

    return res

# 자물쇠와 열쇠가 딱 맞는지 검사하는 함수
def check(arr):
    for i in range(len(arr)):
        for j in range(len(arr[0])):
            if arr[i][j] == 0 or arr[i][j] == 2: return False
        
    return True


def solution(key, lock):
    keyLen = len(key)
    lockLen = len(lock)
    
    for i in range(lockLen+keyLen-1):
        for j in range(lockLen+keyLen-1):
            for _ in range(4):
                result = [arr[:] for arr in lock]
                key = rotate_matrix_by_90_degree(key)
                origin = [i - (keyLen-1), j - (keyLen-1)]
            
                for k in range(keyLen):
                    for t in range(keyLen):
                        if origin[0]+k < 0 or origin[0]+k >= lockLen or origin[1]+t < 0 or origin[1]+t >= lockLen:
                            continue
                        result[origin[0]+k][origin[1]+t] = lock[origin[0]+k][origin[1]+t] + key[k][t]
                                                
                if check(result): return True
        
    return False

'''