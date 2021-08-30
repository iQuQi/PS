#include <queue>
#include <stack>
#include <map>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <climits>
#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
char arr[50][50];
/*
보물섬 지도를 발견한 후크 선장은 보물을 찾아나섰다. 
보물섬 지도는 아래 그림과 같이 직사각형 모양이며 여러 칸으로 나뉘어져 있다. 
각 칸은 육지(L)나 바다(W)로 표시되어 있다. 

이 지도에서 이동은 상하좌우로 이웃한 육지로만 가능하며, 한 칸 이동하는데 한 시간이 걸린다. 
보물은 서로 간에 최단 거리로 이동하는데 있어 가장 긴 시간이 걸리는 육지 두 곳에 나뉘어 묻혀있다
육지를 나타내는 두 곳 사이를 최단 거리로 이동하려면 같은 곳을 두 번 이상 지나가거나, 
멀리 돌아가서는 안 된다.

예를 들어 위와 같이 지도가 주어졌다면 보물은 아래 표시된 두 곳에 묻혀 있게 되고, 
이 둘 사이의 최단 거리로 이동하는 시간은 8시간이 된다.

보물 지도가 주어질 때, 보물이 묻혀 있는 두 곳 간의 최단 거리로 이동하는 시간을 구하는
프로그램을 작성하시오
*/

int n, m;
int dx[4] = { 1,0,-1,0 }, dy[4] = { 0,1,0,-1 }; // 오른쪽 아래쪽 왼쪽 위쪽
int visited[50][50];

int isok(int x, int y) {
	if (x < 0 || y < 0 || x >= m || y >= n || visited[y][x] || arr[y][x] == 'W') return false;
	return true;
}

void print() {
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << visited[i][j];
		}
		cout << "\n";
	}
	cout << "\n";
}

//visit 배열 초기화
void reset() {
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			visited[i][j] = 0;
		}
	}
}

int bfs(int x, int y) {
	queue<pair<pair<int, int>, int>> q;
	pair<int, int> pos;

	pos.first = x;
	pos.second = y;

	q.push({ pos,0 });
	visited[y][x] = 1;

	int dep = 0;
	while (!q.empty()) {
		pair<pair<int, int>, int>now = q.front();
		q.pop();

		x = now.first.first;
		y = now.first.second;

		//네방향 검사
		for (int k = 0; k < 4; k++)
		{
			//조건 검사
			if (isok(x + dx[k], y + dy[k])) {
				q.push({ { x + dx[k],y + dy[k] }, now.second + 1 });
				visited[y + dy[k]][x + dx[k]] = 1;
				//최단거리 갱신할때는 항상 아래의 조건을 검사해주자
				if (dep <= (now.second + 1)) dep = now.second + 1;
			}
		}
	}
	return dep;
}


int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	//세로 가로
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			//L/W로 표시된 보물지도가 주어짐
			cin >> arr[i][j];
		}
	
	int max = -1;

	//최단경로를 구한다
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (arr[i][j] == 'L') {
				int tmp = bfs(j, i);
				if (tmp >= max) max = tmp;
				reset();
			}
		}
	}

	cout << max << "\n";


}

