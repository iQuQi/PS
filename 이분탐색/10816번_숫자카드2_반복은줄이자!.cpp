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


//�̺� Ž��
int binary(int left, int right, int val) {
	int mid = (left + right) / 2;

	while (left <= right) {
		//ã�� ���
		if (val ==card_num[mid].first) {
			break;
		}
		//�� ��쿡 �°� right�� left ����
		else if (val < card_num[mid].first) {
			right = mid - 1;
		}
		else if (val > card_num[mid].first){
			left = mid + 1;
		}
		//mid ���� ����
		mid = (right + left) / 2;
	}
	return left>right? 0:card_num[mid].second;

	
}

int main() {
	int tmp;
	//���� ī�忡 ���� �ϳ�. n���� ī��. m�� �־��� �� �� ���� ���� ī�尡 �����	
	int n, m; cin >> n;
	//���� ���� ī�� �Է� �ޱ�
	for (int i = 0; i < n; i++)
	{
		cin >> tmp; mycard.push_back(tmp);
	}
	sort(mycard.begin(), mycard.end());

	//������������ �����صΰ� �� ī�忡�� �ߺ��� �ٿ��� distinct�ϰ� �����ϵ� �� ������ ���� ����
	//�̷��� ���� �ʰ� �ٷ� mycard �迭���� ���ڸ� ã�� while�� �ߺ� ī�带 ã�ԵǸ� �ð� �ʰ� �߻�
	card_num.push_back({ mycard[0],1 });
	for (int i =1; i < mycard.size(); i++)
	{
		if (mycard[i] == card_num.back().first) card_num.back().second++;
		else card_num.push_back({ mycard[i] , 1 });
	}


	//ã�ƾߵǴ� ������ �迭
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> tmp; list.push_back(tmp);
	}


	//���̳ʸ� Ž������ card_num �迭���� �ش� ���ڸ� ã�� �� ������ ����(second) ���
	for (int i = 0; i < m-1; i++)
	{
		cout << binary(0, card_num.size()-1, list[i] ) <<" ";
	}

	cout << binary(0, card_num.size() - 1, list[m-1]) << "\n";

}

