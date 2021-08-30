#include <iostream>
#include <vector>
#include <queue>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <climits>
using namespace std;

/*
그래프가 주어졌을 때, 그 그래프의 최소 스패닝 트리를 구하는 프로그램을 작성하시오.

최소 스패닝 트리는, 주어진 그래프의 모든 정점들을 연결하는 부분 그래프 중에서
그 가중치의 합이 최소인 트리를 말한다.
*/

int v, e,a, b, c,ans,pa,pb;
int parent[10000 + 1];
int Find(int a) {

	if (parent[a] == a) return a;

	return parent[a] = Find(parent[a]);

}

void Union(int a, int b) {
	if (a == b) return;
	pa = Find(a);
	pb = Find(b);
	if (pa != pb) parent[pa] = pb;
}

class Edge{
public:
	int start;
	int end;
	int weight;//가중치 - 음수일 수 도 있음


	Edge() {
		start = 0;
		end = 0;
		weight = 0;
		
	}

	Edge(int st,int en,int wei) {
		start = st;
		end = en;
		weight = wei;
	}

	bool operator >(const Edge& e) const{
		
		return  weight > e.weight;
	}

};


priority_queue<Edge, vector<Edge>,greater<Edge>> edges;


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> v >> e;

	//초기화
	for (int i = 0; i < v; i++)
	{
		parent[i] = i;
	}

	//정점은 1-v까지의 번호.
	for (int i = 0; i < e; i++)
	{
		cin >> a >> b >> c;
		edges.push(Edge(a, b,c));//오름차순으로 만들어주기 위해 - 붙여서 넣기
	}


	//모든 edge에 대해 
	while (!edges.empty()) {
		Edge e = edges.top(); edges.pop();// 가중치가 가장 작은거 부터 뽑기

		//간선의 양 끝점이 이미 같은 집합인 경우 해당 간선은 MST에 포함 x
		if (Find(e.start)!= Find(e.end)) {
			Union(e.start, e.end);
			ans += e.weight; // 가중치 합
		}
	}

	cout << ans;
}

