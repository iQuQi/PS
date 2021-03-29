#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#define CON 1'000'000'000 // x�� �ִ�
//�̷��� ���� ����ǥ�� ū ���� �ڸ��� ǥ�� ����
using namespace std;
long long x, y, z, now_z;

//�����̰� ���ڱ� ������ ������ �̱�Ե�
//������ ���� ����� �����ִٰ� �Ҷ�
//������ �ּ� ��� �� �ؾ� �·��� ���ϴ� ��

//�·��� ���� ������ �ʴ� �ٸ� -1 ���
//�·����� �Ҽ����� ����
//x�� ���� Ƚ�� y�� �̱� ����

long long bin(long long left, long long right) {
	long long mid, ret = -1;

	while (left <= right)
	{
		mid = (left + right) / 2;
		//mid �� �� �̰��� �� �·�
		z = (y + mid) * 100 / (x + mid);

		//���� �������� ���ٸ�
		if (z > now_z) {
			right = mid - 1;
		}
		//���� �·����� ���ٸ�
		else {
			left = mid + 1;
			ret= mid + 1;
		}
	}
	return ret;
}


int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> x >> y;
	//����·�
	now_z = (y * 100) / x;

	//���� �·��� 99�۶�� 100�� ���� �� �� �����Ƿ� �Ұ���
	if (now_z >= 99)
	{
		cout << -1;
		return 0;
	}
	cout << bin(0, CON);

}
