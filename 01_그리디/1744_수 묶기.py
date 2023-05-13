
'''
길이가 N인 수열이 주어졌을 때, 그 수열의 합을 구하려고 한다. 
하지만, 그냥 그 수열의 합을 모두 더해서 구하는 것이 아니라, 
수열의 두 수를 묶으려고 한다. 어떤 수를 묶으려고 할 때, 위치에 상관없이 묶을 수 있다. 
하지만, 같은 위치에 있는 수(자기 자신)를 묶는 것은 불가능하다. 
그리고 어떤 수를 묶게 되면, 수열의 합을 구할 때 묶은 수는 서로 곱한 후에 더한다.

예를 들면, 어떤 수열이 {0, 1, 2, 4, 3, 5}일 때, 
그냥 이 수열의 합을 구하면 0+1+2+4+3+5 = 15이다. 
하지만, 2와 3을 묶고, 4와 5를 묶게 되면, 0+1+(2*3)+(4*5) = 27이 되어 최대가 된다.

수열의 모든 수는 단 한번만 묶거나, 아니면 묶지 않아야한다.

수열이 주어졌을 때, 수열의 각 수를 적절히 묶었을 때, 
그 합이 최대가 되게 하는 프로그램을 작성하시오.
'''


n = int(input())
arr = []
# 수열 입력받기
for i in range(n):
  a = int(input())
  arr.append(a)
positive = [a for a in arr if a > 0]
negative = [a for a in arr if a <= 0]
positive.sort(reverse = True)
negative.sort()

total = 0
# 양수 배열 - 가장 큰 수를 기준으로 정렬하여 곱 (1은 무조건 더한다)
for i in range(0,len(positive),2):
  # 짝이 없는 경우 그냥 더하기
  if i == len(positive)-1:
    total += positive[i]
  # 더 커지는 방법으로 계산
  else:
    if positive[i]+positive[i+1] < positive[i]*positive[i+1]:
      total += (positive[i]*positive[i+1])
    else:
      total += positive[i]
      total += positive[i+1]

# 음수 배열 - 가장 작은 수를 기준으로 정렬하여 곱 (0을 음수배열에 넣어야 음수가 하나 남았을때 곱해서 없앨 수 있음)
for i in range(0,len(negative),2):
  # 짝이 없는 경우 그냥 더하기
  if i == len(negative)-1:
    total += negative[i]
  # 더 커지는 방법으로 계싼
  else:
    total += (negative[i]*negative[i+1])
      
print(total)
    