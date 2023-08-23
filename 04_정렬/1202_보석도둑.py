'''[못품]
세계적인 도둑 상덕이는 보석점을 털기로 결심했다.

상덕이가 털 보석점에는 보석이 총 N개 있다. 
각 보석은 무게 Mi와 가격 Vi를 가지고 있다. 
상덕이는 가방을 K개 가지고 있고, 각 가방에 담을 수 있는 최대 무게는 Ci이다. 
가방에는 최대 한 개의 보석만 넣을 수 있다.

상덕이가 훔칠 수 있는 보석의 최대 가격을 구하는 프로그램을 작성하시오.
'''
# 아이디어: 가방별로 훔칠 수 있는 보석을 최대힙을 통해 탐색하는게 핵심

import sys
from heapq import heappush, heappop
input = sys.stdin.readline

N, K = map(int, input().split())
jewels = []
bags = []

# 보석 정보 입력 받기
for i in range(N):  # 30만번
    m, v = map(int, input().split())
    jewels.append((m, v))
    # 오답이유1: 가치순이 아닌 무게순으로 정렬해야함!
    # 무게 오름차순, 무게 같으면 가격 오름차순

# 가방 정보 입력받기
for i in range(K):  # 30만번
    bags.append(int(input()))

bags.sort()  # 180만번
jewels.sort()  # 180만번

total = 0
possible = []

# 무게가 적은 가방부터 검사
# 오답이유2: 가방 순으로 체크 해야함. 나는 보석을 기준으로 검사했음
for bag in bags:  # 30만번
    # 제일 가벼운 보석이 들어갈 수 있는 한...
    while jewels and jewels[0][0] <= bag:
        # 오답이유3: logN에서 밑은 10이 아니라 2임 바보!
        heappush(possible, -jewels[0][1])  # logN
        heappop(jewels)  # logN

    # 그 중에서 가치가 가장 높은 보석을 실제로 넣는다
    # [주의] possible은 유지됨
    if possible:
        total -= heappop(possible)  # logN

print(total)
# 오답이유4: count를 따로세면 count 0이 되어도 bisect 검색에 걸리기 때문에 제대로 연산이 안됨

'''내코드
import sys
from bisect import bisect_right
input = sys.stdin.readline

N, K = map(int, input().split())
jewels = []
bags = []

# 보석 정보 입력 받기
for i in range(N): # 30만번
  m, v = map(int,input().split())
  jewels.append((v,-m)) 

# 가방 정보 입력받기
for i in range(K): # 60만번
  c = int(input())
  if c not in bags: bags.append((c,1))
  else: 
    count = bags[bags.index(c)][1]
    bags[bags.index(c)]  = (c,count+1)

bags.sort() # 150만번
jewels.sort() # 150만번
total = 0

# 우선순위가 높은 보석부터 체크하면서 담는다
while jewels: # 30만
  v,m = jewels.pop()

  right = bisect_right(bags, (-m,1)) #5
  if right >= K or bags[right][1] < 1: continue
    
  bags[right] = (bags[right][0], bags[right][1]-1)
  total += v

print(total)



'''
