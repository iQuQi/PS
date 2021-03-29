#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> s;
vector<int> j;

//������ ������ ��ֹ��� �ִ� �������� ���˹����� �İ��ؾ��ϴ� ��ֹ��� �ּڰ��� �׷��� ������ ����ã��


int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, h;
	cin >> n >> h;//n�� ������ ���� h�� ����
	//��ֹ��� n�� �̸� ũ��� h�� ���� ����
	// ù ��ֹ��� �׻� ����(�Ʒ�)  �� �ٿ� ������(��)  -> �ݺ�

	int a, b, min = 100000 + 1, cnt = 0, tmp;

	//�Է� �ޱ�
	for (int i = 1; i <= n / 2; i++)
	{
		cin >> a >> b;
		s.push_back(a);
		j.push_back(b);

	}
	
	//������ ������ �迭�� ũ���� ����
	sort(s.begin(), s.end());
	sort(j.begin(), j.end());

	//i�� ���� ���� ����
	for (int i = 1; i <= h; i++)
	{
		//�ν����ϴ� ���� - lower bound= ���ϴ� �� �̻��� ó������ ������ ��ġ Ž�� -> �̺�Ž��
		tmp = n / 2 - (lower_bound(s.begin(), s.end(), i) - s.begin());
		//�ν����ϴ� ������ - upper bound- ���ϴ� ���� �ʰ��ϴ� ���� ó�� ������ ��ġ -> �̺�Ž��
		tmp += n / 2 - (upper_bound(j.begin(), j.end(), h - i) - j.begin());

		//�ּڰ� ����
		if (tmp < min) {
			min = tmp;
			cnt = 1;
		}
		//�ּڰ��� ���� ���� count
		else if (tmp == min) {
			cnt++;
		}
	}

	cout << min << " " << cnt;
}
