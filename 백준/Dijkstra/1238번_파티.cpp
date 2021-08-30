#include <iostream>
#include <vector>
#include <queue>
#include <stdlib.h>
#include <string>
#include <algorithm>
/*
N���� ���ڷ� ���е� ������ ������ �� ���� �л��� ��� �ִ�.

��� �� �� N���� �л��� X (1 �� X �� N)�� ������ �𿩼� ��Ƽ�� ���̱�� �ߴ�. 
�� ���� ���̿��� �� M���� �ܹ��� ���ε��� �ְ� i��° ���� �����µ� 
Ti(1 �� Ti �� 100)�� �ð��� �Һ��Ѵ�.

������ �л����� ��Ƽ�� �����ϱ� ���� �ɾ�� �ٽ� �׵��� ������ ���ƿ;� �Ѵ�. 
������ �� �л����� ���� �������� �ִ� �ð��� ���� ���⸦ ���Ѵ�.

�� ���ε��� �ܹ����̱� ������ �Ƹ� �׵��� ���� ���� ���� �ٸ����� �𸥴�. 
N���� �л��� �� ���� ���µ� ���� ���� �ð��� �Һ��ϴ� �л��� �������� ���Ͽ���.
*/
using namespace std;
const int INF = 2000000000;
const int MAX_V = 20005;//���� �ִ밳��
priority_queue<pair<int, int>> pq;//maxheap, fir�� ����ġ sec�� Ȯ���ϰ� ���� ����
vector<pair<int, int>>edge[MAX_V];//����� ���� ����Ʈ,fist �� �� ������ ����� ����, sec�� ����ġ





int N, M;
int x;
int u, v, t;

//���۸������� �ٸ� ������ ������ �ִܰŸ� ���س���
vector<int> Dist1(int start) {
	vector<int >dist(MAX_V, INF);//���������� ���Ѵ밪���� �ϴ� �ʱ�ȭ������
	dist[start] = 0;

	for (auto e : edge[start])
	{
		if (dist[e.first] == INF)
		{
			pq.push({ -e.second,e.first });
		}
	}

	while (!pq.empty()) {
		int now, nowdist;
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
				pq.push({ -(nowdist + e.second), e.first });
			}
		}
	}

	return dist;


}




int main() {
	cin >> N >> M;//������ �ܹ��⵵���� ������ �־���
	cin >> x;//��Ƽ�ϴ� ����

	for (int i = 0; i < M; i++)
	{
		cin >> u >> v >> t;//u->v�� ����  �ɸ��� �ð� t
		edge[u].push_back({ v,t });//��������Ʈ�����
	}

	int dab = -1;
	//x���� �� ���������� �Ÿ� �̸� ���صα�
	vector<int> come = Dist1(x);

	for (int i = 1; i <= N; i++)
	{
		if (i == x)continue;
		vector<int> go = Dist1(i);
		dab = max(dab, go[x] + come[i]);
	}


	cout << dab;


	return 0;
}

