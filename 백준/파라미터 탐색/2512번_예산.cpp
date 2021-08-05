#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#define CON 1000000000 
using namespace std;
int n, m, need;
vector<int > v;//요청을 저장하는 배열

//가능한 최대의 총 예산 배정
//모든 요청이 배정될 수 있는 경우 요청한 금액을 그대로 배정
//모든 요청이 배정될 수 없는 경우 특정한 정수 상한액을 계산해서 모두 상한액을 배정. 
//   -> 상한액 이하의 요청의 경우 요청 금액 그대로 배정

int too(int upper) {
	int ans = 0;
	int need = 0;

	for (int i = 0; i < n; i++)
	{
		if (v[i] <= upper)need += v[i]; // 상한액보다 적다면 그대로 제공
		else need += upper; // 상한액보다 많다면 상한액으로 제공
	}

	//총예산 보다 필요한 금액이 적은 경우 -> 모든 요청에 대해 금액 그대로 배정
	if (need <= m)return 1;
	//총예산 보단 필요한 금액이 큼 -> 불가능
	return 0;

}

int bin(int low, int high) {
	int mid, ret = low;
	//(1)yes------------|--------no(max)
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (too(mid)) {
			//상한액의 최댓값을 갱신
			if (ret <= mid)ret = mid;
			low = mid + 1;
		}
		else {
			high = mid - 1;
		}
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;// 지방의수
	int k, max = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> k;//각 지방의 예산 요청
		if (max <= k)max = k;
		v.push_back(k);
	}
	cin >> m;//총예산
	cout << bin(1, max);

}
