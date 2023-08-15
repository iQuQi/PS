'''[못품]
버블 소트 알고리즘을 다음과 같이 C++로 작성했다.

bool changed = false;
for (int i=1; i<=N+1; i++) {
    changed = false;
    for (int j=1; j<=N-i; j++) {
        if (A[j] > A[j+1]) {
            changed = true;
            swap(A[j], A[j+1]);
        }
    }
    if (changed == false) {
        cout << i << '\n';
        break;
    }
}
위 소스에서 N은 배열의 크기이고, A는 정렬해야 하는 배열이다. 배열은 A[1]부터 사용한다.

위와 같은 소스를 실행시켰을 때, 어떤 값이 출력되는지 구해보자.
'''

# 아이디어:
# 정렬 전의 요소들의 인덱스 값과, 정렬 후의 요소들의 인덱스 값을 비교해본다면,
# 버블정렬시에 몇단계를 거쳤는지 알 수 있음

# 뺀값이 음수인경우는 뒤로 이동, 양수인 경우는 앞으로 이동한 칸 수
# 최대값이 버블정렬이 몇회차까지 필요한지를 나타냄 (위 코드의 경우는 여기에 +1 해준게 최대값)
# 즉 앞으로 몇번 이동해야하는지가 답이라는 것임

'''
[풀이] https://steady-coding.tistory.com/41
{10, 1, 5, 2, 3} => {1 2 3 5 10}

1은 +1칸, 2는 +2칸, 3은 +2칸, 5는 -1칸, 10은 -4칸입니다.
이동한 횟수 자체는 10이 더 많은데 왜 2를 고르는 것인가요?

위에서 버블 소트를 실행한 과정을 보면 해답을 찾을 수 있습니다.
앞쪽으로 이동하는 요소는 1턴에 1칸이 최대인데, 
뒤쪽으로 이동하는 요소는 1턴에 얼마든지 이동할 수 있습니다. 
... 오답이유: 오른쪽으로 가는게 양수라고 생각했음
'''


import sys
input = sys.stdin.readline

n = int(input())
arr = []
for i in range(n):
    arr.append((int(input()), i))

sorted_arr = sorted(arr)
answer = []

for i in range(n):
    # 원래 인덱스 - 이동 후 인덱스
    # (sorted_arr[i][1] - i)로 해도될듯
    answer.append(sorted_arr[i][1] - arr[i][1])

print(max(answer) + 1)
