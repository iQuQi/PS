# 주기적으로 외벽 상태를 점검해야 한다
# 외벽의 구조는 동그란 원 모양이며, 총 둘레는 N 미터
# 외벽에는 몇개의 취약점이 존재하므로 친구들을 보내서 점검을 하기로 했다.
# 친구들이 이동할 수 있는 거리가 담긴 배열 dist와 외벽의 길이 n, 취약점의 위치가 담긴 배열 weak가 주어질때
# 취약 지점을 점검하기 위해 보내야 하는 친구 수의 최솟값을 구하자
# 친구들은 출발지점부터 시계 혹은 반시계 방향으로만 외벽을 따라서 이동

# ======================= 못품 -- 다시 풀어보기

from itertools import permutations


def solution(n, weak, dist):
    # 길이를 2배로 늘려서 '원형'을 일자 형태로 변형 **
    length = len(weak)
    for i in range(length):
        weak.append(weak[i] + n)

    answer = len(dist) + 1  # 투입할 친구 수의 최솟값을 찾아야 하므로 len(dist) + 1로 초기화

    # 0부터 length - 1까지의 위치를 각각 시작점으로 설정
    for start in range(length):
        # 친구를 나열하는 모든 경우 각각에 대하여 확인
        for friends in list(permutations(dist, len(dist))):
            count = 1  # 투입할 친구의 수
            # 해당 친구가 점검할 수 있는 마지막 위치
            position = weak[start] + friends[count - 1]
            # 시작점부터 모든 취약한 지점을 확인
            for index in range(start, start + length):
                # 점검할 수 있는 위치를 벗어나는 경우
                if position < weak[index]:
                    count += 1  # 새로운 친구를 투입
                    if count > len(dist):  # 더 투입이 불가능하다면 종료
                        break
                    position = weak[index] + friends[count - 1]
            answer = min(answer, count)  # 최솟값 계산

    if answer > len(dist):
        return -1
    return answer
