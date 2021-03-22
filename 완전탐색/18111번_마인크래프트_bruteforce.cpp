#include <iostream>
#include <vector>
#include <queue>
#include <stdlib.h>
#include <string>
#include <algorithm>

using namespace std;
int arr[505][505];

int main() {
	//�����ϰ� ������ �۾�
	//����� �ļ� ���濡 ��°���  2��
	//����� ���濡�� ������ ���� ���� ���� 1��
	//�ִ� �ð��ȿ� ���� ���� ������

	//���: �ִܽð��� �� ����

	//�ִ� ���̴� 256�̸� ����x. 
	int n,m, b;//�Է�: ���� ���� ,���ۺ��� ���� ���� ����� ����
	cin >> n >> m >> b;
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> arr[i][j];
		}
	}

	int ansTime = 999999999, ansLayer = -1;
	//brute force�� ��� ���̿� ���� ���
	for (int nowLayer = 0; nowLayer <= 256; nowLayer++)
	{
		//now layer -> ��ǥ����
		int nowTime = 0, nowInvent = b;
		int need = 0;


		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				need = nowLayer - arr[i][j];
				if (need > 0) {
					//����� �״� ���
					nowTime += need;
					nowInvent -= need;
				}
				else {
					//����� �μ��� ���
					nowTime += 2 * (-need);
					nowInvent -= need;
				}
			}
		}
		
		//��ȿ�� ���̰� �ּ� �ð��̶�� �����Ѵ�
		if (nowInvent >= 0 && nowTime <= ansTime) {
			ansTime = nowTime;
			ansLayer = nowLayer;
		}

	}

	//���
	cout << ansTime << " " << ansLayer << endl;
}

