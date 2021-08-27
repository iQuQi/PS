#include <iostream>
#include <vector>
#include <queue>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <climits>
/*
�����̴� ģ����� �Բ� ������ ������ �Ѵ�. 

�ѱ����� ���ð� N�� �ְ� ������ �� ���� ���̿� ���� ���� ����, 
���� ���� �ִ�. �������� ���� ������ �־����� ��, �� ���� ��ΰ� ������ ������ 
�˾ƺ���. ���� �߰��� �ٸ� ���ø� �����ؼ� ������ �� ���� �ִ�. 

���� ��� ���ð� 5�� �ְ�, A-B, B-C, A-D, B-D, E-A�� ���� �ְ�, 
�������� ���� ��ȹ�� E C B C D ��� E-A-B-C-B-C-B-D��� �����θ� ���� ������ 
�޼��� �� �ִ�.

���õ��� ������ ���õ� ���� ���� ���ΰ� �־��� �ְ�, 
�������� ���� ��ȹ�� ���� ���õ��� ������� �־����� �� �������� ���θ� 
�Ǻ��ϴ� ���α׷��� �ۼ��Ͻÿ�. ���� ���ø� ���� �� �湮�ϴ� �͵� �����ϴ�.
*/
using namespace std;
int n, m;
int k, a, b;
int pa, pb;
int parent[205];
int path[1005];

int Find(int a) {
	if (parent[a] == a) return a;
	return parent[a] = Find(parent[a]);
}

void Union(int a, int b) {
	pa = Find(a);
	pb = Find(b);

	if (pa == pb) return;
	parent[pa] = pb;
}

int main() {

	cin >> n >> m;//n�� ��ü �����Ǽ� , m�� �����ȹ�� ���� ������ ��

	for (int i = 1; i <= n; i++)parent[i] = i; // �ʱ�ȭ


	// i�� ���ÿ� j�������� ��������
	// 1�̸� ����� ���̰� 0�̸� ���� x
	int a;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++) 
		{
			cin >> a;
			if (a) Union(i, j);
		}
	}

	//���� ��ȹ�� �־���
	int t;
	for (int i = 1; i <= m; i++)
	{
		cin >> t;
		path[i] = t;
	}

	//�����ȹ�� �������� ���Ѵ�
	int ch = 1;
	for (int i = 1; i < m; i++)
	{
		if (Find(path[i]) != Find(path[i + 1])) {
			ch = 0;
			break;
		}
	}

	if (ch) cout << "YES\n";
	else cout << "NO\n";


}

