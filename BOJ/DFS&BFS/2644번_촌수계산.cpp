#include <iostream>
#include <vector>
#include <queue>
#include <string>
#
using namespace std;
int gajok[100 + 5][100 + 5];//인접행렬

bool visited[100 + 5];//방문여부
int dis[105][105];
queue<pair<int, int>>bfs;
int n, m;
int a, b;
int x, y;
/*
우리 나라는 가족 혹은 친척들 사이의 관계를 촌수라는 
단위로 표현하는 독특한 문화를 가지고 있다. 
이러한 촌수는 다음과 같은 방식으로 계산된다. 
기본적으로 부모와 자식 사이를 1촌으로 정의하고 이로부터 사람들 간의 촌수를 계산한다. 
예를 들면 나와 아버지, 아버지와 할아버지는 각각 1촌으로 나와 할아버지는 2촌이 되고, 
아버지 형제들과 할아버지는 1촌, 나와 아버지 형제들과는 3촌이 된다.

여러 사람들에 대한 부모 자식들 간의 관계가 주어졌을 때, 
주어진 두 사람의 촌수를 계산하는 프로그램을 작성하시오.
*/

void bfss(int from, int to) {
	int dab = -1;
	bfs.push({ from,0 });
	visited[from] = true;

	//큐가 비었거나 목적지에 도달하면 끝
	while (!bfs.empty() && !visited[to]) {
		int now = bfs.front().first;
		int chon = bfs.front().second;

		bfs.pop();

		for (int i = 1; i <= n; i++) {
			//방문하지않았고 부모 또는 자식 관계인 가족인 경우 진행
			if (!visited[i] && gajok[now][i]) {
				bfs.push({ i, chon + 1 });
				visited[i] = 1;
				if (i == to) dab = chon + 1; //목적지에 도달 했다면 dab 갱신
			}
		}
	}
	cout << dab;
}

int main() {
	cin >> n; 	//전체 사람의수
	cin >> a >> b;  // 촌수를 계산해야하는 서로 다른 두사람의 번호 (1...n 사이)
	cin >> m; // 부모 자식들 간의 관계의 개수
	for (int i = 0; i < m; i++)
	{
		//x는 y의 부모 번호
		cin >> x >> y;
		gajok[x][y] = 1;
		gajok[y][x] = 1;
	}

	bfss(a, b);

}