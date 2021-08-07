#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
int arr[1001][1001];//3차원배열은 처음인자가 층수
int day = 0, m, n, h, k;
int dx[6] = { 0,1,0,-1,0,0 };
int dy[6] = { 1,0,-1,0,0,0 };
int _z[6] = { 0,0,0,0,1,-1 };
queue<pair<pair<int, int>, int> > q; //x y 익은날짜
/*
철수의 토마토 농장에서는 토마토를 보관하는 큰 창고를 가지고 있다.
토마토는 아래의 그림과 같이 격자 모양 상자의 칸에 하나씩 넣어서 창고에 보관한다.

창고에 보관되는 토마토들 중에는 잘 익은 것도 있지만, 
아직 익지 않은 토마토들도 있을 수 있다. 

보관 후 하루가 지나면, 익은 토마토들의 인접한 곳에 있는 
익지 않은 토마토들은 익은 토마토의 영향을 받아 익게 된다. 

하나의 토마토의 인접한 곳은 왼쪽, 오른쪽, 앞, 뒤 네 방향에 있는 토마토를 의미한다. 
대각선 방향에 있는 토마토들에게는 영향을 주지 못하며, 
토마토가 혼자 저절로 익는 경우는 없다고 가정한다.

철수는 창고에 보관된 토마토들이 며칠이 지나면 다 익게 되는지, 
그 최소 일수를 알고 싶어 한다.

토마토를 창고에 보관하는 격자모양의 상자들의 크기와 
익은 토마토들과 익지 않은 토마토들의 정보가 주어졌을 때, 
며칠이 지나면 토마토들이 모두 익는지, 그 최소 일수를 구하는 프로그램을 작성하라.

단, 상자의 일부 칸에는 토마토가 들어있지 않을 수도 있다.
*/

int main()
{
	cin >> m >> n; //m가로n세로
	//배열 입력받기

	//토마토 정보 입력 받기
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++){
			cin >> arr[i][j];
		}
	}

	//익어있는 토마토의 위치 정보를 q에 pair로 저장
	for (int j = 1; j <= n; j++)
	{
		for (int k = 1; k <= m; k++)
		{
			if (arr[j][k] == 1) q.push({ { k ,j}, 0 });
			
		}
	}
	pair <pair< int, int>, int> now;

	//큐가 빌때까지 반복
	while (!q.empty()) {
		now = q.front();
		q.pop();

		//상하좌우에 대해 모두
		for (int i = 0; i < 4; i++)
		{
			int nextx = now.first.first + dx[i];
			int nexty = now.first.second + dy[i];

			//조건 검사 - 통 내부의 좌표 & next토마토가 존재하고 아직 익지 않은 상태라면
			if (nextx >= 1 && nextx <= m && nexty >= 1 && nexty <= n && arr[nexty][nextx] == 0)
			{
				arr[nexty][nextx] = 1; // 익었음을 표시
				q.push({ {nextx, nexty},  now.second + 1 }); //익은 토마토를 저장하는 큐에 넣어줌
				day = max(now.second + 1, day); //날짜 갱신
			}
		}
	}

	//토마토가 모두 익지 못하는 상황이면 -1을 출력
	for (int j = 1; j <= n; j++)
	{
		for (int k = 1; k <= m; k++)
		{
			if (arr[j][k] == 0)
			{
				cout << "-1" << "\n";
				return 0;
			}
		}
	}
	//아니라면 최소 날짜 출력
	cout << day << "\n";
	return 0;
}