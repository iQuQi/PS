#include <iostream>
#include <vector>
#include <queue>
#include <stdlib.h>
#include <string>
#include <algorithm>

using namespace std;
int dp[45][2];

/*
�Ǻ���ġ�� ����Լ��� ������ ���
fibonacci(3)�� ȣ���ϸ� ������ ���� ���� �Ͼ��.


fibonacci(3)�� fibonacci(2)�� fibonacci(1) (ù ��° ȣ��)�� ȣ���Ѵ�.
fibonacci(2)�� fibonacci(1) (�� ��° ȣ��)�� fibonacci(0)�� ȣ���Ѵ�.
�� ��° ȣ���� fibonacci(1)�� 1�� ����ϰ� 1�� �����Ѵ�.
fibonacci(0)�� 0�� ����ϰ�, 0�� �����Ѵ�.
fibonacci(2)�� fibonacci(1)�� fibonacci(0)�� ����� ���, 1�� �����Ѵ�.
ù ��° ȣ���� fibonacci(1)�� 1�� ����ϰ�, 1�� �����Ѵ�.
fibonacci(3)�� fibonacci(2)�� fibonacci(1)�� ����� ���, 2�� �����Ѵ�.


1�� 2�� ��µǰ�, 0�� 1�� ��µȴ�. N�� �־����� ��, fibonacci(N)�� ȣ������ ��, 
0�� 1�� ���� �� �� ��µǴ��� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.
*/

int main() {
	int n, t;
	cin >> t;
	dp[0][0] = 1;
	dp[0][1] = 0;
	dp[1][0] = 0;
	dp[1][1] = 1;
	//dp[][0]�� ��� �ش� ���̽����� 0�� ��µǴ� Ƚ��
	//dp[][1]�� ��� �ش� ���̽����� 1�� ��µǴ� Ƚ��

	//Ʈ�������� �׷����� �׷��� top-down ���� ������ ���ص� ����

	for (int i = 2; i <= 40; i++)
	{
		dp[i][0] = dp[i - 1][0] + dp[i - 2][0];
		dp[i][1] = dp[i - 1][1] + dp[i - 2][1];
		//cout << i << "=" << dp[i][0] << " " << dp[i][1]<<endl;
	}

	for (int i = 0; i < t; i++)
	{
		cin >> n;
		cout << dp[n][0] << " " << dp[n][1] << endl;
	}

}

