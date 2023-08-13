# 리스트를 90도 회전하는 메소드
def rotate_matrix_by_90_degree(arr):
    row_length = len(arr)
    column_length = len(arr[0])

    res = [[0] * row_length for _ in range(column_length)]

    for r in range(row_length):
        for c in range(column_length):
            res[c][row_length - 1 - r] = arr[r][c]

    return res
