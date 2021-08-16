#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
/*
�ݵ�ü�� ������ �� n���� ��Ʈ�� �ٸ� n���� ��Ʈ�� �����ؾ� �� ���� �ִ�.

���� ��� ���� �׸��� n���� ��Ʈ�� �ٸ� n���� ��Ʈ�� ��� �����ؾ� �ϴ����� ��Ÿ����. 
������ �̿� ���� ������ �� ��쿡�� ���ἱ�� ���� ���̱� ������ �̿� ���� ������ �� ����.

n���� ��Ʈ�� �ٸ� n���� ��Ʈ�� ��� ����Ǿ�� �ϴ����� �־����� ��, 
���ἱ�� ���� ������(��ġ��, ��������) �ʵ��� �ϸ鼭 �ִ� �� ������ ������ �� �ִ����� 
�˾Ƴ��� ���α׷��� �ۼ��Ͻÿ�
*/
int arr[100000 + 5];
vector<int> dp;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}

	for (int i = 1; i <= n; i++)
	{
		if (dp.size() == 0 || arr[i] > dp.back())dp.push_back(arr[i]);
		else {
			int index = lower_bound(dp.begin(), dp.end(), arr[i]) - dp.begin();
			dp[index] = arr[i];
		}
	}

	cout << dp.size();




}
