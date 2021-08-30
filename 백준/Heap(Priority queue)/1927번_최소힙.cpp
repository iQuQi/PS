#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>

/*
�θ� �� �˷��� �ڷᱸ�� �� �ּ� ���� �ִ�. 
�ּ� ���� �̿��Ͽ� ������ ���� ������ �����ϴ� ���α׷��� �ۼ��Ͻÿ�.

�迭�� �ڿ��� x�� �ִ´�.
�迭���� ���� ���� ���� ����ϰ�, �� ���� �迭���� �����Ѵ�.
���α׷��� ó���� ����ִ� �迭���� �����ϰ� �ȴ�.
*/

using namespace std;

priority_queue<int> pq;
vector<int >v;

int main() {
	int n; int x;

	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> x;
		if (x > 0) pq.push(-x);
		else if (x == 0) {
			if (pq.empty()) v.push_back(0);
			else {
				v.push_back(pq.top());
				pq.pop();
			}
		}
	}

	for (int i = 0; i < v.size(); i++){
		cout << -v[i] << "\n";
	}
}

