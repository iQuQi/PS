# 📝 다이나믹 프로그래밍(DP) 
> 메모리 공간을 더 사용해서 연산 속도를 비약적으로 증가시키는 방법

<br>

## DP (동적계획법)
1. 중복을 줄이는 것이 핵심
2. **2가지 조건**을 만족할 때 사용 가능
- 큰 문제를 작은 문제로 나눌 수 있다
- 작은 문제에서 구한 정답은 그것을 포함하는 큰 문제에서도 동일하다
3. **메모이제이션** (Memoization) = **캐싱** (Caching)
4. **점화식**으로 표현되면 DP 사용 가능



<br><br>

## 대표적인 DP 예시 - 피보나치 수열
1. 피보나치 수열의 점화식 => **An = An-1 + An-2, A1 = 1, A2 = 1**
2. n이 커질 수록 반복되어 계산되는 양이 기하급수적으로 늘어난다
3. 재귀함수 구현 시 **O(2^n)**
    ```python
    # 피보나치 함수(Fibonacci Function)을 재귀함수로 구현
    def fibo(x):
        if x == 1 or x == 2:
            return 1
        return fibo(x - 1) + fibo(x - 2)
    ```
4. But! DP 이용 시 **O(N)** (아래 코드 참조)

<br><br>


## Top-Down & Bottom-Up 방식
1. 재귀 함수를 이용해서 DP -> 큰 문제를 해결하기 위해 작은 문제 호출 = 탑다운
   ```python
    # 피보나치 함수(Fibonacci Function)을 재귀함수로 구현
    # 한 번 계산된 결과를 메모이제이션(Memoization)하기 위한 리스트 초기화
    d = [0] * 100

    # 피보나치 함수(Fibonacci Function)를 재귀함수로 구현 (탑다운 다이나믹 프로그래밍)
    def fibo(x):
        # 종료 조건(1 혹은 2일 때 1을 반환)
        if x == 1 or x == 2:
            return 1
        # 이미 계산한 적 있는 문제라면 그대로 반환
        if d[x] != 0:
            return d[x]
        # 아직 계산하지 않은 문제라면 점화식에 따라서 피보나치 결과 반환
        d[x] = fibo(x - 1) + fibo(x - 2)
        return d[x]
    ```
2. 반복문을 이용해서 DP -> 작은 문제부터 차근차근 해결 = 보텀업
   ```python
    # 앞서 계산된 결과를 저장하기 위한 DP 테이블 초기화
    d = [0] * 100

    # 첫 번째 피보나치 수와 두 번째 피보나치 수는 1
    d[1] = 1
    d[2] = 1
    n = 99

    # 피보나치 함수(Fibonacci Function) 반복문으로 구현(보텀업 다이나믹 프로그래밍)
    for i in range(3, n + 1):
        d[i] = d[i - 1] + d[i - 2]
    ```
3. DP의 전형적인 형태는 **보텀업 방식**임 - 이때 사용되는 저장용 리스트가 DP테이블
4. 메모이제이션은 **탑다운 방식**에 국한되어 사용되는 표현
- Memoization != DP
- Memoization = 이전에 계산된 결과를 일시적으로 기록해놓는 넓은 개념

<br><br>

## 실전
1. 메모이제이션은 때에 따라 사전 자료형 사용 - 수열처럼 연속적이지 않은 경우 
    ```python
    dic = {0:0, 1:1}
    def fibonacci(n):
        if n in dic: return dic[n]
        dic[n] = fibonacci(n-1) + fibonacci(n-2)
        return dic[n]
    ```
2. 일반적으로는 간단한 형태로 출제되나, 3차원 리스트를 이용해야하는 고난도 문제(플로이드 워셜 파트에서 다룸)가 출제될 수 있음
3. 문제 푸는 과정
- 주어진 문제가 DP 인가? -> **완전탐색으로 시간이 오래걸린다면 중복 여부 확인** & 점화식으로 표현 가능?
- 일단 단순히 재귀함수(탑다운)로 비효율적인 코드를 적고 메모이제이션 적용이 가능한지 확인 후 개선
- 다만, 가능하다면 **재귀함수보다 반복문 형태를 더 권장** -> 스택 오버플로우 때문
- Tip🍯) sys 라이브러리의 setrecursionlimit()로 재귀 제한 완화 가능

<br><br>

## 🎒 Knapsack (대표적인 DP 문제)
0. 예제
    ```
    도둑이 보석가게에 배낭을 메고 침입했다.
    배낭의 최대 용량은 W이며, 이를 초과해서 보석을 담으면 배낭이 찢어질 것이다.
    각 보석들의 무게와 가격은 알고 있다.
    배낭이 찢어지지 않는 선에서 가격 합이 최대가 되도록 보석을 담는 방법은?
    ```
1. 보석을 자를 수 있다고 가정하는 Fractional Knapsack 문제 => Greedy
2. 자를 수 없다고 가정하는 0-1 Knapsack 문제 => DP
3. 점화식
    ```
    B[k][W] = B[k-1][W] (if wk > W)
            = max(B[k-1][W], B[k-1][W-wk] + wk) (else)

    # B[i, w]: 물건 1~i까지만 고려하고, (임시) 배낭 용량이 w일 때의 최대 가치
    ```
4. 구현 의사코드
    ```
    // 배낭의 용량이 0일 때, 어떤 물건도 담을 수 없으므로 가치 = 0
    for i = 0 to n: K[i, 0] = 0

    // 물건이 0이라는 건 어떤 물건도 배낭에 담으려고 고려하지 않았을 때를 의미함.
    for w = 0 to C: K[0, w] = 0 

    for i = 1 to n: // 물건 1~n
        for w = 1 to C: // 배낭의 임시 용량 1~C
            if(wi > w): // 물건 i의 무게가 배낭의 임시 용량을 초과하면
        		K[i, w] = K[i - 1, w] // 물건 i-1 까지만 담는다.
        	else: // wi <= w
                // 현재 보석을 담지 않기 
                // 현재 보석을 담기 = 현재 보석 무게를 뺀 것 만큼을 채우는 최대 가치 + 현재 보석 가치
                // 위 두가지 중 더 가치가 큰 쪽을 택한다
        		K[i, w] = max{K[i - 1, w], K[i - 1, w - wi] + vi}

    return K[n, C] // 최적해 리턴
    ```

<br><br>

## 〽️ 최장 증가 부분 수열(LIS) (대표적인 DP 문제)
1. 임의의 수열이 주어지고 수열에서 몇 개의 수를 제거하여 부분 수열을 만들 수 있을 때, 가장 긴 수열을 구하는 문제
2. 최장 '감소' 부분 수열 문제의 경우 arr.reverse()
3. 단순한 DP 풀이 - O(N^2)
    ```python
    # 수열의 크기
    n = int(input())  
    # 수열 A를 이루고 있는 A(i)를 담은 배열
    arr = list(map(int, input().split())) 
    # dp[i] = arr[i]를 마지막 원소로 가질 때 가장 긴 증가하는 부분 수열의 길이
    dp = [1] * n

    for i in range(n):
        for j in range(i):
            if arr[i] > arr[j]:
                dp[i] = max(dp[i], dp[j]+1)

    print(max(dp))
    ```
4. 이진 탐색 활용 - O(NlogN) => DP로만 풀면 시간 초과가 날 때가 있음
    ```python
    from bisect import bisect_left

    n = int(input())
    arr = list(map(int, input().split()))
    # 최장 증가 부분 수열 저장
    dp = [arr[0]]

    for i in range(n):
        if arr[i] > dp[-1]:
            dp.append(arr[i])
        else:
            idx = bisect_left(dp, arr[i])
            dp[idx] = arr[i]

    print(len(dp))
    # 이때 DP는 실제 최장 증가 부분 수열이 아님. 길이만 같을뿐!
    ```