#include <iostream>
#include <vector>
#include <queue>
#include <stdlib.h>
#include <math.h>
#include <string>
#include <algorithm>
#include <climits>


using namespace std;
vector<int> mycard;
vector<pair<int,int>> card_num;
vector<int> list;


//이분 탐색
int binary(int left, int right, int val) {
	int mid = (left + right) / 2;

	while (left <= right) {
		//찾은 경우
		if (val ==card_num[mid].first) {
			break;
		}
		//각 경우에 맞게 right와 left 갱신
		else if (val < card_num[mid].first) {
			right = mid - 1;
		}
		else if (val > card_num[mid].first){
			left = mid + 1;
		}
		//mid 값도 갱신
		mid = (right + left) / 2;
	}
	return left>right? 0:card_num[mid].second;

	
}

int main() {
	int tmp;
	//숫자 카드에 정수 하나. n개의 카드. m이 주어질 때 이 수가 적힌 카드가 몇개인지	
	int n, m; cin >> n;
	//내가 가진 카드 입력 받기
	for (int i = 0; i < n; i++)
	{
		cin >> tmp; mycard.push_back(tmp);
	}
	sort(mycard.begin(), mycard.end());

	//오름차순으로 정리해두고 각 카드에서 중복은 줄여서 distinct하게 저장하되 그 개수를 따로 저장
	//이렇게 하지 않고 바로 mycard 배열에서 숫자를 찾고 while로 중복 카드를 찾게되면 시간 초과 발생
	card_num.push_back({ mycard[0],1 });
	for (int i =1; i < mycard.size(); i++)
	{
		if (mycard[i] == card_num.back().first) card_num.back().second++;
		else card_num.push_back({ mycard[i] , 1 });
	}


	//찾아야되는 숫자의 배열
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> tmp; list.push_back(tmp);
	}


	//바이너리 탐색으로 card_num 배열에서 해당 숫자를 찾고 그 숫자의 개수(second) 출력
	for (int i = 0; i < m-1; i++)
	{
		cout << binary(0, card_num.size()-1, list[i] ) <<" ";
	}

	cout << binary(0, card_num.size() - 1, list[m-1]) << "\n";

}

