#include <iostream>
#include <algorithm>
using namespace std;

/*
�� ���� �����̰� �ִ�. �� �����̴� ���̰� V������ ���� ���븦 �ö� ���̴�.

�����̴� ���� A���� �ö� �� �ִ�. ������, �㿡 ���� �ڴ� ���� B���� �̲�������. 
��, ���� �ö� �Ŀ��� �̲������� �ʴ´�.

�����̰� ���� ���븦 ��� �ö󰡷���, ��ĥ�� �ɸ����� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.
*/
int main() {
	long long A, B, V;
	cin >> A >> B >> V;

	long long V_ = V - A;

	double day = (double)V_ / (A - B);
	int dayre = (int)day;
	if (day != (int)day)
	{
		dayre = (int)day + 1;
	}
	cout << dayre + 1;

}