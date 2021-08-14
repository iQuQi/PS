#include <iostream>
#include <string>
using namespace std;
/*
세준이는 양수와 +, -, 그리고 괄호를 가지고 식을 만들었다. 
그리고 나서 세준이는 괄호를 모두 지웠다.

그리고 나서 세준이는 괄호를 적절히 쳐서 이 식의 값을 최소로 만들려고 한다.

괄호를 적절히 쳐서 이 식의 값을 최소로 만드는 프로그램을 작성하시오.
*/
int main()
{
	int dab = 0;
	string str, n_str = "";
	cin >> str;
	bool bagi = false;

	for (int i = 0; i <= str.size(); i++) {
		//연산자
		if (str[i] == '+' || str[i] == '-' || str[i] == '\0') {
			if (bagi) dab -= stoi(n_str);
			else dab += stoi(n_str);
			n_str = "";
			if (str[i] == '-') bagi = true; // 첫 빼기 이후를 -( 뒤 모든 부분 ) 으로 묶어버림
											//'뒤 모든 부분'은 최대값이 되면 됨

											//빼기가 나오고 다음 빼기 전까지를 괄호로 하나로 묶어버리면 
											//얼마든지 뒷부부은 전부 뺄셈화 가능 
											//즉 첫 빼기 이후로 모든 피연산자를 뺄셈하면 됨
												
			continue;
		}
		//피연산자
		n_str += str[i];
	}

	cout << dab;








}