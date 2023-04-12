# 화폐 종류의 개수 N, 만들고자 하는 금액 M이 주어질때
# 필요한 화폐의 개수의 최소값 구하기. 단, 사용 가능한 화폐개수에 제한 없음


# ======================
# 정수 N, M을 입력 받기
n, m = map(int, input().split())
# N개의 화폐 단위 정보를 입력 받기
array = []
for i in range(n):
    array.append(int(input()))

# 한 번 계산된 결과를 저장하기 위한 DP 테이블 초기화
d = [10001] * (m + 1)

# 다이나믹 프로그래밍(Dynamic Programming) 진행(보텀업)
d[0] = 0
for i in range(n):
    for j in range(array[i], m + 1):
        if d[j - array[i]] != 10001: # (i - k)원을 만드는 방법이 존재하는 경우
            d[j] = min(d[j], d[j - array[i]] + 1)

# 계산된 결과 출력
if d[m] == 10001: # 최종적으로 M원을 만드는 방법이 없는 경우
    print(-1)
else:
    print(d[m])


'''내코드
n, m = map(int, input().split())
money = [0] * n
make = [-1] * 10001
make[0] = 0

for i in range(n):
  money[i] = int(input())

for price in money:
  make[price] = 1

for i in range(10001):
  if make[i] == -1:
    min_money = 1e9
    for j in range(n):
    # 인덱스 에러 막기
      if make[i-money[j]] == -1: continue
      min_money = min(min_money, make[i-money[j]] + 1)
    if min_money != 1e9: make[i] = min_money

print(make[m])

'''