#include <iostream>
#include <vector>
#include <queue>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <climits>
/*
���� 2020��, �����̴� ���峪���� �� �����̴�. 
���峪�󿡴� N���� ������ �ְ� N���� ���� ���̿��� M���� ���ο� W���� ��Ȧ�� �ִ�. 
(�� ���δ� ������ ������ ��Ȧ�� ������ �ִ�.) 

��Ȧ�� ���� ��ġ���� ���� ��ġ�� ���� �ϳ��� ����ε�, 
Ư���ϰԵ� ������ �ϰ� �Ǹ� ������ �Ͽ��� ������ �ð��� �ڷ� ���� �ȴ�. 
��Ȧ �������� �ð谡 �Ųٷ� ���ٰ� �����Ͽ��� ����.

�ð� ������ �ſ� �����ϴ� �����̴� �� ���� �ñ����� ������. 
�� �������� ����� �Ͽ��� �ð������� �ϱ� �����Ͽ� �ٽ� ����� �Ͽ��� 
��ġ�� ���ƿ��� ��, ����� �Ͽ��� ������ �ð��� �ǵ��ư� �ִ� ��찡 �ִ��� ������ 
�ñ�������. 

�������� �����̸� ���� �̷� ���� �������� �Ұ������� ���ϴ� ���α׷��� �ۼ��Ͽ���.
*/
using namespace std;
using ll = long long;


vector<Edge> Edges;
vector<ll> ShortPath;

const ll INF = LLONG_MAX;
int N, M, W;
int s, e, t;

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

bool Bellman_Ford(int start) {
	ShortPath[start] = 0;
	for (int n = 1; n <= N; n++)
	{
		for (int m = 0; m < 2 * M + W; m++) // ������� ���ΰ���*2 + �ܹ��� ��Ȧ
		{
			auto e = Edges[m];
			if (ShortPath[e.from] == INF) continue;
			else if (ShortPath[e.to] > ShortPath[e.from] + e.weight)
				ShortPath[e.to] = ShortPath[e.from] + e.weight;
		}
	}

	bool ret = true;

	for (int n = 1; n <= N; n++)
	{
		for (int m = 0; m < 2 * M + W; m++)
		{
			auto e = Edges[m];
			if (ShortPath[e.from] == INF) continue;
			else if (ShortPath[e.from] == -INF)
				ShortPath[e.to] = -INF;
			else if (ShortPath[e.to] > ShortPath[e.from] + e.weight) {
				ShortPath[e.to] = -INF;
				ret = false;//���� ����Ŭ ����
			}
		}
	}
	return ret;
}

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int tc;
	vector<string>str;
	cin >> tc;//�׽�Ʈ ���̽�

	for (int i = 0; i < tc; i++)
	{
		cin >> N >> M >> W;//���� ����, ������ ����, ��Ȧ�� ����
		ShortPath.assign(N + 1, INF);//�ʱ�ȭ

		//���� ���� - �����
		for (int j = 0; j < M; j++)
		{
			cin >> s >> e >> t;//������, ������, t�� �ɸ��� �ð�
			Edges.push_back(Edge(s, e, t));
			Edges.push_back(Edge(e, s, t));
		}

		//��Ȧ ���� - �ܹ���
		for (int k = 0; k < W; k++)
		{
			cin >> s >> e >> t;//t�� �پ��� �ð�
			Edges.push_back(Edge(s, e, -t));
		}

		bool dab = false;//��������Ŭ üũ

		for (int j = 1; j <= N; j++)
		{
			if (ShortPath[j] != INF) continue; // ���������� ���ƿ� �� ���ٸ�
			if (!Bellman_Ford(j)) {//���������� ���ƿ� �� �ִٸ�

				dab = true;//��������Ŭ ����
				break;
			}
		}

		if (dab) str.push_back("YES\n");//��������Ŭ ����
		else str.push_back("NO\n");//��������Ŭ ����

		Edges.clear(); // �׽�Ʈ ���̽��� �����Ҷ��� �ʱ�ȭ�� ��������
	}

	for (int i = 0; i < str.size(); i++)
	{
		cout << str[i];
	}


}

