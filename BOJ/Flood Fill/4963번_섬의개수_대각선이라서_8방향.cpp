#include <iostream>
#include <string>
#include <queue>
#include <vector>
using namespace std;
int arr[51][51];
int com = 0, h, w;
int dx[8] = { 0,1,0,-1 ,1,1,-1,-1 };
int dy[8] = { 1,0,-1,0 ,1,-1,-1,1 };
//k 0 - 아래, 1 - 오른쪽, 2 - 위 ,3 - 왼쪽 
int visited[51][51];
/*
정사각형으로 이루어져 있는 섬과 바다 지도가 주어진다. 
섬의 개수를 세는 프로그램을 작성하시오.

한 정사각형과 가로, 세로 또는 대각선으로 연결되어 있는 사각형은 걸어갈 수 있는 사각형이다.

두 정사각형이 같은 섬에 있으려면, 한 정사각형에서 다른 정사각형으로 걸어서 갈 수 있는 
경로가 있어야 한다. 지도는 바다로 둘러싸여 있으며, 지도 밖으로 나갈 수 없다.
*/

bool isOk(int i, int j) {
	if (i<0 || i>h || j<0 || j>w || visited[i][j] || !arr[i][j])
	{
		return false;
	}
	return true;
}

void dfs(int i, int j) {
	visited[i][j] = 1;
	for (int k = 0; k < 8; k++)
	{
		if (isOk(i + dx[k], j + dy[k])) {
			dfs(i + dx[k], j + dy[k]);
		}
	}

}



int main()
{
	//테스트 케이스
	while (1) {
		cin >> w >> h;
		com = 0;
		if (w == 0 && h == 0)break;
		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				cin >> arr[i][j];//1은 땅 0은 바다
			}
		}

		//컴포넌트 세기
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (!visited[i][j] && arr[i][j])
				{
					com++;
					dfs(i, j);
				}
			}
		}

		//visit 배열 초기화
		for (int i = 0; i < 51; i++)
		{
			for (int j = 0; j < 51; j++)
			{

				visited[i][j] = 0;
				arr[i][j] = 0;
			}
		}

		cout << com << endl;
	}
}