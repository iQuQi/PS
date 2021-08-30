#include <iostream>
#include <vector>
#include <queue>
#include <stdlib.h>
#include <cstdio>
#include <algorithm>

using namespace std;
/*
세로 R칸, 가로 C칸으로 된 표 모양의 보드가 있다. 
보드의 각 칸에는 대문자 알파벳이 하나씩 적혀 있고, 
좌측 상단 칸 (1행 1열) 에는 말이 놓여 있다.

말은 상하좌우로 인접한 네 칸 중의 한 칸으로 이동할 수 있는데, 
새로 이동한 칸에 적혀 있는 알파벳은 지금까지 지나온 모든 칸에 
적혀 있는 알파벳과는 달라야 한다. 즉, 같은 알파벳이 적힌 칸을 두 번 지날 수 없다.

좌측 상단에서 시작해서, 말이 최대한 몇 칸을 지날 수 있는지를 
구하는 프로그램을 작성하시오. 말이 지나는 칸은 좌측 상단의 칸도 포함된다.
*/
int r, c;
int alpha[26];
char arr[22][22];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int dab = 0, _max = -1;
//이때까지 나온 알파벳인지 확인하는 함수
int isOk(int dep, int nextX, int nextY) {

	if (alpha[arr[nextY][nextX] - 65]) return 0;
	return 1;
}

void backTrack(int depth, int nx, int ny) {

	for (int i = 0; i < 4; i++)
	{
		//범위에서 벗어나거나 이때까지 밟은 알파벳중 하나면 끝
		if (ny + dy[i]<1 || ny + dy[i] >r || nx + dx[i] < 1 || nx + dx[i] > c || !isOk(depth, nx + dx[i], ny + dy[i])) {
			dab = depth - 1;
			if (_max <= dab) _max = dab;
			continue;
		}
		alpha[arr[ny + dy[i]][nx + dx[i]] - 65] = 1;
		backTrack(depth + 1, nx + dx[i], ny + dy[i]);
		alpha[arr[ny + dy[i]][nx + dx[i]] - 65] = 0;//다시 복원시켜주는 것이 중요
	}


	return;
}

int main() {
	cin >> r >> c;
	//가로 세로 입력 받기
	for (int i = 1; i <= r; i++)
	{
		for (int j = 1; j <= c; j++)
		{
			scanf("%1s", &arr[i][j]);
		}
	}
	alpha[arr[1][1] - 65] = 1;
	backTrack(2, 1, 1);//첫 depth의 값은 이미 정해져있으므로 두번재 depth부터 시작
	cout << _max;
}
