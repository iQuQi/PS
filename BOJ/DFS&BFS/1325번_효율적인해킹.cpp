#include <queue>
#include <stack>
#include <map>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <climits>
#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
char arr[50][50];

/*
해커 김지민은 잘 알려진 어느 회사를 해킹하려고 한다. 
이 회사는 N개의 컴퓨터로 이루어져 있다. 김지민은 귀찮기 때문에,
한 번의 해킹으로 여러 개의 컴퓨터를 해킹 할 수 있는 컴퓨터를 해킹하려고 한다.

이 회사의 컴퓨터는 신뢰하는 관계와, 신뢰하지 않는 관계로 이루어져 있는데, 
A가 B를 신뢰하는 경우에는 B를 해킹하면, A도 해킹할 수 있다는 소리다.

이 회사의 컴퓨터의 신뢰하는 관계가 주어졌을 때, 
한 번에 가장 많은 컴퓨터를 해킹할 수 있는 컴퓨터의 번호를 출력하는 프로그램을 작성하시오.
*/
int n, m;
vector<int> list[10000 + 1];
int visited[10000 + 1];
int hack = 0;

void print() {
	//인접 리스트 뽑기
	cout << "adj list!!!" << endl;
	for (int i = 1; i <= n; i++)
	{

		cout << i << " : ";
		for (int j = 0; j < list[i].size(); j++)
		{
			cout << list[i][j] << " ";
		}
		cout << "\n";
	}
}

//visit 배열 초기화
void reset() {
	for (int i = 1; i <= 10000; i++)
	{
		visited[i] = 0;
	}
}


int dfs(int s) {

	visited[s] = 1;
	hack++;

	for (int i = 0; i < list[s].size(); i++)
	{
		if (!visited[list[s][i]]) {
			dfs(list[s][i]);
		}
	}

	return hack;

}


int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);


	int hack_com[10000 + 1];
	int a, b;
	cin >> n >> m;
	//인접리스트 생성
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b;
		list[b].push_back(a);
	}

	int max = -1;

	//각 컴퓨터가 해킹할 수 있는 컴퓨터의 수를 구하고 max 값을 구한다
	for (int i = 1; i <= n; i++)
	{
		hack_com[i] = dfs(i);
		if (hack >= max) max = hack_com[i];
		hack = 0;

		//초기화를 잊지말자!!
		reset();
	}

	//max값을 가진 컴퓨터 찾기
	for (int i = 1; i <= n; i++)
	{
		if (hack_com[i] == max) cout << i << " ";
	}

}

