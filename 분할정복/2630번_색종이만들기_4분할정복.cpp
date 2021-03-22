#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
//파란색또는 하얀색으로 칠해진 종이 조각들
//종이를 자르는 규칙: 
//1. 전체 종이가 모두 같은 색이 아닐경우 가로와 세로로 중간 부분을 잘라서
//같은 크기의 4조각으로 만듬
//2.이 과정을 반복해서 종이가 모두 같은 색으로 칠해져있거나
//하나의 정사각형 칸이 되어 더 이상 자를 수 없을 때 까지 반복

//n은 2^1~2^7 (2의 거듭제곱만)
//하얀칸은 0 파란칸은 1
// 하얀색 종이 개수와 파란색 색종이 개수 출력
using namespace std;

int arr[130][130];
int n;
int blue, white;

//R은 row 부분 C은 col 부분
void color(int startR, int endR, int startC, int  endC) {

	//한개 정사각형인 경우
	//주의->좌표로생각x 하나정사각형이 가로세로1씩차이나는 거 아님
	if (startR == endR && startC == endC)
	{
		if (arr[startR][startC] == 0) white++;
		else blue++;
		return;
	}


	bool allSame = true;
	int beforeColor = arr[startR][startC];

	//이전 칸의 색깔과 하나라도 다른게 발견되면 false
	for (int i = startR; i <= endR; i++)
	{
		for (int j = startC; j <= endC; j++)
		{
			if (arr[i][j] != beforeColor)
			{
				allSame = false;
				break;
			}
		}
		if (!allSame)break;
	}

	//모두 같다면 더 자를 필요x -> return
	if (allSame)
	{
		if (beforeColor == 0)white++;
		else blue++;
		return;
	}

	//하나의 정사각형도 아니고 모두같지 않다면 4등분
	int midR = (startR + endR) / 2, midC = (startC + endC) / 2;
	color(startR, midR, startC, midC);  // 첫번째칸
	color(startR, midR, midC + 1, endC);  // 두번째
	color(midR + 1, endR, startC, midC);  //  세번째
	color(midR + 1, endR, midC + 1, endC); //  네번째
	// 1 2
	// 3 4

}




int main() {

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> arr[i][j];
		}
	}

	color(0, n - 1, 0, n - 1);
	cout << white << endl;
	cout << blue << endl;
}