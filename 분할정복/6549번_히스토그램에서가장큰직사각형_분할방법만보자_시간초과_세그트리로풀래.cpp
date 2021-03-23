#include <iostream>
#include <vector>
#include <queue>
#include <stdlib.h>
#include <math.h>
#include <string>
#include <algorithm>
#include <climits>
//������׷��� ���簢�� ���� ���� �Ʒ������� ���ĵǾ� �ִ� �����̴�.
//�� ���簢���� ���� �ʺ� ������ ������, ���̴� ���� �ٸ� ���� �ִ�.
//������׷����� ���� ���̰� ū ���簢���� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

//��� ���簢���� �ʺ�� 1
//�׽�Ʈ ���̽��� ������ - ���پ� �� �׽�Ʈ
//�Է��� ������ �� ���� 0�� �ϳ� �־���

//<���ٹ�>
//1.start~cut-1����
//2.cut ���� ����
//cut= ���� ���� �ָ� �������� ���� ����
//�׷� �� mid�� �����ϴ� ���̴� �翬�� �׳���*n
//3.mid+1~end ���� �ִ밪�� ���� ���ϰ�
//���߿��� �ִ��� ã�´�

using namespace std;
int n;
int index = 0;
int input;
vector<pair<int,int> >hei;




long long histo(int start, int end) {

	if(start<end){
		//���� ���� ������ �ּҰ� ���ϱ�
		//O(N) -> �ð� �ʰ��Ф�
		int cut = (*min_element(hei.begin() + start, hei.begin() + end)).second;
		
		//���� ���������� �ִ�
		long long left_max=histo(start,cut-1);
		//������ ���������� �ִ�
		long long right_max = histo(cut+1, end);
		//�ڸ������� �����ϴ� �ִ�
		long long mid_max = hei[cut].first * (end - start + 1);

		//������ ���� �߿� �ִ�
		long long tmp = left_max < right_max ? right_max : left_max;
		//���� �ִ�
		return mid_max < tmp ? tmp : mid_max;
		
	}
	return hei[start].first;
}



int main() {
	
	while (scanf("%d", &n) && n != 0) {
	
		//�� ���簢���ǳ��� �Է¹ޱ�
		for (int i = 0; i < n; i++)
		{
			cin >> input;
			hei.push_back({ input,i });

		}
		printf("%lld\n",histo(0, n - 1));
		hei.clear();
		
	}


	//cf)������ �迭 �ʱ�ȭ=memset(arr, 0, sizeof(arr));
		//������ �迭 �ʱ�ȭ=memset(array, 0, sizeof(array[0][0] * ROW_MAX * COL_MAX)
}

