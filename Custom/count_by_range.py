from bisect import bisect_left, bisect_right

# 정렬된 배열에서 특정 수의 개수 구하기
def count_by_range(array, left_value, right_value):
    right_index = bisect_right(array, right_value)
    left_index = bisect_left(array, left_value)
    return right_index - left_index

count = count_by_range(array, x, x)
