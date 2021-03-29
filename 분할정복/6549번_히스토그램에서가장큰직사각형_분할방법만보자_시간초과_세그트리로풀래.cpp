#include <iostream>
#include <vector>
#include <queue>
#include <stdlib.h>
#include <math.h>
#include <string>
#include <algorithm>
#include <climits>
//히스토그램은 직사각형 여러 개가 아래쪽으로 정렬되어 있는 도형이다.
//각 직사각형은 같은 너비를 가지고 있지만, 높이는 서로 다를 수도 있다.
//히스토그램에서 가장 넓이가 큰 직사각형을 구하는 프로그램을 작성하시오.

//모든 직사각형의 너비는 1
//테스트 케이스는 여러개 - 한줄씩 한 테스트
//입력의 마지막 줄 에는 0이 하나 주어짐

//<접근법>
//start~mid-1까지
//mid 포함 구간
//근데 mid가 middle이 아님 . 가장 낮은 애를 기준으로 반을 가름
//그럼 그 mid를 포함하는 넓이는 당연히 그높이*n
//mid+1~end 까지 최대값을 각각 구하고
//이중에서 최댓값을 찾는다

using namespace std;
int n;
int index = 0;
int input;
vector<pair<int,int> >hei;




long long histo(int start, int end) {

	if(start<end){
		//벡터 범위 내에서 최소값 구하기
		int cut = (*min_element(hei.begin() + start, hei.begin() + end)).second;
		
		//왼쪽 구간에서의 최댓값
		long long left_max=histo(start,cut-1);
		//오른쪽 구간에서의 최댓값
		long long right_max = histo(cut+1, end);

		long long tmp = left_max < right_max ? right_max : left_max;
		int mid_max = hei[cut].first * (end - start + 1);
		return mid_max < tmp ? tmp : mid_max;
		
	}
	return hei[start].first;
}



int main() {
	
	while (scanf("%d", &n) && n != 0) {
	
		//각 직사각형의높이 입력받기

		for (int i = 0; i < n; i++)
		{
			cin >> input;
			hei.push_back({ input,i });

		}
		printf("%d\n",histo(0, n - 1));
		//cf)일차원 배열 초기화=memset(arr, 0, sizeof(arr));
		//이차원 배열 초기화=memset(array, 0, sizeof(array[0][0] * ROW_MAX * COL_MAX)
		hei.clear();
		
		
	}
}
