#include <iostream>
#include <vector>
#include <queue>
#include <stdlib.h>

using namespace std;
/*
���� 1, 2, 3���θ� �̷������ ������ �ִ�. 
������ ������ ������ �� ���� �κ� ������ ������ ���� ������, 
�� ������ ���� �����̶�� �θ���. �׷��� ���� ������ ���� �����̴�.

������ ���� ������ ���̴�.
33
32121323
123123213

������ ���� ������ ���̴�.
2
32
32123
1232123

���̰� N�� ���� �������� N�ڸ��� ������ ���� ���� ���� ���� ���� ��Ÿ���� ������ 
���ϴ� ���α׷��� �ۼ��϶�. 
���� ���, 1213121�� 2123212�� ��� ���� ���������� 
�� �߿��� ���� ���� ��Ÿ���� ������ 1213121�̴�.
*/
int n;
int sol[85];

int isOk(int dep) {
	for (int i = 1; i <= dep; i++)//üũ�� ���ӵǴ� �κ� ���� AA�� �� A ���̸� i��
	{
		for (int j = 1; j <= dep + 1 - 2 * i; j++) // j�� AA�� �� ���� A�� ������
		{
			int ch = 0;
			for (int k = 0; k < i; k++)//A�Ǳ��̸� �ϳ��� üũ
			{
				if (sol[j + k] != sol[j + i + k]) {
					ch = 1;
					break;
				}
			}
			if (ch == 0) return 0;//AA�� �Ǵ� ������ �ϳ��� ������ false
		}
	}
	return 1;
}

void backTrack(int depth) {
	//���� �Ʒ� depth ����
	//���� ���� �����ϴ°� ���� ���� ���� ���̹Ƿ� �ٷ� ����ع����� ��
	if (depth == n + 1) {
		for (int i = 1; i <= n; i++)
		{
			cout << sol[i];
		}
		cout << endl;
		exit(0);
		return;
	}

	//1 2 3 �� ���� ��� ����� �� ����
	for (int i = 1; i <= 3; i++)
	{
		sol[depth] = i;
		if (!isOk(depth)) continue;//����ġ��
		backTrack(depth + 1);
	}

}

int main() {
	cin >> n;
	backTrack(1);
}