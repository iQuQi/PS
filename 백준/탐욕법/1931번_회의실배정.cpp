#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>


using namespace std;
int n;

//ȸ�� ����ü �����α�
struct conference {
	int start;
	int end;
	conference(int a, int b) : start(a), end(b) {}//������
};


//������ ����
bool operator<(conference a, conference b) {
	if (a.end == b.end)
	{//���ð��� �����ϸ� ���۽ð��� ������ ��
		return a.start < b.start;
	}

	//���ð��� ������ ��
	return a.end < b.end;
}


int main() {
	cin >> n;
	int s, e;
	vector<conference> v;

	for (int i = 0; i < n; i++)
	{
		cin >> s >> e;
		v.push_back(conference(s, e));
	}


	//������ �����ε��� < �� sort
	sort(v.begin(), v.end());

	int ans = 1;
	int beforeConf = 0;


	for (int i = 1; i < n; i++)
	{
		if (v[i].start >= v[beforeConf].end)
		{
			//����ȸ���� ������ �ð����� ���� ȸ���� ���۽ð��� ���ų� ���϶�
			beforeConf = i;
			ans++;
		}
	}
	cout << ans << endl;
}