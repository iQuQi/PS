#include <iostream>
#include <vector>
#include <queue>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <climits>
/*
때는 2020년, 백준이는 월드나라의 한 국민이다. 
월드나라에는 N개의 지점이 있고 N개의 지점 사이에는 M개의 도로와 W개의 웜홀이 있다. 
(단 도로는 방향이 없으며 웜홀은 방향이 있다.) 

웜홀은 시작 위치에서 도착 위치로 가는 하나의 경로인데, 
특이하게도 도착을 하게 되면 시작을 하였을 때보다 시간이 뒤로 가게 된다. 
웜홀 내에서는 시계가 거꾸로 간다고 생각하여도 좋다.

시간 여행을 매우 좋아하는 백준이는 한 가지 궁금증에 빠졌다. 
한 지점에서 출발을 하여서 시간여행을 하기 시작하여 다시 출발을 하였던 
위치로 돌아왔을 때, 출발을 하였을 때보다 시간이 되돌아가 있는 경우가 있는지 없는지 
궁금해졌다. 

여러분은 백준이를 도와 이런 일이 가능한지 불가능한지 구하는 프로그램을 작성하여라.
*/
using namespace std;
using ll = long long;


vector<Edge> Edges;
vector<ll> ShortPath;

const ll INF = LLONG_MAX;
int N, M, W;
int s, e, t;

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

bool Bellman_Ford(int start) {
	ShortPath[start] = 0;
	for (int n = 1; n <= N; n++)
	{
		for (int m = 0; m < 2 * M + W; m++) // 양방향인 도로개수*2 + 단방향 웜홀
		{
			auto e = Edges[m];
			if (ShortPath[e.from] == INF) continue;
			else if (ShortPath[e.to] > ShortPath[e.from] + e.weight)
				ShortPath[e.to] = ShortPath[e.from] + e.weight;
		}
	}

	bool ret = true;

	for (int n = 1; n <= N; n++)
	{
		for (int m = 0; m < 2 * M + W; m++)
		{
			auto e = Edges[m];
			if (ShortPath[e.from] == INF) continue;
			else if (ShortPath[e.from] == -INF)
				ShortPath[e.to] = -INF;
			else if (ShortPath[e.to] > ShortPath[e.from] + e.weight) {
				ShortPath[e.to] = -INF;
				ret = false;//음수 사이클 존재
			}
		}
	}
	return ret;
}

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int tc;
	vector<string>str;
	cin >> tc;//테스트 케이스

	for (int i = 0; i < tc; i++)
	{
		cin >> N >> M >> W;//지점 개수, 도록의 개수, 웜홀의 개수
		ShortPath.assign(N + 1, INF);//초기화

		//도로 정보 - 양방향
		for (int j = 0; j < M; j++)
		{
			cin >> s >> e >> t;//시작점, 도착점, t는 걸리는 시간
			Edges.push_back(Edge(s, e, t));
			Edges.push_back(Edge(e, s, t));
		}

		//웜홀 정보 - 단방향
		for (int k = 0; k < W; k++)
		{
			cin >> s >> e >> t;//t는 줄어드는 시간
			Edges.push_back(Edge(s, e, -t));
		}

		bool dab = false;//음수사이클 체크

		for (int j = 1; j <= N; j++)
		{
			if (ShortPath[j] != INF) continue; // 시작점으로 돌아올 수 없다면
			if (!Bellman_Ford(j)) {//시작점으로 돌아올 수 있다면

				dab = true;//음수사이클 존재
				break;
			}
		}

		if (dab) str.push_back("YES\n");//음수사이클 존재
		else str.push_back("NO\n");//음수사이클 없음

		Edges.clear(); // 테스트 케이스가 존재할때는 초기화를 잊지말자
	}

	for (int i = 0; i < str.size(); i++)
	{
		cout << str[i];
	}


}

