#include <iostream>
#include <vector>
#include <queue>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <climits>
#include <bits/stdc++.h>

using namespace std;
/*
�տ��� �ڷ� ����, �ڿ��� ������ ���� ���� ������ �Ӹ���� �̶�� �Ѵ�.
���� ��� {1}, {1, 2, 1}, {1, 2, 2, 1}�� ���� ������ �Ӹ���� ������,
{1, 2, 3}, {1, 2, 3, 2} ���� �Ӹ������ �ƴϴ�.

�� ������ �־����� ��, �� ������ �ּ� ������ ���� ���� �־� �Ӹ������
������� �Ѵ�. �ּ� �� ���� ���� ���� ������ �Ǵ����� �˾Ƴ��� ���α׷���
�ۼ��Ͻÿ�.
*/

const int MAX = 5005;

int N;
int arr[MAX];
// dp[i][j] : i,j �� �� ������ �ϴ� �縰��� ����� �� �ʿ��� �ּ� ����
// i=j �� �� dp[i][j] = 0 �̰�, ���ϰ��� �ϴ� ���� dp[0][N-1] 

int dp[MAX][MAX];

int palin(int s, int e) {//�������� ����
	if (s >= e) return 0;

	int& ret = dp[s][e]; 

	if (ret != -1) return ret; // -1 �� �ƴ϶� �ٸ� ������ �̹� �������ִ� ���
	/*
	min���� palin�� 2�� ������ �������� �ߺ��Ǵ� ����� ����� ����
	(_(_(��������Լ�)_)_)_____  -----1
	_____(_(_(��������Լ�)_)_)  -----2
	�߰����� ���ÿ� �ǵ��̰� �Ǵ� �κ��� ������ ��
	*/

	ret = 0; // �ʱ� 0���� ����
	// arr[s] = arr[e] �� ��� �׳� �������� Ž��
	if (arr[s] == arr[e]) ret += palin(s + 1, e - 1);

	// arr[s]!=arr[e] �� ��� ���� �����ְ�(+1) �Ѱܺ��� �� �� ������.
	else ret += 1 + min(palin(s + 1, e), palin(s, e - 1));

	return ret;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	/*
	 �糡���� �������� ���� ���鼭 �縰����� ����� �� �ʿ��� �ּ� ������ ����
	1. Ž���ϴ� �� ���� ������ �׳� ���� Ž������ �Ѿ��
	2. Ž���ϴ� �� ���� �ٸ���, ������ �����ְ�, ���ʸ� �Ѿ��

	*/
	cin >> N;
	for (int i = 0; i < N; ++i) cin >> arr[i];
	memset(dp, -1, sizeof(dp));//#include <bits/stdc++.h>

	cout << palin(0, N - 1) << '\n';

	return 0;


}
