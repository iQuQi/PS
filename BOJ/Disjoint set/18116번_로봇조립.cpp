#include <iostream>
#include <vector>
#include <queue>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <climits>
using namespace std;
const int num = 1000005;
int n, m;
int k, a, b;
int pa, pb;
int parent[num][2];//첫번째로 자신의 부모저장, 두번째로 자신이 루트인경우 원소개수저장
int path[1005];

/*
성규는 로봇을 조립해야 한다. 상자 안에는 여러 로봇의 부품들이 섞여 있다. 
그런데 어떤 부품이 어느 로봇의 부품인지 표시가 되어있지 않다. 호재는 전자과라서
두 부품을 보면 같은 로봇의 부품인지 알 수 있다. 그래서 성규는 호재의 지시에 
따라 부품들을 정리하기로 하였다.

부품들은 1부터 106까지의 정수로 표현된다. 그리고 부품 i가 속한 로봇은 robot(i)라고도 
표현한다. 예를 들어, 부품 11과 부품 22가 로봇 A의 부품이라고 알고 있는 경우, 
robot(11)은 로봇 A를 의미하고, robot(22)도 로봇 A를 의미한다.

서로 다른 로봇은 공통 부품을 가지지 않는다. 즉 어떤 부품이 로봇 A의 부품이라면, 
로봇 B의 부품은 될 수 없다.

호재는 2가지 지시를 한다.

서로 다른 부품 2개를 말해주며, 두 부품은 같은 로봇의 부품이라는 정보를 알려준다.
부품 i에 대해서, 지금까지 알아낸 robot(i)의 부품이 몇 개냐고 물어본다.
초기에는 부품에 대한 정보가 존재하지 않는다.
*/



int Find(int a) {

	if (parent[a][0] == a) return a;

	return parent[a][0] = Find(parent[a][0]);

}

void print(int a) {
	int pa = Find(a);
	cout << parent[pa][1] << "\n";
}

void Union(int a, int b) {

	pa = Find(a);
	pb = Find(b);
	if (pa == pb) return;
	parent[pa][0] = pb;
	parent[pb][1] += parent[pa][1];

}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	//초기화
	for (int i = 1; i <= num; i++) {
		parent[i][1] = 1;
		parent[i][0] = i;
	}

	char menu;
	int a, b;
	cin >> n;//호재의 지시의 횟수

	for (int i = 1; i <= n; i++)
	{
		cin >> menu;
		if (menu == 'I') {//같은 로봇의 부품임을 알려줌
			cin >> a >> b;
			Union(a, b);

		}
		else if (menu == 'Q') {//몇개의 부품인지 물어봄
			cin >> a;
			print(a);

		}
	}



}

