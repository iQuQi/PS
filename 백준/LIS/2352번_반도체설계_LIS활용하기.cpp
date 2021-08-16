#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
/*
반도체를 설계할 때 n개의 포트를 다른 n개의 포트와 연결해야 할 때가 있다.

예를 들어 왼쪽 그림이 n개의 포트와 다른 n개의 포트를 어떻게 연결해야 하는지를 나타낸다. 
하지만 이와 같이 연결을 할 경우에는 연결선이 서로 꼬이기 때문에 이와 같이 연결할 수 없다.

n개의 포트가 다른 n개의 포트와 어떻게 연결되어야 하는지가 주어졌을 때, 
연결선이 서로 꼬이지(겹치지, 교차하지) 않도록 하면서 최대 몇 개까지 연결할 수 있는지를 
알아내는 프로그램을 작성하시오
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
