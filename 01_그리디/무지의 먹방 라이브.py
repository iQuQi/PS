# 무지는 회전 음식으로 먹방을 진행함
# 음식은 순서대로 번호가 있으며 각 음식을 다 먹는데 걸리는 시간은 모두 다르다.
# 한번에 1초씩 먹고 아직 먹지 않은 다음 번호의 음식을 먹는다.
# 그러나 방송 후 k초 뒤에 네트워크 문제로 먹방이 중단되는데...
# 무지는 다시 방송을 켜서 몇번째 음식부터 먹어야하는지 알고 싶다.
# 아이디어: 시간이 적게 걸리는 음식을 다 먹어치우자.
# 1) [1번-8초 2번-6초 3번-9초]인 경우 6초가 걸리는 2번을 먼저 다 먹어버리려면 6 * (남은 음식 개수=3) = 18초가 걸린다
# 2) [1번-8초 3번-9초] - 8초가 걸리는 1번을 먼저 먹어버리려면 2 * (남은 음식 개수=2) = 4초가 소요됨
# 3) 만약 k가 19초였다면, 2)번 진행 시 시간을 넘겨버림 => 남은 음식을 나열해두고 나머지 연산

# ==============================

import heapq


def solution(food_times, k):
    # 전체 음식을 먹는 시간보다 k가 크거나 같다면 -1
    if sum(food_times) <= k:
        return -1

    # 시간이 작은 음식부터 빼야 하므로 우선순위 큐를 이용
    q = []
    for i in range(len(food_times)):
        # (음식 시간, 음식 번호) 형태로 우선순위 큐에 삽입
        heapq.heappush(q, (food_times[i], i + 1))

    sum_value = 0  # 먹기 위해 사용한 시간
    previous = 0  # 직전에 다 먹은 음식 시간
    length = len(food_times)  # 남은 음식의 개수

    # sum_value + (현재의 음식 시간 - 이전 음식 시간) * 현재 음식 개수와 k 비교
    # 힙 인덱싱 가능 & sorted(q) 가능
    while sum_value + ((q[0][0] - previous) * length) <= k:
        now = heapq.heappop(q)[0]
        sum_value += (now - previous) * length
        length -= 1  # 다 먹은 음식 제외
        previous = now  # 이전 음식 시간 재설정

    # 남은 음식 중에서 몇 번째 음식인지 확인하여 출력
    result = sorted(q, key=lambda x: x[1])  # 음식의 번호 기준으로 정렬
    return result[(k - sum_value) % length][1]
