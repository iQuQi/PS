#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
//�Ķ����Ǵ� �Ͼ������ ĥ���� ���� ������
//���̸� �ڸ��� ��Ģ: 
//1. ��ü ���̰� ��� ���� ���� �ƴҰ�� ���ο� ���η� �߰� �κ��� �߶�
//���� ũ���� 4�������� ����
//2.�� ������ �ݺ��ؼ� ���̰� ��� ���� ������ ĥ�����ְų�
//�ϳ��� ���簢�� ĭ�� �Ǿ� �� �̻� �ڸ� �� ���� �� ���� �ݺ�

//n�� 2^1~2^7 (2�� �ŵ�������)
//�Ͼ�ĭ�� 0 �Ķ�ĭ�� 1
// �Ͼ�� ���� ������ �Ķ��� ������ ���� ���
using namespace std;

int arr[130][130];
int n;
int blue, white;

//R�� row �κ� C�� col �κ�
void color(int startR, int endR, int startC, int  endC) {

	//�Ѱ� ���簢���� ���
	//����->��ǥ�λ���x �ϳ����簢���� ���μ���1�����̳��� �� �ƴ�
	if (startR == endR && startC == endC)
	{
		if (arr[startR][startC] == 0) white++;
		else blue++;
		return;
	}


	bool allSame = true;
	int beforeColor = arr[startR][startC];

	//���� ĭ�� ����� �ϳ��� �ٸ��� �߰ߵǸ� false
	for (int i = startR; i <= endR; i++)
	{
		for (int j = startC; j <= endC; j++)
		{
			if (arr[i][j] != beforeColor)
			{
				allSame = false;
				break;
			}
		}
		if (!allSame)break;
	}

	//��� ���ٸ� �� �ڸ� �ʿ�x -> return
	if (allSame)
	{
		if (beforeColor == 0)white++;
		else blue++;
		return;
	}

	//�ϳ��� ���簢���� �ƴϰ� ��ΰ��� �ʴٸ� 4���
	int midR = (startR + endR) / 2, midC = (startC + endC) / 2;
	color(startR, midR, startC, midC);  // ù��°ĭ
	color(startR, midR, midC + 1, endC);  // �ι�°
	color(midR + 1, endR, startC, midC);  //  ����°
	color(midR + 1, endR, midC + 1, endC); //  �׹�°
	// 1 2
	// 3 4

}




int main() {

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> arr[i][j];
		}
	}

	color(0, n - 1, 0, n - 1);
	cout << white << endl;
	cout << blue << endl;
}