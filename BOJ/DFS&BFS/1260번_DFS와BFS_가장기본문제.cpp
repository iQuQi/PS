#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <queue>
#include <string.h>

/*
그래프를 DFS로 탐색한 결과와 BFS로 탐색한 결과를 출력하는 프로그램을 작성하시오. 
단, 방문할 수 있는 정점이 여러 개인 경우에는 정점 번호가 작은 것을 먼저 방문하고, 
더 이상 방문할 수 있는 점이 없는 경우 종료한다. 정점 번호는 1번부터 N번까지이다.
*/
using namespace std;
int dab[1001][1001];//인접행렬

bool visited[1001];//방문여부
queue<int> bfs;

int N, M, V;
int a, b;


//DFS 함수
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

	//인접행렬만들기
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
	//방문 배열 초기화
	memset(visited, false, sizeof(visited));
	bfss(V);



}