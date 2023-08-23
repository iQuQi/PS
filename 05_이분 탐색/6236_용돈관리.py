'''
현우는 용돈을 효율적으로 활용하기 위해 계획을 짜기로 하였다. 
현우는 앞으로 N일 동안 자신이 사용할 금액을 계산하였고, 
돈을 펑펑 쓰지 않기 위해 정확히 M번만 통장에서 돈을 빼서 쓰기로 하였다. 

현우는 통장에서 K원을 인출하며, 통장에서 뺀 돈으로 하루를 보낼 수 있으면 
그대로 사용하고, 모자라게 되면 남은 금액은 통장에 집어넣고 다시 K원을 인출한다. 

다만 현우는 M이라는 숫자를 좋아하기 때문에, 
정확히 M번을 맞추기 위해서 남은 금액이 그날 사용할 금액보다 많더라도 
남은 금액은 통장에 집어넣고 다시 K원을 인출할 수 있다. 

현우는 돈을 아끼기 위해 인출 금액 K를 최소화하기로 하였다. 
현우가 필요한 최소 금액 K를 계산하는 프로그램을 작성하시오.
'''
import sys
input = sys.stdin.readline

n, m = map(int, input().split())
money = []
for i in range(n):
    money.append(int(input()))
total = sum(money)
biggest = max(money)
min_k = total


def possible(now):
    have = now
    out = 1

    for t in money:
        if have - t < 0:
            out += 1
            have = now
        have -= t
    # 문제에서 정확히 m번 사용해야한다고 했으나
    # 남은 돈이 넉넉함에도 다시 빼는게 가능하다고 함
    # 예를 들어, 5번꺼내야하는데 4번밖에 못꺼냈을 경우, 꺼낼 날 직전날에도 꺼냈다빼서 사용하게 되면
    # +1 가능이므로 out<=m으로 게산해도 무방
    return out <= m


def solution(left, right):
    global min_k

    while left <= right:
        now = (left+right) // 2
        if possible(now):
            min_k = min(min_k, now)
            right = now - 1
        else:
            left = now + 1

    return


solution(biggest, total)
print(min_k)
