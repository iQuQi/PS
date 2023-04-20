# 숫자와 문자로 구성된 문자열 입력
# 문자끼리 따로 모아서 정렬, 그 뒤에 각 숫자의 합계를 붙여서 출력

input_ = input()

numbers = 0
result = ''
input_ = sorted(input_)
for s in input_:
  if s.isdigit(): numbers += int(s)
  else: result += s

# 0일때는 붙이면 안됨
if numbers > 0: result += str(numbers)
print(result)