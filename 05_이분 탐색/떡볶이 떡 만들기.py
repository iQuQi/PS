# 떡볶이 떡의 개수N과 요청한 떡의 길이M이 주어진다
# 높이 H로 설정한 기계로 떡을 자르면 그보다 긴 부분만 잘리고 손님이 가져가게 된다
# 예를 들어 10 9 12 길이의 떡들이 있을때, 10 높이로 떡을 자르면 -> 0 0 2, 즉 2길이만큼의 떡을 가져가게 된다

# ============== 전형적인 파라메트릭 문제!

# 떡의 개수(N)와 요청한 떡의 길이(M)을 입력
n, m = list(map(int, input().split(' ')))
# 각 떡의 개별 높이 정보를 입력
array = list(map(int, input().split()))

# 이진 탐색을 위한 시작점과 끝점 설정
start = 0
end = max(array)

# 이진 탐색 수행 (반복적)
result = 0
while (start <= end):
    total = 0
    mid = (start + end) // 2
    for x in array:
        # 잘랐을 때의 떡볶이 양 계산
        if x > mid:
            total += x - mid
    # 떡볶이 양이 부족한 경우 더 많이 자르기 (오른쪽 부분 탐색)
    if total < m:
        end = mid - 1
    # 떡볶이 양이 충분한 경우 덜 자르기 (왼쪽 부분 탐색)
    else:
        result = mid  # 최대한 덜 잘랐을 때가 정답이므로, 여기에서 result에 기록
        start = mid + 1

# 정답 출력
print(result)
