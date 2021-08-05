#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>


using namespace std;
int n, k = 0;
long long swap_ = 0;
vector<int> v;
int sorted[500000 + 5];


void bubble(int start, int end) {
	int mid = (start + end) / 2;
	//임시 백터 생성
	vector<int> tmp;
	//두번째 배열의 시작
	int right = mid + 1;
	//첫번째 배열의 시작
	int left = start;

	//첫번째 배열에 두번째배열 원소 하나씩 버블정렬
	while (left <= mid && right <= end) {
		if (v[left] > v[right])//오른쪽 배열의 원소가 왼쪽꺼보다 작을때
		{
			//머지 소트에서 이동칸수가 버블 소트에서의 스왑 횟수와 동일한가봄
			swap_ += mid - left + 1;
			tmp.push_back(v[right++]);
			//배열 인덱싱 하면서 동시에 후증가 해버리기
		}
		else {//오른쪽원소가 왼쪽보다클때
			tmp.push_back(v[left++]);
		}
	}

	//한쪽 배열만 남은 경우 그냥 남은 원소 다 집어넣기
	while (left <= mid) tmp.push_back(v[left++]);
	while (right <= end) tmp.push_back(v[right++]);

	//새로 덮어씌우기
	for (int i = start, j = 0; i <= end; i++, j++) {
		v[i] = tmp[j];
	}

}

void bubbleSort(int start, int end) {
	if (start < end)
	{
		int mid = (start + end) / 2;
		bubbleSort(start, mid);
		bubbleSort(mid + 1, end);
		bubble(start, end);
	}
}


int main() {
	cin >> n;
	int in;
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &in);
		v.push_back(in);
	}

	bubbleSort(0, n - 1);
	cout << swap_;
}