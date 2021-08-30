#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
//첫째 줄에 행렬 A의 크기 N 과 M이 주어진다. 
//둘째 줄부터 N개의 줄에 행렬 A의 원소 M개가 순서대로 주어진다. 
//그 다음 줄에는 행렬 B의 크기 M과 K가 주어진다. 
//이어서 M개의 줄에 행렬 B의 원소 K개가 차례대로 주어진다. 
//N과 M, 그리고 K는 100보다 작거나 같고, 
//행렬의 원소는 절댓값이 100보다 작거나 같은 정수이다.

int matrix[105][105];
int matrix2[105][105];
int dab[105][105];
int main()
{
	int n, m, k;
	int in;

	//입력
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> matrix[i][j];
		}
	}

	cin >> m >> k;

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < k; j++)
		{
			cin >> matrix2[i][j];
		}
	}

	//행렬곱
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < k; j++)
		{
			for (int p = 0; p < m; p++)
			{
				dab[i][j] += matrix[i][p] * matrix2[p][j];

			}
			cout << dab[i][j] << " ";
		}
		cout << endl;
	}
}