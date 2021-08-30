#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
//�ڿ��� A�� B�� ���� ���� �˰� �ʹ�. �� ���Ϸ��� ���� �ſ� Ŀ�� �� �����Ƿ� 
//�̸� C�� ���� �������� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.
long long a, b, c;

//���� ���� long long �������� ��������
long long pow_my(long long b) {
	long long tmp;
	//ũ�Ⱑ �ʰ� �� �� �����Ƿ� ƴƴ�� c�� ������ ���� ���ֱ�
	if (b > 1) tmp = pow_my(b / 2) % c; // �̸� ����� �α�
	
	if (b == 1)return a % c;

	//���� ����
	//b�� ¦���� ��� = (c^n/2)(c^n/2)
	else if (b % 2 == 0) {
		return(tmp*tmp) % c;
	}
	//b�� Ȧ���� ��� = (c^n-1/2)(c^n-1/2)c -> Ȧ��/2 �ÿ� �ڵ����� ������
	else if (b % 2 == 1) {
		return ((tmp*tmp) % c*(a%c)) % c;
	}
}

int main()
{
	cin >> a >> b >> c;
	cout << pow_my(b);
}