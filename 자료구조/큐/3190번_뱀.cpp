#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>


using namespace std;

int arr[105][105];//���
vector<pair<int, int>>bam;//�����ġ����
queue<pair<int, char>> q;//������ȯ ���� ����

int n;//����ũ�� nxn
int k;//����ǰ���
int l;//���⺯ȯ Ƚ��(����=L,������=D)
int tailIndex = 0; //�� ���Ϳ��� ������ġ

//�����=1 ó���� ����������
//����� ��ġ�� �̵���ΰ� �־���

//���� ����ġ ���
void print() {
	int arr[105][105] = { 0, };
	for (int i = tailIndex; i < bam.size(); i++)
	{
		int x = bam[i].first;
		int y = bam[i].second;
		arr[y][x] = 1;
	}

	for (int i = 1; i < n; i++)
	{
		for (int j = 1; j < n; j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}


int isok(int x, int y) {
	//���� �ε����� ���
	if (x<1 || x>n || y<1 || y>n) {
		return 0;
	}
	//�ڱ� ���� �ε����� ���
	for (int i = tailIndex; i < bam.size(); i++)
	{
		if (bam[i].first == x && bam[i].second == y) {
			return 0;
		}
	}
	return 1;
}

int main() {
	cin >> n >> k;
	for (int i = 0; i < k; i++)
	{
		int h, y;
		cin >> h >> y;
		arr[h][y] = 1;//�����ġ
	}

	cin >> l;
	for (int i = 0; i < l; i++)
	{
		int turn; // ���ʵڿ� ����ٲٴ���
		char dir;// L�̸� ���� D�� ������
		cin >> turn >> dir;
		q.push({ turn,dir });
	}

	//�Է³�

	int time = 0;
	int nDir = 0;//nDir : ���� ���� 0 = ������  1=�Ʒ�   2=����   3=��
	bam.push_back({ 1,1 });//���� ���� ������ġ�ϴ� ���� X Y ��ǥ, �������(����->�Ӹ�)

	int headX = 1;
	int headY = 1;

	while (1) {
		time++;

		if (nDir == 0) {
			headX++;
			if (!isok(headX, headY)) break;
			bam.push_back({ headX,headY });
			if (!arr[headY][headX]) {
				tailIndex++;
			}
			else arr[headY][headX] = 0;
		}
		else if (nDir == 1) {
			headY++;
			if (!isok(headX, headY)) break;
			bam.push_back({ headX,headY });
			if (!arr[headY][headX]) {
				tailIndex++;
			}
			else arr[headY][headX] = 0;
		}
		else if (nDir == 2) {
			headX--;
			if (!isok(headX, headY)) break;
			bam.push_back({ headX,headY });
			if (!arr[headY][headX]) {
				tailIndex++;
			}
			else arr[headY][headX] = 0;
		}
		else {
			headY--;
			if (!isok(headX, headY)) break;
			bam.push_back({ headX,headY });
			if (!arr[headY][headX]) {
				tailIndex++;
			}
			else arr[headY][headX] = 0;
		}


		//����time�� ������ȯ time�ϰ�� ������ȯ
		if (!q.empty() && q.front().first == time) {
			if (q.front().second == 'D') nDir = (nDir + 1) % 4;
			else {
				nDir--;
				if (nDir == -1) nDir = 3;
			}
			q.pop();
		}

	}

	cout << time;
}