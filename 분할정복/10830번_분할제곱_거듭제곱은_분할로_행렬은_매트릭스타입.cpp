#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
//크기가 N*N인 행렬 A가 주어진다.이때, A의 B제곱을 구하는 프로그램을 작성하시오.
//수가 매우 커질 수 있으니, A^B의 각 원소를 1, 000으로 나눈 나머지를 출력한다

int matrix2[105][105];


int n;
long long b;

//2차원 배열을 매트릭스로 정의
typedef vector<vector<int> > matrix;

//연산자 오버로딩 - 매트릭스 곱 
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

//매트릭스의 제곱 함수 정의 - 분할정복의 거듭제곱 활용
matrix pow(matrix A, long long b) {

	matrix tmp;
	if (b == 1) return A;
	tmp = pow(A, b / 2);

	if (b % 2 == 0) return tmp * tmp;
	else if (b % 2 == 1) return tmp * tmp*A;




}

//매트릭스 프린트 함수
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

	//이차원 벡터의 생성자: n개의 원소를 갖는 일차원 벡터를 n개 갖는 이차원 벡터
	matrix A(n, vector<int>(n));

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> A[i][j];
		}
	}
	print(pow(A, b));

}