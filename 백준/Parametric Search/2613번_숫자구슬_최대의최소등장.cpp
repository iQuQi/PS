#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;
int n;
int m;
int arr[305] = { 0, };
int dab[305];

vector<int > v;
/*
N개의 숫자 구슬이 <그림 1>과 같이 막대에 꿰어져 일자로 놓여 있다.
이들 구슬은 막대에서 빼낼 수 없고, 바꿀 수 없다.

|---5 4 2 6 9 3 8 7----|

이 숫자 구슬을 M개의 그룹으로 나누었을 때 각각의 그룹의 합 중 최댓값이
최소가 되도록 하려 하다.

예를 들어 세 그룹으로 나눈다고 할 때 
<그림 2>와 같이 그룹을 나누면 그룹의 합은 각각 11, 15, 18이 되어 
그 중 최댓값은 18이 되고, 

<그림 3>과 같이 나누면 각 그룹의 합은 각각 17, 12, 15가 되어
그 중 최댓값은 17이 된다.

숫자 구슬의 배열이 위와 같을 때는 그룹의 합 중 최댓값이 17보다 작게 만들 수는 없다.
그룹에 포함된 숫자 구슬의 개수는 0보다 커야 한다.

각 그룹의 합 중 최댓값이 최소가 되도록 M개의 그룹으로 나누었을 때, 
그 최댓값과 각 그룹을 구성하는 구슬의 개수를 찾아 출력하는 프로그램을 작성하시오.
*/


//mid값을 받아서 그 수가 최댓값이 되게 m개의 그룹으로 나눌수 있는지
int goosle(int mm) {

	//cout << "mm : " << mm << endl;
	int sum = 0, cnt = 0;
	int group = 1;

	for (int i = 0; i < n; i++)
	{
		//mid보다 하나의 구슬값이 클경우 불가능하므로 0리턴
		if (v[i] > mm) return 0;
		sum += v[i];
		cnt++;

		//mid값 넘어가면 앞구슬까지 group 묶기
		if (sum > mm)
		{
			cnt--;
			sum = v[i];

			arr[group] = cnt;
			group++;
			cnt = 1;
		}
		//마지막 남은 떨이 구슬 다 넣기
		if (i == n - 1) arr[group] = cnt;
	}
	//그룹이 m개이하로 나누어떨어지는 경우 1리턴
	if (group <= m)return 1;
	return 0;
}

//이진탐색 답 받아서 그룹별 구슬개수 출력
void print(int re) {
	int sum = 0, cnt = 0;
	int group = 1;
	for (int i = 0; i < n; i++)
	{
		sum += v[i];
		cnt++;
		if (sum > re)
		{
			cnt--;
			sum = v[i];
			dab[group] = cnt;
			group++;
			cnt = 1;
		}
		if (i == n - 1)dab[group] = cnt;
	}

	//m은 나눠야될 그룹 group은 내가 만든케이스의 그룹개수 -> need 는 쪼개서 더 만들어줘야될 그룹수
	int need = m - group;
	for (int i = 1; i <= group; i++)
	{
		if (dab[i] == 1)cout << dab[i] << " ";
		else {
			while (dab[i] >= 2 && need >= 1) {
				//cout << "while.." << endl;
				cout << 1 << " ";
				dab[i]--;
				need--;
			}
			cout << dab[i] << " ";
		}
	}

}


//이진탐색함수
int bin(int low, int high) {
	int mid;
	int tmp;
	int re = high;
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (goosle(mid)) {
			if (re >= mid)re = mid;
			high = mid - 1;
		}
		else {
			low = mid + 1;
		}
	}
	return re;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;//구슬개수
	cin >> m;//그룹수
	int sum = 0;
	int k;
	for (int i = 0; i < n; i++)
	{
		cin >> k;

		sum += k;
		v.push_back(k);//구슬배열
	}

	int ret = bin(1, sum);
	cout << ret << endl;
	print(ret);




}
