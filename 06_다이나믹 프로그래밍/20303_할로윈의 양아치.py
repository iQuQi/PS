'''
... pypy안하면 시간초과 나는거였네;
Trick or Treat!!

10월 31일 할로윈의 밤에는 거리의 여기저기서 아이들이 친구들과 모여 사탕을 받기 위해 돌아다닌다. 올해 할로윈에도 어김없이 많은 아이가 할로윈을 즐겼지만 단 한 사람, 일찍부터 잠에 빠진 스브러스는 할로윈 밤을 즐길 수가 없었다. 뒤늦게 일어나 사탕을 얻기 위해 혼자 돌아다녀 보지만 이미 사탕은 바닥나 하나도 얻을 수 없었다.

단단히 화가 난 스브러스는 거리를 돌아다니며 다른 아이들의 사탕을 빼앗기로 마음을 먹는다. 다른 아이들보다 몸집이 큰 스브러스에게 사탕을 빼앗는 건 어렵지 않다. 또한, 스브러스는 매우 공평한 사람이기 때문에 한 아이의 사탕을 뺏으면 그 아이 친구들의 사탕도 모조리 뺏어버린다. (친구의 친구는 친구다?!)

사탕을 빼앗긴 아이들은 거리에 주저앉아 울고 
$K$명 이상의 아이들이 울기 시작하면 울음소리가 공명하여 온 집의 어른들이 거리로 나온다. 스브러스가 어른들에게 들키지 않고 최대로 뺏을 수 있는 사탕의 양을 구하여라.

스브러스는 혼자 모든 집을 돌아다녔기 때문에 다른 아이들이 받은 사탕의 양을 모두 알고 있다. 또한, 모든 아이는 스브러스를 피해 갈 수 없다.
'''
import sys
input = sys.stdin.readline


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


# N은 거리에 있는 아이들의 수, M은 아이들의 친구 관계 수, K는 울음소리가 공명하기 위한 최소 아이수
# N <= 30000, M <= 100 000, K <= min(N,3000)
n, m, k = map(int, input().split())
candies = [0] + [*map(int, input().split())]  # spread 방식 참고
parent = [i for i in range(n+1)]

# 친구끼리 팀묶기 -> 서로소 집합
for _ in range(m):  # 100000
    a, b = map(int, input().split())
    union(a, b)

# 실패..
# team = {}
# for idx,p in enumerate(parent): # 30000번
#   if idx == 0: continue
#   if p in team.keys():
#     team[p]['weight'] += 1 # 파이썬 딕셔너리의 경우 .으로 접근안됨!
#     team[p]['value'] += candy[idx-1]
#   else:
#     team[p] = {'weight': 1, 'value': candy[idx-1]}

# teamKeys = list(team.keys()) # list 로 안감싸면 인덱스 접근 안됨
# teamLen = len(teamKeys)

cnt_candies = [0] * (n+1)
cnt_friends = [0] * (n+1)
for i in range(1, n+1):
    root = find_parent(i)
    cnt_candies[root] += candies[i]
    cnt_friends[root] += 1

# 여기부터 냅색
dp = [0]*k  # 오답이유: k부터 공명하기 시작하므로 k-1까지 해야함

for i in range(1, n+1):
    if i != parent[i]:
        continue
    for j in range(k-1, -1, -1):  # 반대방향으로 하면 덮어씌워지는 문제를 막을 수 있어서 일차원 dp 배열로 구현가능 & 시간,공간절약
        if cnt_friends[i] > j:
            continue
        dp[j] = max(dp[j], dp[j-cnt_friends[i]] + cnt_candies[i])

print(dp[k-1])
