#include <iostream>
#include <vector>
#include <queue>

using namespace std;
//N개의 정수로 이루어진 수열이 있을 때, 크기가 양수인 부분수열 중에서 
//그 수열의 원소를 다 더한 값이 S가 되는 경우의 수를 구하는 프로그램을 작성하시오.
int  arr[25];

int n, s;
int dab = 0;
int sol[25];

int isOk(int last) {
	int sum = 0;
	int ch = 0;

	sol[n] = last;
	for (int i = 1; i <= n; i++)
	{
		if (sol[i])
		{
			ch++;
			sum += arr[i];
		}
	}

	if (ch != 0 && sum == s) return 1;
	return 0;
}

void backTrack(int depth) {


	//가장 아래 depth에 도착했을때 최적해인지 확인한다
	if (depth == n) {
		if (isOk(0))dab++;
		if (isOk(1))dab++;
		return;
	}

	for (int i = 0; i <= 1; i++)
	{
		sol[depth] = i;
		backTrack(depth + 1);
	}
}

int main() {
	cin >> n >> s;

	//n개의 수이므로 dep=n
	//->dfs사용
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}

	backTrack(1);

	cout << dab << endl;

}