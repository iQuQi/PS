#include <iostream>
#include <vector>
#include <queue>
#include <stdlib.h>
#include <algorithm>

using namespace std;


vector<pair<int, int>>v1;
/*

�ð� ����	�޸� ����	����	����	���� ���	���� ����
1 ��	256 MB	47550	14135	8909	28.135%
����
������� 18���� ������ �����ڰ� ���� '��ƾ �簢��'�̶� ���񿡼� ������ ������ ���� ���� �α⸦ ������ �ִ�.
�� ������ �Ʒ� �׸��� ���� ����, ���� ���� 9���� �� 81���� ���� ĭ���� �̷���� ���簢�� �� ������ �̷����µ�,
���� ���� �� �Ϻ� ĭ���� 1���� 9������ ���� �� �ϳ��� ���� �ִ�.

������ �� ĭ�� ä��� ����� ������ ����.

������ �����ٰ� �����ٿ��� 1���� 9������ ���ڰ� �� ������ ��Ÿ���� �Ѵ�.
���� ������ ���еǾ� �ִ� 3x3 ���簢�� �ȿ��� 1���� 9������ ���ڰ� �� ������ ��Ÿ���� �Ѵ�.
���� ���� ���, ù° �ٿ��� 1�� ������ ������ 2���� 9������ ���ڵ��� �̹� ��Ÿ�� �����Ƿ�
ù° �� ��ĭ���� 1�� ���� �Ѵ�.



���� ���� ��� ��ġ�� 3x3 ���簢���� ��쿡�� 3�� ������ ������ ���ڵ��� �̹� ���������Ƿ�
��� �� ĭ���� 3�� ���� �Ѵ�.

�̿� ���� �� ĭ�� ���ʷ� ä�� ���� ������ ���� ���� ����� ���� �� �ִ�.

���� ���� �� ������ �ǿ� ���� �ִ� ���ڵ��� ������ �־��� �� ��� �� ĭ�� ä����
���� ����� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.
*/

int arr[11][11];
int sol[82];
//üũ�� �迭
int garo[10][10], sero[10][10], nemo[10][10];

//�������� ���� ���� ��� 
void print() {
	for (int i = 1; i <= 9; i++) {
		for (int j = 1; j <= 9; j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}


int isok(int x, int y, int gab) {
	int area;//���� �׸� ���� ã���


	//���ΰ˻�
	if (garo[y][gab]) {
		return 0;
	}
	//���ΰ˻�
	if (sero[x][gab]) {
		return 0;
	}

	//�׸�˻�
	if (y < 4) {
		if (x < 4) area = 1;
		else if (x < 7) area = 2;
		else area = 3;
		if (nemo[area][gab]) return 0;
	}
	else if (y < 7) {
		if (x < 4) area = 4;
		else if (x < 7) area = 5;
		else area = 6;
		if (nemo[area][gab]) return 0;
	}
	else {
		if (x < 4) area = 7;
		else if (x < 7) area = 8;
		else area = 9;
		if (nemo[area][gab]) return 0;
	}
	return area;
}

int isok2() {
	//��� ĭ�� ä�������� �˻�
	for (int i = 1; i <= 9; i++) {
		for (int j = 1; j <= 9; j++) {
			if (!arr[i][j]) return 0;
		}

	}
	return 1;
}


void backTrack(int depth, vector<pair<int, int>>v) {//color : 0-��  1-��

	//���� ����
	if (depth == v.size() && isok2()) {
		print();
		exit(0);//��� ����
	}

	int x = v[depth].first;
	int y = v[depth].second;
	int area;

	for (int i = 1; i <= 9; i++)
	{
		//���ΰ˻� ���ΰ˻� �����׸�˻�
		area = isok(x, y, i);
		if (area == 0) continue;//���� ġ��

		arr[y][x] = i;
		garo[y][i]++;
		sero[x][i]++;
		nemo[area][i]++;

		backTrack(depth + 1, v);

		//������Ű��
		arr[y][x] = 0;
		garo[y][i]--;
		sero[x][i]--;
		nemo[area][i]--;
	}
}

int main() {
	//ĭ ������ �ϳ��� �迭�� �����صΰ� �Ź� for������ Ž���ϴ°� �ð��� �ʹ� �ɸ�
	//�Ʒ��� ���� ��������
	for (int i = 1; i <= 9; i++) {
		for (int j = 1; j <= 9; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 0) v1.push_back({ j,i });
			//�������� ����
			garo[i][arr[i][j]]++;
			//�������� ����
			sero[j][arr[i][j]]++;
			//���� �׸� ��������
			if (i < 4) {
				if (j < 4) nemo[1][arr[i][j]]++;
				else if (j < 7) nemo[2][arr[i][j]]++;
				else nemo[3][arr[i][j]]++;
			}
			else if (i < 7) {
				if (j < 4) nemo[4][arr[i][j]]++;
				else if (j < 7) nemo[5][arr[i][j]]++;
				else nemo[6][arr[i][j]]++;
			}
			else {
				if (j < 4) nemo[7][arr[i][j]]++;
				else if (j < 7) nemo[8][arr[i][j]]++;
				else nemo[9][arr[i][j]]++;

			}

		}
	}

	backTrack(0, v1);


}