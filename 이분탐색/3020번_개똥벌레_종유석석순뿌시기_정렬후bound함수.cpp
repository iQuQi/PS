#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> s;
vector<int> j;

//석순과 종유석 장애물이 있는 동굴에서 개똥벌레가 파과해야하는 장애물의 최솟값과 그러한 구간의 개수찾기


int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, h;
	cin >> n >> h;//n은 동굴의 길이 h는 높이
	//장애물은 n개 이며 크기는 h를 넘지 않음
	// 첫 장애물은 항상 석순(아래)  그 다움 종유석(위)  -> 반복

	int a, b, min = 100000 + 1, cnt = 0, tmp;

	//입력 받기
	for (int i = 1; i <= n / 2; i++)
	{
		cin >> a >> b;
		s.push_back(a);
		j.push_back(b);

	}
	
	//석순과 종유석 배열을 크기대로 정렬
	sort(s.begin(), s.end());
	sort(j.begin(), j.end());

	//i는 현재 가는 구간
	for (int i = 1; i <= h; i++)
	{
		//부숴야하는 석순 - lower bound= 원하는 값 이상이 처음으로 나오는 위치 탐색 -> 이분탐색
		tmp = n / 2 - (lower_bound(s.begin(), s.end(), i) - s.begin());
		//부숴야하는 종유석 - upper bound- 원하는 값을 초과하는 값이 처음 나오는 위치 -> 이분탐색
		tmp += n / 2 - (upper_bound(j.begin(), j.end(), h - i) - j.begin());

		//최솟값 갱신
		if (tmp < min) {
			min = tmp;
			cnt = 1;
		}
		//최솟값을 가진 구간 count
		else if (tmp == min) {
			cnt++;
		}
	}

	cout << min << " " << cnt;
}
