# G개의 탑승구가 있고 P개의 비행기가 있다
# P줄만큼 각 비행기가 갈 수 있는 탑승구가 주어지고, 비행기가 차례로 도착할때
# 최대 몇개의 비행기가 도킹 할 수 있는지 출력
# 예를들어 첫번째 비행기의 탑승구 값이 7이면 1~7번 탑승구에 도킹할 수 있다는 뜻임

# 아이디어: 가능한 가장 큰 번호의 탑승구에 도킹시킨다

# =====================

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

# 탑승구의 개수 입력받기
g = int(input())
# 비행기의 개수 입력받기
p = int(input())
parent = [0] * (g + 1) # 부모 테이블 초기화

# 부모 테이블상에서, 부모를 자기 자신으로 초기화
for i in range(1, g + 1):
    parent[i] = i

result = 0
for _ in range(p):
    data = find_parent(parent, int(input())) # 현재 비행기의 탑승구의 루트 확인
    if data == 0: # 현재 루트가 0이라면, 종료
        break
    union_parent(parent, data, data - 1) # 그렇지 않다면 바로 왼쪽의 집합과 합치기
    result += 1

print(result)