#include <iostream>
#include <vector>
#include <queue>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <climits>
/*
절댓값 힙은 다음과 같은 연산을 지원하는 자료구조이다.

배열에 정수 x (x ≠ 0)를 넣는다.
배열에서 절댓값이 가장 작은 값을 출력하고, 그 값을 배열에서 제거한다. 
절댓값이 가장 작은 값이 여러개일 때는, 가장 작은 수를 출력하고, 
그 값을 배열에서 제거한다.

프로그램은 처음에 비어있는 배열에서 시작하게 된다.
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

		if (x == 0) {//배열에서 절댓값이 가장 작은 값을 출력
			if (pq.empty()) cout << 0 << "\n";
			else {
				if (pq.top().second > 0) {//음수 였던 경우
					cout << pq.top().first << "\n";
				}
				else {//양수 였던 경우
					cout << -pq.top().first << "\n";
				}
				pq.pop();
			}
		}
		else {//배열에 x를 넣는 연산
			if (x > 0) {//양수
				pq.push({ -x,-1 });
			}
			else {//음수
				pq.push({ x,1 });
			}
		}
	}

}
