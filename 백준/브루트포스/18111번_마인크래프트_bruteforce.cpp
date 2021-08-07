#include <iostream>
#include <vector>
#include <queue>
#include <stdlib.h>
#include <string>
#include <algorithm>

using namespace std;
int arr[505][505];

int main() {
	//평평하게 땅고르기 작업
	//블록을 파서 가방에 담는것은  2초
	//블록을 가방에서 꺼내서 위에 놓는 것은 1초
	//최단 시간안에 땅을 고르게 만들자

	//출력: 최단시간과 그 높이

	//최대 높이는 256이며 음수x. 
	int n,m, b;//입력: 세로 가로 ,시작부터 원래 가진 블록의 개수
	cin >> n >> m >> b;
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> arr[i][j];
		}
	}

	int ansTime = 999999999, ansLayer = -1;
	//brute force로 모든 높이에 대해 계산
	for (int nowLayer = 0; nowLayer <= 256; nowLayer++)
	{
		//now layer -> 목표높이
		int nowTime = 0, nowInvent = b;
		int need = 0;


		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				need = nowLayer - arr[i][j];
				if (need > 0) {
					//블록을 쌓는 경우
					nowTime += need;
					nowInvent -= need;
				}
				else {
					//블록을 부수는 경우
					nowTime += 2 * (-need);
					nowInvent -= need;
				}
			}
		}
		
		//유효한 값이고 최소 시간이라면 갱신한다
		if (nowInvent >= 0 && nowTime <= ansTime) {
			ansTime = nowTime;
			ansLayer = nowLayer;
		}

	}

	//출력
	cout << ansTime << " " << ansLayer << endl;
}

