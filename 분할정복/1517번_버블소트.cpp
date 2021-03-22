#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>


using namespace std;
int n, k = 0;
long long swap_ = 0;
vector<int> v;
int sorted[500000 + 5];


void bubble(int start, int end) {
	int mid = (start + end) / 2;
	//�ӽ� ���� ����
	vector<int> tmp;
	//�ι�° �迭�� ����
	int right = mid + 1;
	//ù��° �迭�� ����
	int left = start;

	//ù��° �迭�� �ι�°�迭 ���� �ϳ��� ��������
	while (left <= mid && right <= end) {
		if (v[left] > v[right])//������ �迭�� ���Ұ� ���ʲ����� ������
		{
			//���� ��Ʈ���� �̵�ĭ���� ���� ��Ʈ������ ���� Ƚ���� �����Ѱ���
			swap_ += mid - left + 1;
			tmp.push_back(v[right++]);
			//�迭 �ε��� �ϸ鼭 ���ÿ� ������ �ع�����
		}
		else {//�����ʿ��Ұ� ���ʺ���Ŭ��
			tmp.push_back(v[left++]);
		}
	}

	//���� �迭�� ���� ��� �׳� ���� ���� �� ����ֱ�
	while (left <= mid) tmp.push_back(v[left++]);
	while (right <= end) tmp.push_back(v[right++]);

	//���� ������
	for (int i = start, j = 0; i <= end; i++, j++) {
		v[i] = tmp[j];
	}

}

void bubbleSort(int start, int end) {
	if (start < end)
	{
		int mid = (start + end) / 2;
		bubbleSort(start, mid);
		bubbleSort(mid + 1, end);
		bubble(start, end);
	}
}


int main() {
	cin >> n;
	int in;
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &in);
		v.push_back(in);
	}

	bubbleSort(0, n - 1);
	cout << swap_;
}