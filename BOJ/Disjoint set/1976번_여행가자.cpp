#include <iostream>
#include <vector>
#include <queue>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <climits>
/*
동혁이는 친구들과 함께 여행을 가려고 한다. 

한국에는 도시가 N개 있고 임의의 두 도시 사이에 길이 있을 수도, 
없을 수도 있다. 동혁이의 여행 일정이 주어졌을 때, 이 여행 경로가 가능한 것인지 
알아보자. 물론 중간에 다른 도시를 경유해서 여행을 할 수도 있다. 

예를 들어 도시가 5개 있고, A-B, B-C, A-D, B-D, E-A의 길이 있고, 
동혁이의 여행 계획이 E C B C D 라면 E-A-B-C-B-C-B-D라는 여행경로를 통해 목적을 
달성할 수 있다.

도시들의 개수와 도시들 간의 연결 여부가 주어져 있고, 
동혁이의 여행 계획에 속한 도시들이 순서대로 주어졌을 때 가능한지 여부를 
판별하는 프로그램을 작성하시오. 같은 도시를 여러 번 방문하는 것도 가능하다.
*/
using namespace std;
int n, m;
int k, a, b;
int pa, pb;
int parent[205];
int path[1005];

int Find(int a) {
	if (parent[a] == a) return a;
	return parent[a] = Find(parent[a]);
}

void Union(int a, int b) {
	pa = Find(a);
	pb = Find(b);

	if (pa == pb) return;
	parent[pa] = pb;
}

int main() {

	cin >> n >> m;//n은 전체 도시의수 , m은 여행계획에 속한 도시의 수

	for (int i = 1; i <= n; i++)parent[i] = i; // 초기화


	// i번 도시와 j번도시의 연결정보
	// 1이면 연결된 것이고 0이면 연결 x
	int a;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++) 
		{
			cin >> a;
			if (a) Union(i, j);
		}
	}

	//여행 계획이 주어짐
	int t;
	for (int i = 1; i <= m; i++)
	{
		cin >> t;
		path[i] = t;
	}

	//여행계획이 가능한지 구한다
	int ch = 1;
	for (int i = 1; i < m; i++)
	{
		if (Find(path[i]) != Find(path[i + 1])) {
			ch = 0;
			break;
		}
	}

	if (ch) cout << "YES\n";
	else cout << "NO\n";


}

