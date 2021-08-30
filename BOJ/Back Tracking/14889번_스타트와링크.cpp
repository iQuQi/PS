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
������ ��ŸƮ��ũ�� �ٴϴ� ������� �𿩼� �౸�� �غ����� �Ѵ�. 
�౸�� ���� ���Ŀ� �ϰ� �ǹ� ������ �ƴϴ�. 
�౸�� �ϱ� ���� ���� ����� �� N���̰� �ű��ϰԵ� N�� ¦���̴�. 
���� N/2������ �̷���� ��ŸƮ ���� ��ũ ������ ������� ������ �Ѵ�.

BOJ�� ��ϴ� ȸ�� ��� ������� ��ȣ�� 1���� N������ �����߰�, 
�Ʒ��� ���� �ɷ�ġ�� �����ߴ�. �ɷ�ġ Sij�� i�� ����� j�� ����� ���� ���� 
������ ��, ���� �������� �ɷ�ġ�̴�. ���� �ɷ�ġ�� ���� ���� ��� ���� �ɷ�ġ 
Sij�� ���̴�. Sij�� Sji�� �ٸ� ���� ������, i�� ����� j�� ����� ���� ���� ������ ��,
���� �������� �ɷ�ġ�� Sij�� Sji�̴�.

N=4�̰�, S�� �Ʒ��� ���� ��츦 ���캸��.

i\j	1	2	3	4
1	 	1	2	3
2	4	 	5	6
3	7	1	 	2
4	3	4	5

���� ���, 1, 2���� ��ŸƮ ��, 3, 4���� ��ũ ���� ���� ��쿡 �� ���� 
�ɷ�ġ�� �Ʒ��� ����.

��ŸƮ ��: S12 + S21 = 1 + 4 = 5
��ũ ��: S34 + S43 = 2 + 5 = 7
1, 3���� ��ŸƮ ��, 2, 4���� ��ũ ���� ���ϸ�, �� ���� �ɷ�ġ�� �Ʒ��� ����.

��ŸƮ ��: S13 + S31 = 2 + 7 = 9
��ũ ��: S24 + S42 = 6 + 4 = 10

�౸�� ����ְ� �ϱ� ���ؼ� ��ŸƮ ���� �ɷ�ġ�� ��ũ ���� �ɷ�ġ��
���̸� �ּҷ� �Ϸ��� �Ѵ�. ���� ������ ���� ��쿡�� 1, 4���� ��ŸƮ ��,
2, 3�� ���� ��ũ ���� ���ϸ� ��ŸƮ ���� �ɷ�ġ�� 6, ��ũ ���� �ɷ�ġ�� 
6�� �Ǿ ���̰� 0�� �ǰ� �� ���� �ּ��̴�.
*/
int n, team1, team2,pre;
int min_diff = 2'000'000'000;
int sol[22], s[22][22];

int diff() {
	vector<int> team2_member;team2_member.push_back(0);
	team1 = 0; team2 = 0;

	//��2 ��� ���ϱ�
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
	//�����
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


	//��1 ��
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

	//���� �Ʒ� depth�� ���������� ���������� Ȯ���Ѵ�
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

