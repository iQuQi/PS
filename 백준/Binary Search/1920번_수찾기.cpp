#include <stdio.h>
#include <algorithm>
#include <iostream>
/*
N개의 정수 A[1], A[2], …, A[N]이 주어져 있을 때,
이 안에 X라는 정수가 존재하는지 알아내는 프로그램을 작성하시오.
*/
using namespace std;
int jungsu[100000 + 1];
int N;


//이분 탐색 함수 코드
int find(int find_val) {
	int L = 0, R = N - 1;
	while (L < R) {
		int mid = (L + R) / 2;
		if (jungsu[mid] == find_val)
			return 1;
		else if (jungsu[mid] < find_val)
			L = mid + 1;
		else
			R = mid - 1;
	}
	if (jungsu[L] == find_val)
		return 1;
	else
		return 0;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);


	int M;

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> jungsu[i];
	}
	//정렬이 되어있어야함 ** 중요
	sort(jungsu, jungsu + N);

	cin >> M;
	for (int i = 0; i < M; i++) {
		int val; cin >> val;
		cout << find(val) << "\n";

	}



}