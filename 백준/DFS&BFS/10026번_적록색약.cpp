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
char arr[100 + 5][100 + 5];
int visited[100][100];

/*
적록색약은 빨간색과 초록색의 차이를 거의 느끼지 못한다. 
따라서, 적록색약인 사람이 보는 그림은 아닌 사람이 보는 그림과는 좀 다를 수 있다.

크기가 N×N인 그리드의 각 칸에 R(빨강), G(초록), B(파랑) 중 하나를 색칠한 그림이 있다. 
그림은 몇 개의 구역으로 나뉘어져 있는데, 구역은 같은 색으로 이루어져 있다. 
또, 같은 색상이 상하좌우로 인접해 있는 경우에 두 글자는 같은 구역에 속한다. 
(색상의 차이를 거의 느끼지 못하는 경우도 같은 색상이라 한다)

예를 들어, 그림이 아래와 같은 경우에

RRRBB
GGBBB
BBBRR
BBRRR
RRRRR
적록색약이 아닌 사람이 봤을 때 구역의 수는 총 4개이다. (빨강 2, 파랑 1, 초록 1) 
하지만, 적록색약인 사람은 구역을 3개 볼 수 있다. (빨강-초록 2, 파랑 1)

그림이 입력으로 주어졌을 때, 적록색약인 사람이 봤을 때와 아닌 사람이 봤을 때 구역의 수를 구하는 프로그램을 작성하시오.
*/
int n, fir, sec, com1, com2, tmpB;
int dx[4] = { 1,0,-1,0 }, dy[4] = { 0,1,0,-1 }; // 오른쪽 아래쪽 왼쪽 위쪽
//일반인용
bool is_ok(int x, int y, char color) {
	if (x < 0 || x >= n || y < 0 || y >= n || visited[y][x] || arr[y][x] != color) return false;
	return true;
}

//적록 색약용
bool is_ok_2(int x, int y) {
	if (x < 0 || x >= n || y < 0 || y >= n || visited[y][x] || arr[y][x] == 'B') return false;
	return true;
}



void dfs(int x, int y, char color, int type) {
	visited[y][x] = 1;
	for (int k = 0; k < 4; k++)
	{
		//일반인인 경우
		if (type == 1 && is_ok(x + dx[k], y + dy[k], color)) {
			dfs(x + dx[k], y + dy[k], color, type);
		}
		//적록색약 인경우
		else if (type == 2 && is_ok_2(x + dx[k], y + dy[k])) {
			dfs(x + dx[k], y + dy[k], color, type);
		}


	}


}

void print() {
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << visited[i][j];
		}
		cout << '\n';
	}
	cout << "\n";
}


int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> arr[i][j];
		}
	}

	//일반인 눈의 구역 개수
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			//R이고 방문 안한 경우
			if (arr[i][j] == 'R' && !visited[i][j]) {
				com1++;
				dfs(j, i, 'R', 1);
				//cout << com1 << endl;
				//print();
			}

			//B이고 방문 안한 경우
			else if (arr[i][j] == 'G' && !visited[i][j]) {
				com1++;
				dfs(j, i, 'G', 1);
				//cout << com1 << endl;
				//print();
			}

			//G이고 방문 안한 경우
			else if (arr[i][j] == 'B' && !visited[i][j]) {
				com1++;
				tmpB++;
				dfs(j, i, 'B', 1);
				//cout << com1 << endl;
				//print();
			}
		}
	}

	//방문 배열 초기화
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			visited[i][j] = 0;
		}
	}

	//적록색약 눈의 구역 개수
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			//R또는 G이고 방문 안한 경우
			if (!visited[i][j] && (arr[i][j] == 'R' || arr[i][j] == 'G')) {
				com2++;
				dfs(j, i, 'R', 2);
				//cout << com2 << endl;
				//print();
			}


		}
	}
	com2 += tmpB;

	cout << com1 << " " << com2;

}

