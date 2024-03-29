# 목차

[소수의 판별](#-소수의-판별)

[투 포인터](#-투-포인터)

[구간 합](#-구간합-계산)

[순열과 조합](#-순열과-조합)

[비트마스크](#-비트마스크)

<br><br>
<br><br>

# 🩻 소수의 판별

> 소수란 2보다 큰 자연수 중에서 1과 자기자신을 제외한 자연수로는 나누어 떨어지지 않는 자연수 (단 1은 제외)

<br><br>

## 하나의 수가 소수인지 판별(개선 코드) - O(X^1/2)

```python
   import math

   # 소수 판별 함수
   def is_prime_number(x):
       # 2부터 x의 제곱근까지의 모든 수를 확인하며
       for i in range(2, int(math.sqrt(x)) + 1):
           # x가 해당 수로 나누어떨어진다면
           if x % i == 0:
               return False # 소수가 아님
       return True # 소수임

   print(is_prime_number(4)) # 4는 소수가 아님
   print(is_prime_number(7)) # 7은 소수임
```

1. 2부터 X-1까지 모두 나누어보면서 확인하는 것은 비효율적임
2. 가운데 약수(X^1/2)를 기준으로 대칭적으로 2개씩 앞뒤로 묶어서 곱하면 해당 수가 만들어짐 = 대칭적 형태

<br><br>

## 여러 개의 수가 소수인지 판별 => **에라토스테네스의 체**

```python
import math

n = 1000 # 2부터 1,000까지의 모든 수에 대하여 소수 판별
array = [True for i in range(n + 1)] # 처음엔 모든 수가 소수(True)인 것으로 초기화

# 에라토스테네스의 체 알고리즘
for i in range(2, int(math.sqrt(n)) + 1): # 2부터 n의 제곱근까지의 모든 수를 확인하며
    if array[i] == True: # i가 소수인 경우 (남은 수인 경우)
        # i를 제외한 i의 모든 배수를 지우기
        j = 2
        while i * j <= n:
            array[i * j] = False
            j += 1

# 모든 소수 출력
for i in range(2, n + 1):
    if array[i]:
        print(i, end=' ')
```

1.  과정

        a) 2부터 N까지의 모든 자연수를 나열한다 (1은 예외 처리)
        b) 남은 수 중에서 아직 처리하지 않은 가장 작은 수 i를 찾는다
        c) 남은 수 중에서 i의 배수를 모두 제거 - i는 제거 x
        d) 더 이상 반복할 수 없을 때까지 b~c 과정 반복, 단 i는 N의 제곱근까지만 증가

2.  **시간복잡도**:
    - O(NloglogN) - 사실상 선형 시간.
3.  **공간복잡도**:
    - 빠른 대신 메모리가 많이 필요하다는 단점.
    - N의 크기만큼의 리스트 할당이 필요
4.  **결론**:
    - N이 1,000,000 이내로 주어지는 경우에 사용
    - 이론상 400만번 정도의 연산 & 충분한 메모리

<br><br>
<br><br>

# 🐾 투 포인터

> 리스트에 순차적으로 접근해야 할 때 2개의 점의 위치를 기록하면서 처리하는 알고리즘

> 구현 가능한 방식이 매우 많다는 특징이 있음

<br><br>

## 특정한 합을 가지는 부분 연속 수열 찾기

1.  양의 정수로만 구성된 리스트가 주어졌을 때, 특정한 합(M)을 갖는 부분 연속 수열의 개수를 출력
2.  과정

        a) 시작점과 끝점이 첫번째 원소의 인덱스를 가리키도록 함
        b) 현재 부분합이 M과 같다면 카운트
        c) 현재 부분합이 M보다 작으면 end += 1
        d) 현재 부분합이 M보다 크거나 같으면 start += 1
        e) 모든 경우를 확인할 때까지 b-d 반복

3.  시작점을 오른쪽으로 이동시키면 항상 합이 감소하고, 끝점을 오른쪽으로 이동하면 항상 합이 증가하므로 투포인터 알고리즘에 적합한 문제 -> 만약 **음수 데이터**가 포함된 경우 사용 불가
4.  코드

    ```python
    n = 5 # 데이터의 개수 N
    m = 5 # 찾고자 하는 부분합 M
    data = [1, 2, 3, 2, 5] # 전체 수열

    count = 0
    interval_sum = 0
    end = 0

    # start를 차례대로 증가시키며 반복
    for start in range(n):
        # end를 가능한 만큼 이동시키기
        while interval_sum < m and end < n:
            interval_sum += data[end]
            end += 1
        # 부분합이 m일 때 카운트 증가
        if interval_sum == m:
            count += 1
        interval_sum -= data[start]

    print(count)
    ```

<br><br>

## 정렬되어 있는 두 리스트의 합집합

1.  이미 정렬된 2개의 리스트가 주어짐
2.  두 리스트의 모든 원소를 합해서 정렬한 결과를 계산하는 문제
3.  해당 알고리즘은 병합 정렬과 같은 일부 알고리즘에서 사용되고 있음
4.  과정

        a) 정렬된 리스트 A,B를 받는다
        b) 리스트 A에서 처리되지 않은 원소 중 가장 작은 원소 i를 가리킴
        c) 리스트 A에서 처리되지 않은 원소 중 가장 작은 원소 i를 가리킴
        d) A[i]와 B[j] 중에서 더 작은 원소를 결과 리스트에 담는다
        e) 리스트 A,B에서 더 이상 처리할 원소가 없을 때까지 b-d 반복

5.  코드 - 시간복잡도 O(N+M) (N,M은 각 리스트의 원소 개수)

    ```python
    # 사전에 정렬된 리스트 A와 B 선언
    n, m = 3, 4
    a = [1, 3, 5]
    b = [2, 4, 6, 8]

    # 리스트 A와 B의 모든 원소를 담을 수 있는 크기의 결과 리스트 초기화
    result = [0] * (n + m)
    i = 0
    j = 0
    k = 0

    # 모든 원소가 결과 리스트에 담길 때까지 반복
    while i < n or j < m:
        # 리스트 B의 모든 원소가 처리되었거나, 리스트 A의 원소가 더 작을 때
        if j >= m or (i < n and a[i] <= b[j]):
            # 리스트 A의 원소를 결과 리스트로 옮기기
            result[k] = a[i]
            i += 1
        # 리스트 A의 모든 원소가 처리되었거나, 리스트 B의 원소가 더 작을 때
        else:
            # 리스트 B의 원소를 결과 리스트로 옮기기
            result[k] = b[j]
            j += 1
        k += 1

    # 결과 리스트 출력
    for i in result:
        print(i, end=' ')
    ```

<br><br>
<br><br>

# 🧮 구간합 계산

1. **여러개의 쿼리**(구간)로 구성되는 문제 형태로 출제됨
2. 매 쿼리마다 계산시 O(NM) (N은 수의 개수, M은 쿼리 개수)
3. **접두사 합**: 리스트의 맨 앞부터 특정 위치까지의 합을 구해놓은 것

<br>

## Prefix Sum (접두사 합)

1. N개의 수에 대해 접두사 합을 계산해서 배열 P에 저장
2. 매 M개의 쿼리 정보 [L,R] -> **구간합 = P[R] - P[L-1]**
3. 코드 - 매 쿼리 O(1) -> 전체 시간복잡도 O(N+M)

   ```python
   # 데이터의 개수 N과 전체 데이터 선언
   n = 5
   data = [10, 20, 30, 40, 50]

   # 접두사 합(Prefix Sum) 배열 계산
   sum_value = 0
   prefix_sum = [0]
   for i in data:
       sum_value += i
       prefix_sum.append(sum_value)

   # 구간 합 계산 (세 번째 수부터 네 번째 수까지)
   left = 3
   right = 4
   print(prefix_sum[right] - prefix_sum[left - 1])
   ```

<br><br>
<br><br>

# 🫵 순열과 조합

> 파이썬 기본 라이브러리 사용

<br><br>

# 💡 비트마스크

> 집합의 요소들의 구성 여부를 표현할 때 유용한 테크닉

## 사용목적

- DP나 순열 등, 배열 활용만으로 해결할 수 없는 문제
- 작은 메모리와 빠른 수행시간으로 해결이 가능 (But, 원소의 수가 많지 않아야 함)
- 집합을 배열의 인덱스로 표현할 수 있음
- 코드가 간결해짐

## 비트마스킹 활용

- 집합에서 i번째 요소가 존재하면 1, 그렇지 않으면 0을 의미하는 것

## 삽입

- 현재 이진수로 10101로 표현되고 있을 때, i번째 비트 값을 1로 변경하려고 함
- i = 3일 때 변경 후에는 11101이 나와야 한다. 이때는 OR연산을 활용
- 10101 | 1 << 3
- 1 << 3은 1000이므로 10101 | 01000이 되어 11101을 만들 수 있다.

## 삭제

- 반대로 0으로 변경하려면, AND연산과 NOT 연산을 활용한다.
- 11101 & ~1 << 3
- ~1 << 3은 10111이므로, 11101 & 10111이 되어 10101을 만들 수 있다.

## 조회

- i번째 비트가 무슨 값인지 알려면, AND연산을 활용한다.
- 10101 & 1 << i
- 3번째 비트 값 : 10101 & (1 << 3) = 10101 & 01000 → 0
- 4번째 비트 값 : 10101 & (1 << 4) = 10101 & 10000 → 10000

<br><br>
