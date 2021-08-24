#include <iostream>
#include <vector>
#include <queue>
#include <stdlib.h>
#include <string>
#include <algorithm>
/*
N개의 숫자로 구분된 각각의 마을에 한 명의 학생이 살고 있다.

어느 날 이 N명의 학생이 X (1 ≤ X ≤ N)번 마을에 모여서 파티를 벌이기로 했다. 
이 마을 사이에는 총 M개의 단방향 도로들이 있고 i번째 길을 지나는데 
Ti(1 ≤ Ti ≤ 100)의 시간을 소비한다.

각각의 학생들은 파티에 참석하기 위해 걸어가서 다시 그들의 마을로 돌아와야 한다. 
하지만 이 학생들은 워낙 게을러서 최단 시간에 오고 가기를 원한다.

이 도로들은 단방향이기 때문에 아마 그들이 오고 가는 길이 다를지도 모른다. 
N명의 학생들 중 오고 가는데 가장 많은 시간을 소비하는 학생은 누구일지 구하여라.
*/
using namespace std;
const int INF = 2000000000;
const int MAX_V = 20005;//정점 최대개수
priority_queue<pair<int, int>> pq;//maxheap, fir은 가중치 sec는 확인하고 싶은 정점
vector<pair<int, int>>edge[MAX_V];//연결된 간선 리스트,fist 는 그 정점과 연결된 정점, sec는 가중치





int N, M;
int x;
int u, v, t;

//시작마을에서 다른 마을들 까지의 최단거리 구해놓기
vector<int> Dist1(int start) {
	vector<int >dist(MAX_V, INF);//갈수없으면 무한대값으로 일단 초기화되있음
	dist[start] = 0;

	for (auto e : edge[start])
	{
		if (dist[e.first] == INF)
		{
			pq.push({ -e.second,e.first });
		}
	}

	while (!pq.empty()) {
		int now, nowdist;
		nowdist = -pq.top().first;
		now = pq.top().second;
		pq.pop();

		if (dist[now] != INF) {
			continue;
		}

		dist[now] = nowdist;

		for (auto e : edge[now])
		{
			if (dist[e.first] == INF) {
				pq.push({ -(nowdist + e.second), e.first });
			}
		}
	}

	return dist;


}




int main() {
	cin >> N >> M;//마을과 단방향도로의 개수가 주어짐
	cin >> x;//파티하는 마을

	for (int i = 0; i < M; i++)
	{
		cin >> u >> v >> t;//u->v로 가고  걸리는 시간 t
		edge[u].push_back({ v,t });//인접리스트만들기
	}

	int dab = -1;
	//x에서 각 마을까지의 거리 미리 구해두기
	vector<int> come = Dist1(x);

	for (int i = 1; i <= N; i++)
	{
		if (i == x)continue;
		vector<int> go = Dist1(i);
		dab = max(dab, go[x] + come[i]);
	}


	cout << dab;


	return 0;
}

