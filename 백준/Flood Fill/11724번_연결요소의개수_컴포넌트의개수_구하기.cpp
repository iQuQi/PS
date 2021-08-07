#include <iostream>
#include <vector>
using namespace std;
int dab[1001][1001];//�������
//���� ���� �׷����� �־����� ��, ���� ��� (Connected Component)�� ������ 
//���ϴ� ���α׷��� �ۼ��Ͻÿ�.


bool visited[1001];//�湮����
int N, M;
//DFS �Լ�
void dfss(int now) {

	for (int i = 1; i <= N; i++) {
		if (dab[now][i] && !visited[i]) {
			visited[i] = 1;
			dfss(i);
		}
	}
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	int a, b;
	int com = 0;
	//������ĸ����
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		dab[a][b] = 1;
		dab[b][a] = 1;

	}

	//������Ʈ�� ���� ���ϱ�
	for (int i = 1; i <= N; i++)
	{
		if (visited[i])	continue;
		visited[i] = 1;
		com++;
		dfss(i);
	}


	cout << com << "\n";

}