#include <iostream>
#include <vector>
#include <queue>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <climits>
/*
KOI 준비를 위해 회의를 개최하려 한다. 
주최측에서는 회의에 참석하는 사람의 수와 참석자들 사이의 관계를 따져 하나 
이상의 위원회를 구성하려고 한다. 위원회를 구성하는 방식은 다음과 같다.

서로 알고 있는 사람은 반드시 같은 위원회에 속해야 한다.
효율적인 회의 진행을 위해 위원회의 수는 최대가 되어야 한다.

이런 방식으로 위원회를 구성한 후에 각 위원회의 대표를 한 명씩 뽑아야 한다. 
각 위원회의 대표만이 회의 시간 중 발언권을 가지며, 

따라서 회의 참석자들이 자신의 의견을 말하기 위해서는 자신이 속한 위원회의 대표에게 
자신의 의견을 전달해야 한다. 그런데 각 참석자는 자신이 알고 있는 사람에게만 의견을 
전달할 수 있어 대표에게 의견을 전달하기 위해서는 때로 여러 사람을 거쳐야 한다. 

대표에게 의견을 전달하는 경로가 여러 개 있을 경우에는 가장 적은 사람을 거치는 
경로로 의견을 전달하며 이때 거치는 사람의 수를 참석자의 의사전달시간이라고 한다.

위원회에서 모든 참석자들의 의사전달시간 중 최댓값이 최소가 되도록 대표를 정하는 
프로그램을 작성하시오.

예를 들어 1번, 2번, 3번 세 사람으로 구성되어 있는 위원회에서 1번과 2번, 2번과 3번이 
서로 알고 있다고 하자. 1번이 대표가 되면 3번이 대표인 1번에게 의견을 전달하기 위해서
2번을 거쳐야만 한다. 반대로 3번이 대표가 되어도 1번이 대표인 3번에게 
의견을 전달하려면 2번을 거쳐야만 한다. 하지만 2번이 대표가 되면 1번과 3번 
둘 다 아무도 거치지 않고 대표에게 직접 의견을 전달 할 수 있다. 

따라서 이와 같은 경우 2번이 대표가 되어야 한다.
*/
using namespace std;
int n, m;
int a, b;
const int MAX_N = 102;//참석하는 인원은 100명 이하
int DP[MAX_N][MAX_N];
int ch[102];//그룹나누기1
vector<int> ch2[102];//그룹나누기2
vector<int> rep;//대표자 선발해두기
const int INF = MAX_N * 100'000;

//플로이드 함수
void Floyd_Warshall() {
	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				DP[i][j] = min(DP[i][j], DP[i][k] + DP[k][j]);

			}
		}
	}

	//inf값이면 0으로 바꿔준다 -> 도달 불가능 하다면 같은 위원회 x
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (DP[i][j] == INF)DP[i][j] = 0;

		}
	}

}



//그룹구별하고 그룹개수 및 각각의 대표자 선발
int chCom() {
	int com = 0;//위원회의 수

	//그룹구별하기
	for (int i = 1; i <= n; i++)
	{
		if (ch[i] != 0) continue;//이미 i 번째 사람이 위원회에 속해진 경우
		ch[i] = i;

		for (int j = 1; j <= n; j++)
		{
			if (i == j) continue;
			if (DP[i][j] != 0) {//0이 아니라면 도달가능, 즉 같은 위원회
				ch[j] = i;
			}
		}
	}

	//위원회의 수 카운트
	int visited[102] = { 0, };
	for (int i = 1; i <= n; i++)
	{

		//ch배열에서 같은 값을 갖는 i들을 ch2배열에 넣어서 분류
		ch2[ch[i]].push_back(i);
		visited[ch[i]] = 1;
	}

	for (int i = 1; i <= n; i++)
	{
		if (visited[i] == 1)com++;//만들어진 위원회의 수
	}

	//의사전달시간 최댓값의 최소가 되는 대표구하기
	for (int i = 1; i <= n; i++)
	{
		if (ch2[i].empty()) continue;//i번째 벡터가 비었을때, 즉 위원회가 존재x

		int minOfMax = 500;
		int tmp;

		//각 그룹에있는 사람수만큼
		for (int j = 0; j < ch2[i].size(); j++)
		{

			int max_ = -1;
			//각각의 사람에 대해 의사전달최대시간을 찾는다
			for (int k = 1; k <= n; k++)
			{
				if (max_ < DP[ch2[i][j]][k]) max_ = DP[ch2[i][j]][k];
			}

			//그 최대시간이 현재 최대의최소값 보다 작으면 갱신
			if (minOfMax > max_) {

				minOfMax = max_;
				//가장 마지막에 갱신된 j를 저장
				tmp = j;

			}
		}
		//tmp에 저장해둔 j에 해당하는 번호가 대표자의 번호임
		rep.push_back(ch2[i][tmp]);
	}
	return com;
}


int main() {

	//초기화
	for (int i = 0; i < MAX_N; i++)
	{
		for (int j = 0; j < MAX_N; j++)
		{
			if (i == j)DP[i][j] = 0;
			else DP[i][j] = INF;
		}
	}

	cin >> n >> m;//전체 참석자 n명 , 서로 알고있는 관계의 개수 M
	for (int i = 1; i <= m; i++)
	{
		cin >> a >> b;
		DP[a][b] = 1;
		DP[b][a] = 1;
	}

	Floyd_Warshall();

	int com = chCom();//위원회의 개수 출력
	cout << com << "\n";

	//대표자들의 번호를 작은순으로 정렬
	sort(rep.begin(), rep.end());
	for (int i = 0; i < rep.size(); i++) cout << rep[i] << "\n";
	
	return 0;


}
