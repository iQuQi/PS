'''
음이 아닌 정수가 N개 들어있는 리스트가 주어졌을 때, 
리스트에 포함된 수를 나열하여 만들 수 있는 가장 큰 수를 구하는 프로그램을 작성하시오.
'''

N = int(input())
arr = input().split()


def sort_key(x):
    result = []

    fill_x = ''
    # 오답이유: 자릿수를 첫수로만 채움 -> 해당 수를 최대자릿수인 10자리까지 반복해서 채워야함
    # 예를들어 312라는 수가 있다면 312를 비교하는 시점에서는 312보다 큰 수는 이미 쓰인 상황이고
    # 앞 3자리수가 같은 312~라는 수가 또있다는 뜻이다
    # 즉, 현재의 수를 사용하고 나면 뒤에 오게 되는 수가 312~이므로
    # 312312로 간주한다
    # 위 과정을 반복 -> 312312가 비교되는 시점에서는...
    while len(fill_x) < 10:
        fill_x += x

    for i in fill_x[:10]:
        result.append(i)

    return tuple(result)


arr.sort(key=sort_key)
arr.reverse()

answer = ''
for i in arr:
    answer += i

if answer[0] == '0':
    print(0)
else:
    print(answer)
