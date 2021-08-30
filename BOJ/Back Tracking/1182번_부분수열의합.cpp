#include <iostream>
#include <vector>
#include <queue>

using namespace std;
//N���� ������ �̷���� ������ ���� ��, ũ�Ⱑ ����� �κм��� �߿��� 
//�� ������ ���Ҹ� �� ���� ���� S�� �Ǵ� ����� ���� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.
int  arr[25];

int n, s;
int dab = 0;
int sol[25];

int isOk(int last) {
	int sum = 0;
	int ch = 0;

	sol[n] = last;
	for (int i = 1; i <= n; i++)
	{
		if (sol[i])
		{
			ch++;
			sum += arr[i];
		}
	}

	if (ch != 0 && sum == s) return 1;
	return 0;
}

void backTrack(int depth) {


	//���� �Ʒ� depth�� ���������� ���������� Ȯ���Ѵ�
	if (depth == n) {
		if (isOk(0))dab++;
		if (isOk(1))dab++;
		return;
	}

	for (int i = 0; i <= 1; i++)
	{
		sol[depth] = i;
		backTrack(depth + 1);
	}
}

int main() {
	cin >> n >> s;

	//n���� ���̹Ƿ� dep=n
	//->dfs���
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}

	backTrack(1);

	cout << dab << endl;

}