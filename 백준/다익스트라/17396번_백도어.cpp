#include <iostream>
#include <vector>
#include <queue>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <climits>
/*
유섭이는 무척이나 게으르다. 오늘도 할 일을 모두 미뤄둔 채 열심히 롤을 하던 유섭이는 
오늘까지 문제를 내야 한다는 사실을 깨달았다. 

그러나 게임은 시작되었고 지는 걸 무척이나 싫어하는 유섭이는 어쩔 수 없이 
백도어를 해 게임을 최대한 빠르게 끝내기로 결심하였다.

최대한 빨리 게임을 끝내고 문제를 출제해야 하기 때문에 유섭이는 최대한 빨리 
넥서스가 있는 곳으로 달려가려고 한다. 

유섭이의 챔피언은 총 N개의 분기점에 위치할 수 있다. 
0번째 분기점은 현재 유섭이의 챔피언이 있는 곳을, 
N-1 번째 분기점은 상대편 넥서스를 의미하며 나머지 1, 2, ..., N-2번째 분기점은 
중간 거점들이다. 그러나 유섭이의 챔피언이 모든 분기점을 지나칠 수 있는 것은 아니다. 

백도어의 핵심은 안 들키고 살금살금 가는 것이기 때문에 
적 챔피언 혹은 적 와드(시야를 밝혀주는 토템), 미니언, 포탑 등 상대의 시야에 
걸리는 곳은 지나칠 수 없다.

입력으로 각 분기점을 지나칠 수 있는지에 대한 여부와 각 분기점에서 다른 분기점으로 
가는데 걸리는 시간이 주어졌을 때, 유섭이가 현재 위치에서 넥서스까지 갈 수 있는 
최소 시간을 구하여라.
*/
using namespace std;
const long long INF = LONG_MAX;
const int MAX_V = 200000 + 5;//정점 최대개수
vector<int> see;
priority_queue<pair<long long, int>> pq;//maxheap, fir은 가중치 sec는 확인하고 싶은 정점
vector<pair<int, long long>>edge[MAX_V];//연결된 간선 리스트,fist 는 그 정점과 연결된 정점, sec는 가중치





int N, M;
int u, v;
long long t;

vector<long long> Dist1(int start) {
	vector<long long>dist(MAX_V, INF);//갈수없으면 무한대값으로 일단 초기화되있음
	dist[start] = 0;

	for (auto e : edge[start])
	{
		if (dist[e.first] == INF)
		{
			if (!see[e.first] || e.first == (N - 1)) {
				pq.push({ -e.second,e.first });
			}

		}
	}

	while (!pq.empty()) {
		int now;
		long long nowdist;
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
				//상대 시야에 보이지 않거나 보이더라도 그곳이 상대의 넥서스인 경우
				if (!see[e.first] || e.first == (N - 1)) {
					pq.push({ -(nowdist + e.second), e.first });
				}
			}
		}
	}

	return dist;


}




int main() {

	cin >> N >> M;//분기점과 간선의 수가 주어짐
	for (int i = 0; i < N; i++)
	{
		int yn;
		cin >> yn;
		see.push_back(yn);
		//0이면 상대시야에 보이지 않음 1이면 보임
		//a0는 무조건 0 an-1은 무조건1
	}

	for (int i = 0; i < M; i++)
	{
		cin >> u >> v >> t;//u->v로 가고  걸리는 시간 t
		edge[u].push_back({ v,t });//인접리스트만들기 - 양방향
		edge[v].push_back({ u,t });
	}

	vector<long long> re = Dist1(0);

	long long dab = -1;
	if (re[N - 1] != INF) dab = re[N - 1]; //도달할 수 없다면 -1 출력
	cout << dab;
	return 0;
}

