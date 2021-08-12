#include <iostream>
#include <vector>
#include <queue>
#include <stdlib.h>

using namespace std;
/*
숫자 1, 2, 3으로만 이루어지는 수열이 있다. 
임의의 길이의 인접한 두 개의 부분 수열이 동일한 것이 있으면, 
그 수열을 나쁜 수열이라고 부른다. 그렇지 않은 수열은 좋은 수열이다.

다음은 나쁜 수열의 예이다.
33
32121323
123123213

다음은 좋은 수열의 예이다.
2
32
32123
1232123

길이가 N인 좋은 수열들을 N자리의 정수로 보아 그중 가장 작은 수를 나타내는 수열을 
구하는 프로그램을 작성하라. 
예를 들면, 1213121과 2123212는 모두 좋은 수열이지만 
그 중에서 작은 수를 나타내는 수열은 1213121이다.
*/
int n;
int sol[85];

int isOk(int dep) {
	for (int i = 1; i <= dep; i++)//체크할 연속되는 부분 수열 AA의 중 A 길이를 i로
	{
		for (int j = 1; j <= dep + 1 - 2 * i; j++) // j는 AA의 중 앞의 A의 시작점
		{
			int ch = 0;
			for (int k = 0; k < i; k++)//A의길이를 하나씩 체크
			{
				if (sol[j + k] != sol[j + i + k]) {
					ch = 1;
					break;
				}
			}
			if (ch == 0) return 0;//AA가 되는 수열이 하나라도 있으면 false
		}
	}
	return 1;
}

void backTrack(int depth) {
	//가장 아래 depth 도착
	//가장 먼저 도착하는게 가장 적은 수일 것이므로 바로 출력해버리면 됨
	if (depth == n + 1) {
		for (int i = 1; i <= n; i++)
		{
			cout << sol[i];
		}
		cout << endl;
		exit(0);
		return;
	}

	//1 2 3 에 대해 모든 경우의 수 보기
	for (int i = 1; i <= 3; i++)
	{
		sol[depth] = i;
		if (!isOk(depth)) continue;//가지치기
		backTrack(depth + 1);
	}

}

int main() {
	cin >> n;
	backTrack(1);
}