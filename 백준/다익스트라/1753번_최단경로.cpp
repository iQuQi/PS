#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>

/*
방향그래프가 주어지면 주어진 시작점에서 다른 모든 정점으로의 최단 경로를 구하는 
프로그램을 작성하시오. 
단, 모든 간선의 가중치는 10 이하의 자연수이다.
*/
using namespace std;
const int INF = 2000000000;
const int MAX_V = 20005;
priority_queue<pair<int, int>> pq;
vector<pair<int, int>>edge[MAX_V];
vector<int >dist(MAX_V, INF);
int V, E;
int K;
int u, v, w;
void Dist(int start) {
	dist[start] = 0;

	
	for (auto e : edge[start])//시작점에서 연결된 모든 인접 정점에대해
	{
		//아직 확정난 정점이 아니라면
		if (dist[e.first] == INF)
		{
			pq.push({ -e.second,e.first });
			//가중치와 끝점을 넣어주되 가중치는 음수로 넣어주어서
			//오름차순으로 만들어주기
		}
	}

	//큐가 빌때까지
	while (!pq.empty()) {
		int now, nowdist;
		nowdist = -pq.top().first;
		now = pq.top().second;
		pq.pop();

		//이미 결정난 정점인 경우 패스
		if (dist[now] != INF) {
			continue;
		}

		//최단 거리 결정
		dist[now] = nowdist;

		//연결된 모든 정점을 큐에 넣어준다
		for (auto e : edge[now])
		{
			if (dist[e.first] == INF) {
				pq.push({ -(nowdist + e.second), e.first });
			}
		}
	}
}


int main() {
	cin >> V >> E; // 정점 개수와 간선의 개수
	cin >> K; //시작 정점의 번호
	for (int i = 0; i < E; i++)
	{
		cin >> u >> v >> w; // E개의 줄,  각 간선 정보 (u->v & 가중치 w)
		edge[u].push_back({ v,w });
	}

	Dist(K);

	for (int v = 1; v <= V; v++)
	{
		if (dist[v] == INF) cout << "INF\n";
		else cout << dist[v] << "\n";
	}
	return 0;
}