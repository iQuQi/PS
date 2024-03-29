# 어떠한 수 N이 1이 될 때까지 다음 아래 2개를 반복.
# 다만 두번째 연산은 나누어떨어질 때만 선택가능
# 1) 1을 뺀다 2) K로 나눈다
# 연산 횟수의 최솟값 구하기

# 아이디어: 최대한 많이 나누는 것이 최선의 선택이다.

# ===============================

# N, K공백을 기준으로 구분하여 입력 받기
n, k = map(int, input().split())

result = 0

while True:
    # N이 K로 나누어 떨어지는 수가 될 때까지만 1씩 빼기
    target = (n // k) * k
    result += (n - target)
    n = target
    # N이 K보다 작을 때 (더 이상 나눌 수 없을 때) 반복문 탈출
    if n < k:
        break
    # K로 나누기
    result += 1
    n //= k

# 마지막으로 남은 수에 대하여 1씩 빼기
result += (n - 1)
# N의 범위가 커지만 일일이 1씩 빼주는 것이 부담
# 즉, N이 K의 배수가 되도록 효율적으로 한 번에 빼주도록 하면 됨!
print(result)
