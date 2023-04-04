# 정렬된 카드 두 묶음 A,B를 합칠 때 A 개수 + B 개수 만큼의 연산이 필요
# 수많은 카드 묶음을 두개씩 차례로 합칠 때, 최소한 몇번의 비교가 필요한지 구하자
# 예를 들어 10,20,40 크기의 묶음이 있을 때
# (10 + 20) + (30 + 40) == 100
# (10 + 40) + (50 + 20) = 120 => 비효율적인 방법

# ====================
import heapq # => 매 순간 가장 작은 수의 묶음이 필요하므로

n = int(input())

# 힙(Heap)에 초기 카드 묶음을 모두 삽입
heap = []
for i in range(n):
    data = int(input())
    heapq.heappush(heap, data)

result = 0

# 힙(Heap)에 원소가 1개 남을 때까지
while len(heap) != 1:
    # 가장 작은 2개의 카드 묶음 꺼내기
    one = heapq.heappop(heap)
    two = heapq.heappop(heap)
    # 카드 묶음을 합쳐서 다시 삽입
    sum_value = one + two
    result += sum_value
    heapq.heappush(heap, sum_value)

print(result)


'''
내 코드 - 틀림 
처음에 정렬한 순으로 계산하는 것이 아닌 매 순간 가장 작은 크기의 묶음을 사용해야 함

N = int(input())
size_ = []
for i in range(N):
  num = int(input())
  size_.append(num)

size_.sort()

sum_ = 0
for i in range(1,N):
  if i == 1: 
    sum_ += (size_[0] + size_[1]) * (N-i)
  else: 
    sum_ += (size_[i] * (N-i))

print(sum_)

'''