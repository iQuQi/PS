#include <iostream>
#include <vector>
#include <queue>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <climits>
/*
�ʱ⿡ {0}, {1}, {2}, ... {n} �� ���� n+1���� ������ �̷�� �ִ�. 
���⿡ ������ �����, �� ���Ұ� ���� ���տ� ���ԵǾ� �ִ����� Ȯ���ϴ� 
������ �����Ϸ��� �Ѵ�.

������ ǥ���ϴ� ���α׷��� �ۼ��Ͻÿ�.
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
	cin >> n >> m;//n+1���� ���� & �Է����� �־����� ������ ���� m

	//�ʱ�ȭ
	for (int i = 0; i <= n; i++) parent[i] = i;
	
	for (int i = 0; i < m; i++)
	{
		cin >> k >> a >> b; //k�� 0�̸� a�� b�� ���Ե� ���� ��ġ�� 1�̸� ������������ Ȯ��
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

