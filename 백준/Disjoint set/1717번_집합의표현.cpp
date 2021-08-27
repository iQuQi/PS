#include <iostream>
#include <vector>
#include <queue>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <climits>
/*
초기에 {0}, {1}, {2}, ... {n} 이 각각 n+1개의 집합을 이루고 있다. 
여기에 합집합 연산과, 두 원소가 같은 집합에 포함되어 있는지를 확인하는 
연산을 수행하려고 한다.

집합을 표현하는 프로그램을 작성하시오.
*/


using namespace std;
int n, m;
int k, a, b;
int pa, pb;
int parent[1000000+4];


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



int main() {
	vector<string>v;
	cin >> n >> m;//n+1개의 집합 & 입력으로 주어지는 연산의 개수 m

	//초기화
	for (int i = 0; i <= n; i++) parent[i] = i;
	
	for (int i = 0; i < m; i++)
	{
		cin >> k >> a >> b; //k가 0이면 a와 b가 포함된 집합 합치기 1이면 같은집합인지 확인
		if (k) {//find
			pa = Find(a);
		
			pb = Find(b);
		
			if (pa == pb) v.push_back("YES\n");
			else v.push_back("NO\n");
		}
		else {//union
			Union(a, b);
		}
	}

	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i];
	}
	
}

