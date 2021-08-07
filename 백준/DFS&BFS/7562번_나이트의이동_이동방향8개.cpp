#include <iostream>
#include <vector>
#include <queue>
using namespace std;
/*
체스판 위에 한 나이트가 놓여져 있다. 나이트가 한 번에 이동할 수 있는 칸은 아래 그림에 나와있다.
나이트가 이동하려고 하는 칸이 주어진다. 나이트는 몇 번 움직이면 이 칸으로 이동할 수 있을까?
*/
int arr[305][305];
//나이트가 이동할 수 있는 방향
int dx[8] = { 1,1,-1,-1,2,2,-2,-2 };
int dy[8] = { 2,-2,2,-2,1,-1,1,-1 };

int cnt = 0;
int n, l, nx, ny, wx, wy;
int visited[305][305] = { 0 };

//조건 검사 함수
int is_ok(int x, int y) {
	if (x < 0 || x >= l || y < 0 || y >= l || visited[y][x]) {
		return 0;
	}
	return 1;
}

//이동 횟수 구하기
int knight(int l, int nx, int ny, int wx, int wy) {

	if (nx == wx && ny == wy) return 0; // 원래 그위치라면
	queue<pair<pair<int, int>, int>>q;//x랑 y 좌표

	//초기화
	for (int i = 0; i < 305; i++)
	{
		for (int j = 0; j < 305; j++)
		{
			visited[i][j] = 0;
		}
	}
	//시작점 push
	q.push({ { nx,ny },0 });
	visited[ny][nx] = 1;


	//큐가 빌때까지
	while (!q.empty()) {
		int size = q.size();
		pair < pair<int, int>, int > now = q.front();
		q.pop();

		int x = now.first.first;
		int y = now.first.second;
		int cnt = now.second;

		//8방향 모두 체크
		for (int i = 0; i < 8; i++)
		{
			//조건 검사
			if (is_ok(x + dx[i], y + dy[i])) {
				q.push({ { x + dx[i], y + dy[i]} ,cnt + 1 });
				visited[y + dy[i]][x + dx[i]] = 1;//방문 체크

				//목적지에 도착한 경우
				if (x + dx[i] == wx && y + dy[i] == wy) return cnt + 1;
			}
		}
	}
	return -1;
}


int main() {

	cin >> n;//테스트개수
	for (int i = 0; i < n; i++) {
		// 1.판 한변의 길이 2.현재 나이트 좌표 3. 목표좌표
		cin >> l >> nx >> ny >> wx >> wy;
		cout << knight(l, nx, ny, wx, wy) << endl;
	}
}