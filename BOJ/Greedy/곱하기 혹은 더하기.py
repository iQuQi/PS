
# 0~9로만 이루어진 문자열이 있다
# 왼쪽부터 문자 사이에 + 또는 x를 끼워넣어서 최대한 큰 수를 만드려고 한다
# 단 일반적인 수학 연산 순서와 다르게 무조건 왼쪽 연산을 우선으로 한다.
# 어떤 전략을 써야할까?
# 아이디어: 1이하의 수면 더하기, 2이상의 수면 곱하기 

# ============

data = input()

# 첫 번째 문자를 숫자로 변경하여 대입
result = int(data[0])

for i in range(1, len(data)):
    # 두 수 중에서 하나라도 '0' 혹은 '1'인 경우, 곱하기보다는 더하기 수행
    num = int(data[i])
    if num <= 1 or result <= 1:
        result += num
    else:
        result *= num

print(result)