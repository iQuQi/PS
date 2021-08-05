#include <queue>
#include <stack>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <climits>
#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <math.h>

/*
������� ����� ģ�� �ܰ����� �հ����� ���ʾﰳ ������ �ִ�. 
��� �� �ܰ����� ��Ÿ�� ġ�� �;���, ���ͳݿ��� ������ ��ε� �˻��ߴ�. 
���� �� ��Ÿ�� ġ���� �Ѵ�.

���� ��Ÿ�� 1�� �ٺ��� 6�� �ٱ��� �� 6���� ���� �ְ�, 
�� ���� P���� �������� �������� �ִ�. 
������ ��ȣ�� 1������ P������ �������� �ִ�.

��ε�� ���� �����̰�, �� ���� �ٿ��� �ش��ϴ� ������ ������ 
���� ƨ��� ������ �� �ִ�. ���� ���, 4�� ���� 8�� ������ ������ ƨ�� �� �ִ�. 
����, � ���� ������ ���� �� ������ �ִٸ�, ���� ���� ������ ���� �߻��Ѵ�.

���� ���, 3�� ���� 5�� ������ �̹� ������ �ִٰ� ����. 
�̶�, 7�� ������ ���� ���� �����Ϸ���, 
5�� ������ ������ ���� ���� �ʰ� �ٸ� �հ������� 7�� ������ ������ ���� ƨ��� �ȴ�. 
���⼭ 2�� ������ ���� �����Ϸ��� �Ѵٸ�, 
5���� 7���� ������ �հ����� �� ������ 2�� ������ ������ �����ؾ� �Ѵ�.

�̷��� �հ������� ������ �� �� �����ų� ���� ���� �հ����� �� �� �������ٰ� �Ѵ�.
� ��ε� �־����� ��, �հ����� ���� ���� �����̴� ȸ���� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.
*/
using namespace std;
int finger(priority_queue<int, vector<int>, less<int>> *gita, int pr) {

	int ret;

	//if(!gita->empty())cout << "now top : " << gita->top() << endl;
	if (gita->empty()) {
		//	cout << "empty\n";
		gita->push(pr);
		//cout << "push : " << gita->top() << endl;
		ret = 1;
	}
	//pr���� ��ȣ�� ������ �� -1�� ������
	else if (gita->top() < pr) {
		//	cout << "one mov\n";
		gita->push(pr);
		//cout << "push : " << gita->top() << endl;
		ret = 1;
	}
	//������ �ְ� ƨ���� �� - 0�� ������
	else if (gita->top() == pr) {
		//	cout << "zero move\n";
		ret = 0;
	}
	//�ٶ��� ��ƾ��� -2�� ������
	else if (gita->top() > pr) {
		//	cout << "two move\n";
		ret = 0;
		while (!gita->empty() && gita->top() > pr) {
			gita->pop();
			ret++;
			//cout << "pop... ";
		}

		//�����ִ°� �ִµ� �װ� pr�� ���� ��
		if (!gita->empty() && gita->top() == pr) {
			//nothing
		}
		//�����ִ°� ���ų� �����ִµ� pr�� �ٸ���
		else {
			gita->push(pr);
			//		cout << "push : " << gita->top() << endl;
			ret++;
		}

	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n; int p;
	cin >> n >> p;
	int jul, pr;
	long long min = 0;
	priority_queue<int, vector<int>, less<int>> gita[7];
	for (int i = 0; i < n; i++)
	{
		cin >> jul >> pr;
		min += finger(&gita[jul], pr);
		//	cout << "now min: " << min << endl;
	}

	cout << min << endl;
}

