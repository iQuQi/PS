#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>


using namespace std;

int arr[105][105];//사과
vector<pair<int, int>>bam;//뱀몸위치저장
queue<pair<int, char>> q;//방향전환 정보 저장

int n;//보드크기 nxn
int k;//사과의개수
int l;//방향변환 횟수(왼쪽=L,오른쪽=D)
int tailIndex = 0; //뱀 벡터에서 꼬리위치

//뱀길이=1 처음에 오른쪽향함
//사과의 위치와 이동경로가 주어짐

//현재 뱀위치 출력
void print() {
	int arr[105][105] = { 0, };
	for (int i = tailIndex; i < bam.size(); i++)
	{
		int x = bam[i].first;
		int y = bam[i].second;
		arr[y][x] = 1;
	}

	for (int i = 1; i < n; i++)
	{
		for (int j = 1; j < n; j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}


int isok(int x, int y) {
	//벽에 부딪히는 경우
	if (x<1 || x>n || y<1 || y>n) {
		return 0;
	}
	//자기 몸과 부딪히는 경우
	for (int i = tailIndex; i < bam.size(); i++)
	{
		if (bam[i].first == x && bam[i].second == y) {
			return 0;
		}
	}
	return 1;
}

int main() {
	cin >> n >> k;
	for (int i = 0; i < k; i++)
	{
		int h, y;
		cin >> h >> y;
		arr[h][y] = 1;//사과위치
	}

	cin >> l;
	for (int i = 0; i < l; i++)
	{
		int turn; // 몇초뒤에 방향바꾸는지
		char dir;// L이면 왼쪽 D면 오른쪽
		cin >> turn >> dir;
		q.push({ turn,dir });
	}

	//입력끝

	int time = 0;
	int nDir = 0;//nDir : 현재 방향 0 = 오른쪽  1=아래   2=왼쪽   3=위
	bam.push_back({ 1,1 });//뱀의 몸이 현재위치하는 길의 X Y 좌표, 순서대로(꼬리->머리)

	int headX = 1;
	int headY = 1;

	while (1) {
		time++;

		if (nDir == 0) {
			headX++;
			if (!isok(headX, headY)) break;
			bam.push_back({ headX,headY });
			if (!arr[headY][headX]) {
				tailIndex++;
			}
			else arr[headY][headX] = 0;
		}
		else if (nDir == 1) {
			headY++;
			if (!isok(headX, headY)) break;
			bam.push_back({ headX,headY });
			if (!arr[headY][headX]) {
				tailIndex++;
			}
			else arr[headY][headX] = 0;
		}
		else if (nDir == 2) {
			headX--;
			if (!isok(headX, headY)) break;
			bam.push_back({ headX,headY });
			if (!arr[headY][headX]) {
				tailIndex++;
			}
			else arr[headY][headX] = 0;
		}
		else {
			headY--;
			if (!isok(headX, headY)) break;
			bam.push_back({ headX,headY });
			if (!arr[headY][headX]) {
				tailIndex++;
			}
			else arr[headY][headX] = 0;
		}


		//다음time이 방향전환 time일경우 방향전환
		if (!q.empty() && q.front().first == time) {
			if (q.front().second == 'D') nDir = (nDir + 1) % 4;
			else {
				nDir--;
				if (nDir == -1) nDir = 3;
			}
			q.pop();
		}

	}

	cout << time;
}