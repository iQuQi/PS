#include <iostream>
#include <stdio.h>

#include <string>
#include <algorithm>
#include <cmath>
using namespace std;
//2193�� ��ģ��
/*
��ģ���� 0���� �������� �ʴ´�.
��ģ�������� 1�� �� �� �������� ��Ÿ���� �ʴ´�. 
��, 11�� �κ� ���ڿ��� ���� �ʴ´�.
N(1 �� N �� 90)�� �־����� ��, 
N�ڸ� ��ģ���� ������ ���ϴ� ���α׷��� �ۼ��Ͻÿ�.
*/
int main() {
	int N;
	long long dp[100][3];
	scanf("%d", &N);

	dp[1][0] = 0; //0���� ������ ��ģ�� ����
	dp[1][1] = 1; //1�� ������ ��ģ�� ����
	dp[1][2] = 1; // �� ��ģ���� ����

	for (int i = 2; i < 100; i++) {
		dp[i][0] = dp[i - 1][2];
		dp[i][1] = dp[i - 1][0];
		dp[i][2] = dp[i][0] + dp[i][1];
	}

	printf("%lld", dp[N][2]);
}

