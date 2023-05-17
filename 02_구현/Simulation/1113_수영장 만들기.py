'''_
지민이는 수영장을 만들려고 한다. 수영장을 만들 곳의 크기는 N*M이고, 각 칸은 직육면체이다. 
따라서, 각 칸의 직육면체의 높이가 쓰여 있는 다음과 같은 땅을 생각할 수 있다.

16661
61116
16661
이 수영장은 15만큼의 물이 들어있는 수영장을 만들 수 있다. 
가운데 3개의 칸에 5만큼 물을 채우면 되기 때문이다.

자 이제 가운데 물을 더 추가했다고 생각하면, 벽(높이가 6인 직육면체)을 넘어서 밖으로 나갈 것이다. 
물은 항상 높이가 더 낮은 곳으로만 흐르고, 직육면체 위의 표면에는 물이 없다. 
그리고, 땅의 높이는 0이고, 땅은 물을 무한대로 흡수 할 수 있다.

땅의 모양이 주어질 때, 수영장에 물이 얼마만큼 있을 수 있는지 구하는 프로그램을 작성하시오.

입력
첫째 줄에 N과 M이 주어진다. N과 M은 50보다 작거나 같은 자연수이다.
둘째 줄부터 N개의 줄에 땅의 높이가 주어진다. 높이는 1보다 크거나 같고, 9보다 작거나 같은 자연수이다.
'''

'''
**못품
[풀이방법]
1. 물의 높이를 1씩 높여가며 물이 담기는 넓이를 구한다.
2. 물이 담기는 위치를 BFS를 통해 탐색해 범위 밖으로(수영장이 안되는 조건) 연결되면 cnt에 추가하지 않는다.
3. main(solution)함수를 만들어 해결하니 return을 사용해 프로그램을 종료할 수 있어 편함
'''

import sys
from collections import deque

visited = []
res = 0


def solution():
    global res, visited
    
    # 수영장이 될 수 있는지 확인하고 되면 물 양 더하기
    def bfs(x, y, h):
        global res, visited

        que = deque([x, y])
        
        flag = True  # 수영장이 될 수 있는지 체크하는 변수

        visited[x][y] = True
        cnt = 1
        while que:
            x, y = que.popleft()

            for t in range(4):
                nx = x + dx[t]
                ny = y + dy[t]
                # 수영장 밖으로 물이 넘치면 flag False로 하고 연결된 나머지 전부 체크(수영장이 안되는 위치 전부)
                if nx == -1 or nx == N or ny == -1 or ny == M:
                    flag = False
                    continue
                
                if board[nx][ny] <= h and not visited[nx][ny]:
                    visited[nx][ny] = True
                    que.append([nx, ny])
                    cnt += 1
        if flag:
            res += cnt

    N, M = map(int, input().split())
    board = [list(map(int, list(sys.stdin.readline().rstrip()))) for _ in range(N)]

    dx = [-1, 0, 0, 1]
    dy = [0, -1, 1, 0]
    
    # 수면을 1부터 8까지 올리면서 확인
    for num in range(1, 9):
        visited = [[0] * M for _ in range(N)]
        for i in range(N):
            for j in range(M):
                # 현재 수면보다 낮고 아직 체크 안한 곳
                if board[i][j] <= num and not visited[i][j]:
                    bfs(i, j, num)
    print(res)


solution()