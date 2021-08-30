#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>

/*
����׷����� �־����� �־��� ���������� �ٸ� ��� ���������� �ִ� ��θ� ���ϴ� 
���α׷��� �ۼ��Ͻÿ�. 
��, ��� ������ ����ġ�� 10 ������ �ڿ����̴�.
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

	
	for (auto e : edge[start])//���������� ����� ��� ���� ����������
	{
		//���� Ȯ���� ������ �ƴ϶��
		if (dist[e.first] == INF)
		{
			pq.push({ -e.second,e.first });
			//����ġ�� ������ �־��ֵ� ����ġ�� ������ �־��־
			//������������ ������ֱ�
		}
	}

	//ť�� ��������
	while (!pq.empty()) {
		int now, nowdist;
		nowdist = -pq.top().first;
		now = pq.top().second;
		pq.pop();

		//�̹� ������ ������ ��� �н�
		if (dist[now] != INF) {
			continue;
		}

		//�ִ� �Ÿ� ����
		dist[now] = nowdist;

		//����� ��� ������ ť�� �־��ش�
		for (auto e : edge[now])
		{
			if (dist[e.first] == INF) {
				pq.push({ -(nowdist + e.second), e.first });
			}
		}
	}
}


int main() {
	cin >> V >> E; // ���� ������ ������ ����
	cin >> K; //���� ������ ��ȣ
	for (int i = 0; i < E; i++)
	{
		cin >> u >> v >> w; // E���� ��,  �� ���� ���� (u->v & ����ġ w)
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