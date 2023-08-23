'''
다솜이는 불우이웃 돕기 활동을 하기 위해 무엇을 할지 생각했다. 마침 집에 엄청나게 많은 랜선이 있다는 것을 깨달았다. 마침 랜선이 이렇게 많이 필요 없다고 느낀 다솜이는 랜선을 지역사회에 봉사하기로 했다.

다솜이의 집에는 N개의 방이 있다. 각각의 방에는 모두 한 개의 컴퓨터가 있다. 각각의 컴퓨터는 랜선으로 연결되어 있다. 어떤 컴퓨터 A와 컴퓨터 B가 있을 때, A와 B가 서로 랜선으로 연결되어 있거나, 또 다른 컴퓨터를 통해서 연결이 되어있으면 서로 통신을 할 수 있다.

다솜이는 집 안에 있는 N개의 컴퓨터를 모두 서로 연결되게 하고 싶다.

N개의 컴퓨터가 서로 연결되어 있는 랜선의 길이가 주어질 때, 다솜이가 기부할 수 있는 랜선의 길이의 최댓값을 출력하는 프로그램을 작성하시오.
'''
import sys
input = sys.stdin.readline

n = int(input())  # 50보다 작거나 같은 자연수
lan = []
total = 0
for i in range(n):
    # list(input().rstrip()) 로 해야 글자별로 나눠서 배열화 & \n 자동 제거
    row = list(input().rstrip())
    for j in range(n):
        if row[j] == '0':
            continue  # 오답이유 row[j] == 0 으로함 -> 문자열임!
        length = ord(row[j])-38 if row[j].isupper() else ord(row[j]) - 96
        total += length
        # 아래 처럼도 가능
        # graph.append((ord(data[i][j]) - ord('a') + 1, i+1, j+1))
        # graph.append((ord(data[i][j]) - ord('A') + 27, i+1, j+1))
        lan.append((length, i, j))

parent = [i for i in range(n)]


def find_parent(a):
    if a != parent[a]:
        parent[a] = find_parent(parent[a])
    return parent[a]


def union(a, b):
    pa = find_parent(a)
    pb = find_parent(b)
    if pa < pb:
        parent[pb] = pa
    else:
        parent[pa] = pb


lan.sort()
remain = 0
test = 0
for length, i, j in lan:
    if find_parent(i) != find_parent(j):
        union(i, j)
        test += length
        # 오답이유2: A - B, C - D 연결되는 경우 A,B,C,D가 group에 모두 들어가서 정답 처리됨!
        # if i not in group: group.append(i)
        # if j not in group: group.append(j)
    else:
        remain += length

# 오답이유3: 아래처럼 안하고 parent.count(parent[0]) != n 조건으로 함
# 이렇게 하면 union 후에 루트 재조정 작업이 적용이 되어있지 않기 때문에 find_parent로 재조정 필요
result = True
for i in range(n):
    if find_parent(i) != 0:
        result = False

# 모든 컴퓨터가 연결되어 있지 않으면 -1을 출력
if not result:
    print(-1)
else:
    print(remain)
