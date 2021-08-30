#include <iostream>
#include <vector>
#include <queue>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <climits>
using namespace std;
#define INF 2000000000
/*
n���� ������ ������ �ִ�. �� �������� ������ ����ؼ�, 
�� ��ġ�� ���� k���� �ǵ��� �ϰ� �ʹ�. �׷��鼭 ������ 
������ �ּҰ� �ǵ��� �Ϸ��� �Ѵ�. ������ ������ �� ���� ����� �� �ִ�.

����� ������ ������ ������, ������ �ٸ� ���� ���� ����̴�.
*/
int n, k;
int DP[10000+1];
int c[100 + 1]; // ������ ���Կ� ������ ��ġ


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);	
	cin >> n >> k;
	for (int j = 0; j <= k; j++)
	{
		DP[j] = INF;
	}

	for (int i = 1; i <= n; i++)
	{
		cin >>  c[i];
		if(c[i]<=10000)DP[c[i]] = 1;
	}
	

	for (int i = 1; i <= k; i++) {
		if (DP[i] == INF) {
			for (int j = 0; j <= n; j++) {
				if ((i - c[j]) >= 0 && DP[i - c[j]] != INF) {
					DP[i] = min(DP[i],DP[i - c[j]] + 1);
				}
			}
		}
		else continue;
	}
	
	if (DP[k]!=INF )cout << DP[k];
	else cout << -1;
}

