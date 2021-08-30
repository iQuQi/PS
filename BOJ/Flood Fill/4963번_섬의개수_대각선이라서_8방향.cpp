#include <iostream>
#include <string>
#include <queue>
#include <vector>
using namespace std;
int arr[51][51];
int com = 0, h, w;
int dx[8] = { 0,1,0,-1 ,1,1,-1,-1 };
int dy[8] = { 1,0,-1,0 ,1,-1,-1,1 };
//k 0 - �Ʒ�, 1 - ������, 2 - �� ,3 - ���� 
int visited[51][51];
/*
���簢������ �̷���� �ִ� ���� �ٴ� ������ �־�����. 
���� ������ ���� ���α׷��� �ۼ��Ͻÿ�.

�� ���簢���� ����, ���� �Ǵ� �밢������ ����Ǿ� �ִ� �簢���� �ɾ �� �ִ� �簢���̴�.

�� ���簢���� ���� ���� ��������, �� ���簢������ �ٸ� ���簢������ �ɾ �� �� �ִ� 
��ΰ� �־�� �Ѵ�. ������ �ٴٷ� �ѷ��ο� ������, ���� ������ ���� �� ����.
*/

bool isOk(int i, int j) {
	if (i<0 || i>h || j<0 || j>w || visited[i][j] || !arr[i][j])
	{
		return false;
	}
	return true;
}

void dfs(int i, int j) {
	visited[i][j] = 1;
	for (int k = 0; k < 8; k++)
	{
		if (isOk(i + dx[k], j + dy[k])) {
			dfs(i + dx[k], j + dy[k]);
		}
	}

}



int main()
{
	//�׽�Ʈ ���̽�
	while (1) {
		cin >> w >> h;
		com = 0;
		if (w == 0 && h == 0)break;
		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				cin >> arr[i][j];//1�� �� 0�� �ٴ�
			}
		}

		//������Ʈ ����
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (!visited[i][j] && arr[i][j])
				{
					com++;
					dfs(i, j);
				}
			}
		}

		//visit �迭 �ʱ�ȭ
		for (int i = 0; i < 51; i++)
		{
			for (int j = 0; j < 51; j++)
			{

				visited[i][j] = 0;
				arr[i][j] = 0;
			}
		}

		cout << com << endl;
	}
}