# 다양한 수로 이루어진 배열이 있을 때, 주어진 수들을 M번 더해서 가장 큰수 만들기
# 특정 인덱스의 수가 연속해서 K번 더해질 수 없는 제한이 있음
# [2,4,5,4,6], M = 8, K = 3일 때 결과 = 6+6+6+5+6+6+6+5

#======================================

# N, M, K를 공백을 기준으로 구분하여 입력 받기
n, m, k = map(int, input().split())
# N개의 수를 공백을 기준으로 구분하여 입력 받기
data = list(map(int, input().split()))

data.sort() # 입력 받은 수들 정렬하기
first = data[n - 1] # 가장 큰 수
second = data[n - 2] # 두 번째로 큰 수

# 가장 큰 수가 더해지는 횟수 계산 -> 반복되는 수열 파악하기
count = int(m / (k + 1)) * k
count += m % (k + 1)

result = 0
result += (count) * first # 가장 큰 수 더하기
result += (m - count) * second # 두 번째로 큰 수 더하기

print(result) # 큰 수의 법칙에 따른 결과