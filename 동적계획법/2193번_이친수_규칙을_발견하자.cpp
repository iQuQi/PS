#include <iostream>
#include <stdio.h>

#include <string>
#include <algorithm>
#include <cmath>
using namespace std;
//2193번 이친수
/*
이친수는 0으로 시작하지 않는다.
이친수에서는 1이 두 번 연속으로 나타나지 않는다. 
즉, 11을 부분 문자열로 갖지 않는다.
N(1 ≤ N ≤ 90)이 주어졌을 때, 
N자리 이친수의 개수를 구하는 프로그램을 작성하시오.
*/
int main() {
	int N;
	long long dp[100][3];
	scanf("%d", &N);

	dp[1][0] = 0; //0으로 끝나는 이친수 개수
	dp[1][1] = 1; //1로 끝나는 이친수 개수
	dp[1][2] = 1; // 총 이친수의 개수

	for (int i = 2; i < 100; i++) {
		dp[i][0] = dp[i - 1][2];
		dp[i][1] = dp[i - 1][0];
		dp[i][2] = dp[i][0] + dp[i][1];
	}

	printf("%lld", dp[N][2]);
}

