#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>

/*
널리 잘 알려진 자료구조 중 최소 힙이 있다. 
최소 힙을 이용하여 다음과 같은 연산을 지원하는 프로그램을 작성하시오.

배열에 자연수 x를 넣는다.
배열에서 가장 작은 값을 출력하고, 그 값을 배열에서 제거한다.
프로그램은 처음에 비어있는 배열에서 시작하게 된다.
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

