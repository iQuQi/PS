#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

int arr[60];
int arr2[60];

//S = A[0]×B[0] + ... + A[N-1]×B[N-1]  -> S값을 가장 작게 만들기. B에 있는 수는 재배열 x
int main() {


	int n, s = 0;
	cin >> n;
	//A배열
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	sort(arr, arr + n);

	//B배열
	for (int i = 0; i < n; i++)
	{
		cin >> arr2[i];
	}
	sort(arr2, arr2 + n, greater<int>()); // greater해줄때 뒤에 <int>() 붙여주기

	//s의 최솟값 구하기
	for (int i = 0; i < n; i++)
	{
		s += arr[i] * arr2[i];
	}

	cout << s;
}