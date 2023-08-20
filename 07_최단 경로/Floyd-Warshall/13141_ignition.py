'''
서훈이는 오늘 있었던 알고리즘 과목 기말고사를 망쳐서 기분이 좋지 않다. 
서훈이는 스트레스도 풀 겸 시험 문제로 나온 그래프를 불로 태우려고 한다.

서훈이는 그래프의 정점 (위 그림에서 동그라미로 표시된 곳) 중 한 곳에 불을 붙일 수 있다. 
정점에 불이 붙으면 곧바로 노드와 연결된 간선을 따라서 불이 전달된다. 
간선 위에서는 불은 1초당 1만큼의 거리를 이동한다. 
만약 어떤 간선의 양 끝 정점에 불이 붙은 경우 불은 간선의 중앙까지 태운 후 꺼진다.

서훈이는 그래프를 최대한 빠른 시간 안에 전부 태우고 싶어한다. 
서훈이를 도와 어떤 정점에 불을 붙일지 구하는 프로그램을 작성하여라. 
단, 위 그림에서 간선끼리 교차하는 것은 무시한다.
'''
# 답지
import sys
import math
input = sys.stdin.readline

# 플로이드 워셜


def find_dist():
    for k in range(1, n+1):
        for i in range(1, n+1):
            for j in range(1, n+1):
                if i == j:
                    continue
                dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j])

# s는 발화점(시작점)


# 나랑 다른 부분 1 -> 간선마다 계산. 나는 정점을 기준으로 인접한 간선을 계산해서 중복되는 부분이 발생
def ignite(s):
    result = 0
    for i in range(1, n+1):
        for j in range(i, n+1):
            # 두 정점 사이에 간선이 없는 경우
            if not max_graph[i][j]:
                continue
            # 불이 i와 j에 전파되는 시간, a < b로 정렬
            a, b = sorted([dist[s][i], dist[s][j]])
            # b인 시점에 남아있는 간선의 길이
            remain = max_graph[i][j]-(b-a)
            result = max(result, b + remain/2)
    return result


n, m = map(int, input().rstrip().split())
dist = [[0 if i == j else math.inf for j in range(n+1)] for i in range(n+1)]
# 태울 간선이 저장되어 있다.
max_graph = [[0]*(n+1) for _ in range(n+1)]

for _ in range(m):
    s, e, l = map(int, input().rstrip().split())
    # dist에는 가장 짧은 간선을 저장한다.
    dist[s][e] = min(dist[s][e], l)
    dist[e][s] = min(dist[e][s], l)
    # max_graph에는 가장 긴 간선을 저장한다.
    max_graph[s][e] = max(max_graph[s][e], l)  # 나랑 다른 부분 2
    max_graph[e][s] = max(max_graph[e][s], l)

find_dist()
min_result = math.inf
for i in range(1, n+1):
    min_result = min(min_result, ignite(i))
print(min_result)


'''
[내답] - pypy3으로 했을때만 통과, 아니면 시간초과
import sys
input = sys.stdin.readline
INF = 1e9

n, m = map(int,input().split()) # (2 ≤ N ≤ 200, N-1 ≤ M ≤ 20,000)
graph = [[] for _ in range(n+1)] # 정점 - 정점 사이에 2개 이상의 간선이 있을 수 있어서 따로...ㅠ
dp = [[INF]*(n+1) for _ in range(n+1)]

for i in range(m):
  s, e, l = map(int,input().split())
  graph[s].append((e,l))
  if dp[s][e] > l: dp[s][e] = l

  if s!=e: 
    graph[e].append((s,l))
    if dp[e][s] > l: dp[e][s] = l

for i in range(n+1): dp[i][i] = 0

for k in range(1,n+1):
  for i in range(1,n+1):
    for j in range(1,n+1):
      dp[i][j] = min(dp[i][j], dp[i][k]+dp[k][j])

# for i in range(1,n+1):
#   print(dp[i][1:])

fire = []
for start in range(1, n+1):
  tmp = []
  for now in range(1, n+1):
    if start == now: continue

    connect = []
    for v,cost in graph[now]:
      connect.append(dp[start][v] + cost)
    min_,max_ = min(connect), max(connect)
    tmp.append(min_ + (max_-min_)/2)
          
  fire.append(max(tmp))

# print(fire)
print('%.1f' %min(fire))


# 주어진 그래프를 모두 태우는 데 걸리는 최소 시간을 출력한다. 
# 답은 소수점 아래 한 자리까지 출력한다.
'''
