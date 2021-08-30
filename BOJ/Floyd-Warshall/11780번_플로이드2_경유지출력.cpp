#include <iostream>
#include <vector>
#include <queue>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <list>
#include <climits>
/*
n(1 ≤ n ≤ 100)개의 도시가 있다. 
그리고 한 도시에서 출발하여 다른 도시에 도착하는 m(1 ≤ m ≤ 100,000)개의 버스가 있다.
각 버스는 한 번 사용할 때 필요한 비용이 있다.

모든 도시의 쌍 (A, B)에 대해서 도시 A에서 B로 가는데 필요한 비용의 최솟값을 구하는 
프로그램을 작성하시오.

-출력
먼저, n개의 줄을 출력해야 한다. i번째 줄에 출력하는 j번째 숫자는 
도시 i에서 j로 가는데 필요한 최소 비용이다. 만약, i에서 j로 갈 수 없는 경우에는
그 자리에 0을 출력한다.

그 다음에는 n×n개의 줄을 출력해야 한다. i×n+j번째 줄에는 
도시 i에서 도시 j로 가는 최소 비용에 포함되어 있는 도시의 개수 k를 출력한다. 
그 다음, 도시 i에서 도시 j로 가는 경로를 공백으로 구분해 출력한다. 

이때, 도시 i와 도시 j도 출력해야 한다. 만약, i에서 j로 갈 수 없는 경우에는 
0을 출력한다.
*/
using namespace std;
int n, m;
int a, b, c;
int cnt = 0;
const int MAX_N = 102;
int DP[MAX_N][MAX_N];
int between[105][105];
list<int> L[10000 + 1];
const int INF = MAX_N * 100'000;
void Floyd_Warshall() {
	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (DP[i][j] > DP[i][k] + DP[k][j]) {
					DP[i][j] = DP[i][k] + DP[k][j];
					between[i][j] = k;//경유지 저장
				}


			}

		}
	}

}

void printBe() {
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++) cout << between[i][j] << " ";
		cout << "\n";
	}
}

//중간 경로를 출력 - 재귀함수로 쪼개서 출력
void print2(int start, int end) {
	if (between[start][end] == 0) {
		cout << start << " ";
		return;
	}

	print2(start, between[start][end]);
	print2(between[start][end], end);
}


void kCount(int start, int end) {
	
	if (between[start][end] == 0) {
		cnt++;
		return;
	}

	kCount(start, between[start][end]);
	kCount(between[start][end], end);
}


//경로 출력
void print() {
	int num = 1;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (DP[i][j] == 0) {
				cout << 0 << "\n";
				continue;
			}

			cnt = 0;
			kCount(i, j); // 최소 비용에 포함되어있는 도시의 개수 출력
			cout << cnt + 1 << " ";

			print2(i, j);//중간 경로 출력
			cout << j;//도착점 출력
			cout << "\n";
		}

	}

}



int main() {

	//초기화
	for (int i = 0; i < MAX_N; i++)
	{
		for (int j = 0; j < MAX_N; j++)
		{
			if (i == j)DP[i][j] = 0;
			else DP[i][j] = INF;
		}
	}

	//경로와 비용 입력 받기
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
	{
		cin >> a >> b >> c;
		DP[a][b] = min(DP[a][b], c);
	}

	Floyd_Warshall();

	//최소비용 출력
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (DP[i][j] == INF)DP[i][j] = 0;
			cout << DP[i][j] << " ";
		}
		cout << "\n";
	}

	//경로 출력
	print();
	return 0;
}
