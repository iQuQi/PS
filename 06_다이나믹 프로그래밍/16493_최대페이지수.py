'''
철수는 한양대학교 도서관에서 책을 빌려놓고 까먹고 있다가 며칠 후 책을 반납해야 한다는 사실을 깨달았다. 
남은 기간 동안 최대한 많은 페이지를 읽고 연체없이 반납하고 싶다.

빌린 책은 여러 챕터로 구성된 에세이집인데 챕터들은 서로 독립적이다. 
즉, 어느 챕터를 읽기 위해 다른 챕터를 먼저 읽어야 할 필요가 없다. 
철수는 중간에 관두는 것을 못견디는 성격이라, 한 챕터를 읽기 시작하면 끝까지 봐야한다. 

남은 기간 N일과, 책의 각 챕터 당 그 챕터를 전부 읽는데 소요되는 일 수와 페이지 수가 주어질 때, 
N일간 읽을 수 있는 최대 페이지 수를 구하는 프로그램을 작성하라.
'''

# 냅색 문제
import sys
input = sys.stdin.readline


n, m = map(int, input().split())  # 1 ~ 200, 1~20
info = [(-1, -1)]
dp = [[0] * (n+1) for _ in range(m+1)]

for i in range(m):
    day, page = map(int, input().split())  # 1 ~ 20, 1~300
    info.append((day, page))


# N일간 읽을 수 있는 최대 페이지 출력
# B[k][W] = B[k-1][W] (if wk > W)
#        = max(B[k-1][W], B[k][W-wk] + wk) (else)

for c in range(1, m+1):  # 1~c까지의 챕터만 고려
    for d in range(1, n+1):  # 남은 일수 d
        nd, np = info[c]
        if nd > d:
            dp[c][d] = dp[c-1][d]
        else:
            dp[c][d] = max(dp[c-1][d], dp[c-1][d-nd]+np)


print(dp[m][n])
