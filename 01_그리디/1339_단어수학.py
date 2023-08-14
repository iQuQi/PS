'''
민식이는 수학학원에서 단어 수학 문제를 푸는 숙제를 받았다.

단어 수학 문제는 N개의 단어로 이루어져 있으며, 각 단어는 알파벳 대문자로만 이루어져 있다. 
이때, 각 알파벳 대문자를 0부터 9까지의 숫자 중 하나로 바꿔서 N개의 수를 합하는 문제이다. 
같은 알파벳은 같은 숫자로 바꿔야 하며, 두 개 이상의 알파벳이 같은 숫자로 바뀌어지면 안 된다.

예를 들어, GCF + ACDEB를 계산한다고 할 때, 
A = 9, B = 4, C = 8, D = 6, E = 5, F = 3, G = 7로 결정한다면, 
두 수의 합은 99437이 되어서 최대가 될 것이다.

N개의 단어가 주어졌을 때, 그 수의 합을 최대로 만드는 프로그램을 작성하시오.
'''

# 각 알파벳이 몇 만큼 있는지 확인 (자릿수까지 계산해서 AAA -> A가 111번 )
import sys
import math
input = sys.stdin.readline

n = int(input())
words = [list(input().rstrip()) for _ in range(n)]
numbers = [i for i in range(10)]
matched = {}

for word in words:
    for idx, i in enumerate(word):
        # 오답이유: ^는 승수 표현이 아니다! 비트 연산자임 -> math.pow 사용하기
        if i in matched.keys():
            matched[i] += math.pow(10, (len(word) - idx - 1))
        else:
            matched[i] = math.pow(10, (len(word) - idx - 1))

dict2tuple = []
for key in matched.keys():
    dict2tuple.append((int(matched[key]), key))
dict2tuple.sort(reverse=True)

total = 0
for i in dict2tuple:
    total += i[0]*numbers.pop()
print(total)
