#include <iostream>
#include <vector>
#include <queue>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <climits>
using namespace std;

/*
이 문제는 아주 평범한 배낭에 관한 문제이다.

한 달 후면 국가의 부름을 받게 되는 준서는 여행을 가려고 한다.
세상과의 단절을 슬퍼하며 최대한 즐기기 위한 여행이기 때문에,
가지고 다닐 배낭 또한 최대한 가치 있게 싸려고 한다.

준서가 여행에 필요하다고 생각하는 N개의 물건이 있다.
각 물건은 무게 W와 가치 V를 가지는데, 해당 물건을 배낭에 넣어서
가면 준서가 V만큼 즐길 수 있다.

아직 행군을 해본 적이 없는 준서는
최대 K만큼의 무게만을 넣을 수 있는 배낭만 들고 다닐 수 있다.
준서가 최대한 즐거운 여행을 하기 위해 배낭에 넣을 수 있는
물건들의 가치의 최댓값을 알려주자.
*/
int N, W, w, v;
int DP[100 + 1][100'000 + 1];
int _w[100 + 1], c[100 + 1]; // 보석의 무게와 보석의 가치

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> W;

	for (int i = 1; i <= N; i++)
	{
		cin >> _w[i] >> c[i];
	}

	for (int k = 0; k < N; k++) {
		for (int w = 1; w <= W; w++) {
			if (w >= _w[k + 1])
				DP[k + 1][w] = max(DP[k][w], DP[k][w - _w[k + 1]] + c[k + 1]);
			else
				DP[k + 1][w] = DP[k][w];
		}
	}

	cout << DP[N][W];
}

