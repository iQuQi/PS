#include <iostream>
#include <vector>
#include <queue>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <climits>
using namespace std;
const int num = 1000005;
int n, m;
int k, a, b;
int pa, pb;
int parent[num][2];//ù��°�� �ڽ��� �θ�����, �ι�°�� �ڽ��� ��Ʈ�ΰ�� ���Ұ�������
int path[1005];

/*
���Դ� �κ��� �����ؾ� �Ѵ�. ���� �ȿ��� ���� �κ��� ��ǰ���� ���� �ִ�. 
�׷��� � ��ǰ�� ��� �κ��� ��ǰ���� ǥ�ð� �Ǿ����� �ʴ�. ȣ��� ���ڰ���
�� ��ǰ�� ���� ���� �κ��� ��ǰ���� �� �� �ִ�. �׷��� ���Դ� ȣ���� ���ÿ� 
���� ��ǰ���� �����ϱ�� �Ͽ���.

��ǰ���� 1���� 106������ ������ ǥ���ȴ�. �׸��� ��ǰ i�� ���� �κ��� robot(i)��� 
ǥ���Ѵ�. ���� ���, ��ǰ 11�� ��ǰ 22�� �κ� A�� ��ǰ�̶�� �˰� �ִ� ���, 
robot(11)�� �κ� A�� �ǹ��ϰ�, robot(22)�� �κ� A�� �ǹ��Ѵ�.

���� �ٸ� �κ��� ���� ��ǰ�� ������ �ʴ´�. �� � ��ǰ�� �κ� A�� ��ǰ�̶��, 
�κ� B�� ��ǰ�� �� �� ����.

ȣ��� 2���� ���ø� �Ѵ�.

���� �ٸ� ��ǰ 2���� �����ָ�, �� ��ǰ�� ���� �κ��� ��ǰ�̶�� ������ �˷��ش�.
��ǰ i�� ���ؼ�, ���ݱ��� �˾Ƴ� robot(i)�� ��ǰ�� �� ���İ� �����.
�ʱ⿡�� ��ǰ�� ���� ������ �������� �ʴ´�.
*/



int Find(int a) {

	if (parent[a][0] == a) return a;

	return parent[a][0] = Find(parent[a][0]);

}

void print(int a) {
	int pa = Find(a);
	cout << parent[pa][1] << "\n";
}

void Union(int a, int b) {

	pa = Find(a);
	pb = Find(b);
	if (pa == pb) return;
	parent[pa][0] = pb;
	parent[pb][1] += parent[pa][1];

}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	//�ʱ�ȭ
	for (int i = 1; i <= num; i++) {
		parent[i][1] = 1;
		parent[i][0] = i;
	}

	char menu;
	int a, b;
	cin >> n;//ȣ���� ������ Ƚ��

	for (int i = 1; i <= n; i++)
	{
		cin >> menu;
		if (menu == 'I') {//���� �κ��� ��ǰ���� �˷���
			cin >> a >> b;
			Union(a, b);

		}
		else if (menu == 'Q') {//��� ��ǰ���� ���
			cin >> a;
			print(a);

		}
	}



}

