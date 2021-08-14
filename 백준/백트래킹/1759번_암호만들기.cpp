#include <iostream>
#include <vector>
#include <queue>
#include <stdlib.h>
#include <algorithm>

using namespace std;
/*
바로 어제 최백준 조교가 방 열쇠를 주머니에 넣은 채 깜빡하고 
서울로 가 버리는 황당한 상황에 직면한 조교들은, 
702호에 새로운 보안 시스템을 설치하기로 하였다. 
이 보안 시스템은 열쇠가 아닌 암호로 동작하게 되어 있는 시스템이다.

암호는 서로 다른 L개의 알파벳 소문자들로 구성되며 
최소 한 개의 모음(a, e, i, o, u)과 최소 두 개의 자음으로 구성되어 
있다고 알려져 있다. 

또한 정렬된 문자열을 선호하는 조교들의 
성향으로 미루어 보아 암호를 이루는 알파벳이 암호에서 증가하는 순서로 
배열되었을 것이라고 추측된다. 

즉, abc는 가능성이 있는 암호이지만 bac는 그렇지 않다.

새 보안 시스템에서 조교들이 암호로 사용했을 법한 문자의 종류는
C가지가 있다고 한다. 이 알파벳을 입수한 민식, 영식 형제는 조교들의 방에 
침투하기 위해 암호를 추측해 보려고 한다.

C개의 문자들이 모두 주어졌을 때,
가능성 있는 암호들을 모두 구하는 프로그램을 작성하시오.
*/
int l, c;
char sol[20];
char arr[20];
//기저조건 체크용
int isOk() {
	// a(97) e(101) i(105) o(111) u(117) 모음
	// 0 4  8 14 20
	//그이외 자음
	int ja = 0;
	int mo = 0;

	for (int i = 1; i <= l; i++)
	{
		if ((sol[i] - 97) == 0 || (sol[i] - 97) == 4 || (sol[i] - 97) == 8 
			|| (sol[i] - 97) == 14 || (sol[i] - 97) == 20) mo++;
		else ja++;
	}
	if (ja >= 2 && mo >= 1) return 1;
	
	return 0;
}

//가지치기 체크용
int isOk2(int dep) {
	int ch[20] = { 0 };
	char ch2[20];

	//오름차순 체크
	for (int i = 1; i <= dep; i++)
	{
		ch2[i] = sol[i];
	}
	sort(ch2, ch2 + dep + 1);
	for (int i = 1; i <= dep; i++)
	{
		if (ch2[i] != sol[i]) return 0;
	}

	//같은문자있는지 체크
	for (int i = 1; i <= dep; i++)
	{
		for (int j = 1; j <= c; j++)
		{
			if (sol[i] == arr[j])ch[j]++;
		}
	}

	for (int j = 1; j <= c; j++)
	{
		if (ch[j] >= 2) return 0;
	}
	return 1;
}

void backTrack(int depth) {

	//기저조건
	if (depth == l + 1) {

		if (isOk()) {
			for (int i = 1; i <= l; i++) cout << sol[i];
			cout << endl;
		}
		return;
	}

	for (int i = 1; i <= c; i++)
	{
		sol[depth] = arr[i];
		if (!isOk2(depth)) continue;//가지치기
		backTrack(depth + 1);
	}

}

int main() {
	cin >> l >> c;
	//서로 다른 L개의 알파벳 소문자, - 최소 한개의 모음과 두개의 자음으로 구성 - 오름차순
	//주어진 c개의 문자로 가능한 암호를 모두 구하자
	char in;

	for (int i = 1; i <= c; i++)
	{
		cin >> in;
		arr[i] = in;
	}
	sort(arr, arr + c + 1);
	backTrack(1);



}