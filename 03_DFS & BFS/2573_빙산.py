'''.
지구 온난화로 인하여 북극의 빙산이 녹고 있다. 
빙산을 그림 1과 같이 2차원 배열에 표시한다고 하자. 
빙산의 각 부분별 높이 정보는 배열의 각 칸에 양의 정수로 저장된다. 
빙산 이외의 바다에 해당되는 칸에는 0이 저장된다. 
그림 1에서 빈칸은 모두 0으로 채워져 있다고 생각한다.

 	 	 	 	 	 	 
 	2	4	5	3	 	 
 	3	 	2	5	2	 
 	7	6	2	4	 	 
 	 	 	 	 	 	 
그림 1. 행의 개수가 5이고 열의 개수가 7인 2차원 배열에 저장된 빙산의 높이 정보

빙산의 높이는 바닷물에 많이 접해있는 부분에서 더 빨리 줄어들기 때문에, 
배열에서 빙산의 각 부분에 해당되는 칸에 있는 높이는 
일년마다 그 칸에 동서남북 네 방향으로 붙어있는 0이 저장된 칸의 개수만큼 줄어든다. 
단, 각 칸에 저장된 높이는 0보다 더 줄어들지 않는다. 
바닷물은 호수처럼 빙산에 둘러싸여 있을 수도 있다. 
따라서 그림 1의 빙산은 일년후에 그림 2와 같이 변형된다.

그림 3은 그림 1의 빙산이 2년 후에 변한 모습을 보여준다. 
2차원 배열에서 동서남북 방향으로 붙어있는 칸들은 서로 연결되어 있다고 말한다. 
따라서 그림 2의 빙산은 한 덩어리이지만, 그림 3의 빙산은 세 덩어리로 분리되어 있다.


 	 	 	 	 	 	 
 	 	2	4	1	 	 
 	1	 	1	5	 	 
 	5	4	1	2	 	 
 	 	 	 	 	 	 
그림 2

 	 	 	 	 	 	 
 	 	 	3	 	 	 
 	 	 	 	4	 	 
 	3	2	 	 	 	 
 	 	 	 	 	 	 
그림 3

한 덩어리의 빙산이 주어질 때, 
이 빙산이 두 덩어리 이상으로 분리되는 최초의 시간(년)을 구하는 프로그램을 작성하시오. 
그림 1의 빙산에 대해서는 2가 답이다. 
만일 전부 다 녹을 때까지 두 덩어리 이상으로 분리되지 않으면 프로그램은 0을 출력한다.
'''



import sys 
import copy
from collections import deque
input = sys.stdin.readline

dx = [1,0,-1,0]
dy = [0,1,0,-1]

n,m = map(int,input().rstrip().split())
board = [[0]*m for _ in range(n)]
for i in range(n):
  for j,h in enumerate(list(input().rstrip().split(' '))):
    board[i][j] =  int(h)  


def bfs(graph, next_year, visited, start):
  y,x = start
  q = deque([(y,x)])
  visited[y][x] = True

  while q:
    y,x = q.popleft()
      
    for t in range(4):
      ny,nx = y+dy[t], x+dx[t]
      if ny < 0 or ny >= n or nx < 0 or nx >= m:
        continue
        
      nh = graph[ny][nx]
      if nh > 0 and not visited[ny][nx]: 
        visited[ny][nx] = True
        q.append((ny,nx))
      elif nh == 0 and next_year[y][x]>0:
        next_year[y][x] -= 1

  
year = 0
while True: 
  count = 0
  visited = [[False]*m for _ in range(n)]
  next_year = copy.deepcopy(board) # 이렇게 안하면 옆에서 녹아버려서 생긴 바다로 인해서 다음칸이 더 녹아버리는 현상 발생 -> 한해가 가면 그 전 해의 상태를 기준으로 녹아야함
  
  for i in range(n):
    for j in range(m):
      if not visited[i][j] and board[i][j] != 0:
        bfs(board, next_year,visited, (i,j))
        count += 1

  board = next_year

  if count >= 2: 
    print(year)
    break
  if count == 0:
    print(0)
    break

  year += 1

    
    