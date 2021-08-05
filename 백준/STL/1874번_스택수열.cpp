#include <cstdio>
#include <stack>
#include <vector>

/*
���� (stack)�� �⺻���� �ڷᱸ�� �� �ϳ���, 
��ǻ�� ���α׷��� �ۼ��� �� ���� �̿�Ǵ� �����̴�. 
������ �ڷḦ �ִ� (push) �Ա��� �ڷḦ �̴� (pop) �Ա��� 
���� ���� ���߿� �� �ڷᰡ ���� ���� ������ (LIFO, Last in First out) Ư���� ������ �ִ�.

1���� n������ ���� ���ÿ� �־��ٰ� �̾� �þ�������ν�, 
�ϳ��� ������ ���� �� �ִ�. �̶�, ���ÿ� push�ϴ� ������
�ݵ�� ���������� ��Ű���� �Ѵٰ� ����. ������ ������ �־����� �� 
������ �̿��� �� ������ ���� �� �ִ��� ������, �ִٸ� 
� ������ push�� pop ������ �����ؾ� �ϴ����� �˾Ƴ� �� �ִ�. 
�̸� ����ϴ� ���α׷��� �ۼ��϶�.
*/
using namespace std;
int arr[100000 + 1];
int main() {
	int n, i, j = 0;
	stack <int> s;
	vector <char> v;

	scanf("%d", &n);

	//�Է� �ޱ�
	for (i = 0; i < n; i++) scanf("%d", &arr[i]);

	for (i = 1; i <= n; i++) {
		s.push(i);//���� ����
		v.push_back('+');//���� ��� ���� vector

		while (!s.empty() && s.top() == arr[j]) {
			s.pop();
			v.push_back('-');
			j++;
		}
	}

	if (!s.empty()) printf("NO\n");
	else {
		for (i = 0; i < v.size(); i++) printf("%c\n", v[i]);
	}

	return 0;
}