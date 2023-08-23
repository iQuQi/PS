'''
양팔 저울과 몇 개의 추가 주어졌을 때, 이를 이용하여 입력으로 
주어진 구슬의 무게를 확인할 수 있는지를 결정하려고 한다.

무게가 각각 1g과 4g인 두 개의 추가 있을 경우, 주어진 구슬과 1g 추 하나를
양팔 저울의 양쪽에 각각 올려놓아 수평을 이루면 구슬의 무게는 1g이다. 
또 다른 구슬이 4g인지를 확인하려면 1g 추 대신 4g 추를 올려놓으면 된다.

구슬이 3g인 경우 아래 <그림 1>과 같이 구슬과 추를 올려놓으면 양팔 저울이 
수평을 이루게 된다. 
따라서 각각 1g과 4g인 추가 하나씩 있을 경우 주어진 구슬이 3g인지도 확인해 볼 수 있다.

<그림 2>와 같은 방법을 사용하면 구슬이 5g인지도 확인할 수 있다. 
구슬이 2g이면 주어진 추를 가지고는 확인할 수 없다.

추들의 무게와 확인할 구슬들의 무게가 입력되었을 때, 주어진 추만을 사용하여 
구슬의 무게를 확인 할 수 있는지를 결정하는 프로그램을 작성하시오.
'''

n = int(input())
n_weight = list(map(int, input().split()))

marble = int(input())
m_weight = list(map(int, input().split()))

dp = [False] * 40001
possible = []

for w in n_weight:

    # copy 안해주면 안에서 append 한게 바로 반영되서 무한루프
    for p in possible.copy():
        # 이전 추까지의 케이스에 자신의 무게를 빼고 더해주는 경우의 수 더하기
        if p+w not in possible:
            possible.append(p+w)
        if abs(p-w) not in possible:
            possible.append(abs(p-w))
    # 자기 자신의 값 추가
    if w not in possible:
        possible.append(w)

for p in possible:
    dp[p] = True

for w in m_weight:
    if dp[w]:
        print('Y ', end='')
    else:
        print('N ', end='')
print()
