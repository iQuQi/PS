#include <stdio.h>
int temp[1000 + 5];
/*
2��n ũ���� ���簢���� 1��2, 2��1 Ÿ�Ϸ� ä��� 
����� ���� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Ʒ� �׸��� 2��5 ũ���� ���簢���� ä�� �� ���� ����� ���̴�.
*/
int ling(int n) {
	if (n == 1) return 1;
	if (n == 2) return 2;
	if (temp[n]) return temp[n];
	//n-1����� �� ���� + n-2 ����� �Ѱ��� 
	//n-1�� n�� ��쿡�� ���� ���簢������ ������ ���
	//n-2�� n�� ��쿡�� ���� �ΰ��� ������ ���
	else return temp[n] = (ling(n - 1) + ling(n - 2)) % 10007;
}

int main() {
	int n;
	scanf("%d", &n);
	printf("%d", ling(n));


}