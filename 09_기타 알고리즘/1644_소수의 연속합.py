'''
하나 이상의 연속된 소수의 합으로 나타낼 수 있는 자연수들이 있다. 
몇 가지 자연수의 예를 들어 보면 다음과 같다.

3 : 3 (한 가지)
41 : 2+3+5+7+11+13 = 11+13+17 = 41 (세 가지)
53 : 5+7+11+13+17 = 53 (두 가지)
하지만 연속된 소수의 합으로 나타낼 수 없는 자연수들도 있는데, 20이 그 예이다. 
7+13을 계산하면 20이 되기는 하나 7과 13이 연속이 아니기에 적합한 표현이 아니다. 
또한 한 소수는 반드시 한 번만 덧셈에 사용될 수 있기 때문에, 
3+5+5+7과 같은 표현도 적합하지 않다.

자연수가 주어졌을 때, 이 자연수를 연속된 소수의 합으로 나타낼 수 있는 경우의 수를 
구하는 프로그램을 작성하시오.
'''

# 수학 - 소수 & 투 포인터
import math

n = int(input()) # 2부터 1,000까지의 모든 수에 대하여 소수 판별
array = [True for i in range(n + 1)] # 처음엔 모든 수가 소수(True)인 것으로 초기화

# 에라토스테네스의 체 알고리즘 
for i in range(2, int(math.sqrt(n)) + 1): # 2부터 n의 제곱근까지의 모든 수를 확인하며
    if array[i] == True: # i가 소수인 경우 (남은 수인 경우)
        # i를 제외한 i의 모든 배수를 지우기
        j = 2 
        while i * j <= n:
            array[i * j] = False
            j += 1

sosu = [idx+2 for idx,i in enumerate(array[2:]) if i == True]

total = 0
count = 0
start, end = 0,0

while start < len(sosu) and end < len(sosu):
  if total + sosu[end] >= n:
    if total + sosu[end] == n: count += 1
    total -= sosu[start]
    if start == end: end += 1
    start += 1
    
  else: 
    total += sosu[end]
    end += 1
    
print(count)