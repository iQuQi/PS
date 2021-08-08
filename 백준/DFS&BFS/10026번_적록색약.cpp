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

