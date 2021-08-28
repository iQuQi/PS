#include <iostream>
#include <vector>
#include <queue>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <climits>
using namespace std;

/*
�׷����� �־����� ��, �� �׷����� �ּ� ���д� Ʈ���� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�ּ� ���д� Ʈ����, �־��� �׷����� ��� �������� �����ϴ� �κ� �׷��� �߿���
�� ����ġ�� ���� �ּ��� Ʈ���� ���Ѵ�.
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
	int weight;//����ġ - ������ �� �� ����


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

	//�ʱ�ȭ
	for (int i = 0; i < v; i++)
	{
		parent[i] = i;
	}

	//������ 1-v������ ��ȣ.
	for (int i = 0; i < e; i++)
	{
		cin >> a >> b >> c;
		edges.push(Edge(a, b,c));//������������ ������ֱ� ���� - �ٿ��� �ֱ�
	}


	//��� edge�� ���� 
	while (!edges.empty()) {
		Edge e = edges.top(); edges.pop();// ����ġ�� ���� ������ ���� �̱�

		//������ �� ������ �̹� ���� ������ ��� �ش� ������ MST�� ���� x
		if (Find(e.start)!= Find(e.end)) {
			Union(e.start, e.end);
			ans += e.weight; // ����ġ ��
		}
	}

	cout << ans;
}

