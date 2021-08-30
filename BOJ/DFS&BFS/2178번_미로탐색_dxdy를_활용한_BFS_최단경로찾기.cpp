#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <string.h>
using namespace std;
int miro[100 + 5][100 + 5];//인접행렬
int _x[4] = { 0,1,0,-1 }; //아래 오른쪽 위 왼쪽
int _y[4] = { 1,0,-1,0 };
bool visited[100 + 5][100 + 5];//방문여부
int dis[105][105];
queue<pair<int, int >>bfs;
int N, M;
/*
N×M크기의 배열로 표현되는 미로가 있다.

1	0	1	1	1	1
1	0	1	0	1	0
1	0	1	0	1	1
1	1	1	0	1	1
미로에서 1은 이동할 수 있는 칸을 나타내고, 
0은 이동할 수 없는 칸을 나타낸다. 이러한 미로가 주어졌을 때, 
(1, 1)에서 출발하여 (N, M)의 위치로 이동할 때 
지나야 하는 최소의 칸 수를 구하는 프로그램을 작성하시오. 

한 칸에서 다른 칸으로 이동할 때, 서로 인접한 칸으로만 이동할 수 있다.

위의 예에서는 15칸을 지나야 (N, M)의 위치로 이동할 수 있다. 
칸을 셀 때에는 시작 위치와 도착 위치도 포함한다.
*/



void bfss() {
	//시작 정점
	bfs.push({ 1,1 });
	dis[1][1] = 1;

	//큐가 빌때까지 
	while (!bfs.empty()) {
		int size = bfs.size();
		int x = bfs.front().first;
		int y = bfs.front().second;

		bfs.pop();
		visited[y][x] = true;

		//상 하 좌 우에서 갈 수있는 모든 정점에 대해 BFS를 돌린다
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < 4; j++)
			{
				int nx = x + _x[j];
				int ny = y + _y[j];
		
				//가려는 곳까지의 최단 칸수가 현재위치의 최단 칸수+1보다 작거나 같다면
				//최단경로가 아니므로 갱신하지 않음
				if (miro[ny][nx] == 1 && dis[ny][nx] > dis[y][x] + 1) 
				{
					bfs.push({ nx,ny });
					dis[ny][nx] = dis[y][x] + 1;
				}
			}
		}
	}
	cout << dis[N][M];
}

int main() {
	cin >> N >> M;//n이세로,y m이가로,x

	//초기화 함수
	for (int i = 0; i < 105; i++)
	{
		memset(miro[i], -1, sizeof(miro[i]));
	}

	//미로를 입력 받는다
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			scanf("%1d", &miro[i][j]);
			dis[i][j] = 10000;
		}
	}

	//최단 경로 탐색 시작
	bfss();

}