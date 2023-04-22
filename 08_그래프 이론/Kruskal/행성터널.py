# N개의 행성을 N-1개의 다리를 이용해서 모두 서로 연결되게 하려고 한다
# 각 행성의 좌표는 (x,y,z)
# 두 행성(A,B) 사이의 다리를 짓는 비용은 min(|xa-xb|,|ya-yb|,|za-zb|) 이다
# 필요한 최소 비용을 구하자

# =====
# N개의 정점 N-1개의 간선을 이용해서 모두 연결 & 최소 비용 = 최소 스패닝 트리 문제!!

# 특정 원소가 속한 집합을 찾기
def find_parent(parent, x):
    # 루트 노드가 아니라면, 루트 노드를 찾을 때까지 재귀적으로 호출
    if parent[x] != x:
        parent[x] = find_parent(parent, parent[x])
    return parent[x]
 
# 두 원소가 속한 집합을 합치기
def union_parent(parent, a, b):
    a = find_parent(parent, a)
    b = find_parent(parent, b)
    if a < b:
        parent[b] = a
    else:
        parent[a] = b
 
# 노드의 개수 입력받기
n = int(input())
parent = [0] * (n + 1) # 부모 테이블 초기화

# 모든 간선을 담을 리스트와, 최종 비용을 담을 변수
edges = []
result = 0

# 부모 테이블상에서, 부모를 자기 자신으로 초기화
for i in range(1, n + 1):
    parent[i] = i

x = []
y = []
z = []

# 모든 노드에 대한 좌표 값 입력받기
for i in range(1, n + 1):
    data = list(map(int, input().split()))
    x.append((data[0], i))
    y.append((data[1], i))
    z.append((data[2], i))

x.sort()
y.sort()
z.sort()

# 인접한 노드들로부터 간선 정보를 추출하여 처리
for i in range(n - 1):
    # 비용순으로 정렬하기 위해서 튜플의 첫 번째 원소를 비용으로 설정
    edges.append((x[i + 1][0] - x[i][0], x[i][1], x[i + 1][1]))
    edges.append((y[i + 1][0] - y[i][0], y[i][1], y[i + 1][1]))
    edges.append((z[i + 1][0] - z[i][0], z[i][1], z[i + 1][1]))

# 간선을 비용순으로 정렬
edges.sort()

# 간선을 하나씩 확인하며
for edge in edges:
    cost, a, b = edge
    # 사이클이 발생하지 않는 경우에만 집합에 포함
    if find_parent(parent, a) != find_parent(parent, b):
        union_parent(parent, a, b)
        result += cost

print(result)




'''내코드

from heapq import heappush, heappop

def find_parent(parent,a):
  if parent[a] != a: 
    parent[a] = find_parent(parent,parent[a])

  return parent[a]


def union_parent(parent,a,b):
  pa = find_parent(parent,a)
  pb = find_parent(parent,b)

  if pa > pb: parent[pb] = pa
  else: parent[pa] = pb
    

coord_x, coord_y , coord_z = [] , [], []
diff = []

n = int(input())
parent = [0] * n


for i in range(n): 
  parent[i] =  i
  x, y, z = map(int,input().split())
  
  coord_x.append((x,i)) 
  coord_y.append((y,i))
  coord_z.append((z,i))


coord_x.sort() 
coord_y.sort() 
coord_z.sort() 

for i in range(n-1): 
  heappush(diff, (abs(coord_x[i][0] - coord_x[i+1][0]), coord_x[i][1], coord_x[i+1][1]))
  heappush(diff, (abs(coord_y[i][0] - coord_y[i+1][0]), coord_y[i][1], coord_y[i+1][1]))
  heappush(diff, (abs(coord_z[i][0] - coord_z[i+1][0]), coord_z[i][1], coord_z[i+1][1]))

total = 0 
count = 0

while count < n-1: 
  min_cost, a, b = heappop(diff)

  if find_parent(parent,a) != find_parent(parent,b):
    union_parent(parent,a,b)
    total += min_cost
    count += 1


print(total)

'''