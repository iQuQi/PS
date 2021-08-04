#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int dp[12];
/*
정수 4를 1, 2, 3의 합으로 나타내는 방법은 총 7가지가 있다. 
합을 나타낼 때는 수를 1개 이상 사용해야 한다.

1+1+1+1
1+1+2
1+2+1
2+1+1
2+2
1+3
3+1

정수 n이 주어졌을 때, n을 1, 2, 3의 합으로 나타내는 
방법의 수를 구하는 프로그램을 작성하시오.
*/
int main() {
	int *N = NULL;
	int T, i, j;
	scanf("%d", &T);
	N = (int *)malloc(T * sizeof(int));
	for (i = 0; i < T; i++) {
		scanf("%d", &N[i]);
	}

	dp[1] = 1; // '1'의경우
	dp[2] = 2; // '2'의 경우
	dp[3] = 4; // '3'의 경우
	//d[i] 는 i 를 1,2,3의 합응로 나타내는 경우의 수


	for (i = 4; i < 13; i++) {
		//점화식을 세울때는 이전의 항과의 관계만 생각하지 말고 전, 전전의 항도 연결짓자
		dp[i] = dp[i - 3] + dp[i - 2] + dp[i - 1];
	}



	for (i = 0; i < T; i++) {
		printf("%d\n", dp[N[i]]);

	}

}