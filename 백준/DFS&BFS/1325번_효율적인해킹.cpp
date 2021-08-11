#include <queue>
#include <stack>
#include <map>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <climits>
#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
char arr[50][50];

/*
��Ŀ �������� �� �˷��� ��� ȸ�縦 ��ŷ�Ϸ��� �Ѵ�. 
�� ȸ��� N���� ��ǻ�ͷ� �̷���� �ִ�. �������� ������ ������,
�� ���� ��ŷ���� ���� ���� ��ǻ�͸� ��ŷ �� �� �ִ� ��ǻ�͸� ��ŷ�Ϸ��� �Ѵ�.

�� ȸ���� ��ǻ�ʹ� �ŷ��ϴ� �����, �ŷ����� �ʴ� ����� �̷���� �ִµ�, 
A�� B�� �ŷ��ϴ� ��쿡�� B�� ��ŷ�ϸ�, A�� ��ŷ�� �� �ִٴ� �Ҹ���.

�� ȸ���� ��ǻ���� �ŷ��ϴ� ���谡 �־����� ��, 
�� ���� ���� ���� ��ǻ�͸� ��ŷ�� �� �ִ� ��ǻ���� ��ȣ�� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.
*/
int n, m;
vector<int> list[10000 + 1];
int visited[10000 + 1];
int hack = 0;

void print() {
	//���� ����Ʈ �̱�
	cout << "adj list!!!" << endl;
	for (int i = 1; i <= n; i++)
	{

		cout << i << " : ";
		for (int j = 0; j < list[i].size(); j++)
		{
			cout << list[i][j] << " ";
		}
		cout << "\n";
	}
}

//visit �迭 �ʱ�ȭ
void reset() {
	for (int i = 1; i <= 10000; i++)
	{
		visited[i] = 0;
	}
}


int dfs(int s) {

	visited[s] = 1;
	hack++;

	for (int i = 0; i < list[s].size(); i++)
	{
		if (!visited[list[s][i]]) {
			dfs(list[s][i]);
		}
	}

	return hack;

}


int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);


	int hack_com[10000 + 1];
	int a, b;
	cin >> n >> m;
	//��������Ʈ ����
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b;
		list[b].push_back(a);
	}

	int max = -1;

	//�� ��ǻ�Ͱ� ��ŷ�� �� �ִ� ��ǻ���� ���� ���ϰ� max ���� ���Ѵ�
	for (int i = 1; i <= n; i++)
	{
		hack_com[i] = dfs(i);
		if (hack >= max) max = hack_com[i];
		hack = 0;

		//�ʱ�ȭ�� ��������!!
		reset();
	}

	//max���� ���� ��ǻ�� ã��
	for (int i = 1; i <= n; i++)
	{
		if (hack_com[i] == max) cout << i << " ";
	}

}

