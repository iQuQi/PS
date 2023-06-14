'''
LCS(Longest Common Subsequence, 최장 공통 부분 수열)문제는 
두 수열이 주어졌을 때, 모두의 부분 수열이 되는 수열 중 가장 긴 것을 찾는 문제이다.

예를 들어, ACAYKP와 CAPCAK의 LCS는 ACAK가 된다.

첫째 줄과 둘째 줄에 두 문자열이 주어진다. 
문자열은 알파벳 대문자로만 이루어져 있으며, 최대 1000글자로 이루어져 있다.

입력으로 주어진 두 문자열의 LCS의 길이를 출력하기
'''

# 못품..
# i는 고정된 채로 j를 늘려가며 비교하는 경우 같은 글자가 나오면 무조건 +1을 하고 
# 아니라면 dp[i-1][j]와 dp[i][j-1] 중 큰 수로 정하기
S1 = list(input())
S2 = list(input())
len1 = len(S1)
len2 = len(S2)

dp = [[0]*(len2 + 1) for _ in range(len1+1)]

for i in range(1,len1 + 1) :
    for j in range(1,len2 + 1) :
        if S1[i-1] == S2[j-1] :
            dp[i][j] = dp[i-1][j-1] + 1
        else :
            dp[i][j] = max(dp[i-1][j],dp[i][j-1])


print(dp[len1][len2])