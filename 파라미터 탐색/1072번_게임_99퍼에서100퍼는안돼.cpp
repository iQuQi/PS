#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#define CON 1'000'000'000 // x의 최댓값
//이렇게 작은 따옴표로 큰 숫자 자릿수 표시 가능
using namespace std;
long long x, y, z, now_z;

//형택이가 갑자기 게임을 무조건 이기게됨
//이전의 승패 기록은 남아있다고 할때
//게임을 최소 몇번 더 해야 승률이 변하는 가

//승률이 절대 변하지 않는 다면 -1 출력
//승률에서 소수점은 버림
//x는 게임 횟수 y는 이긴 게임

long long bin(long long left, long long right) {
	long long mid, ret = CON+5;
	//(1)no------------|--------yes(max)

	while (left <= right)
	{
		mid = (left + right) / 2;
		//mid 판 더 이겼을 시 승률
		z = (y + mid) * 100 / (x + mid);

		//현재 슬률보다 높다면
		if (z > now_z) {
			right = mid - 1;
			//if (re >= mid)re = mid; 
			//아래 ret=mid+1 대신 여기에 써도됨 동일한 결과 
			//헷갈린다면 무조건 yes 인쪽에서 갱신한다고 생각하자
		}
		//현재 승률보다 같다면
		else {
			left = mid + 1;
			ret= mid + 1;
		}
	}
	return ret;
}


int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> x >> y;
	//현재승률
	now_z = (y * 100) / x;

	//현재 승률이 99퍼라면 100은 절대 될 수 없으므로 불가능
	if (now_z >= 99)
	{
		cout << -1;
		return 0;
	}
	cout << bin(0, CON);

}
