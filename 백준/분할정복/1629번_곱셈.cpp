#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
//자연수 A를 B번 곱한 수를 알고 싶다. 단 구하려는 수가 매우 커질 수 있으므로 
//이를 C로 나눈 나머지를 구하는 프로그램을 작성하시오.
long long a, b, c;

//리턴 값이 long long 범위임을 주의하자
long long pow_my(long long b) {
	long long tmp;
	//크기가 초과 될 수 있으므로 틈틈이 c로 나머지 연산 해주기
	if (b > 1) tmp = pow_my(b / 2) % c; // 미리 만들어 두기
	
	if (b == 1)return a % c;

	//분할 정복
	//b가 짝수인 경우 = (c^n/2)(c^n/2)
	else if (b % 2 == 0) {
		return(tmp*tmp) % c;
	}
	//b가 홀수인 경우 = (c^n-1/2)(c^n-1/2)c -> 홀수/2 시에 자동으로 내림됨
	else if (b % 2 == 1) {
		return ((tmp*tmp) % c*(a%c)) % c;
	}
}

int main()
{
	cin >> a >> b >> c;
	cout << pow_my(b);
}