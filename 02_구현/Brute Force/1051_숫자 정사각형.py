'''_
N×M크기의 직사각형이 있다. 각 칸에는 한 자리 숫자가 적혀 있다. 
이 직사각형에서 꼭짓점에 쓰여 있는 수가 모두 같은 가장 큰 정사각형을 찾는 프로그램을 작성하시오. 
이때, 정사각형은 행 또는 열에 평행해야 한다.
'''

n, m = map(int, input().split())

arr = []
'''
42101
22100
22101
'''
# 위처럼 공백없이 입력될 때 다음과 같이 받기
for i in range(n):
    arr.append(list(input()))

check = min(n, m)
answer = 0
# 정사각형 너비를 1부터 늘려가면서 완전 탐색
for i in range(n):
    for j in range(m):
        for k in range(check):
            # 파이썬은 == == == 연산 계속 가능...!
            if ((i + k) < n) and ((j + k) < m) and (arr[i][j] == arr[i][j + k] == arr[i + k][j] == arr[i + k][j + k]):
                answer = max(answer, (k + 1)**2)
                
print(answer)