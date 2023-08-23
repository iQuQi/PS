'''
강토는 자신의 기타 강의 동영상을 블루레이로 만들어 판매하려고 한다. 
블루레이에는 총 N개의 강의가 들어가는데, 
블루레이를 녹화할 때, 강의의 순서가 바뀌면 안 된다. 

순서가 뒤바뀌는 경우에는 강의의 흐름이 끊겨, 학생들이 대혼란에 빠질 수 있기 때문이다. 즉, i번 강의와 j번 강의를 같은 블루레이에 녹화하려면 
i와 j 사이의 모든 강의도 같은 블루레이에 녹화해야 한다.

강토는 이 블루레이가 얼마나 팔릴지 아직 알 수 없기 때문에, 
블루레이의 개수를 가급적 줄이려고 한다. 

오랜 고민 끝에 강토는 M개의 블루레이에 모든 기타 강의 동영상을 녹화하기로 했다. 
이때, 블루레이의 크기(녹화 가능한 길이)를 최소로 하려고 한다. 
단, M개의 블루레이는 모두 같은 크기이어야 한다.

강토의 각 강의의 길이가 분 단위(자연수)로 주어진다. 
이때, 가능한 블루레이의 크기 중 최소를 구하는 프로그램을 작성하시오.
'''
import sys
input = sys.stdin.readline

n, m = map(int, input().split())
course = list(map(int, input().split()))
total = sum(course)
longest = max(course)
min_length = total


def possible(now):
    tmp = 0
    count = 1

    for c in course:
        if tmp + c <= now:
            tmp += c
        else:
            tmp = c
            count += 1
    return count <= m


def solution(left, right):
    global min_length

    while left <= right:
        now = (left+right) // 2
        if possible(now):
            min_length = min(min_length, now)
            right = now - 1
        else:
            left = now + 1

    return


# 오답이유 solution(1,total)로 함.
# 최소값은 모든 강의를 모두 다른 블루레이에 하나씩 넣는 것 -> 가장 긴 강의의 길이!
solution(longest, total)
print(min_length)
