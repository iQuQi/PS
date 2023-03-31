
# 숫자 N을 왼쪽 오른쪽 반으로 나눠서 각 자리숫자를 더한다
# 양쪽의 합계가 같다면 럭키 스트레이트 기술 사용 가능!

N  = input()
length = len(N)
left = N[0:length//2] # length/2로 하면 실수가 나와서 인덱싱 에러남
right = N[length//2:length]

l_sum = 0
r_sum = 0
for i in left:
  l_sum += int(i)
for j in right:
  r_sum += int(j)
  
if l_sum == r_sum : print('LUCKY')
else: print('READY')