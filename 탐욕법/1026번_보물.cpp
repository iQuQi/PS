#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

int arr[60];
int arr2[60];

//S = A[0]��B[0] + ... + A[N-1]��B[N-1]  -> S���� ���� �۰� �����. B�� �ִ� ���� ��迭 x
int main() {


	int n, s = 0;
	cin >> n;
	//A�迭
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	sort(arr, arr + n);

	//B�迭
	for (int i = 0; i < n; i++)
	{
		cin >> arr2[i];
	}
	sort(arr2, arr2 + n, greater<int>()); // greater���ٶ� �ڿ� <int>() �ٿ��ֱ�

	//s�� �ּڰ� ���ϱ�
	for (int i = 0; i < n; i++)
	{
		s += arr[i] * arr2[i];
	}

	cout << s;
}