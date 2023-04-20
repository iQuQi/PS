# 파이썬 문법정리

## 🗂️ 목차

[자료형]

- [수](#1️⃣-수-자료형)
- [리스트](#2️⃣-리스트-자료형)
- [문자열](#3️⃣-문자열-자료형)
- [튜플](#4️⃣-튜플-자료형)
- [사전](#5️⃣-사전-자료형)
- [집합](#6️⃣-집합-자료형)

[조건문, 반복문과 함수]

- [조건문](#1️⃣-조건문)
- [반복문](#2️⃣-반복문)
- [함수](#3️⃣-함수)

[입출력]

- [입력](#1️⃣-입력)
- [출력](#2️⃣-출력)

[주요 표준 라이브러리]

- [내장 함수](#1️⃣-내장-함수)
- [itertools](#2️⃣-itertools)
- [heapq](#3️⃣-heapq)
- [bisect](#4️⃣-bisect)
- [collections](#5️⃣-collections)
- [math](#6️⃣-math)

<br/><br/>

## 🔍 자료형

### 1️⃣ 수 자료형

1. **정수형** : 양수, 정수, 0
2. **실수형** 
  - 소수부나 정수부가 0일 때 생략 가능 ex) .7, -5.
  - e(E) 표기법:
      - 유효숫자e^(지수) = 유효숫자 x 10^(지수) ⇒ 자릿수 실수를 할 확률을 줄임
      - 무한(INF)를 1e9(10억)로 표현하기도 함
  - round(실수, 반올림할 위치 - 1):
      - round가 필요한 이유? - 보통 소수점 다섯번째 자리에서 반올림한 결과가 같으면 정답으로 인정
            
        ```python
        a = 0.3 + 0.6
        print(a)
        ====
        0.899999999....  #2진수로 0.9를 정확히 표현할 방법이 없음
        ```
            
      - round VS print(’%.f’, %_)
          - round(1.4736, 2) ⇒ 1.5 (0은 생략 됨)
          - print(’%.2f’,  %실수변수)에 1.4736을 넣으면? ⇒ 1.50
3. **연산** 
  - 코드를 짤 때 0은 항상 예외적으로 검사하기
  - 파이썬3에서 정수/정수는 실제 값이 정수라도 실수로 나옴 ex) 4/2 = 2.0

    종류 | 예시 
    |---|------|
    일반 연산자| +, -, *,  /(일반적인 나누기), //(몫), %(나머지), **(거듭제곱)
    쉬프트 연산자| << N (2^N배), >> N ((1/2)^N배)
    비트단위 연산자| ~(not), &(and), \|(or), ^(nor)
4. C언어와 동일하게 음수의 몫 구하기: int(a/b)

<br/>

### 2️⃣ 리스트 자료형

1. **소개**
  - 연결 리스트 자료 구조 기능 포함 → append(), remove() 등의 메서드 지원
  - C++ STL vector와 유사
2. **리스트 생성**
  - list() or []
  - **1차원 배열 초기화**: arr = [0] * N
  - **2차원 배열 초기화**: arr = [[0] * N for _ in range(M)]
3. **인덱싱과 슬라이싱**
  - 인덱스는 음,양의 정수 모두 가능.
  - 음의 정수의 경우 거꾸로 탐색
  - arr[a:b(:step)] ⇒ a부터 b-1 까지 가져오기. step은 옵션 & **음수로 넣으면 뒤에서부터 가져오기**
  
4. **리스트 컴프리헨션 (예시)**
  - array = [i for i in range(20) if i % 2 == 1]  ⇒ 0~19까지의 수 중 홀수만 포함하는 리스트 생성
  - array = [i * i for i in range(1,10)]  ⇒ 1~9까지의 수의 제곱 값을 포함하는 리스트
  - 2차원 배열 초기화 방법도 여기에 해당
  - 2차원 배열 flatten
    ```python
    # 2차원 -> 1차원
    flatten_arr = [y for x in arr for y in x]
    ```
5. **활용**

    사용법 | 설명 | 시간 복잡도
    |---|------|---|
    append(값)| 맨 뒤에 원소 하나 삽입|O(1)
    extend(값)| 리스트 연장| - |
    pop(index)|해당 인덱스에 원소 제거. 기본값은 -1|O(1)
    sort()|오름차순 정렬. reverse = True 인자를 넣어주면 내림차순 정렬 & key 인자로 정렬 함수 넣어주기 가능 | O(NlogN)
    reverse()|원소의 순서를 모두 뒤집기|O(N)
    insert(삽입할 인덱스, 값)|특정위치에 원소 삽입 |O(N)
    count(값)|특정 값을 가지는 데이터 개수 세기 |O(N)
    remove(값)|특정 값을 가지는 원소 제거. 여러개가 있으면 하나만 제거한다.  그 값이 없다면 에러 발생(in 으로 선확인 필요) |O(N)
    x in array| 리스트에 특정한 값이 있는지 검사| O(N)
6. **추가**
- 특정 원소를 모두 제거하는 메소드는 없음. 대신 아래와 같은 방식 사용
    ```python
    a = [1,2,3,4,5,6]
    remove_set = {3,4}
    result = [i for i in a if i not in remove_set]
    ```
- 리스트 중복 제거 => set()
7. 2차원 배열 예외
    ```python
    # 복사 방법1. deepcopy() -> 코딩 테스트에서는 사용 불가...인줄 알았는데 아닌가봄
    import copy
    a = [[1,2],[3,4]]
    b = copy.deepcopy(a)
    
    # 복사 방법2. 새로운 배열 생성 
    a = [[1, 2], [3, 4]]
    b = [arr[:] for arr in a]
    ```
    ```python
    # count()
    test=[0,0,0]
    test2 = [[0,0,0]]
    print(test.count(0), test2.count(0))
    =======
    3 0
    ```
    ```python
    # 중복제거 - tuple로 묶어준 후 set() 
    # ex) 동일한 (x,y) 점이 들어가지 않도록 하기
    a = []
    a.append((element1, element2)) # ...반복
    a = set(a)
    ```
    ```python
    # 2차원 배열 정렬 -> key 넣어주기
    a = [(1, 2), (0, 1), (5, 2), (5, 1), (3, 0)]

    sorted(a) # 디폴트 - 0인덱스 먼저 그다음 1인덱스...
    [(0, 1), (1, 2), (3, 0), (5, 1), (5, 2)]

    sorted(a, key=lambda x: x[0]) # 0 인덱스에 대해서만 정렬, 1인덱스 정렬 x
    [(0, 1), (1, 2), (3, 0), (5, 2), (5, 1)]
    ```

<br/>

### 3️⃣ 문자열 자료형

1. **초기화**
- ""나 '' 사용. 큰 따옴표로 구성하는 경우 내부적으로 작은 따옴표 사용 가능(반대도 마찬가지)
- 백슬래시(\)를 사용하면 큰 따옴표나 작은 따옴표를 원하는 만큼 포함시킬 수 있음 
2. **연산**
- 덧셈: 'a' + 'b' = 'ab'
- 곱셈: 'a' * 3 = 'aaa'
- 내부적으로 리스트와 같이 처리되므로 **인덱싱과 슬라이싱**이 가능하다
3. 문자열을 일정 길이로 자르기
    ```python
    length = N 
    # range의 3번째 인자는 step 
    [arr[i:i + length] for i in range(0, len(arr), length)]
    ```
4. 관련 함수
    사용법 | 설명 
    |---|---------|
    replace(target, wanted, [count])|특정 문자를 원하는 문자로 교체, count 미입력시 전체 변환 |
    'A'.join(B)|B는 문자열 혹은 문자 배열. A를 원소 사이에 넣어 합친 후 문자열로 반환.  주로 공백을 넣고 싶을 때 사용 |
    isdigit()| 어떤 문자열이 숫자의 형태면 True를 반환
    isdecimal()| 어떤 문자열이 int형으로 변환이 가능하면 True를 반환
    isalpha()| 주어진 문자열이 알파벳으로만 구성되어 있는지 판별한다. 공백이 있으면 False를 반환
    isalnum()| 주어진 문자열이 알파벳+숫자로만 구성되어 있는지 판별. 공백 시 False

<br/>

### 4️⃣ 튜플 자료형
> (원소1, 원소2)

1. 한 번 선언된 값은 **변경 불가능** 
- 우선 순위 큐 구현에 사용
- 변경하면 안되는 값을 변경하고 있지는 않은지 체크 가능
2. **소괄호(()) 사용**
3. 리스트에 비해 상대적으로 **공간이 효율적**
4. 일반적으로 각 원소의 **성질이 다를 때** 사용. 예시) 다익스트라 알고리즘 - (비용, 노드 번호)

<br/>

### 5️⃣ 사전 자료형
> {key1: value1, key2: value2}
1. **키(key)와 값(value)의 쌍**을 데이터로 가짐 => **순서 X**
2. {} 또는 dict()로 초기화
3. 내부적으로 해시 테이블을 사용하므로 검색 및 수정이 O(1) => 리스트보다 훨씬 빨리 동작함
4. 없는 키를 참조하게 될 경우 **에러** 
5. 활용
    사용법 | 설명
    |----|-----|
    원소 in 사전|특정 원소가 있는지 찾기
    keys()|키 데이터만 뽑아서 리스트로 반환
    values()|값 데이터만 뽑아서 리스트로 반환
    del dict[key]|dict에서 key에 해당하는 값 제거


<br/>

### 6️⃣ 집합 자료형
> {1, 2, 3, 4, 5} 또는 set([1, 2, 3, 4, 5])
1. **중복을 허용하지 않음**
2. 사전 자료형과 동일하게 **순서가 없음** = **인덱싱 불가능**
3. 마찬가지로 검색 및 수정이 O(1)
4. <b>set()</b>으로 초기화
5. 일반적으로 **특정한 데이터가 이미 등장한 적이 있는지 여부를 체크**할 때 사용
6. set(집합) 내부 원소
- mutable(변경 가능 - 리스트, 딕셔너리, 집합)한 값은 가질 수 없음
- 상수, 문자열, 튜플 등 immutable한 값은 가능함
7. **연산**: 합집합(|), 차집합(-), 교집합(&)
8. **활용**
    사용법 | 설명
    |---|----|
    add(x)|하나의 집합 데이터에 값을 추가
    update([x,y...])|여러 개의 값을 한꺼번에 추가
    remove(x)|특정한 값 제거. 없으면 오류 o
    discard(x)|특정한 값 제거. 없어도 오류 x
    x (not) in set|특정한 값이 있는지 (없는지) 검사

<br/><br/>

## 🚥 조건문, 반복문과 함수

### 1️⃣ 조건문

1. **if, elif, else로 분기문 작성.**
2. **비교 연산자:** == , !=, >, <, >=, <=
3. **논리 연산자:** and, or, not
4. **기타 연산자:** in, not in ⇒ 여러개의 데이터를 담는 자료형에 사용 가능
5. **조건부 표현식 (예시)**
    - result = ‘Success’ if score ≥ 80 else ‘Fail’
    - 조건문 중첩 가능
6. **부등식 계산**
    - 1 < x <  20 ⇒ (O)
    - 다른 언어와 달리 파이썬은 수학의 부등식을 그대로 사용 가능

<br/>

### 2️⃣ 반복문

1. **While문**
    
    ```python
    while i < 9: 
    	# 코드 
    ```
    
2. **For문**
    
    ```python
    for i in range(1,n): # 1~n-1
    	# 코드
    ```
    
3. **키워드**: break, continue, pass

<br/>

### 3️⃣ 함수

1. **사용법**
    
    ```python
    def 함수명(매개변수):
      # 실행 코드
      # 매개변수나 return 문은 필수 아님
      return 반환 값
    ```
    
2. **파라미터 지정 및 디폴트** 
    
    ```python
    def add(a = 0,b = 0): # 디폴트
      print(a,b)
        
    add(b=3, a=2) # 파라미터 지정, 이 경우 순서가 달라도 됨
    
    ```
    
3. **글로벌 키워드**: 함수 안에서 함수 밖의 변수 데이터를 변경하는 방법
        
    ```python
    a = 0
    
    def fun():
      global a # read만 할거면 global 키워드 없어도 됨
      a += 1
    
    ```
4. **람다 표현식** 
- 함수를 매우 간단하게 작성할 수 있음
- 파이썬 정렬 라이브러리를 사용할 때 정렬 기준(key)을 설정할 때도 자주 사용

    ```python
    # 일반적인 add 메서드
    def add(a,b)
      return a+b
    print(add(3,7))
     
    # 람다 표현식으로 구현한 add() 메서드
    print((lambda a,b: a+b)(3,7))
    ```
    
    
<br/><br/>

## 💬 입출력

### 1️⃣ 입력

1. **input()**
  - 한줄의 문자열 입력 (줄바꿈 단위) -> split()을 통해 공백 단위로 쪼개서 사용 가능
  - 문자열로 받기 때문에 자료형 변환이 필요
2. **사용법 공식** *** 필수 암기
  - list(map(int, input().split())) → int 대신 float, str 가능
  - 공백으로 구분된 데이터 개수가 많지 않다면 list() 없이 변수에 풀어서 받아도 됨
      - a, b, c = map(int, input().split())
      - split(':'): 구분자 지정 가능
3. **빠른 입력** ⇒ 매우 많은 수의 데이터를 입력 받아야 할 때 사용 *** 관행적으로 외워서 사용
    
    ```python
    import sys
    sys.stdin.readline().rstrip()
    # readline()으로 입력 시 엔터가 줄 바꿈 기호로 입력되는데,
    # 이 공백 문자를 제거하려면 반드시 rstrip() 함수가 필요

    # 일반적인 사용법 - int() 적용 시 개행문자까지 제거되서 rstrip 불필요
    input = sys.stdin.readline
    int(input())
    ```
4. **기타 함수**

    | 사용법 | 설명 |
    |----|------|
    ord()| 유니코드를 정수로 변경. ( A -> 65, a -> 97 ), ordinal을 의미
    chr()| 정수를 유니코드로 변경. ( 65 -> A, 97 -> a )
    bool()| 0 = False, 나머지는 True (*실제로 print(False == 0) -> True)


<br/>


### 2️⃣ 출력

1. **print()**
- 기본적으로 출력 후 줄바꿈 수행
2. 다양한 출력법

    사용법 | 설명
    |----|------|
    print(a,b)| 띄어쓰기로 구분하여 출력
    print(a+b)| print("a" + "b") => ab, 다만 문자열과 수를 더하게 될 경우 에러가 나므로 형변환 필요
    print(f"정답은 {answer}입니다")|python 3.6이상 부터 지원하는 f-string 문법
    print(a,b,sep='')|띄어쓰기 없이 출력
    print(a, end = '')|줄바꿈 없이 출력. 다시 줄바꿈을 해주고 싶을 때는 추가로 print() 사용
    print('%x %o' %(16진수변수, 8진수변수))|16,8진수로 출력. 대문자 사용 시 대문자로 출력
    print('%.2f' %실수변수)|print('%.2f' %1.235) => 1.24
    print('%08d' %정수)|print('%.05d' %21) => 00021, 0을 생략하면 공백으로 자리 채움

<br/><br/>

## ⭐️ 주요 표준 라이브러리 6가지

대부분의 코딩 테스트에서는 표준 라이브러리 사용을 허용한다.

추가로 필요한 기능은 찾아서 사용하도록 하자.

### 1️⃣ 내장 함수
> import 없이 사용. 없어서는 안될 필수적인 기능 포함

> 놀랍게도 avg 없음!

<br>

1. **sum()**: 모든 원소의 합을 반환
2. **min()/max()**: 2개이상의 파라미터를 받아서 그 중 최소/최대값을 반환
3. **eval()**: 수학 수식이 문자열 형식으로 들어오면 그 결과를 반환 
4. **sorted()**: 정렬된 결과 반환
- 문자열 정렬 가능 ex) sorted('zdefa') => ['a','d','e','f','z']
- key 속성으로 정렬 기준 명시 가능
  ```python
  # 튜플의 첫번째 인자로 오름차순 정렬 후 두번째 인자로 내림차순 하게 하려면 
  # x[1] 자리에 (x[0], -x[1]) 넣어주면 됨
  result = sorted([('홍길동', 35), ('이순신', 23), ('아무개', 40)], key = lambda x: x[1])
  print(result)
  =====
  [('이순신', 23), ('홍길동', 35), ('아무개', 40)]
  ```
- reverse 속성으로 오름차순/내림차순 설정. 기본적으로 오름차순

<br/>

### 2️⃣ itertools
> 반복되는 형태의 데이터 처리

<br>

1. **permutations**:
    ```python
    from itertools import permutations
    data = ['A','B','C']
    result = list(permutations(data, 3)) 
    print(result)
    =====
    [('A','B','C'),('A','C','B'),('B','A','C'),('B','C','A'),('C','A','B'),('C','B','A')]
    ```
2. **combinations**:
    ```python
    from itertools import combinations
    data = ['A','B','C']
    result = list(combinations(data, 2)) 
    print(result)
    =====
    [('A', 'B'), ('A', 'C'), ('B', 'C')]
    ```
3. **product**: 중복을 허용하는 순열
    ```python
    from itertools import product
    data = ['A','B','C']
    result = list(product(data, repeat=2)) 
    print(result)
    =====
    [('A', 'A'), ('A', 'B'), ('A', 'C'),('B', 'A'), ('B', 'B'), ('B', 'C'),('C', 'A'), ('C', 'B'), ('C', 'C')]
    ```
4. **combinations_with_replacement**: 중복을 허용하는 조합
    ```python
    from itertools import combinations_with_replacement
    data = ['A','B','C']
    result = list(combinations_with_replacement(data, 2)) 
    print(result)
    =====
    [('A', 'A'), ('A', 'B'), ('A', 'C'),('B', 'B'), ('B', 'C'), ('C', 'C')]
    ```
5. **2차원 배열의 경우**
    ```python
    # 이런식으로 새로운 튜플 배열을 만들어서 사용
    coords = [(x, y) for x in range(n) for y in range(m)]

    ```

<br/>

### 3️⃣ heapq
> (최소) 힙 제공. 우선순위 큐 기능 구현할 때 사용
1. 단순히 원소를 전부 넣어다가 빼는 것만으로 시간 복잡도 O(NlogN)에 오름차순 정렬 완료 
2. 힙의 최상단 원소는 항상 가장 작은 원소이기 때문!
3. 최대 힙은 제공하지 않음 -> 삽입 시 부호 변경 & 꺼낼 때 다시 부호 변경하면 됨
4. 사용법
    ```python
    import heapq

    # 초기화
    q = []

    # 예시 - 튜플 힙
    heapq.heappush(q, (3, 22))
    heapq.heappush(q, (2, 30))

    print(q[0])
    result = sorted(q, key =  lambda x: x[1])
    print(result)

    heapq.heappop(q)
    ======
    (2, 30)
    [(3, 20), (2, 30)]

    ```
5. **heappush(h,value)**: 원소 삽입
6. **heappop(h)**: 원소 꺼내기

<br/>

### 4️⃣ bisect
> 이진탐색. ‘정렬된 배열’에서 특정한 원소를 찾아야 할 때 매우 효과적
1. **bisect_left(a,x)**: 정렬된 순서를 유지하면서 리스트 a에 데이터 x를 삽입할 가장 왼쪽 인덱스 찾기 -> O(logN)
2. **bisect_right(a,x)**: 정렬된 순서를 유지하면서 리스트 a에 데이터 x를 삽입할 가장 오른쪽 인덱스 찾기 -> O(logN)
3. **예시**
    ```python
    from bisect import bisect_right, bisect_left

    def count_by_range(a, left_val, right_val):
      right_index = bisect_right(a, right_val)
      left_index = bisect_left(a, left_val)
      return right_index - left_index
      
    a = [1,2,3,3,3,3,4,4,8,9]
    
    # 값이 4인 데이터 개수 출력
    print(count_by_range(a,4,4)) 
    ==== 
    2
    # 값이 [-1,3] 범위에 있는 데이터 개수 출력
    print(count_by_range(a,-1,3)) 
    ====
    6
    ```

<br/>

### 5️⃣ collections
> 유용한 자료구조 제공

1. **deque**
    ```python
      from collections import deque
      data = deque([2,3,4]) # deque()로 초기화 가능
      data.appendleft(1)
      data.append(5)

      print(data)
      print(list(data))
      =====
      deque([1,2,3,4,5])
      [1,2,3,4,5]
    ```
    
- 리스트 자료형은 삽입과 삭제를 '맨 뒤'원소를 기준으로 수행 => 앞쪽의 원소를 처리할 때는 많은 시간 소요
- 비교

  | |리스트 | deque |
  |-----|---|---|
  가장 앞쪽에 원소 추가|O(N)|O(1)
  가장 뒤쪽에 원소 추가|O(1)|O(1)
  가장 앞쪽의 원소 제거|O(N)|O(1)
  가장 뒤쪽의 원소 제거|O(1)|O(1)
- 다만 리스트와 달리 인덱싱과 슬라이싱 사용 불가
- 스택, 큐의 기능을 모두 포함
    - stack: 원소 삽입 => append(), 원소 삭제 => pop()
    - queue: 원소 삽입 => append(), 원소 삭제 => popleft()
 
2. **Counter**: 등장 횟수를 세는 기능
    ```python
    from collections import Counter
    counter = Counter(['red','blue','red','green'])
    
    print(counter['blue'])
    print(dict(counter))
    =====
    1
    {'red':2, 'blue':1, 'green': 1}
    ```

<br/>

### 6️⃣ math
> 필수적인 수학적 기능을 제공

| 함수 | 설명
| -----|------|
math.pi | 파이
math.e | 자연상수
math.ceil(x)⭐️|	x를 올림하여 정수값을 반환
math.floor(x)⭐️|	x를 내림하여 정수값을 반환
math.trunc(x)⭐️|  x의 소수점을 자른 후 정수값을 반환
math.copysign(x, y)|	x값의 절댓값에 y의 부호를 갖는 유리수를 반환
math.comb(n, k)|	nCk과 같은 조합 값을 반환 (n개의 수에서 k개를 선택)
math.perm(n, k)|	nPk와 같은 순열 값을 반환 (n개의 수에서 k를 꺼내 순서대로 나열)
math.factorial(x)|	x의 팩토리얼을 반환 (1*2*3*...*x)
math.fmod(x, y)|	x에 y를 나눈 후 나머지를 제공 (부동소수점 연산에 사용)
math.fsum(iterable)|	이터러블(iterable)에 있는 값의 정확한 부동 소수점 합을 반환
math.prod(iterable)|	이터러블(iterable)의 모든 수의 곱을 반환 (빈 경우 1을 반환)
math.gcd(integers)⭐️|	여러개의 정수를 받아 최대 공약수를 반환
math.lcm(integers)⭐️| 여러개의 정수를 받아 최소 공약수를 반환
math.isclose(a, b)⭐️|	두 실수가 같은지 판단하는 정확한 함수
math.isfinite(x)|	x값이 무한하거나 Nan(Not a number) 일경우 True 값을 반환
math.isinf(x)|x가 양 또는 음의 무한대이면 True, 반대일 경우 False를 반환
math.isnan(x)⭐️|x가 Nan(Not a number)일경우 True, 반대일 경우 False를 반환
math.sqrt(n)⭐️| 제곱근 반환
math.modf(x)|	x의 (소수, 정수)부분으로 반환, 정수부분은 float로 반환

