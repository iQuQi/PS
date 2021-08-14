#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
int matrix2[105][105];

int n;
long long b;

/*
ũ�Ⱑ N*N�� ��� A�� �־�����.
�̶�, A�� B������ ���ϴ� ���α׷��� �ۼ��Ͻÿ�. ���� �ſ� Ŀ�� �� ������, 
A^B�� �� ���Ҹ� 1,000���� ���� �������� ����Ѵ�.
*/
typedef vector<vector<int> > matrix;

//������ �������̵�
matrix operator * (matrix a, matrix b) {

	matrix mat(n, vector<int>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				mat[i][j] = (mat[i][j] + a[i][k] % 1000 * b[k][j] % 1000) % 1000;
			}

		}
	}
	return mat;
}


matrix pow(matrix A, long long b) {

	matrix tmp;
	if (b == 1) return A;
	tmp = pow(A, b / 2);

	if (b % 2 == 0) return tmp * tmp;
	else if (b % 2 == 1) return tmp * tmp*A;




}

void print(matrix mat) {
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << mat[i][j] % 1000 << " ";
		}
		cout << endl;
	}

}


int main()
{


	cin >> n >> b;
	int input;

	matrix A(n, vector<int>(n));
	for (int i = 0; i < n; i++)
	{
		vector<int> v;
		for (int j = 0; j < n; j++)
		{

			cin >> input;
			A[i][j] = input;
		}
	}
	print(pow(A, b));
	//��İ�


}