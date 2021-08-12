#include <iostream>
#include <vector>
#include <queue>
#include <stdlib.h>
#include <algorithm>

using namespace std;


vector<pair<int, int>>v1;
/*

시간 제한	메모리 제한	제출	정답	맞은 사람	정답 비율
1 초	256 MB	47550	14135	8909	28.135%
문제
스도쿠는 18세기 스위스 수학자가 만든 '라틴 사각형'이랑 퍼즐에서 유래한 것으로 현재 많은 인기를 누리고 있다.
이 게임은 아래 그림과 같이 가로, 세로 각각 9개씩 총 81개의 작은 칸으로 이루어진 정사각형 판 위에서 이뤄지는데,
게임 시작 전 일부 칸에는 1부터 9까지의 숫자 중 하나가 쓰여 있다.

나머지 빈 칸을 채우는 방식은 다음과 같다.

각각의 가로줄과 세로줄에는 1부터 9까지의 숫자가 한 번씩만 나타나야 한다.
굵은 선으로 구분되어 있는 3x3 정사각형 안에도 1부터 9까지의 숫자가 한 번씩만 나타나야 한다.
위의 예의 경우, 첫째 줄에는 1을 제외한 나머지 2부터 9까지의 숫자들이 이미 나타나 있으므로
첫째 줄 빈칸에는 1이 들어가야 한다.



또한 위쪽 가운데 위치한 3x3 정사각형의 경우에는 3을 제외한 나머지 숫자들이 이미 쓰여있으므로
가운데 빈 칸에는 3이 들어가야 한다.

이와 같이 빈 칸을 차례로 채워 가면 다음과 같은 최종 결과를 얻을 수 있다.

게임 시작 전 스도쿠 판에 쓰여 있는 숫자들의 정보가 주어질 때 모든 빈 칸이 채워진
최종 모습을 출력하는 프로그램을 작성하시오.
*/

int arr[11][11];
int sol[82];
//체크용 배열
int garo[10][10], sero[10][10], nemo[10][10];

//스도쿠판 현재 상태 출력 
void print() {
	for (int i = 1; i <= 9; i++) {
		for (int j = 1; j <= 9; j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}


int isok(int x, int y, int gab) {
	int area;//작은 네모 영역 찾기용


	//가로검사
	if (garo[y][gab]) {
		return 0;
	}
	//세로검사
	if (sero[x][gab]) {
		return 0;
	}

	//네모검사
	if (y < 4) {
		if (x < 4) area = 1;
		else if (x < 7) area = 2;
		else area = 3;
		if (nemo[area][gab]) return 0;
	}
	else if (y < 7) {
		if (x < 4) area = 4;
		else if (x < 7) area = 5;
		else area = 6;
		if (nemo[area][gab]) return 0;
	}
	else {
		if (x < 4) area = 7;
		else if (x < 7) area = 8;
		else area = 9;
		if (nemo[area][gab]) return 0;
	}
	return area;
}

int isok2() {
	//모든 칸이 채워졌는지 검사
	for (int i = 1; i <= 9; i++) {
		for (int j = 1; j <= 9; j++) {
			if (!arr[i][j]) return 0;
		}

	}
	return 1;
}


void backTrack(int depth, vector<pair<int, int>>v) {//color : 0-흑  1-백

	//기저 조건
	if (depth == v.size() && isok2()) {
		print();
		exit(0);//즉시 종료
	}

	int x = v[depth].first;
	int y = v[depth].second;
	int area;

	for (int i = 1; i <= 9; i++)
	{
		//가로검사 세로검사 작은네모검사
		area = isok(x, y, i);
		if (area == 0) continue;//가지 치기

		arr[y][x] = i;
		garo[y][i]++;
		sero[x][i]++;
		nemo[area][i]++;

		backTrack(depth + 1, v);

		//복원시키기
		arr[y][x] = 0;
		garo[y][i]--;
		sero[x][i]--;
		nemo[area][i]--;
	}
}

int main() {
	//칸 정보를 하나의 배열에 저장해두고 매번 for문으로 탐색하는건 시간이 너무 걸림
	//아래와 같이 저장하자
	for (int i = 1; i <= 9; i++) {
		for (int j = 1; j <= 9; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 0) v1.push_back({ j,i });
			//가로정보 저장
			garo[i][arr[i][j]]++;
			//세로정보 저장
			sero[j][arr[i][j]]++;
			//작은 네모 정보저장
			if (i < 4) {
				if (j < 4) nemo[1][arr[i][j]]++;
				else if (j < 7) nemo[2][arr[i][j]]++;
				else nemo[3][arr[i][j]]++;
			}
			else if (i < 7) {
				if (j < 4) nemo[4][arr[i][j]]++;
				else if (j < 7) nemo[5][arr[i][j]]++;
				else nemo[6][arr[i][j]]++;
			}
			else {
				if (j < 4) nemo[7][arr[i][j]]++;
				else if (j < 7) nemo[8][arr[i][j]]++;
				else nemo[9][arr[i][j]]++;

			}

		}
	}

	backTrack(0, v1);


}