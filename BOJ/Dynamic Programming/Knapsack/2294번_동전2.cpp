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
n가지 종류의 동전이 있다. 이 동전들을 적당히 사용해서, 
그 가치의 합이 k원이 되도록 하고 싶다. 그러면서 동전의 
개수가 최소가 되도록 하려고 한다. 각각의 동전은 몇 개라도 사용할 수 있다.

사용한 동전의 구성이 같은데, 순서만 다른 것은 같은 경우이다.
*/
int n, k;
int DP[10000+1];
int c[100 + 1]; // 보석의 무게와 보석의 가치


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

