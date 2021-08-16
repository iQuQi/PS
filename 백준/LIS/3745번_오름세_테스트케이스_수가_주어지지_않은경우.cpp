#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
/*
주식투자를 좋아하는 정인이는 주가의 오름세를 살펴보려고 한다.

정인이는 n일 동안 매일 주가를 적어놓았고, 여기서 오름세를 찾아보려고 한다.

n일 동안의 주가를 p1, p2, ..., pn이라고 했을 때, 
오름세란 부분수열 pi1 < pi2 < ... < pik (i1 < i2 < ... ik)을 말한다.

n일 동안 주가가 주어졌을 때, 가장 긴 오름세를 찾는 프로그램을 작성하시오.
*/
int arr[100000 + 5];
vector<int> dp;
int main() {


	int n;
	//케이스 개수가 정해져있지 않은 경우 입력 받는 법
	while (scanf("%d", &n) > 0) {
		for (int i = 1; i <= n; i++)
		{
			cin >> arr[i];
		}

		for (int i = 1; i <= n; i++)
		{
			if (dp.size() == 0 || arr[i] > dp.back()) dp.push_back(arr[i]);
			else {
				//lower_bound는 이분탐색 
				int index = lower_bound(dp.begin(), dp.end(), arr[i]) - dp.begin();
				dp[index] = arr[i];
			}
		}

		//DP의  길이 == LIS의 길이
		cout << dp.size() << endl;
		//테스트 케이스 마다 초기화 필수
		dp.resize(0, 0);
	}




}
