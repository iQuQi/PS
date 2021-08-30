#include <stdio.h>
int temp[1000 + 5];
/*
2×n 크기의 직사각형을 1×2, 2×1 타일로 채우는 
방법의 수를 구하는 프로그램을 작성하시오.

아래 그림은 2×5 크기의 직사각형을 채운 한 가지 방법의 예이다.
*/
int ling(int n) {
	if (n == 1) return 1;
	if (n == 2) return 2;
	if (temp[n]) return temp[n];
	//n-1경우의 총 개수 + n-2 경우의 총개수 
	//n-1는 n읙 경우에서 세로 직사각형으로 끝나는 경우
	//n-2는 n의 경우에서 가로 두개로 끝나는 경우
	else return temp[n] = (ling(n - 1) + ling(n - 2)) % 10007;
}

int main() {
	int n;
	scanf("%d", &n);
	printf("%d", ling(n));


}