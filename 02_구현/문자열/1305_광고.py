# 못품,KMP 알고리즘으로 푼다는 발상을 하는 것이 중요하다
# KMP에서 실패함수를 활용
# 이 문제의 답은 (광고판의 크기) - pi[-1] (우왕...)

'''
세준이는 길 한가운데에서 전광판을 쳐다보고 있었다. 전광판에는 광고가 흘러나오고 있었다. 
한참을 전광판을 쳐다본 세준이는 이 광고가 의미하는 것이 무엇인지 궁금해지기 시작했다.

전광판에는 같은 내용의 문구가 무한히 반복되어 나온다. 
또, 전광판의 크기는 전광판에서 한번에 보이는 최대 문자수를 나타낸다. 
만약 전광판의 크기가 L이라면, 한번에 L개의 문자를 표시할 수 있는 것이다.

광고업자는 최대한의 광고효과를 내기 위해서 길이가 N인 광고를 무한히 붙여서 광고한다.

예를 들어, 광고 업자 백은진이 광고하고 싶은 내용이 aaba 이고, 
전광판의 크기가 6이라면 맨 처음에 보이는 내용은 aabaaa 이다. 시간이 1초가 지날 때마다, 
문자는 한 칸씩 옆으로 이동한다. 따라서 처음에 aabaaa가 보였으면 그 다음에는 abaaab가 보인다. 
그 다음에는 baaaba가 보인다.

세준이가 어느 순간 전광판을 쳐다봤을 때, 그 때 쓰여 있는 문자가 입력으로 주어졌을 때, 
가능한 광고의 길이중 가장 짧은 것을 출력하는 프로그램을 작성하시오.
'''

import sys
input = sys.stdin.readline

L = int(input())
show = input().rstrip()  # 오답: int 로 안감쌌으면 rstrip 추가!!


def KMP_table(pattern):
    lp = len(pattern)
    tb = [0 for _ in range(lp)]  # 정보 저장용 테이블

    pidx = 0  # 테이블의 값을 불러오고, 패턴의 인덱스에 접근
    for idx in range(1, lp):  # 테이블에 값 저장하기 위해 활용하는 인덱스
        # pidx가 0이 되거나, idx와 pidx의 pattern 접근 값이 같아질때까지 진행
        while pidx > 0 and pattern[idx] != pattern[pidx]:
            pidx = tb[pidx - 1]

        # 값이 일치하는 경우, pidx 1 증가시키고 그 값을 tb에 저장
        if pattern[idx] == pattern[pidx]:
            pidx += 1
            tb[idx] = pidx

    return tb


print(L - KMP_table(show)[-1])
