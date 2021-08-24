#include <iostream>
#include <vector>
#include <queue>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <list>
#include <climits>
/*
n(1 �� n �� 100)���� ���ð� �ִ�. 
�׸��� �� ���ÿ��� ����Ͽ� �ٸ� ���ÿ� �����ϴ� m(1 �� m �� 100,000)���� ������ �ִ�.
�� ������ �� �� ����� �� �ʿ��� ����� �ִ�.

��� ������ �� (A, B)�� ���ؼ� ���� A���� B�� ���µ� �ʿ��� ����� �ּڰ��� ���ϴ� 
���α׷��� �ۼ��Ͻÿ�.

-���
����, n���� ���� ����ؾ� �Ѵ�. i��° �ٿ� ����ϴ� j��° ���ڴ� 
���� i���� j�� ���µ� �ʿ��� �ּ� ����̴�. ����, i���� j�� �� �� ���� ��쿡��
�� �ڸ��� 0�� ����Ѵ�.

�� �������� n��n���� ���� ����ؾ� �Ѵ�. i��n+j��° �ٿ��� 
���� i���� ���� j�� ���� �ּ� ��뿡 ���ԵǾ� �ִ� ������ ���� k�� ����Ѵ�. 
�� ����, ���� i���� ���� j�� ���� ��θ� �������� ������ ����Ѵ�. 

�̶�, ���� i�� ���� j�� ����ؾ� �Ѵ�. ����, i���� j�� �� �� ���� ��쿡�� 
0�� ����Ѵ�.
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
					between[i][j] = k;//������ ����
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

//�߰� ��θ� ��� - ����Լ��� �ɰ��� ���
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


//��� ���
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
			kCount(i, j); // �ּ� ��뿡 ���ԵǾ��ִ� ������ ���� ���
			cout << cnt + 1 << " ";

			print2(i, j);//�߰� ��� ���
			cout << j;//������ ���
			cout << "\n";
		}

	}

}



int main() {

	//�ʱ�ȭ
	for (int i = 0; i < MAX_N; i++)
	{
		for (int j = 0; j < MAX_N; j++)
		{
			if (i == j)DP[i][j] = 0;
			else DP[i][j] = INF;
		}
	}

	//��ο� ��� �Է� �ޱ�
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
	{
		cin >> a >> b >> c;
		DP[a][b] = min(DP[a][b], c);
	}

	Floyd_Warshall();

	//�ּҺ�� ���
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (DP[i][j] == INF)DP[i][j] = 0;
			cout << DP[i][j] << " ";
		}
		cout << "\n";
	}

	//��� ���
	print();
	return 0;
}
