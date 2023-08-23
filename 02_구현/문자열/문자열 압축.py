# 문자열을 쪼개서 압축 => 2개로 쪼갠 경우 aabbccc = 2a2b3c
# 길이가 최소가 되도록 압축하자
# 단, 문자열의 처음부터 일정한 길이로 쪼개야 함


def solution(s):
    answer = len(s)
    # 1개 단위(step)부터 압축 단위를 늘려가며 확인
    for step in range(1, len(s) // 2 + 1):
        compressed = ""
        prev = s[0:step]  # 앞에서부터 step만큼의 문자열 추출
        count = 1
        # 단위(step) 크기만큼 증가시키며 이전 문자열과 비교
        for j in range(step, len(s), step):
            # 이전 상태와 동일하다면 압축 횟수(count) 증가
            if prev == s[j:j + step]:
                count += 1
            # 다른 문자열이 나왔다면(더 이상 압축하지 못하는 경우라면)
            else:
                compressed += str(count) + prev if count >= 2 else prev
                prev = s[j:j + step]  # 다시 상태 초기화
                count = 1
        # 남아있는 문자열에 대해서 처리
        compressed += str(count) + prev if count >= 2 else prev
        # 만들어지는 압축 문자열이 가장 짧은 것이 정답
        answer = min(answer, len(compressed))
    return


''' 내 코드
def solution(s):

    min_len = 1e9

    for N in range(1,len(s)+1):
        result = ''
        prev_index = 0
        dup_count = 1
        split_list = [s[i:i + N] for i in range(0, len(s), N)] + ['END']
        

        for (index, now) in enumerate(split_list):
            if index == 0: continue
            if split_list[prev_index] == now:
                dup_count += 1
            else:
                if dup_count > 1:
                    result += str(dup_count) + split_list[prev_index]
                else: 
                    result += split_list[prev_index]
                                                          
                prev_index = index
                dup_count = 1
                
        if min_len >= len(result):  min_len = len(result)
            
    return min_len
'''
