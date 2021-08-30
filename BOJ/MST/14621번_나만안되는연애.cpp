#include <iostream>
#include <vector>
#include <queue>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <climits>
using namespace std;

/*
깽미는 24살 모태솔로이다. 깽미는 대마법사가 될 순 없다며 
자신의 프로그래밍 능력을 이용하여 미팅 어플리케이션을 만들기로 결심했다. 
미팅 앱은 대학생을 타겟으로 만들어졌으며 대학교간의 도로 데이터를 수집하여 만들었다.

이 앱은 사용자들을 위해 사심 경로를 제공한다. 이 경로는 3가지 특징을 가지고 있다.

사심 경로는 사용자들의 사심을 만족시키기 위해 남초 대학교와 여초 대학교들을 연결하는 
도로로만 이루어져 있다.

사용자들이 다양한 사람과 미팅할 수 있도록 어떤 대학교에서든 모든 대학교로 이동이 가능한 경로이다.
시간을 낭비하지 않고 미팅할 수 있도록 이 경로의 길이는 최단 거리가 되어야 한다.

만약 도로 데이터가 만약 왼쪽의 그림과 같다면, 오른쪽 그림의 보라색 선과 같이 경로를 
구성하면 위의 3가지 조건을 만족하는 경로를 만들 수 있다.



이때, 주어지는 거리 데이터를 이용하여 사심 경로의 길이를 구해보자.
*/

int n,m,u,v,d,ans,pa,pb,cnt;
int parent[1000+1];
char gender;
int gender_arr[1000 + 1];
int max_wei = -1;
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

int genderCheck(int start, int end) {
	return gender_arr[start] != gender_arr[end];
}

class Edge{
public:
	int start;
	int end;
	int weight;


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

	cin >> n >> m; // 학교의 개수와 학교를 연결하는 도로의 개수
	//길은 양방향

	//초기화
	for (int i = 1; i <= n; i++)
	{
		parent[i] = i;
		cin >> gender;
		if (gender == 'M')gender_arr[i] = 0; //남초 대학
		else gender_arr[i] = 1; //여초 대학

	}

	for (int i = 0; i < m; i++)
	{
		cin >>u >> v >> d;
		if(genderCheck(u,v)) edges.push(Edge(u, v,d));
	}

	cnt = n;//집합의 수 세기
	//모든 edge에 대해 
	while (!edges.empty()) {
		Edge e = edges.top(); edges.pop();// 가중치가 가장 작은거 부터 뽑기
		//간선의 양 끝점이 이미 같은 집합인 경우 해당 간선은 MST에 포함 x
		if (Find(e.start)!= Find(e.end)) {
			Union(e.start, e.end);
			cnt--;
			ans += e.weight; // 가중치 합
		}
	}
	if(cnt==1)cout << ans;
	else cout << -1;//모든 대학을 연결하는 경로가 없는 경우
}

