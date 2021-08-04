#include <stdio.h>
#include <stdlib.h>


/*
RGB�Ÿ����� ���� N�� �ִ�. 
�Ÿ��� �������� ��Ÿ�� �� �ְ�, 1�� ������ N�� ���� ������� �ִ�.

���� ����, �ʷ�, �Ķ� �� �ϳ��� ������ ĥ�ؾ� �Ѵ�. 
������ ���� ����, �ʷ�, �Ķ����� ĥ�ϴ� ����� �־����� ��,
�Ʒ� ��Ģ�� �����ϸ鼭 ��� ���� ĥ�ϴ� ����� �ּڰ��� ���غ���.

1�� ���� ���� 2�� ���� ���� ���� �ʾƾ� �Ѵ�.
N�� ���� ���� N-1�� ���� ���� ���� �ʾƾ� �Ѵ�.
i(2 �� i �� N-1)�� ���� ���� i-1��, i+1�� ���� ���� ���� �ʾƾ� �Ѵ�.
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



	dp[0][0] = price[0][0]; //n��° ���� �������� ���
	dp[0][1] = price[0][1]; //n��° ���� �Ķ����� ���
	dp[0][2] = price[0][2]; //n��° ���� �ʷϻ��� ���

	for (i = 1; i < N; i++) {
		for (j = 0; j < 3; j++) {
			if (j == 0) {
				//n��° ���� �������� ����� �ּڰ��� ���Ϸ���
				//n-1��° ���� �Ķ����� ��쿡���� �ּڰ��� �ʷϻ��ΰ�� �ּڰ� �� min ��
				dp[i][j] = min(dp[i - 1][1], dp[i - 1][2]) + price[i][j];
			}
			else if (j == 1) {
				//n��° ���� �Ķ����̰ų� �ʷϻ��� ��쵵 ���� ���������� ����
				dp[i][j] = min(dp[i - 1][0], dp[i - 1][2]) + price[i][j];
			}
			else dp[i][j] = min(dp[i - 1][0], dp[i - 1][1]) + price[i][j];
		}
	}




	dab = min(min(dp[N - 1][0], dp[N - 1][1]), dp[N - 1][2]);
	printf("%d", dab);














}