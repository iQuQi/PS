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
앞에서 뒤로 보나, 뒤에서 앞으로 보나 같은 수열을 팰린드롬 이라고 한다.
예를 들어 {1}, {1, 2, 1}, {1, 2, 2, 1}과 같은 수열은 팰린드롬 이지만,
{1, 2, 3}, {1, 2, 3, 2} 등은 팰린드롬이 아니다.

한 수열이 주어졌을 때, 이 수열에 최소 개수의 수를 끼워 넣어 팰린드롬을
만들려고 한다. 최소 몇 개의 수를 끼워 넣으면 되는지를 알아내는 프로그램을
작성하시오.
*/

const int MAX = 5005;

int N;
int arr[MAX];
// dp[i][j] : i,j 를 양 끝으로 하는 펠린드롬 만드는 데 필요한 최소 개수
// i=j 일 때 dp[i][j] = 0 이고, 구하고자 하는 답은 dp[0][N-1] 

int dp[MAX][MAX];

int palin(int s, int e) {//시작점과 끝점
	if (s >= e) return 0;

	int& ret = dp[s][e]; 

	if (ret != -1) return ret; // -1 이 아니라 다른 값으로 이미 수정되있는 경우
	/*
	min으로 palin을 2번 돌리는 과정에서 중복되는 계산이 생기기 떄문
	(_(_(내부재귀함수)_)_)_____  -----1
	_____(_(_(내부재귀함수)_)_)  -----2
	중간에서 동시에 건들이게 되는 부분이 나오게 됨
	*/

	ret = 0; // 초기 0으로 생각
	// arr[s] = arr[e] 인 경우 그냥 안쪽으로 탐색
	if (arr[s] == arr[e]) ret += palin(s + 1, e - 1);

	// arr[s]!=arr[e] 인 경우 한쪽 맞춰주고(+1) 넘겨보는 것 중 작은거.
	else ret += 1 + min(palin(s + 1, e), palin(s, e - 1));

	return ret;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	/*
	 양끝에서 안쪽으로 좁혀 오면서 펠린드롬을 만드는 데 필요한 최소 개수를 세기
	1. 탐색하는 두 수가 같으면 그냥 다음 탐색으로 넘어가기
	2. 탐색하는 두 수가 다르면, 한쪽을 맞춰주고, 그쪽만 넘어가기

	*/
	cin >> N;
	for (int i = 0; i < N; ++i) cin >> arr[i];
	memset(dp, -1, sizeof(dp));//#include <bits/stdc++.h>

	cout << palin(0, N - 1) << '\n';

	return 0;


}
