# 각 스테이지의 실패율을 구하고 , 실패율이 높은 스테이지 부터 내림차순 정렬
# 전체 스테이지 수 = N, 게임을 이용하는 사용자가 현재 멈춰있는 스테이지 번호가 담긴 배열 stages
# 실패율 = 스테이지에 도달했으나 아직 클리어 못한 플레이어 수 / 도달한 플레이어 수


# ===================
def solution(N, stages):
    answer = []
    length = len(stages)

    # 스테이지 번호를 1부터 N까지 증가시키며
    for i in range(1, N + 1):
        # 해당 스테이지에 머물러 있는 사람의 수 계산
        count = stages.count(i)
        
        # 실패율 계산
        if length == 0:
            fail = 0
        else:
            fail = count / length
        
        # 리스트에 (스테이지 번호, 실패율) 원소 삽입
        answer.append((i, fail))
        length -= count # ** 머물러있는 사람 수 세는 아이디어!

    # 실패율을 기준으로 각 스테이지를 내림차순 정렬
    answer = sorted(answer, key=lambda t: t[1], reverse=True)
    
    # 정렬된 스테이지 번호 반환
    answer = [i[0] for i in answer]
    return answer


''' 내코드
def solution(N, stages):
    stage_fail = [0] * (N+2)
    
    for stage in stages:
        stage_fail[stage] += 1
        
            
    for index, count in enumerate(stage_fail):
        if sum(stage_fail[index:]) == 0: stage_fail[index] = (0,index)
        else: stage_fail[index] = (count / sum(stage_fail[index:]), index)
        
    
    return [ stage_info[1] for stage_info in sorted(stage_fail[1:-1], key= lambda x: (-x[0], x[1]))]
'''