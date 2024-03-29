# 두개의 문자열 A와 B가 주어졌을 때, 문자열 A를 편집해서 B를 만들려고 한다
# 다음 3가지 연산으로 변형. 연산의 최소 횟수를 구하시오
'''
1. 삽입 - 특정한 위치에 하나의 문자 삽입
2. 삭제 - 특정한 위치에 하나의 문자 삭제
3. 교체 - 특정한 위치에 하나의 문자를 다른 문자로 교체
'''

''' 점화식
1. 문자가 같을 때: dp[i][j] = dp[i - 1][j - 1]
=> 행과 열의 문자가 같다면 왼쪽 위의 수 그대로 대입

2. 문자가 다를 때: dp[i][j] = 1 + min(dp[i][j - 1], dp[i - 1][j], dp[i - 1][j - 1])
=> 행과 열의 문자가 다르다면, 왼쪽(삽입), 위쪽(삭제), 왼쪽 위(교체) 중 더 작은수에 1을 더해서 대입
'''


# 최소 편집 거리(Edit Distance) 계산을 위한 다이나믹 프로그래밍
# 스트링 편집 거리(string edit distance) 알고리즘: 두 문자열의 유사도를 측정하기 위해 사용되는 알고리즘으로 Levenshtein distance(LD)라고도 함
def edit_dist(str1, str2):
    n = len(str1)
    m = len(str2)

    # 다이나믹 프로그래밍을 위한 2차원 DP 테이블 초기화
    dp = [[0] * (m + 1) for _ in range(n + 1)]

    # DP 테이블 초기 설정
    for i in range(1, n + 1):
        dp[i][0] = i
    for j in range(1, m + 1):
        dp[0][j] = j

    # 최소 편집 거리 계산
    for i in range(1, n + 1):
        for j in range(1, m + 1):
            # 문자가 같다면, 왼쪽 위에 해당하는 수를 그대로 대입
            if str1[i - 1] == str2[j - 1]:
                dp[i][j] = dp[i - 1][j - 1]
            # 문자가 다르다면, 세 가지 경우 중에서 최솟값 찾기
            else:  # 삽입(왼쪽), 삭제(위쪽), 교체(왼쪽 위) 중에서 최소 비용을 찾아 대입
                dp[i][j] = 1 + min(dp[i][j - 1], dp[i - 1]
                                   [j], dp[i - 1][j - 1])

    return dp[n][m]


# 두 문자열을 입력 받기
str1 = input()
str2 = input()

# 최소 편집 거리 출력
print(edit_dist(str1, str2))
