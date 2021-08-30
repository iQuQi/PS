#include <iostream>
#include <vector>
#include <queue>
#include <stdlib.h>
#include <algorithm>

using namespace std;
/*
N-Queen 문제는 크기가 N × N인 체스판 위에 퀸 N개를 서로 공격할 수 없게 놓는 문제이다.

N이 주어졌을 때, 퀸을 놓는 방법의 수를 구하는 프로그램을 작성하시오.
*/
int n;
int sol[20];
int arr[20][20];
int dab = 0;
int isOk(int dep) {

	for (int i = 1; i < dep; i++)
	{
		//같은 col에 퀸이 이미 있으면 안됨
		//대각선 방향에 퀸이 이미 있으면 안됨
		if (sol[i] == sol[dep] || abs(sol[i] - sol[dep]) == abs(i - dep))return 0;
	}
	return 1;
}

void backTrack(int depth) {


	if (depth == n + 1) {
		dab++;
		return;

	}
	for (int i = 1; i <= n; i++)
	{
		sol[depth] = i;
		if (!isOk(depth)) continue;//가지치기
		backTrack(depth + 1);
	}

}

int main() {
	cin >> n;//퀸의 개수 입력 받기
	backTrack(1);
	cout << dab;
}