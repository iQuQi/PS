'''
[16496 큰수만들기의 심화버전]
숫자의 신은 여러명이 있지만, 그 중에 자연수의 신은 오세준이다. 
오세준은 자연수의 신으로 오래오래 살다가 어느 날 음수의 신과 전쟁을 하게 되었다. 
오세준은 음수의 신 이다솜을 이기기위해서 큰 숫자를 만들기로 했다.

오세준은 지금 K개의 자연수를 가지고 있다. 
오세준은 K개의 수 중에 정확하게 N개의 수를 뽑아내서 그 수를 붙여서 만들 수 있는 수중에 
가장 큰 수를 만들고자 한다. 같은 수를 여러 번 이용해도 된다. 
단, 모든 수는 적어도 한 번은 이용되어야 한다.

오세준이 현재 가지고 있는 K개의 수가 주어졌을 때, 
이 수를 적어도 한 번 이상 이용해서 만들 수 있는 수 중에 가장 큰 수를 출력하는 프로그램을 작성하시오.

예를 들어 지금 오세준이 2, 3, 7 이라는 3개의 수를 가지고 있고, 
4개의 수를 뽑아야 한다면, 7732를 만들면 가장 큰 수가 된다.
'''
import sys
input = sys.stdin.readline

k, n = map(int, input().split())  # n >= k, k와n은 50보다 작거나 같은 자연수
numbers = []
for i in range(k):  # 각수는 1,000,000,000보다 작거나 같은 자연수, 수 중복 가능
    num = input().rstrip()
    filled = ''
    while len(filled) < 10:
        filled += str(num)
    numbers.append((filled[:10], num))


if k < n:
    length_sort = sorted(numbers, key=lambda x: (
        len(x[1]), x[0]), reverse=True)
    max_ = length_sort[0]
    for i in range(n-k):
        numbers.append(max_)

answer = ''
numbers.sort(key=lambda x: x[0], reverse=True)
for filled, real in numbers:
    answer += real
print(answer)
