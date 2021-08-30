#include <iostream>
#include <vector>
#include <queue>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <climits>
/*
���� ���� ������ ���� ������ �����ϴ� �ڷᱸ���̴�.

�迭�� ���� x (x �� 0)�� �ִ´�.
�迭���� ������ ���� ���� ���� ����ϰ�, �� ���� �迭���� �����Ѵ�. 
������ ���� ���� ���� �������� ����, ���� ���� ���� ����ϰ�, 
�� ���� �迭���� �����Ѵ�.

���α׷��� ó���� ����ִ� �迭���� �����ϰ� �ȴ�.
*/
using namespace std;
int n, x;
priority_queue<pair<int,int>> pq;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> x;

		if (x == 0) {//�迭���� ������ ���� ���� ���� ���
			if (pq.empty()) cout << 0 << "\n";
			else {
				if (pq.top().second > 0) {//���� ���� ���
					cout << pq.top().first << "\n";
				}
				else {//��� ���� ���
					cout << -pq.top().first << "\n";
				}
				pq.pop();
			}
		}
		else {//�迭�� x�� �ִ� ����
			if (x > 0) {//���
				pq.push({ -x,-1 });
			}
			else {//����
				pq.push({ x,1 });
			}
		}
	}

}
