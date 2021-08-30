#include <iostream>
#include <vector>
#include <queue>
using namespace std;
/*
ü���� ���� �� ����Ʈ�� ������ �ִ�. ����Ʈ�� �� ���� �̵��� �� �ִ� ĭ�� �Ʒ� �׸��� �����ִ�.
����Ʈ�� �̵��Ϸ��� �ϴ� ĭ�� �־�����. ����Ʈ�� �� �� �����̸� �� ĭ���� �̵��� �� ������?
*/
int arr[305][305];
//����Ʈ�� �̵��� �� �ִ� ����
int dx[8] = { 1,1,-1,-1,2,2,-2,-2 };
int dy[8] = { 2,-2,2,-2,1,-1,1,-1 };

int cnt = 0;
int n, l, nx, ny, wx, wy;
int visited[305][305] = { 0 };

//���� �˻� �Լ�
int is_ok(int x, int y) {
	if (x < 0 || x >= l || y < 0 || y >= l || visited[y][x]) {
		return 0;
	}
	return 1;
}

//�̵� Ƚ�� ���ϱ�
int knight(int l, int nx, int ny, int wx, int wy) {

	if (nx == wx && ny == wy) return 0; // ���� ����ġ���
	queue<pair<pair<int, int>, int>>q;//x�� y ��ǥ

	//�ʱ�ȭ
	for (int i = 0; i < 305; i++)
	{
		for (int j = 0; j < 305; j++)
		{
			visited[i][j] = 0;
		}
	}
	//������ push
	q.push({ { nx,ny },0 });
	visited[ny][nx] = 1;


	//ť�� ��������
	while (!q.empty()) {
		int size = q.size();
		pair < pair<int, int>, int > now = q.front();
		q.pop();

		int x = now.first.first;
		int y = now.first.second;
		int cnt = now.second;

		//8���� ��� üũ
		for (int i = 0; i < 8; i++)
		{
			//���� �˻�
			if (is_ok(x + dx[i], y + dy[i])) {
				q.push({ { x + dx[i], y + dy[i]} ,cnt + 1 });
				visited[y + dy[i]][x + dx[i]] = 1;//�湮 üũ

				//�������� ������ ���
				if (x + dx[i] == wx && y + dy[i] == wy) return cnt + 1;
			}
		}
	}
	return -1;
}


int main() {

	cin >> n;//�׽�Ʈ����
	for (int i = 0; i < n; i++) {
		// 1.�� �Ѻ��� ���� 2.���� ����Ʈ ��ǥ 3. ��ǥ��ǥ
		cin >> l >> nx >> ny >> wx >> wy;
		cout << knight(l, nx, ny, wx, wy) << endl;
	}
}