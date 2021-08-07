#include <iostream>
#include <vector>
#include <queue>
#include <string>
#
using namespace std;
int gajok[100 + 5][100 + 5];//�������

bool visited[100 + 5];//�湮����
int dis[105][105];
queue<pair<int, int>>bfs;
int n, m;
int a, b;
int x, y;
/*
�츮 ����� ���� Ȥ�� ģô�� ������ ���踦 �̼���� 
������ ǥ���ϴ� ��Ư�� ��ȭ�� ������ �ִ�. 
�̷��� �̼��� ������ ���� ������� ���ȴ�. 
�⺻������ �θ�� �ڽ� ���̸� 1������ �����ϰ� �̷κ��� ����� ���� �̼��� ����Ѵ�. 
���� ��� ���� �ƹ���, �ƹ����� �Ҿƹ����� ���� 1������ ���� �Ҿƹ����� 2���� �ǰ�, 
�ƹ��� ������� �Ҿƹ����� 1��, ���� �ƹ��� ��������� 3���� �ȴ�.

���� ����鿡 ���� �θ� �ڽĵ� ���� ���谡 �־����� ��, 
�־��� �� ����� �̼��� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.
*/

void bfss(int from, int to) {
	int dab = -1;
	bfs.push({ from,0 });
	visited[from] = true;

	//ť�� ����ų� �������� �����ϸ� ��
	while (!bfs.empty() && !visited[to]) {
		int now = bfs.front().first;
		int chon = bfs.front().second;

		bfs.pop();

		for (int i = 1; i <= n; i++) {
			//�湮�����ʾҰ� �θ� �Ǵ� �ڽ� ������ ������ ��� ����
			if (!visited[i] && gajok[now][i]) {
				bfs.push({ i, chon + 1 });
				visited[i] = 1;
				if (i == to) dab = chon + 1; //�������� ���� �ߴٸ� dab ����
			}
		}
	}
	cout << dab;
}

int main() {
	cin >> n; 	//��ü ����Ǽ�
	cin >> a >> b;  // �̼��� ����ؾ��ϴ� ���� �ٸ� �λ���� ��ȣ (1...n ����)
	cin >> m; // �θ� �ڽĵ� ���� ������ ����
	for (int i = 0; i < m; i++)
	{
		//x�� y�� �θ� ��ȣ
		cin >> x >> y;
		gajok[x][y] = 1;
		gajok[y][x] = 1;
	}

	bfss(a, b);

}