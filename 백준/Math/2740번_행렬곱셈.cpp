#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
//ù° �ٿ� ��� A�� ũ�� N �� M�� �־�����. 
//��° �ٺ��� N���� �ٿ� ��� A�� ���� M���� ������� �־�����. 
//�� ���� �ٿ��� ��� B�� ũ�� M�� K�� �־�����. 
//�̾ M���� �ٿ� ��� B�� ���� K���� ���ʴ�� �־�����. 
//N�� M, �׸��� K�� 100���� �۰ų� ����, 
//����� ���Ҵ� ������ 100���� �۰ų� ���� �����̴�.

int matrix[105][105];
int matrix2[105][105];
int dab[105][105];
int main()
{
	int n, m, k;
	int in;

	//�Է�
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

	//��İ�
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