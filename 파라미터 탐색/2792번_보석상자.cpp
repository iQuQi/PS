#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#define CON 1000000000 
using namespace std;
int n, m, need;
vector<int > v;
//�������� �ּҰ� �ǰ� ���� ������ -> ������ �ּڰ� ���
//��ΰ� ������ �ʾƵ� ������ �л��� �׻� ���� ������ ������ ����
//�������� ���� ���� ������ ������ �л��� ���� ����

//��� ������ ������ �� �� �ִ°�
int too(int per) {
	int ans = 0;
	for (int i = 0; i < m; i++)
	{
		ans += v[i] / per;//������ �������� per ��ŭ�� ������ ����� �ټ��ִ��� �հ�
		if (v[i] % per != 0) ans++;//������ �������� �ʴ� ��� �������� �Ѹ� �� �� ����
	}

	//��� ���� ��� ����
	if (ans <= n)return 1;
	//�Ұ���
	return 0;
}


//�̺�Ž�� -> parametric 
//��� ������ ���� �� �� �ִ� ��� �� per�� �ּҷ� �Ǵ� �� ���ϱ�
int bin(int low, int high) {
	int mid, ret = high;
	while (low <= high)
	{
		mid = (low + high) / 2;
		//��� ������ ������ �� �ִ� ���
		if (too(mid)) {
			//ret��(min ��) ����
			if (ret >= mid)ret = mid;
			high = mid - 1;
		}
		else {
			low = mid + 1;
		}
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n >> m;//n=���̵�� m=���� ��
	int k, max = 0;
	for (int i = 0; i < m; i++)
	{
		cin >> k;//i�� ���� ������ ����
		if (max <= k)max = k;
		v.push_back(k);
	}
	cout << bin(1, max);
}
