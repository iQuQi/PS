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
������ ������ �߰��� ��ũ ������ ������ ã�Ƴ�����. 
������ ������ �Ʒ� �׸��� ���� ���簢�� ����̸� ���� ĭ���� �������� �ִ�. 
�� ĭ�� ����(L)�� �ٴ�(W)�� ǥ�õǾ� �ִ�. 

�� �������� �̵��� �����¿�� �̿��� �����θ� �����ϸ�, �� ĭ �̵��ϴµ� �� �ð��� �ɸ���. 
������ ���� ���� �ִ� �Ÿ��� �̵��ϴµ� �־� ���� �� �ð��� �ɸ��� ���� �� ���� ������ �����ִ�
������ ��Ÿ���� �� �� ���̸� �ִ� �Ÿ��� �̵��Ϸ��� ���� ���� �� �� �̻� �������ų�, 
�ָ� ���ư����� �� �ȴ�.

���� ��� ���� ���� ������ �־����ٸ� ������ �Ʒ� ǥ�õ� �� ���� ���� �ְ� �ǰ�, 
�� �� ������ �ִ� �Ÿ��� �̵��ϴ� �ð��� 8�ð��� �ȴ�.

���� ������ �־��� ��, ������ ���� �ִ� �� �� ���� �ִ� �Ÿ��� �̵��ϴ� �ð��� ���ϴ�
���α׷��� �ۼ��Ͻÿ�
*/

int n, m;
int dx[4] = { 1,0,-1,0 }, dy[4] = { 0,1,0,-1 }; // ������ �Ʒ��� ���� ����
int visited[50][50];

int isok(int x, int y) {
	if (x < 0 || y < 0 || x >= m || y >= n || visited[y][x] || arr[y][x] == 'W') return false;
	return true;
}

void print() {
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << visited[i][j];
		}
		cout << "\n";
	}
	cout << "\n";
}

//visit �迭 �ʱ�ȭ
void reset() {
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			visited[i][j] = 0;
		}
	}
}

int bfs(int x, int y) {
	queue<pair<pair<int, int>, int>> q;
	pair<int, int> pos;

	pos.first = x;
	pos.second = y;

	q.push({ pos,0 });
	visited[y][x] = 1;

	int dep = 0;
	while (!q.empty()) {
		pair<pair<int, int>, int>now = q.front();
		q.pop();

		x = now.first.first;
		y = now.first.second;

		//�׹��� �˻�
		for (int k = 0; k < 4; k++)
		{
			//���� �˻�
			if (isok(x + dx[k], y + dy[k])) {
				q.push({ { x + dx[k],y + dy[k] }, now.second + 1 });
				visited[y + dy[k]][x + dx[k]] = 1;
				//�ִܰŸ� �����Ҷ��� �׻� �Ʒ��� ������ �˻�������
				if (dep <= (now.second + 1)) dep = now.second + 1;
			}
		}
	}
	return dep;
}


int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	//���� ����
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			//L/W�� ǥ�õ� ���������� �־���
			cin >> arr[i][j];
		}
	
	int max = -1;

	//�ִܰ�θ� ���Ѵ�
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (arr[i][j] == 'L') {
				int tmp = bfs(j, i);
				if (tmp >= max) max = tmp;
				reset();
			}
		}
	}

	cout << max << "\n";


}

