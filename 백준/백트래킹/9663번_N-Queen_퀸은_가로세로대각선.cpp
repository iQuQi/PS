#include <iostream>
#include <vector>
#include <queue>
#include <stdlib.h>
#include <algorithm>

using namespace std;
/*
N-Queen ������ ũ�Ⱑ N �� N�� ü���� ���� �� N���� ���� ������ �� ���� ���� �����̴�.

N�� �־����� ��, ���� ���� ����� ���� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.
*/
int n;
int sol[20];
int arr[20][20];
int dab = 0;
int isOk(int dep) {

	for (int i = 1; i < dep; i++)
	{
		//���� col�� ���� �̹� ������ �ȵ�
		//�밢�� ���⿡ ���� �̹� ������ �ȵ�
		if (sol[i] == sol[dep] || abs(sol[i] - sol[dep]) == abs(i - dep))return 0;
	}
	return 1;
}

void backTrack(int depth) {


	if (depth == n + 1) {
		dab++;
		return;

	}
	for (int i = 1; i <= n; i++)
	{
		sol[depth] = i;
		if (!isOk(depth)) continue;//����ġ��
		backTrack(depth + 1);
	}

}

int main() {
	cin >> n;//���� ���� �Է� �ޱ�
	backTrack(1);
	cout << dab;
}