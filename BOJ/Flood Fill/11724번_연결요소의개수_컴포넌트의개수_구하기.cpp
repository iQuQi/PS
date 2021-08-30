#include <iostream>
#include <vector>
using namespace std;
int dab[1001][1001];//인접행렬
//방향 없는 그래프가 주어졌을 때, 연결 요소 (Connected Component)의 개수를 
//구하는 프로그램을 작성하시오.


bool visited[1001];//방문여부
int N, M;
//DFS 함수
void dfss(int now) {

	for (int i = 1; i <= N; i++) {
		if (dab[now][i] && !visited[i]) {
			visited[i] = 1;
			dfss(i);
		}
	}
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	int a, b;
	int com = 0;
	//인접행렬만들기
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		dab[a][b] = 1;
		dab[b][a] = 1;

	}

	//컴포넌트의 수를 구하기
	for (int i = 1; i <= N; i++)
	{
		if (visited[i])	continue;
		visited[i] = 1;
		com++;
		dfss(i);
	}


	cout << com << "\n";

}