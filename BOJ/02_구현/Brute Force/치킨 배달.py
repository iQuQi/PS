# N x N의 도시 정보가 주어짐. 0은 빈곳, 1은 집, 2는 치킨집이다
# 치킨거리는 집과 가장 가까운 치킨집 사이의 거리다
# 도시의 치킨 거리는 모든 집의 치킨 거리의 합
# 치킨집들중 M개만 남기고 폐업을 시키려고 할때, 도시의 치킨 거리가 가장 작아지게 하고 싶다
# M개를 폐업 시킬 때, 도시의 치킨 거리의 최솟값을 구하자

# =============================
from itertools import combinations

n, m = map(int, input().split())
chicken, house = [], []

for r in range(n):
    data = list(map(int, input().split()))
    for c in range(n):
        if data[c] == 1:
            house.append((r, c)) # 일반 집
        elif data[c] == 2:
            chicken.append((r, c)) # 치킨집

# 모든 치킨 집 중에서 m개의 치킨 집을 뽑는 조합 계산
candidates = list(combinations(chicken, m))

# 치킨 거리의 합을 계산하는 함수
def get_sum(candidate):
    result = 0
    # 모든 집에 대하여
    for hx, hy in house:
        # 가장 가까운 치킨 집을 찾기
        temp = 1e9
        for cx, cy in candidate:
            temp = min(temp, abs(hx - cx) + abs(hy - cy))
        # 가장 가까운 치킨 집까지의 거리를 더하기
        result += temp
    # 치킨 거리의 합 반환
    return result

# 치킨 거리의 합의 최소를 찾아 출력
result = 1e9
for candidate in candidates:
    result = min(result, get_sum(candidate))

print(result)


'''내 코드
from itertools import combinations
n, m = map(int,input().split())
town = []
chickens = []
houses = []
INF = 987654321

# 도시 정보 입력 받기
for i in range(n):
  row = list(map(int,input().split()))
  for index, item in enumerate(row):   
    if item == 2: chickens.append((i,index))
    if item == 1: houses.append((i,index))
  town.append(row)

# 집 - 치킨집 사이의 모든 거리 계산 => 결과적으로 이거 할필요 없었네..
distances = [[0] * len(chickens) for i in range(len(houses))]
for i,house in enumerate(houses):
  for j,chicken in enumerate(chickens):
    distances[i][j] = abs(house[0] - chicken[0]) + abs(house[1] - chicken[1])


# 전체 치킨집 중 M개의 치킨집만 남겼을 때 최소 거리 모두 계산
possibles = list(combinations([i for i in range(len(chickens))], m)) 
min_total = INF
for possible in possibles:
  total = 0
  for house in range(len(houses)):
    distance = INF
    for chicken in possible:
      distance = min(distances[house][chicken], distance)
    total += distance
  min_total = min(min_total, total)
  
print(min_total)  

'''