#include <iostream>
#include <vector>
#include <queue>
#include <stdlib.h>
#include <algorithm>

using namespace std;
/*
�ٷ� ���� �ֹ��� ������ �� ���踦 �ָӴϿ� ���� ä �����ϰ� 
����� �� ������ Ȳ���� ��Ȳ�� ������ ��������, 
702ȣ�� ���ο� ���� �ý����� ��ġ�ϱ�� �Ͽ���. 
�� ���� �ý����� ���谡 �ƴ� ��ȣ�� �����ϰ� �Ǿ� �ִ� �ý����̴�.

��ȣ�� ���� �ٸ� L���� ���ĺ� �ҹ��ڵ�� �����Ǹ� 
�ּ� �� ���� ����(a, e, i, o, u)�� �ּ� �� ���� �������� �����Ǿ� 
�ִٰ� �˷��� �ִ�. 

���� ���ĵ� ���ڿ��� ��ȣ�ϴ� �������� 
�������� �̷�� ���� ��ȣ�� �̷�� ���ĺ��� ��ȣ���� �����ϴ� ������ 
�迭�Ǿ��� ���̶�� �����ȴ�. 

��, abc�� ���ɼ��� �ִ� ��ȣ������ bac�� �׷��� �ʴ�.

�� ���� �ý��ۿ��� �������� ��ȣ�� ������� ���� ������ ������
C������ �ִٰ� �Ѵ�. �� ���ĺ��� �Լ��� �ν�, ���� ������ �������� �濡 
ħ���ϱ� ���� ��ȣ�� ������ ������ �Ѵ�.

C���� ���ڵ��� ��� �־����� ��,
���ɼ� �ִ� ��ȣ���� ��� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.
*/
int l, c;
char sol[20];
char arr[20];
//�������� üũ��
int isOk() {
	// a(97) e(101) i(105) o(111) u(117) ����
	// 0 4  8 14 20
	//���̿� ����
	int ja = 0;
	int mo = 0;

	for (int i = 1; i <= l; i++)
	{
		if ((sol[i] - 97) == 0 || (sol[i] - 97) == 4 || (sol[i] - 97) == 8 
			|| (sol[i] - 97) == 14 || (sol[i] - 97) == 20) mo++;
		else ja++;
	}
	if (ja >= 2 && mo >= 1) return 1;
	
	return 0;
}

//����ġ�� üũ��
int isOk2(int dep) {
	int ch[20] = { 0 };
	char ch2[20];

	//�������� üũ
	for (int i = 1; i <= dep; i++)
	{
		ch2[i] = sol[i];
	}
	sort(ch2, ch2 + dep + 1);
	for (int i = 1; i <= dep; i++)
	{
		if (ch2[i] != sol[i]) return 0;
	}

	//���������ִ��� üũ
	for (int i = 1; i <= dep; i++)
	{
		for (int j = 1; j <= c; j++)
		{
			if (sol[i] == arr[j])ch[j]++;
		}
	}

	for (int j = 1; j <= c; j++)
	{
		if (ch[j] >= 2) return 0;
	}
	return 1;
}

void backTrack(int depth) {

	//��������
	if (depth == l + 1) {

		if (isOk()) {
			for (int i = 1; i <= l; i++) cout << sol[i];
			cout << endl;
		}
		return;
	}

	for (int i = 1; i <= c; i++)
	{
		sol[depth] = arr[i];
		if (!isOk2(depth)) continue;//����ġ��
		backTrack(depth + 1);
	}

}

int main() {
	cin >> l >> c;
	//���� �ٸ� L���� ���ĺ� �ҹ���, - �ּ� �Ѱ��� ������ �ΰ��� �������� ���� - ��������
	//�־��� c���� ���ڷ� ������ ��ȣ�� ��� ������
	char in;

	for (int i = 1; i <= c; i++)
	{
		cin >> in;
		arr[i] = in;
	}
	sort(arr, arr + c + 1);
	backTrack(1);



}