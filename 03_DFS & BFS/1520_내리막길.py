'''
여행을 떠난 세준이는 지도를 하나 구하였다. 
이 지도는 아래 그림과 같이 직사각형 모양이며 여러 칸으로 나뉘어져 있다. 
한 칸은 한 지점을 나타내는데 각 칸에는 그 지점의 높이가 쓰여 있으며, 
각 지점 사이의 이동은 지도에서 상하좌우 이웃한 곳끼리만 가능하다.

현재 제일 왼쪽 위 칸이 나타내는 지점에 있는 세준이는 
제일 오른쪽 아래 칸이 나타내는 지점으로 가려고 한다. 
그런데 가능한 힘을 적게 들이고 싶어 
항상 높이가 더 낮은 지점으로만 이동하여 목표 지점까지 가고자 한다. 
위와 같은 지도에서는 다음과 같은 세 가지 경로가 가능하다.

지도가 주어질 때 이와 같이 제일 왼쪽 위 지점에서 출발하여 
제일 오른쪽 아래 지점까지 항상 내리막길로만 이동하는 경로의 개수를 구하는 프로그램을 작성하시오.
'''

import sys 
sys.setrecursionlimit(30000)
input = sys.stdin.readline

dx = [1,0,-1,0]
dy = [0,1,0,-1]

m,n = map(int,input().rstrip().split())
board = [[0]*n for _ in range(m)]
# 오답이유1: path를 0으로 다 초기화 함으로써 dp 계산이 된 건지 구분이 안됐음
path = [[-1]*n for _ in range(m)]
path[m-1][n-1] = 1

for i in range(m):
  for j,h in enumerate(list(input().rstrip().split(' '))):
    board[i][j] =  int(h)  

def dfs(graph, path, now):
  y,x = now
  h = board[y][x]
  temp_path = 0

  for t in range(4):
    ny,nx = y+dy[t], x+dx[t]
    if ny < 0 or ny >= m or nx < 0 or nx >= n:
      continue

    nh = board[ny][nx]
    if not nh < h: continue 
    # 오답이유2: path[ny][nx] != -1로 함 -> 0도 이미 계산된 칸이므로 dp 값을 써야 함
    elif path[ny][nx] >= 0: 
      temp_path += path[ny][nx]
    else: 
      temp_path += dfs(graph,path, (ny,nx))

  path[y][x] = temp_path
  return path[y][x]

      
dfs(board, path, (0,0))
print(path[0][0])