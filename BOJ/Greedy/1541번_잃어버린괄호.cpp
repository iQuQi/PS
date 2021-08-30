#include <iostream>
#include <string>
using namespace std;
//세준이는 양수와 + , -, 그리고 괄호를 가지고 식을 만들었다.
//그리고 나서 세준이는 괄호를 모두 지웠다.
//그리고 나서 세준이는 괄호를 적절히 쳐서 이 식의 값을 최소로 만들려고 한다.
//괄호를 적절히 쳐서 이 식의 값을 최소로 만드는 프로그램을 작성하시오.

//접근:
//최솟값을 만들기 위해서는 덧셈끼리 모두 묶어 뺴야 한다. 
//그러려면 - 부호를 기준으로 앞뒤에 괄호를 묶어주면 된다. 
//예를 들어 1+2-3+4-5+6은 (1+2)-(3+4)-(5+6)이 될 것이다. 
int main()
{
	int dab = 0;
	//n_str은 각각의 피연산자를 일시적으로 저장
	string str, n_str = "";
	cin >> str;

	//괄호
	bool par = false;

	for (int i = 0; i <= str.size(); i++) {
		//연산자인경우 
		if (str[i] == '+' || str[i] == '-' || str[i] == '\0') {
			//괄호가 열려있는 경우
			//stoi 활용하기 string -> int
			if (par) dab -= stoi(n_str);
			//괄호가 열리지 않은 경우
			else dab += stoi(n_str);
			n_str = "";

			//빼기인 경우  괄호를 열어준다.
			if (str[i] == '-') par = true;
			continue;
		}

		//피연산자
		n_str += str[i];
	}

	cout << dab;








}