#include <iostream>
#include <vector>
#include <queue>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <climits>
using namespace std;

/*
���̴� 24�� ���¼ַ��̴�. ���̴� �븶���簡 �� �� ���ٸ� 
�ڽ��� ���α׷��� �ɷ��� �̿��Ͽ� ���� ���ø����̼��� ������ ����ߴ�. 
���� ���� ���л��� Ÿ������ ����������� ���б����� ���� �����͸� �����Ͽ� �������.

�� ���� ����ڵ��� ���� ��� ��θ� �����Ѵ�. �� ��δ� 3���� Ư¡�� ������ �ִ�.

��� ��δ� ����ڵ��� ����� ������Ű�� ���� ���� ���б��� ���� ���б����� �����ϴ� 
���ηθ� �̷���� �ִ�.

����ڵ��� �پ��� ����� ������ �� �ֵ��� � ���б������� ��� ���б��� �̵��� ������ ����̴�.
�ð��� �������� �ʰ� ������ �� �ֵ��� �� ����� ���̴� �ִ� �Ÿ��� �Ǿ�� �Ѵ�.

���� ���� �����Ͱ� ���� ������ �׸��� ���ٸ�, ������ �׸��� ����� ���� ���� ��θ� 
�����ϸ� ���� 3���� ������ �����ϴ� ��θ� ���� �� �ִ�.



�̶�, �־����� �Ÿ� �����͸� �̿��Ͽ� ��� ����� ���̸� ���غ���.
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

	cin >> n >> m; // �б��� ������ �б��� �����ϴ� ������ ����
	//���� �����

	//�ʱ�ȭ
	for (int i = 1; i <= n; i++)
	{
		parent[i] = i;
		cin >> gender;
		if (gender == 'M')gender_arr[i] = 0; //���� ����
		else gender_arr[i] = 1; //���� ����

	}

	for (int i = 0; i < m; i++)
	{
		cin >>u >> v >> d;
		if(genderCheck(u,v)) edges.push(Edge(u, v,d));
	}

	cnt = n;//������ �� ����
	//��� edge�� ���� 
	while (!edges.empty()) {
		Edge e = edges.top(); edges.pop();// ����ġ�� ���� ������ ���� �̱�
		//������ �� ������ �̹� ���� ������ ��� �ش� ������ MST�� ���� x
		if (Find(e.start)!= Find(e.end)) {
			Union(e.start, e.end);
			cnt--;
			ans += e.weight; // ����ġ ��
		}
	}
	if(cnt==1)cout << ans;
	else cout << -1;//��� ������ �����ϴ� ��ΰ� ���� ���
}

