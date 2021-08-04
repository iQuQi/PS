#include <iostream>
using namespace std;
int c[1000 + 5][1000 + 5];


//이항계수
/*
자연수 과 정수 가 주어졌을 때 이항 계수 nCk
를 10,007로 나눈 나머지를 구하는 프로그램을 작성하시오.
*/
int main() {

	int n, k;
	cin >> n >> k;

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= i; j++) {
			if (i == j || j == 0) {
				c[i][j] = 1;
			}
			//각 항에도 나눗셈 연산을 적용해서 수가 너무 커지는 것을 막는다
			else c[i][j] = (c[i - 1][j - 1] % 10007 + c[i - 1][j] % 10007) % 10007;
		}

	}

	cout << c[n][k] % 10007;
	return 0;
}