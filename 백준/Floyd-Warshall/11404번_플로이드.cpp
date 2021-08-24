#include <iostream>
#include <vector>
#include <queue>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <climits>

/*
n(2 ≤ n ≤ 100)개의 도시가 있다. 
그리고 한 도시에서 출발하여 다른 도시에 도착하는 m(1 ≤ m ≤ 100,000)개의 버스가 있다.
각 버스는 한 번 사용할 때 필요한 비용이 있다.

모든 도시의 쌍 (A, B)에 대해서 도시 A에서 B로 가는데 필요한 비용의 최솟값을 
구하는 프로그램을 작성하시오.
시작 도시와 도착 도시가 같은 경우는 없다.
시작 도시와 도착 도시를 연결하는 노선은 하나가 아닐 수 있다.
*/
using namespace std;
int n, m;
int a, b, c;
const int MAX_N = 102;
int DP[MAX_N][MAX_N];

const int INF = MAX_N * 100'000;
void Floyd_Warshall() {
	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				DP[i][j] = min(DP[i][j], DP[i][k] + DP[k][j]);

			}

		}
	}

}

int main() {
	for (int i = 0; i < MAX_N; i++)
	{
		for (int j = 0; j < MAX_N; j++)
		{
			if (i == j)DP[i][j] = 0;
			else DP[i][j] = INF;
		}
	}

	cin >> n >> m;//도시의 개수와 버스의 개수 입력
	for (int i = 1; i <= m; i++)
	{
		cin >> a >> b >> c;//시작 도착, 비용
		DP[a][b] = min(DP[a][b], c);
	}

	Floyd_Warshall();


	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (DP[i][j] == INF)DP[i][j] = 0;
			cout << DP[i][j] << " ";
		}
		cout << "\n";
	}
	return 0;


}
