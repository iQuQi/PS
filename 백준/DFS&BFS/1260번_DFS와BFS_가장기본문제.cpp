#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <queue>
#include <string.h>

/*
�׷����� DFS�� Ž���� ����� BFS�� Ž���� ����� ����ϴ� ���α׷��� �ۼ��Ͻÿ�. 
��, �湮�� �� �ִ� ������ ���� ���� ��쿡�� ���� ��ȣ�� ���� ���� ���� �湮�ϰ�, 
�� �̻� �湮�� �� �ִ� ���� ���� ��� �����Ѵ�. ���� ��ȣ�� 1������ N�������̴�.
*/
using namespace std;
int dab[1001][1001];//�������

bool visited[1001];//�湮����
queue<int> bfs;

int N, M, V;
int a, b;


//DFS �Լ�
void dfss(int now) {

	cout << now << " ";
	for (int i = 1; i <= N; i++) {
		if (dab[now][i] && !visited[i]) {
			visited[i] = 1;
			dfss(i);
		}
	}
}


//BFS
void bfss(int now) {
	bfs.push(now);
	visited[now] = 1;

	while (!bfs.empty()) {
		int now = bfs.front();
		bfs.pop();
		cout << now << " ";
		for (int i = 1; i <= N; i++) {
			if (dab[now][i] && !visited[i]) {
				bfs.push(i);
				visited[i] = 1;
			}
		}

	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M >> V;

	//������ĸ����
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		dab[a][b] = 1;
		dab[b][a] = 1;
	}
	//DFS
	visited[V] = 1;
	dfss(V);
	cout << "\n";


	//BFS
	//�湮 �迭 �ʱ�ȭ
	memset(visited, false, sizeof(visited));
	bfss(V);



}