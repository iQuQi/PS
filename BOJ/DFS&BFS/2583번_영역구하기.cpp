#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
int arr[101][101];
int com = 0, m, n, k;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
//k 0 - 아래, 1 - 오른쪽, 2 - 위 ,3 - 왼쪽 
int visited[101][101];
int area[100];


/*
눈금의 간격이 1인 M×N(M,N≤100)크기의 모눈종이가 있다. 
이 모눈종이 위에 눈금에 맞추어 K개의 직사각형을 그릴 때, 
이들 K개의 직사각형의 내부를 제외한 나머지 부분이 몇 개의 분리된 영역으로 나누어진다.

예를 들어 M=5, N=7 인 모눈종이 위에 <그림 1>과 같이 직사각형 3개를 그렸다면, 
그 나머지 영역은 <그림 2>와 같이 3개의 분리된 영역으로 나누어지게 된다.



<그림 2>와 같이 분리된 세 영역의 넓이는 각각 1, 7, 13이 된다.

M, N과 K 그리고 K개의 직사각형의 좌표가 주어질 때, 
K개의 직사각형 내부를 제외한 나머지 부분이 몇 개의 분리된 영역으로 나누어지는지, 
그리고 분리된 각 영역의 넓이가 얼마인지를 구하여 이를 출력하는 프로그램을 작성하시오.

입력되는 K개의 직사각형들이 모눈종이 전체를 채우는 경우는 없다.
*/


//조건 검사 함수
bool isOk(int i, int j) {
	if (i < 0 || i >= m || j < 0 || j >= n || visited[i][j] || arr[i][j])
	{
		return false;
	}
	return true;
}


//DFS 함수
void dfs(int i, int j) {

	visited[i][j] = 1;
	for (int k = 0; k < 4; k++)
	{
		//조건 검사
		if (isOk(i +dx[k], j + dy[k])) {
			area[com] += 1;
			dfs(i + dx[k], j + dy[k]);
		}
	}
}

int main()
{
	//세로, 가로 , 직사각형의 개수 입력 받기
	cin >> m >> n >> k;
	int x1, y1, x2, y2;
	for (int i = 0; i < k; i++)
	{
		//왼쪽 아래 x y & 오른쪽 위 x y 좌표 입력 받기
		//모눈 종이 왼쪽 아래가 (0,0)
		cin >> x1 >> y1 >> x2 >> y2;
		for (int j = x1; j < x1 + (x2 - x1); j++)
		{
			for (int t = y1; t < y1 + abs(y2 - y1); t++)
			{
				//모눈종이에서 칸이 채워진 곳을 저장
				arr[t][j] = 1;
			}
		}
	}


	//컴포넌트 구하기
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (!visited[i][j] && !arr[i][j])
			{
				com++;
				area[com] += 1;
				dfs(i, j);
			}
		}
	}

	//첫째 줄에 분리되어 나누어지는 영역의 개수를 출력
	//둘째 줄에는 각 영역의 넓이를 오름차순으로 정렬하여 빈칸을 사이에 두고 출력
	cout << com << endl;
	sort(area + 1, area + com + 1);
	for (int i = 1; i <= com; i++) cout << area[i] << " ";
	

}