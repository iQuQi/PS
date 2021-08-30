#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#define CON 1000000000 
using namespace std;
int n, m, need;
vector<int > v;
//질투심이 최소가 되게 보석 나누기 -> 질투심 최솟값 출력
//모두가 받지는 않아도 되지만 학생은 항상 같은 색상의 보석만 가짐
//질투심은 가장 많은 보석을 가져간 학생의 보석 개수

//모든 보석을 나누어 줄 수 있는가
int too(int per) {
	int ans = 0;
	for (int i = 0; i < m; i++)
	{
		ans += v[i] / per;//보석의 종류별로 per 만큼씩 줬을때 몇명에게 줄수있는지 합계
		if (v[i] % per != 0) ans++;//나누어 떨어지지 않는 경우 나머지를 한명에 줄 수 있음
	}

	//모든 보석 사용 가능
	if (ans <= n)return 1;
	//불가능
	return 0;
}


//이분탐색 -> parametric 
//모든 보석을 나눠 줄 수 있는 경우 중 per이 최소로 되는 값 구하기
int bin(int low, int high) {
	int mid, ret = high;
	//(1)no------------|--------yes(max)
	while (low <= high)
	{
		mid = (low + high) / 2;
		//모든 보석을 나눠줄 수 있는 경우
		if (too(mid)) {
			//ret값(min 값) 갱신
			if (ret >= mid)ret = mid;
			high = mid - 1;
		}
		else {
			low = mid + 1;
		}
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n >> m;//n=아이들수 m=색상 수
	int k, max = 0;
	for (int i = 0; i < m; i++)
	{
		cin >> k;//i번 색상 보석의 개수
		if (max <= k)max = k;
		v.push_back(k);
	}
	cout << bin(1, max);
}
