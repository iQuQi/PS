# 숫자가 쓰인 카드들이 N * M 형태로 놓여있다
# 행을 선택 후 그 행에서 가장 작은 숫자를 택해야하는 규칙이 있음
# 최종적으로 가장 높은 숫자를 뽑는 전략을 세워야 함
# 아이디어: 각 행마다 가장 작은 수를 찾은 뒤에 그 수 중에서 가장 큰 수 찾기

# ===============================

# N, M을 공백을 기준으로 구분하여 입력 받기
n, m = map(int, input().split())

result = 0
# 한 줄씩 입력 받아 확인하기
for i in range(n):
    data = list(map(int, input().split()))
    # 현재 줄에서 '가장 작은 수' 찾기
    min_value = min(data)
    # '가장 작은 수'들 중에서 가장 큰 수 찾기
    result = max(result, min_value)

print(result) # 최종 답안 출력