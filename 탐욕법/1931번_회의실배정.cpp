#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>


using namespace std;
int n;

//회의 구조체 만들어두기
struct conference {
	int start;
	int end;
	conference(int a, int b) : start(a), end(b) {}//생성자
};


//연산자 정의
bool operator<(conference a, conference b) {
	if (a.end == b.end)
	{//끝시간이 동일하면 시작시간이 빠른게 앞
		return a.start < b.start;
	}

	//끝시간이 빠른게 앞
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


	//위에서 오버로딩한 < 로 sort
	sort(v.begin(), v.end());

	int ans = 1;
	int beforeConf = 0;


	for (int i = 1; i < n; i++)
	{
		if (v[i].start >= v[beforeConf].end)
		{
			//이전회의의 끝나는 시간보다 현재 회의의 시작시간이 같거나 뒤일때
			beforeConf = i;
			ans++;
		}
	}
	cout << ans << endl;
}