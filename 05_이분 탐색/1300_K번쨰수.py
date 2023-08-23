'''
세준이는 크기가 N×N인 배열 A를 만들었다. 
배열에 들어있는 수 A[i][j] = i×j 이다. 
이 수를 일차원 배열 B에 넣으면 B의 크기는 N×N이 된다. 
B를 오름차순 정렬했을 때, B[k]를 구해보자.

배열 A와 B의 인덱스는 1부터 시작한다
'''

'''
[풀이]
이분 탐색으로 어떤 수보다 작은 자연수의 곱(i * j)이 몇 개인지 알아내기
A보다 작은 숫자가 몇개인지 찾아내면 A가 몇 번째 숫자인지 알 수 있다.

예를 들어 10 * 10에서 20보다 작거나 같은 수를 생각해보자.
1*1~1*10
2*1~2*10
3*1~3*6
...
10*1~10*2

위 수가 존재할텐데, 이는 반대로 생각해보면 20을 행으로 나눈 몫이다.

20//1: 10개 --> 단 열의 숫자(N*N배열이므로)를 초과할 수 없다.
20//2: 10개
20//3: 6개
'''
import sys
input = sys.stdin.readline

N, K = int(input()), int(input())
start, end = 1, K

while start <= end:
    mid = (start + end) // 2

    temp = 0
    for i in range(1, N+1):  # 1~N
        temp += min(mid//i, N)

    if temp >= K:  # 이분탐색 실행
        answer = mid
        end = mid - 1
    else:
        start = mid + 1

print(answer)
