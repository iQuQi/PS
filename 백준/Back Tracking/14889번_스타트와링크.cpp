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
오늘은 스타트링크에 다니는 사람들이 모여서 축구를 해보려고 한다. 
축구는 평일 오후에 하고 의무 참석도 아니다. 
축구를 하기 위해 모인 사람은 총 N명이고 신기하게도 N은 짝수이다. 
이제 N/2명으로 이루어진 스타트 팀과 링크 팀으로 사람들을 나눠야 한다.

BOJ를 운영하는 회사 답게 사람에게 번호를 1부터 N까지로 배정했고, 
아래와 같은 능력치를 조사했다. 능력치 Sij는 i번 사람과 j번 사람이 같은 팀에 
속했을 때, 팀에 더해지는 능력치이다. 팀의 능력치는 팀에 속한 모든 쌍의 능력치 
Sij의 합이다. Sij는 Sji와 다를 수도 있으며, i번 사람과 j번 사람이 같은 팀에 속했을 때,
팀에 더해지는 능력치는 Sij와 Sji이다.

N=4이고, S가 아래와 같은 경우를 살펴보자.

i\j	1	2	3	4
1	 	1	2	3
2	4	 	5	6
3	7	1	 	2
4	3	4	5

예를 들어, 1, 2번이 스타트 팀, 3, 4번이 링크 팀에 속한 경우에 두 팀의 
능력치는 아래와 같다.

스타트 팀: S12 + S21 = 1 + 4 = 5
링크 팀: S34 + S43 = 2 + 5 = 7
1, 3번이 스타트 팀, 2, 4번이 링크 팀에 속하면, 두 팀의 능력치는 아래와 같다.

스타트 팀: S13 + S31 = 2 + 7 = 9
링크 팀: S24 + S42 = 6 + 4 = 10

축구를 재미있게 하기 위해서 스타트 팀의 능력치와 링크 팀의 능력치의
차이를 최소로 하려고 한다. 위의 예제와 같은 경우에는 1, 4번이 스타트 팀,
2, 3번 팀이 링크 팀에 속하면 스타트 팀의 능력치는 6, 링크 팀의 능력치는 
6이 되어서 차이가 0이 되고 이 값이 최소이다.
*/
int n, team1, team2,pre;
int min_diff = 2'000'000'000;
int sol[22], s[22][22];

int diff() {
	vector<int> team2_member;team2_member.push_back(0);
	team1 = 0; team2 = 0;

	//팁2 멤버 구하기
	for (int i = 1; i <= n; i++)
	{
		int ch = 0;

		for (int j = 1; j <= n/2; j++)
		{
			if (i == sol[j]) ch = 1;
		}

		if (!ch) team2_member.push_back(i);
		
	}

	/*
	//팀출력
	cout << "team1 : ";
	for (int i = 1; i <= n/2; i++)
	{
		cout << sol[i] << " ";
	}
	cout << "\nteam2 :";
	for (int i = 1; i <= n / 2; i++)
	{
		cout << team2_member[i] << " ";
	}
	cout << "\n";
	*/


	//팀1 합
	for (int i = 1; i <= n/2; i++)
	{
		for (int j = 1; j <= n/2; j++)
		{
			
			team1 += s[sol[i]][sol[j]];
			team2 += s[team2_member[i]][team2_member[j]];
		}
	}


	return abs(team1 - team2);
}

void backTrack(int depth) {

	//가장 아래 depth에 도착했을때 최적해인지 확인한다
	if (depth == n/2 +1) {
		min_diff = min(min_diff,diff());
		return;
	}

	for (int i = 1; i <= n; i++)
	{
		if (depth!=1 &&i <= pre ) continue;
		sol[depth] = i;
		int tmp = pre; pre = i; 
		backTrack(depth + 1);
		pre = tmp;

	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);	
	
	cin >> n;
	for (int i = 1;  i<= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> s[i][j];
		}
	}

	backTrack(1);
	cout << min_diff;
}

