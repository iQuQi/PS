#include <iostream>
#include <vector>
#include <queue>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <climits>
using namespace std;
/*
세준이는 성형수술을 한 후에 병원에 너무 오래 입원해 있었다. 
이제 세준이가 병원에 입원한 동안 자기를 생각해준 사람들에게 감사하다고 
말할 차례이다.

세준이를 생각해준 사람은 총 N명이 있다. 사람의 번호는 1번부터 N번까지 있다. 
세준이가 i번 사람에게 인사를 하면 L[i]만큼의 체력을 잃고, J[i]만큼의 기쁨을 얻는다. 
세준이는 각각의 사람에게 최대 1번만 말할 수 있다.

세준이의 목표는 주어진 체력내에서 최대한의 기쁨을 느끼는 것이다. 
세준이의 체력은 100이고, 기쁨은 0이다. 만약 세준이의 체력이 0이나 음수가 되면, 
죽어서 아무런 기쁨을 못 느낀 것이 된다. 세준이가 얻을 수 있는 최대 기쁨을 
출력하는 프로그램을 작성하시오.
*/
int n;
int L[22], J[22];
int DP[22][100+1];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		cin >> L[i];
	}

	for (int i = 1; i <= n; i++)
	{
		cin >> J[i];
	}

	for (int k = 0; k < n; k++) {
		for (int w = 1; w < 100; w++) { // 최대는 100이아니라 99임!!
			if (w >= L[k + 1])
				DP[k + 1][w] = max(DP[k][w], DP[k][w - L[k + 1]] + J[k + 1]);
			else
				DP[k + 1][w] = DP[k][w];

		}
	}

	cout << DP[n][99]; //최대는 100이 아니라 99
}


