#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
/*
�ֽ����ڸ� �����ϴ� �����̴� �ְ��� �������� ���캸���� �Ѵ�.

�����̴� n�� ���� ���� �ְ��� ������Ұ�, ���⼭ �������� ã�ƺ����� �Ѵ�.

n�� ������ �ְ��� p1, p2, ..., pn�̶�� ���� ��, 
�������� �κм��� pi1 < pi2 < ... < pik (i1 < i2 < ... ik)�� ���Ѵ�.

n�� ���� �ְ��� �־����� ��, ���� �� �������� ã�� ���α׷��� �ۼ��Ͻÿ�.
*/
int arr[100000 + 5];
vector<int> dp;
int main() {


	int n;
	//���̽� ������ ���������� ���� ��� �Է� �޴� ��
	while (scanf("%d", &n) > 0) {
		for (int i = 1; i <= n; i++)
		{
			cin >> arr[i];
		}

		for (int i = 1; i <= n; i++)
		{
			if (dp.size() == 0 || arr[i] > dp.back()) dp.push_back(arr[i]);
			else {
				//lower_bound�� �̺�Ž�� 
				int index = lower_bound(dp.begin(), dp.end(), arr[i]) - dp.begin();
				dp[index] = arr[i];
			}
		}

		//DP��  ���� == LIS�� ����
		cout << dp.size() << endl;
		//�׽�Ʈ ���̽� ���� �ʱ�ȭ �ʼ�
		dp.resize(0, 0);
	}




}
