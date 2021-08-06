#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#define CON 1000000000 
using namespace std;
int n, m, need;
vector<int > v;//��û�� �����ϴ� �迭

//������ �ִ��� �� ���� ����
//��� ��û�� ������ �� �ִ� ��� ��û�� �ݾ��� �״�� ����
//��� ��û�� ������ �� ���� ��� Ư���� ���� ���Ѿ��� ����ؼ� ��� ���Ѿ��� ����. 
//   -> ���Ѿ� ������ ��û�� ��� ��û �ݾ� �״�� ����

int too(int upper) {
	int ans = 0;
	int need = 0;

	for (int i = 0; i < n; i++)
	{
		if (v[i] <= upper)need += v[i]; // ���Ѿ׺��� ���ٸ� �״�� ����
		else need += upper; // ���Ѿ׺��� ���ٸ� ���Ѿ����� ����
	}

	//�ѿ��� ���� �ʿ��� �ݾ��� ���� ��� -> ��� ��û�� ���� �ݾ� �״�� ����
	if (need <= m)return 1;
	//�ѿ��� ���� �ʿ��� �ݾ��� ŭ -> �Ұ���
	return 0;

}

int bin(int low, int high) {
	int mid, ret = low;
	//(1)yes------------|--------no(max)
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (too(mid)) {
			//���Ѿ��� �ִ��� ����
			if (ret <= mid)ret = mid;
			low = mid + 1;
		}
		else {
			high = mid - 1;
		}
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;// �����Ǽ�
	int k, max = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> k;//�� ������ ���� ��û
		if (max <= k)max = k;
		v.push_back(k);
	}
	cin >> m;//�ѿ���
	cout << bin(1, max);

}