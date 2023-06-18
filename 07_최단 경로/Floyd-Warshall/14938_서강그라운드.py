'''
예은이는 요즘 가장 인기가 있는 게임 서강그라운드를 즐기고 있다. 
서강그라운드는 여러 지역중 하나의 지역에 낙하산을 타고 낙하하여, 
그 지역에 떨어져 있는 아이템들을 이용해 서바이벌을 하는 게임이다. 

서강그라운드에서 1등을 하면 보상으로 치킨을 주는데, 예은이는 단 한번도 치킨을 먹을 수가 없었다. 
자신이 치킨을 못 먹는 이유는 실력 때문이 아니라 아이템 운이 없어서라고 생각한 예은이는 
낙하산에서 떨어질 때 각 지역에 아이템 들이 몇 개 있는지 알려주는 프로그램을 개발을 하였지만 
어디로 낙하해야 자신의 수색 범위 내에서 가장 많은 아이템을 얻을 수 있는지 알 수 없었다.

각 지역은 일정한 길이 l (1 ≤ l ≤ 15)의 길로 다른 지역과 연결되어 있고 이 길은 양방향 통행이 가능하다.
예은이는 낙하한 지역을 중심으로 거리가 수색 범위 m (1 ≤ m ≤ 15) 이내의 
모든 지역의 아이템을 습득 가능하다고 할 때, 예은이가 얻을 수 있는 아이템의 최대 개수를 알려주자.

주어진 필드가 위의 그림과 같고, 예은이의 수색범위가 4라고 하자. 
( 원 밖의 숫자는 지역 번호, 안의 숫자는 아이템 수, 선 위의 숫자는 거리를 의미한다) 
예은이가 2번 지역에 떨어지게 되면 1번,2번(자기 지역), 3번, 5번 지역에 도달할 수 있다. 
(4번 지역의 경우 가는 거리가 3 + 5 = 8 > 4(수색범위) 이므로 4번 지역의 아이템을 얻을 수 없다.) 
이렇게 되면 예은이는 23개의 아이템을 얻을 수 있고, 이는 위의 필드에서 예은이가 얻을 수 있는 아이템의 최대 개수이다.
'''
import sys
INF = 1e9
input = sys.stdin.readline
n,m,r = map(int,input().split())
items = list(map(int,input().split()))
graph = [[INF]*(n+1) for i in range(n+1)]

result = 0

for i in range(n+1):
  graph[i][i] = 0

for i in range(r):
  a,b,l = map(int,input().split())
  graph[a][b] = l
  graph[b][a] = l

# 100 * 100 * 100 = 백만
for k in range(1,n+1):
  for i in range(1,n+1):
    for j in range(1,n+1):
      graph[i][j] = min(graph[i][j], graph[i][k]+graph[k][j])
      

take = []
for i in range(1,n+1):
  take.append(items[i-1])
  for j in range(1,n+1):
    if i == j: continue
    if graph[i][j] <= m: take[i-1]+=items[j-1]

print(max(take))
      
