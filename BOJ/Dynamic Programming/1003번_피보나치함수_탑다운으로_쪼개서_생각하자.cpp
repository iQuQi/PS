#include <iostream>
#include <vector>
#include <queue>
#include <stdlib.h>
#include <string>
#include <algorithm>

using namespace std;
int dp[45][2];

/*
피보나치를 재귀함수로 구현한 경우
fibonacci(3)을 호출하면 다음과 같은 일이 일어난다.


fibonacci(3)은 fibonacci(2)와 fibonacci(1) (첫 번째 호출)을 호출한다.
fibonacci(2)는 fibonacci(1) (두 번째 호출)과 fibonacci(0)을 호출한다.
두 번째 호출한 fibonacci(1)은 1을 출력하고 1을 리턴한다.
fibonacci(0)은 0을 출력하고, 0을 리턴한다.
fibonacci(2)는 fibonacci(1)과 fibonacci(0)의 결과를 얻고, 1을 리턴한다.
첫 번째 호출한 fibonacci(1)은 1을 출력하고, 1을 리턴한다.
fibonacci(3)은 fibonacci(2)와 fibonacci(1)의 결과를 얻고, 2를 리턴한다.


1은 2번 출력되고, 0은 1번 출력된다. N이 주어졌을 때, fibonacci(N)을 호출했을 때, 
0과 1이 각각 몇 번 출력되는지 구하는 프로그램을 작성하시오.
*/

int main() {
	int n, t;
	cin >> t;
	dp[0][0] = 1;
	dp[0][1] = 0;
	dp[1][0] = 0;
	dp[1][1] = 1;
	//dp[][0]의 경우 해당 케이스에서 0이 출력되는 횟수
	//dp[][1]의 경우 해당 케이스에서 1이 출력되는 횟수

	//트리구조로 그래프를 그래서 top-down 으로 가보면 이해될 것임

	for (int i = 2; i <= 40; i++)
	{
		dp[i][0] = dp[i - 1][0] + dp[i - 2][0];
		dp[i][1] = dp[i - 1][1] + dp[i - 2][1];
		//cout << i << "=" << dp[i][0] << " " << dp[i][1]<<endl;
	}

	for (int i = 0; i < t; i++)
	{
		cin >> n;
		cout << dp[n][0] << " " << dp[n][1] << endl;
	}

}

