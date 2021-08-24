#include <iostream>
#include <vector>
#include <queue>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <climits>
/*
�����̴� ��ô�̳� ��������. ���õ� �� ���� ��� �̷�� ä ������ ���� �ϴ� �����̴� 
���ñ��� ������ ���� �Ѵٴ� ����� ���޾Ҵ�. 

�׷��� ������ ���۵Ǿ��� ���� �� ��ô�̳� �Ⱦ��ϴ� �����̴� ��¿ �� ���� 
�鵵� �� ������ �ִ��� ������ ������� ����Ͽ���.

�ִ��� ���� ������ ������ ������ �����ؾ� �ϱ� ������ �����̴� �ִ��� ���� 
�ؼ����� �ִ� ������ �޷������� �Ѵ�. 

�������� è�Ǿ��� �� N���� �б����� ��ġ�� �� �ִ�. 
0��° �б����� ���� �������� è�Ǿ��� �ִ� ����, 
N-1 ��° �б����� ����� �ؼ����� �ǹ��ϸ� ������ 1, 2, ..., N-2��° �б����� 
�߰� �������̴�. �׷��� �������� è�Ǿ��� ��� �б����� ����ĥ �� �ִ� ���� �ƴϴ�. 

�鵵���� �ٽ��� �� ��Ű�� ��ݻ�� ���� ���̱� ������ 
�� è�Ǿ� Ȥ�� �� �͵�(�þ߸� �����ִ� ����), �̴Ͼ�, ��ž �� ����� �þ߿� 
�ɸ��� ���� ����ĥ �� ����.

�Է����� �� �б����� ����ĥ �� �ִ����� ���� ���ο� �� �б������� �ٸ� �б������� 
���µ� �ɸ��� �ð��� �־����� ��, �����̰� ���� ��ġ���� �ؼ������� �� �� �ִ� 
�ּ� �ð��� ���Ͽ���.
*/
using namespace std;
const long long INF = LONG_MAX;
const int MAX_V = 200000 + 5;//���� �ִ밳��
vector<int> see;
priority_queue<pair<long long, int>> pq;//maxheap, fir�� ����ġ sec�� Ȯ���ϰ� ���� ����
vector<pair<int, long long>>edge[MAX_V];//����� ���� ����Ʈ,fist �� �� ������ ����� ����, sec�� ����ġ





int N, M;
int u, v;
long long t;

vector<long long> Dist1(int start) {
	vector<long long>dist(MAX_V, INF);//���������� ���Ѵ밪���� �ϴ� �ʱ�ȭ������
	dist[start] = 0;

	for (auto e : edge[start])
	{
		if (dist[e.first] == INF)
		{
			if (!see[e.first] || e.first == (N - 1)) {
				pq.push({ -e.second,e.first });
			}

		}
	}

	while (!pq.empty()) {
		int now;
		long long nowdist;
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
				//��� �þ߿� ������ �ʰų� ���̴��� �װ��� ����� �ؼ����� ���
				if (!see[e.first] || e.first == (N - 1)) {
					pq.push({ -(nowdist + e.second), e.first });
				}
			}
		}
	}

	return dist;


}




int main() {

	cin >> N >> M;//�б����� ������ ���� �־���
	for (int i = 0; i < N; i++)
	{
		int yn;
		cin >> yn;
		see.push_back(yn);
		//0�̸� ���þ߿� ������ ���� 1�̸� ����
		//a0�� ������ 0 an-1�� ������1
	}

	for (int i = 0; i < M; i++)
	{
		cin >> u >> v >> t;//u->v�� ����  �ɸ��� �ð� t
		edge[u].push_back({ v,t });//��������Ʈ����� - �����
		edge[v].push_back({ u,t });
	}

	vector<long long> re = Dist1(0);

	long long dab = -1;
	if (re[N - 1] != INF) dab = re[N - 1]; //������ �� ���ٸ� -1 ���
	cout << dab;
	return 0;
}

