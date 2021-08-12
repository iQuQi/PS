#include <iostream>
#include <vector>
#include <queue>
#include <stdlib.h>
#include <cstdio>
#include <algorithm>

using namespace std;
/*
���� Rĭ, ���� Cĭ���� �� ǥ ����� ���尡 �ִ�. 
������ �� ĭ���� �빮�� ���ĺ��� �ϳ��� ���� �ְ�, 
���� ��� ĭ (1�� 1��) ���� ���� ���� �ִ�.

���� �����¿�� ������ �� ĭ ���� �� ĭ���� �̵��� �� �ִµ�, 
���� �̵��� ĭ�� ���� �ִ� ���ĺ��� ���ݱ��� ������ ��� ĭ�� 
���� �ִ� ���ĺ����� �޶�� �Ѵ�. ��, ���� ���ĺ��� ���� ĭ�� �� �� ���� �� ����.

���� ��ܿ��� �����ؼ�, ���� �ִ��� �� ĭ�� ���� �� �ִ����� 
���ϴ� ���α׷��� �ۼ��Ͻÿ�. ���� ������ ĭ�� ���� ����� ĭ�� ���Եȴ�.
*/
int r, c;
int alpha[26];
char arr[22][22];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int dab = 0, _max = -1;
//�̶����� ���� ���ĺ����� Ȯ���ϴ� �Լ�
int isOk(int dep, int nextX, int nextY) {

	if (alpha[arr[nextY][nextX] - 65]) return 0;
	return 1;
}

void backTrack(int depth, int nx, int ny) {

	for (int i = 0; i < 4; i++)
	{
		//�������� ����ų� �̶����� ���� ���ĺ��� �ϳ��� ��
		if (ny + dy[i]<1 || ny + dy[i] >r || nx + dx[i] < 1 || nx + dx[i] > c || !isOk(depth, nx + dx[i], ny + dy[i])) {
			dab = depth - 1;
			if (_max <= dab) _max = dab;
			continue;
		}
		alpha[arr[ny + dy[i]][nx + dx[i]] - 65] = 1;
		backTrack(depth + 1, nx + dx[i], ny + dy[i]);
		alpha[arr[ny + dy[i]][nx + dx[i]] - 65] = 0;//�ٽ� ���������ִ� ���� �߿�
	}


	return;
}

int main() {
	cin >> r >> c;
	//���� ���� �Է� �ޱ�
	for (int i = 1; i <= r; i++)
	{
		for (int j = 1; j <= c; j++)
		{
			scanf("%1s", &arr[i][j]);
		}
	}
	alpha[arr[1][1] - 65] = 1;
	backTrack(2, 1, 1);//ù depth�� ���� �̹� �����������Ƿ� �ι��� depth���� ����
	cout << _max;
}
