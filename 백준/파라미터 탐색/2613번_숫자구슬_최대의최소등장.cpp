#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;
int n;
int m;
int arr[305] = { 0, };
int dab[305];

vector<int > v;
/*
N���� ���� ������ <�׸� 1>�� ���� ���뿡 ����� ���ڷ� ���� �ִ�.
�̵� ������ ���뿡�� ���� �� ����, �ٲ� �� ����.

|---5 4 2 6 9 3 8 7----|

�� ���� ������ M���� �׷����� �������� �� ������ �׷��� �� �� �ִ���
�ּҰ� �ǵ��� �Ϸ� �ϴ�.

���� ��� �� �׷����� �����ٰ� �� �� 
<�׸� 2>�� ���� �׷��� ������ �׷��� ���� ���� 11, 15, 18�� �Ǿ� 
�� �� �ִ��� 18�� �ǰ�, 

<�׸� 3>�� ���� ������ �� �׷��� ���� ���� 17, 12, 15�� �Ǿ�
�� �� �ִ��� 17�� �ȴ�.

���� ������ �迭�� ���� ���� ���� �׷��� �� �� �ִ��� 17���� �۰� ���� ���� ����.
�׷쿡 ���Ե� ���� ������ ������ 0���� Ŀ�� �Ѵ�.

�� �׷��� �� �� �ִ��� �ּҰ� �ǵ��� M���� �׷����� �������� ��, 
�� �ִ񰪰� �� �׷��� �����ϴ� ������ ������ ã�� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.
*/


//mid���� �޾Ƽ� �� ���� �ִ��� �ǰ� m���� �׷����� ������ �ִ���
int goosle(int mm) {

	//cout << "mm : " << mm << endl;
	int sum = 0, cnt = 0;
	int group = 1;

	for (int i = 0; i < n; i++)
	{
		//mid���� �ϳ��� �������� Ŭ��� �Ұ����ϹǷ� 0����
		if (v[i] > mm) return 0;
		sum += v[i];
		cnt++;

		//mid�� �Ѿ�� �ձ������� group ����
		if (sum > mm)
		{
			cnt--;
			sum = v[i];

			arr[group] = cnt;
			group++;
			cnt = 1;
		}
		//������ ���� ���� ���� �� �ֱ�
		if (i == n - 1) arr[group] = cnt;
	}
	//�׷��� m�����Ϸ� ����������� ��� 1����
	if (group <= m)return 1;
	return 0;
}

//����Ž�� �� �޾Ƽ� �׷캰 �������� ���
void print(int re) {
	int sum = 0, cnt = 0;
	int group = 1;
	for (int i = 0; i < n; i++)
	{
		sum += v[i];
		cnt++;
		if (sum > re)
		{
			cnt--;
			sum = v[i];
			dab[group] = cnt;
			group++;
			cnt = 1;
		}
		if (i == n - 1)dab[group] = cnt;
	}

	//m�� �����ߵ� �׷� group�� ���� �������̽��� �׷찳�� -> need �� �ɰ��� �� �������ߵ� �׷��
	int need = m - group;
	for (int i = 1; i <= group; i++)
	{
		if (dab[i] == 1)cout << dab[i] << " ";
		else {
			while (dab[i] >= 2 && need >= 1) {
				//cout << "while.." << endl;
				cout << 1 << " ";
				dab[i]--;
				need--;
			}
			cout << dab[i] << " ";
		}
	}

}


//����Ž���Լ�
int bin(int low, int high) {
	int mid;
	int tmp;
	int re = high;
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (goosle(mid)) {
			if (re >= mid)re = mid;
			high = mid - 1;
		}
		else {
			low = mid + 1;
		}
	}
	return re;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;//��������
	cin >> m;//�׷��
	int sum = 0;
	int k;
	for (int i = 0; i < n; i++)
	{
		cin >> k;

		sum += k;
		v.push_back(k);//�����迭
	}

	int ret = bin(1, sum);
	cout << ret << endl;
	print(ret);




}
