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
/*
KOI 통신연구소는 레이저를 이용한 새로운 비밀 통신 시스템 개발을 위한 실험을 하고 있다. 
실험을 위하여 일직선 위에 N개의 높이가 서로 다른 탑을 
수평 직선의 왼쪽부터 오른쪽 방향으로 차례로 세우고, 
각 탑의 꼭대기에 레이저 송신기를 설치하였다. 
모든 탑의 레이저 송신기는 레이저 신호를 지표면과 평행하게 
수평 직선의 왼쪽 방향으로 발사하고, 
탑의 기둥 모두에는 레이저 신호를 수신하는 장치가 설치되어 있다. 
하나의 탑에서 발사된 레이저 신호는 가장 먼저 만나는 단 하나의 탑에서만 수신이 가능하다.

예를 들어 높이가 6, 9, 5, 7, 4인 다섯 개의 탑이 수평 직선에 일렬로 서 있고, 
모든 탑에서는 주어진 탑 순서의 반대 방향(왼쪽 방향)으로 동시에 레이저 신호를 발사한다고 하자. 
그러면, 높이가 4인 다섯 번째 탑에서 발사한 레이저 신호는 
높이가 7인 네 번째 탑이 수신을 하고, 
높이가 7인 네 번째 탑의 신호는 높이가 9인 두 번째 탑이, 
높이가 5인 세 번째 탑의 신호도 높이가 9인 두 번째 탑이 수신을 한다. 
높이가 9인 두 번째 탑과 높이가 6인 첫 번째 탑이 보낸 레이저 신호는 
어떤 탑에서도 수신을 하지 못한다.

탑들의 개수 N과 탑들의 높이가 주어질 때, 
각각의 탑에서 발사한 레이저 신호를 어느 탑에서 수신하는지를 알아내는 프로그램을 작성하라.
*/
using namespace std;
int arr[500000 + 1];
int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	vector<int> height;


	int n; cin >> n;
	int hei;

	height.push_back(0); //그냥 0번 인덱스 채워주기
	for (int i = 0; i < n; i++)
	{
		cin >> hei;
		height.push_back(hei);
	}

	arr[1] = 0;
	for (int i = 2; i <= n; i++)
	{
		//내가 바로 앞의 탑보다 작다면 바로 앞 탑에서 걸림
		if (height[i] < height[i - 1]) {
			arr[i] = i - 1;
		}
		//		바로 앞보다 크다면 앞의 탑이 어디서 걸렷는지 추적
		else {
			int j = i - 1;
			//가장 왼쪽 탑까지 검사
			while (arr[j] != 0) {
				//바로 앞의 탑의 신호를 수신한 탑이 자신보다 크다면
				if (height[arr[j]] > height[i]) {
					arr[i] = arr[j]; // 같은 탑에서 걸림
					break;
				}

				j = arr[j];


			}
			//arr 값이 갱신이 안됐다면 , 즉 if문에 걸리지 않았다면
			//자신의 신호를 수신한 탑이 없으므로 초기값이 0으로 그대로 남아있을 것
		}
	}

	for (int i = 1; i <= n; i++)
	{
		cout << arr[i] << " ";
	}


}

