#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#define CON 1000000000 
using namespace std;
int n;
long long m;
vector<long long > v;

//나무를 벌목할 건데 높이를 한번 정하고 그 위에 있는 나무들을 모두 잘라 가져감
//필요한 만큼만 가져감. 적어도 m 미터의 나무를 가져가기 위한 절단기 높이의 최댓값
int too(long long hei) {
	long long sum = 0;

	for (int i = 0; i < n; i++) if (v[i] > hei)sum += v[i] - hei;

	//해당 높이설정으로 적어도 m 미터의 나무를 가져갈 수 있는지
	if (sum >= m)	return 1;
	return 0;

}

int bin(long long low, long long high) {//yes 인 설정높이의 최대값
	//(1)yes------------|--------no(max)
	long long mid;
	long long re = low;
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (too(mid)) {
			if (re <= mid)re = mid;
			low = mid + 1;
		}
		else {
			high = mid - 1;
		}
	}
	return re;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n;//나무수
	cin >> m;//집으로 가져가려하는 나무길이
	long long k, max = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> k; // 각 나무의 높이
		if (max <= k)max = k;//최댓값 구해놓기 ->탐색구간의 상한선 설정
		v.push_back(k);
	}

	cout << bin(0, max); 




}
