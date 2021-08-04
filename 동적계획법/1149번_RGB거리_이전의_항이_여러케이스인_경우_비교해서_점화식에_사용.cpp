#include <stdio.h>
#include <stdlib.h>


/*
RGB거리에는 집이 N개 있다. 
거리는 선분으로 나타낼 수 있고, 1번 집부터 N번 집이 순서대로 있다.

집은 빨강, 초록, 파랑 중 하나의 색으로 칠해야 한다. 
각각의 집을 빨강, 초록, 파랑으로 칠하는 비용이 주어졌을 때,
아래 규칙을 만족하면서 모든 집을 칠하는 비용의 최솟값을 구해보자.

1번 집의 색은 2번 집의 색과 같지 않아야 한다.
N번 집의 색은 N-1번 집의 색과 같지 않아야 한다.
i(2 ≤ i ≤ N-1)번 집의 색은 i-1번, i+1번 집의 색과 같지 않아야 한다.
*/


int min(int a, int b) {
	if (a > b) return b;
	else return a;
}


int main() {
	int N, i, j, pri, dab;
	scanf("%d", &N);
	int** price = NULL;
	int ** dp = NULL;

	price = (int**)malloc(N * sizeof(int*));
	dp = (int**)malloc(N * sizeof(int*));

	for (i = 0; i < N; i++) {
		price[i] = (int *)malloc(3 * sizeof(int));
		dp[i] = (int *)malloc(3 * sizeof(int));
		for (j = 0; j < 3; j++) {
			scanf("%d", &pri);
			price[i][j] = pri;
		}
	}



	dp[0][0] = price[0][0]; //n번째 집이 빨강색인 경우
	dp[0][1] = price[0][1]; //n번째 집이 파란색인 경우
	dp[0][2] = price[0][2]; //n번째 집이 초록색인 경우

	for (i = 1; i < N; i++) {
		for (j = 0; j < 3; j++) {
			if (j == 0) {
				//n번째 집이 빨간색인 경우의 최솟값을 구하려면
				//n-1번째 집이 파란색인 경우에서의 최솟값과 초록색인경우 최솟값 중 min 값
				dp[i][j] = min(dp[i - 1][1], dp[i - 1][2]) + price[i][j];
			}
			else if (j == 1) {
				//n번째 집이 파란색이거나 초록색인 경우도 위와 마찬가지로 진행
				dp[i][j] = min(dp[i - 1][0], dp[i - 1][2]) + price[i][j];
			}
			else dp[i][j] = min(dp[i - 1][0], dp[i - 1][1]) + price[i][j];
		}
	}




	dab = min(min(dp[N - 1][0], dp[N - 1][1]), dp[N - 1][2]);
	printf("%d", dab);














}