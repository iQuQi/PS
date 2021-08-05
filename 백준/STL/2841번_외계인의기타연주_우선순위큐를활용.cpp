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
상근이의 상상의 친구 외계인은 손가락을 수십억개 가지고 있다. 
어느 날 외계인은 기타가 치고 싶었고, 인터넷에서 간단한 멜로디를 검색했다. 
이제 이 기타를 치려고 한다.

보통 기타는 1번 줄부터 6번 줄까지 총 6개의 줄이 있고, 
각 줄은 P개의 프렛으로 나누어져 있다. 
프렛의 번호도 1번부터 P번까지 나누어져 있다.

멜로디는 음의 연속이고, 각 음은 줄에서 해당하는 프렛을 누르고 
줄을 튕기면 연주할 수 있다. 예를 들면, 4번 줄의 8번 프렛을 누르고 튕길 수 있다. 
만약, 어떤 줄의 프렛을 여러 개 누르고 있다면, 가장 높은 프렛의 음이 발생한다.

예를 들어, 3번 줄의 5번 프렛을 이미 누르고 있다고 하자. 
이때, 7번 프렛을 누른 음을 연주하려면, 
5번 프렛을 누르는 손을 떼지 않고 다른 손가락으로 7번 프렛을 누르고 줄을 튕기면 된다. 
여기서 2번 프렛의 음을 연주하려고 한다면, 
5번과 7번을 누르던 손가락을 뗀 다음에 2번 프렛을 누르고 연주해야 한다.

이렇게 손가락으로 프렛을 한 번 누르거나 떼는 것을 손가락을 한 번 움직였다고 한다.
어떤 멜로디가 주어졌을 때, 손가락의 가장 적게 움직이는 회수를 구하는 프로그램을 작성하시오.
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
	//pr프렛 번호만 누르면 됨 -1번 움직임
	else if (gita->top() < pr) {
		//	cout << "one mov\n";
		gita->push(pr);
		//cout << "push : " << gita->top() << endl;
		ret = 1;
	}
	//가만히 있고 튕구면 됨 - 0번 움직임
	else if (gita->top() == pr) {
		//	cout << "zero move\n";
		ret = 0;
	}
	//다떼고 잡아야함 -2번 움직임
	else if (gita->top() > pr) {
		//	cout << "two move\n";
		ret = 0;
		while (!gita->empty() && gita->top() > pr) {
			gita->pop();
			ret++;
			//cout << "pop... ";
		}

		//남아있는게 있는데 그게 pr랑 같을 때
		if (!gita->empty() && gita->top() == pr) {
			//nothing
		}
		//남아있는게 없거나 남아있는데 pr과 다를때
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

