#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <string.h>
using namespace std;
int miro[100 + 5][100 + 5];//�������
int _x[4] = { 0,1,0,-1 }; //�Ʒ� ������ �� ����
int _y[4] = { 1,0,-1,0 };
bool visited[100 + 5][100 + 5];//�湮����
int dis[105][105];
queue<pair<int, int >>bfs;
int N, M;
/*
N��Mũ���� �迭�� ǥ���Ǵ� �̷ΰ� �ִ�.

1	0	1	1	1	1
1	0	1	0	1	0
1	0	1	0	1	1
1	1	1	0	1	1
�̷ο��� 1�� �̵��� �� �ִ� ĭ�� ��Ÿ����, 
0�� �̵��� �� ���� ĭ�� ��Ÿ����. �̷��� �̷ΰ� �־����� ��, 
(1, 1)���� ����Ͽ� (N, M)�� ��ġ�� �̵��� �� 
������ �ϴ� �ּ��� ĭ ���� ���ϴ� ���α׷��� �ۼ��Ͻÿ�. 

�� ĭ���� �ٸ� ĭ���� �̵��� ��, ���� ������ ĭ���θ� �̵��� �� �ִ�.

���� �������� 15ĭ�� ������ (N, M)�� ��ġ�� �̵��� �� �ִ�. 
ĭ�� �� ������ ���� ��ġ�� ���� ��ġ�� �����Ѵ�.
*/



void bfss() {
	//���� ����
	bfs.push({ 1,1 });
	dis[1][1] = 1;

	//ť�� �������� 
	while (!bfs.empty()) {
		int size = bfs.size();
		int x = bfs.front().first;
		int y = bfs.front().second;

		bfs.pop();
		visited[y][x] = true;

		//�� �� �� �쿡�� �� ���ִ� ��� ������ ���� BFS�� ������
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < 4; j++)
			{
				int nx = x + _x[j];
				int ny = y + _y[j];
		
				//������ �������� �ִ� ĭ���� ������ġ�� �ִ� ĭ��+1���� �۰ų� ���ٸ�
				//�ִܰ�ΰ� �ƴϹǷ� �������� ����
				if (miro[ny][nx] == 1 && dis[ny][nx] > dis[y][x] + 1) 
				{
					bfs.push({ nx,ny });
					dis[ny][nx] = dis[y][x] + 1;
				}
			}
		}
	}
	cout << dis[N][M];
}

int main() {
	cin >> N >> M;//n�̼���,y m�̰���,x

	//�ʱ�ȭ �Լ�
	for (int i = 0; i < 105; i++)
	{
		memset(miro[i], -1, sizeof(miro[i]));
	}

	//�̷θ� �Է� �޴´�
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			scanf("%1d", &miro[i][j]);
			dis[i][j] = 10000;
		}
	}

	//�ִ� ��� Ž�� ����
	bfss();

}