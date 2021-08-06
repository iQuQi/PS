#include <stdio.h>
#include <algorithm>
#include <iostream>
/*
N���� ���� A[1], A[2], ��, A[N]�� �־��� ���� ��,
�� �ȿ� X��� ������ �����ϴ��� �˾Ƴ��� ���α׷��� �ۼ��Ͻÿ�.
*/
using namespace std;
int jungsu[100000 + 1];
int N;


//�̺� Ž�� �Լ� �ڵ�
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
	//������ �Ǿ��־���� ** �߿�
	sort(jungsu, jungsu + N);

	cin >> M;
	for (int i = 0; i < M; i++) {
		int val; cin >> val;
		cout << find(val) << "\n";

	}



}