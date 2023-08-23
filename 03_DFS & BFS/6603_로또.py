'''
독일 로또는 {1, 2, ..., 49}에서 수 6개를 고른다.

로또 번호를 선택하는데 사용되는 가장 유명한 전략은 49가지 수 중 k(k>6)개의 수를 골라 
집합 S를 만든 다음 그 수만 가지고 번호를 선택하는 것이다.

예를 들어, k=8, S={1,2,3,5,8,13,21,34}인 경우 
이 집합 S에서 수를 고를 수 있는 경우의 수는 총 28가지이다. 
([1,2,3,5,8,13], [1,2,3,5,8,21], [1,2,3,5,8,34], [1,2,3,5,13,21], ..., [3,5,8,13,21,34])

집합 S와 k가 주어졌을 때, 수를 고르는 모든 방법을 구하는 프로그램을 작성하시오.
'''

# 백트래킹 문제 -> 조합으로 풀면 쉽게 풀리는 문제긴 함


def backtracking(arr, depth, select, k):
    if len(select) == 6:
        print(' '.join(list(map(str, select))))
        return
    if depth >= len(arr):
        return

    for t in range(1, -1, -1):
        if t == 1:
            backtracking(arr, depth+1, select + [arr[depth]], k)
        else:
            backtracking(arr, depth+1, select, k)


while True:
    num = list(map(int, input().split()))
    k = num[0]

    if k == 0:
        break
    S = num[1:]

    backtracking(S, 0, [], k)
    print()
