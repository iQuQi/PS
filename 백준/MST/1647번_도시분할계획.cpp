#include <iostream>
#include <vector>
#include <queue>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <climits>
using namespace std;

/*
���������� �� Ż���� ������ �� ������ ���󱸰��� �ϰ� �ִ�. 
�׷��ٰ� ��ȭ�ο� ������ ���� �Ǿ��µ�, 
�װ������� �� �� ���� ���� �������� �־���.

������ N���� ���� �� ������ �����ϴ� M���� ��� �̷���� �ִ�. 
���� ��� �������ε��� �ٴ� �� �ִ� ���� ���̴�. 
�׸��� �� �渶�� ���� �����ϴµ� ��� ������ �ִ�.

������ ������ ������ �� ���� �и��� ������ ������ ��ȹ�� ������ �ִ�. 
������ �ʹ� Ŀ�� ȥ�ڼ��� ������ �� ���� �����̴�. 
������ ������ ���� �� �и��� ���� �ȿ� ������ ���� ����ǵ��� �����ؾ� �Ѵ�. 
�� �и��� ���� �ȿ� �ִ� ������ �� �� ���̿� ��ΰ� �׻� �����ؾ� �Ѵٴ� ���̴�. 
�������� ���� �ϳ� �̻� �־�� �Ѵ�.

�׷��� ������ ������ ��ȹ�� ����ٰ� ���� �ȿ� ���� �ʹ� ���ٴ� ������ �ϰ� �Ǿ���. 
�ϴ� �и��� �� ���� ���̿� �ִ� ����� �ʿ䰡 �����Ƿ� ���� �� �ִ�. 
�׸��� �� �и��� ���� �ȿ����� ������ �� �� ���̿� ��ΰ� 
�׻� �����ϰ� �ϸ鼭 ���� �� ���� �� �ִ�. 

������ ������ �� ������ �����ϵ��� ����� ��� ���ְ� ������ ���� �������� ���� �ּҷ� �ϰ� �ʹ�. 
�̰��� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.
*/

int n,m,a, b, c,ans,pa,pb;
int parent[100000+1];
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

	cin >> n >> m; // ���� ������ ���� ������ �־���
	//���� �����

	//�ʱ�ȭ
	for (int i = 0; i < n; i++)
	{
		parent[i] = i;
	}

	for (int i = 0; i < m; i++)
	{
		cin >> a >> b >> c;
		edges.push(Edge(a, b,c));
	}


	//��� edge�� ���� 
	while (!edges.empty()) {
		Edge e = edges.top(); edges.pop();// ����ġ�� ���� ������ ���� �̱�

		//������ �� ������ �̹� ���� ������ ��� �ش� ������ MST�� ���� x
		if (Find(e.start)!= Find(e.end)) {
			Union(e.start, e.end);
			ans += e.weight; // ����ġ ��
			if (max_wei < e.weight) max_wei = e.weight;
		}
	}
	ans -= max_wei;
	cout << ans;
}

