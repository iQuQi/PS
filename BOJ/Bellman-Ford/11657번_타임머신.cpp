#include <iostream>
#include <vector>
#include <queue>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <climits>
/*
N개의 도시가 있다. 
그리고 한 도시에서 출발하여 다른 도시에 도착하는 버스가 M개 있다. 

각 버스는 A, B, C로 나타낼 수 있는데, A는 시작도시, B는 도착도시, 
C는 버스를 타고 이동하는데 걸리는 시간이다. 시간 C가 양수가 아닌 경우가 있다. 

C = 0인 경우는 순간 이동을 하는 경우, C < 0인 경우는 타임머신으로 시간을 
되돌아가는 경우이다.

1번 도시에서 출발해서 나머지 도시로 가는 가장 빠른 시간을 구하는 프로그램을 작성하시오.
*/
using namespace std;
using ll = long long;

vector<Edge> Edges;
vector<ll> ShortPath;

const ll INF = LLONG_MAX;
int N, M;
int A, B, C;

//간선 클래스 생성
class Edge {
public:
	int from, to, weight;

	Edge() {
		from = 0;
		to = 0;
		weight = 0;
	}

	Edge(int u, int v, int w) {
		from = u;
		to = v;
		weight = w;

	}
	Edge(const Edge& edge) {
		from = edge.from;
		to = edge.to;
		weight = edge.weight;
	}

};


//벨만 포드 코드
bool Bellman_Ford() {
	ShortPath[1] = 0;
	//V번(1번 더 돌려도 문제 없음) 돌려서 최단 경로 탐색
	for (int n = 1; n <= N; n++)//(V번 돌리기)
	{
		for (int m = 0; m < M; m++)//모든 간선을 갱신
		{
			auto e = Edges[m];
			if (ShortPath[e.from] == INF) continue;
			else if (ShortPath[e.to] > ShortPath[e.from] + e.weight)
				ShortPath[e.to] = ShortPath[e.from] + e.weight;
		}
	}

	bool ret = true;//ret는 음수사이클이 있다면 false

	//V번을 또 돌려서 음수 사이클 존재 파악
	for (int n = 1; n <= N; n++)
	{
		for (int m = 0; m < M; m++)
		{
			auto e = Edges[m];
			if (ShortPath[e.from] == INF) continue;
			//아래부분이 다른 점
			else if (ShortPath[e.from] == -INF)
				ShortPath[e.to] = -INF;
			else if (ShortPath[e.to] > ShortPath[e.from] + e.weight) {
				ShortPath[e.to] = -INF;
				ret = false;//음수사이클 존재
			}

		}
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M; // 도시의 개수와 버스 노선의 개수 입력
	ShortPath.resize(N + 1, INF);//초기화

	for (int m = 1; m <= M; m++)
	{
		cin >> A >> B >> C;//버스 노선의 정보
		Edges.push_back(Edge(A, B, C));
	}

	if (Bellman_Ford()) {
		//1번 도시에서 출발
		for (int n = 2; n <= N; n++)
		{
			if (ShortPath[n] == INF)cout << "-1\n"; // 해당 도시로 가는 경로가 없다면
			else cout << ShortPath[n] << "\n";//가장 빠른 시간을 도시 순서대로 출력
		}
	}
	else cout << "-1\n"; // 음수 사이클 존재 시 
}

