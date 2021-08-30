#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#define CON 1000000000 
using namespace std;
int n;
long long m;
vector<long long > v;

//������ ������ �ǵ� ���̸� �ѹ� ���ϰ� �� ���� �ִ� �������� ��� �߶� ������
//�ʿ��� ��ŭ�� ������. ��� m ������ ������ �������� ���� ���ܱ� ������ �ִ�
int too(long long hei) {
	long long sum = 0;

	for (int i = 0; i < n; i++) if (v[i] > hei)sum += v[i] - hei;

	//�ش� ���̼������� ��� m ������ ������ ������ �� �ִ���
	if (sum >= m)	return 1;
	return 0;

}

int bin(long long low, long long high) {//yes �� ���������� �ִ밪
	//(1)yes------------|--------no(max)
	long long mid;
	long long re = low;
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (too(mid)) {
			if (re <= mid)re = mid;
			low = mid + 1;
		}
		else {
			high = mid - 1;
		}
	}
	return re;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n;//������
	cin >> m;//������ ���������ϴ� ��������
	long long k, max = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> k; // �� ������ ����
		if (max <= k)max = k;//�ִ� ���س��� ->Ž�������� ���Ѽ� ����
		v.push_back(k);
	}

	cout << bin(0, max); 




}
