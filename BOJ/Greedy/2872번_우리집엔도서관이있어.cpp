#include <iostream>
#include <vector>
#include <queue>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <climits>
using namespace std;
#define INF 2000000000
/*
상근이는 컴퓨터 공학의 일인자가 되기 위해 책을 매우 많이 구매했다.
하지만, 집에 책장이 없어서 책을 탑처럼 쌓아놓고 있다.

오늘은 오랜만에 상근이가 집에서 휴식을 취하는 날이다.
상근이는 책을 알파벳 순서대로 정렬하려고 한다. 사전 순으로 가장 앞서는
책은 가장 위에 놓고, 가장 뒤에 있는 책은 가장 밑에 놓아야 한다. 책을 정렬할 때
사용할 수 있는 방법은 책 하나를 뺀 다음, 가장 위에 놓는 것이다.

책은 1부터 N까지 번호가 책 이름의 사전 순으로 매겨져 있다.
1은 사전 순으로 가장 앞서는 책이다. 따라서, 위에서부터 책의 번호를 읽으면
(1, 2, ..., N)이 되어야 한다.

예를 들어, 책이 3권있고 처음에 (3, 2, 1)로
쌓여있을 때, 2번 만에 사전순으로 책을 쌓을 수 있다. 가장 먼저, 2번 책을 뺀
다음에 가장 위에 놓는다. 그렇게 되면 (2, 3, 1)이 된다. 마지막으로, 1을 뺀
다음 가장 위에 놓으면 (1, 2, 3)이 된다.

현재 책이 어떻게 쌓여있는지가 주어졌을 때, 몇 번만에 사전 순으로 쌓을 수
있는지 구하는 프로그램을 작성하시오.
*/
int n, book;
vector<int> books;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> book;
		books.push_back(book);
	}

	int index = 1, dab = 0;
	for (int i = 0; i < n; i++)
	{
		if (books[i] == index) index++; // 해당 책은 알맞은 순서이므로 남겨둔다
		else dab++; // 책 빼기
	}
	cout << dab;

}
