#include <iostream>
#include <vector>
#include <queue>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <climits>

/*
n(2 �� n �� 100)���� ���ð� �ִ�. 
�׸��� �� ���ÿ��� ����Ͽ� �ٸ� ���ÿ� �����ϴ� m(1 �� m �� 100,000)���� ������ �ִ�.
�� ������ �� �� ����� �� �ʿ��� ����� �ִ�.

��� ������ �� (A, B)�� ���ؼ� ���� A���� B�� ���µ� �ʿ��� ����� �ּڰ��� 
���ϴ� ���α׷��� �ۼ��Ͻÿ�.
���� ���ÿ� ���� ���ð� ���� ���� ����.
���� ���ÿ� ���� ���ø� �����ϴ� �뼱�� �ϳ��� �ƴ� �� �ִ�.
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

	cin >> n >> m;//������ ������ ������ ���� �Է�
	for (int i = 1; i <= m; i++)
	{
		cin >> a >> b >> c;//���� ����, ���
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
