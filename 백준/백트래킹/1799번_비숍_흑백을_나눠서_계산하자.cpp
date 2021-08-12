#include <iostream>
#include <vector>
#include <queue>
#include <stdlib.h>
#include <algorithm>

using namespace std;
/*
서양 장기인 체스에는 대각선 방향으로 움직일 수 있는 비숍(bishop)이 있다.
< 그림 1 >과 같은 정사각형 체스판 위에 B라고 표시된 곳에 비숍이 있을 때 
비숍은 대각선 방향으로 움직여 O로 표시된 칸에 있는 다른 말을 잡을 수 있다.

그런데 체스판 위에는 비숍이 놓일 수 없는 곳이 있다. 
< 그림 2 >에서 체스판에 색칠된 부분은 비숍이 놓일 수 없다고 하자. 

이와 같은 체스판에 서로가 서로를 잡을 수 없도록 하면서 비숍을 놓는다면
< 그림 3 >과 같이 최대 7개의 비숍을 놓을 수 있다.  
색칠된 부분에는 비숍이 놓일 수 없지만 지나갈 수는 있다.

정사각형 체스판의 한 변에 놓인 칸의 개수를 체스판의 크기라고 한다. 체스판의 크기와 체스판 각 칸에 비숍을 놓을 수 있는지 없는지에 대한 정보가 주어질 때, 서로가 서로를 잡을 수 없는 위치에 놓을 수 있는 비숍의 최대 개수를 구하는 프로그램을 작성하시오.
*/
//흑백으로 나눠야 시간초과 발생안한다고함....ㅜㅅㅜ
//▧ 방향은 col-row의 값이 같다
//▨ 방향은 row+col의 값이 같다

vector<pair<int, int>>v1;//흑
vector<pair<int, int>>v2;//백

int fir[22], sec[22];//오른쪽아래방향(차이저장)-음수나오므로 n-1더해서 저장 , 왼쪽아래방향(합저장) 체크용
int n, Max[2] = { -1,-1 }, bishop = 0;
int arr[11][11];
int sol[11][11];

void backTrack(int depth, int color, vector<pair<int, int>>v) {//color : 0-흑  1-백


	//기저 조건
	if (depth == v.size()) {
		if (Max[color] <= bishop) Max[color] = bishop;
		return;
	};//다돌면 최대개수갱신

	int x = v[depth].first;
	int y = v[depth].second;

	for (int i = 0; i <= 1; i++)//0은 안놓는 경우 1은 놓는 경우
	{
		if (i) {
			//오른쪽 아래 방향 또는 왼쪽 아래 방향에 이미 비숍이 존재할 경우 pass
			if (fir[y - x + (n - 1)] || sec[y + x]) continue;//가지치기
		}

		if (i) {//놓을 수 있는경우
			bishop++;
			fir[y - x + n - 1] = sec[x + y] = 1;

		}

		backTrack(depth + 1, color, v);

		if (i) {//놓을 수 있는경우 - 복원 시키기
			bishop--;
			fir[y - x + n - 1] = sec[x + y] = 0;
		}

	}



}

int main() {
	cin >> n;//체스판 크기
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];//1이면 비숍을 놓을 수 있음, 0 이면 놓을 수 없음
			if (arr[i][j]) {
				//흑백을 나누자
				if ((i + j) % 2 == 0) v1.push_back({ j,i });
				else v2.push_back({ j,i });
			}
		}
	}


	backTrack(0, 0, v1);//흑
	bishop = 0;//초기화 시켜주는거 잊지 말기
	backTrack(0, 1, v2);//백

	cout << Max[0] + Max[1];;

}