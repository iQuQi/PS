#include <iostream>
#include <vector>
#include <queue>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <climits>
/*
N���� ���ð� �ִ�. 
�׸��� �� ���ÿ��� ����Ͽ� �ٸ� ���ÿ� �����ϴ� ������ M�� �ִ�. 

�� ������ A, B, C�� ��Ÿ�� �� �ִµ�, A�� ���۵���, B�� ��������, 
C�� ������ Ÿ�� �̵��ϴµ� �ɸ��� �ð��̴�. �ð� C�� ����� �ƴ� ��찡 �ִ�. 

C = 0�� ���� ���� �̵��� �ϴ� ���, C < 0�� ���� Ÿ�Ӹӽ����� �ð��� 
�ǵ��ư��� ����̴�.

1�� ���ÿ��� ����ؼ� ������ ���÷� ���� ���� ���� �ð��� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.
*/
using namespace std;
using ll = long long;

vector<Edge> Edges;
vector<ll> ShortPath;

const ll INF = LLONG_MAX;
int N, M;
int A, B, C;

//���� Ŭ���� ����
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


//���� ���� �ڵ�
bool Bellman_Ford() {
	ShortPath[1] = 0;
	//V��(1�� �� ������ ���� ����) ������ �ִ� ��� Ž��
	for (int n = 1; n <= N; n++)//(V�� ������)
	{
		for (int m = 0; m < M; m++)//��� ������ ����
		{
			auto e = Edges[m];
			if (ShortPath[e.from] == INF) continue;
			else if (ShortPath[e.to] > ShortPath[e.from] + e.weight)
				ShortPath[e.to] = ShortPath[e.from] + e.weight;
		}
	}

	bool ret = true;//ret�� ��������Ŭ�� �ִٸ� false

	//V���� �� ������ ���� ����Ŭ ���� �ľ�
	for (int n = 1; n <= N; n++)
	{
		for (int m = 0; m < M; m++)
		{
			auto e = Edges[m];
			if (ShortPath[e.from] == INF) continue;
			//�Ʒ��κ��� �ٸ� ��
			else if (ShortPath[e.from] == -INF)
				ShortPath[e.to] = -INF;
			else if (ShortPath[e.to] > ShortPath[e.from] + e.weight) {
				ShortPath[e.to] = -INF;
				ret = false;//��������Ŭ ����
			}

		}
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M; // ������ ������ ���� �뼱�� ���� �Է�
	ShortPath.resize(N + 1, INF);//�ʱ�ȭ

	for (int m = 1; m <= M; m++)
	{
		cin >> A >> B >> C;//���� �뼱�� ����
		Edges.push_back(Edge(A, B, C));
	}

	if (Bellman_Ford()) {
		//1�� ���ÿ��� ���
		for (int n = 2; n <= N; n++)
		{
			if (ShortPath[n] == INF)cout << "-1\n"; // �ش� ���÷� ���� ��ΰ� ���ٸ�
			else cout << ShortPath[n] << "\n";//���� ���� �ð��� ���� ������� ���
		}
	}
	else cout << "-1\n"; // ���� ����Ŭ ���� �� 
}

