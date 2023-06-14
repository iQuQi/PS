# 🌓 이분 탐색 (Binary Search)
> 범위를 반씩 좁혀나가는 탐색

<br><br>

## 순차 탐색
1. 리스트 안에 있는 특정한 데이터를 찾기 위해 앞에서부터 데이터를 하나씩 확인
2. 특정 원소가 있는 지 찾거나 특정 값을 가지는 원소의 개수를 세는 count()에서도 순차 탐색 수행

<br><br>

## 이분 탐색: 반으로 쪼개면서 탐색
1. 데이터를 **매우 빠르게 탐색**
2. 배열 내부의 데이터가 **정렬**되어 있어야만 사용 가능
3. 이진탐색 코드는 반드시 외워둘 것 - 빈출✨
4. 탐색범위가 **1000만 단위**를 넘어가면 이진탐색을 떠올리자 => **시간복잡도 O(logN)**
5. 이때 입력의 수가 너무 많으면 시간초과 남 - **input() 대신, sys.stdin.readline().rstrip() 사용**
3. 구현방법 1 - 재귀함수
    ```python
    # 이진 탐색 소스코드 구현 (재귀 함수)
    def binary_search(array, target, start, end):
        if start > end:
            return None
        mid = (start + end) // 2
        # 찾은 경우 중간점 인덱스 반환
        if array[mid] == target:
            return mid
        # 중간점의 값보다 찾고자 하는 값이 작은 경우 왼쪽 확인
        elif array[mid] > target:
            return binary_search(array, target, start, mid - 1)
        # 중간점의 값보다 찾고자 하는 값이 큰 경우 오른쪽 확인
        else:
            return binary_search(array, target, mid + 1, end)

    # n(원소의 개수)과 target(찾고자 하는 값)을 입력 받기
    n, target = list(map(int, input().split()))
    # 전체 원소 입력 받기
    array = list(map(int, input().split()))

    # 이진 탐색 수행 결과 출력
    result = binary_search(array, target, 0, n - 1)
    if result == None: print("원소가 존재하지 않습니다.")
    else: print(result + 1)
    ```
4. 구현방법 2 - 반복문
    ```python
    # 이진 탐색 소스코드 구현 (반복문)
    def binary_search(array, target, start, end):
        while start <= end:
            mid = (start + end) // 2
            # 찾은 경우 중간점 인덱스 반환
            if array[mid] == target:
                return mid
            # 중간점의 값보다 찾고자 하는 값이 작은 경우 왼쪽 확인
            elif array[mid] > target:
                end = mid - 1
            # 중간점의 값보다 찾고자 하는 값이 큰 경우 오른쪽 확인
            else:
                start = mid + 1
        return None
    ```
5. **bisect 클래스**
- 단순히 정렬된 배열에서 특정한 데이터를 찾을 때는 직접 구현할 필요없이 표준라이브러리 사용

<br><br>

## 🌲 트리 자료구조
1. 트리 구조의 특징
- 부모 노드와 자식 노드의 관계로 표현됨
- 최상단 노드 = 루트 노드
- 최하단 노드 = 말단 노드
- 일부를 떼어내도 트리 구조이며 이를 서브 트리라고 함
- 파일 시스템과 같이 계층적이고 정렬된 데이터를 다루기에 적합하다
2. 큰 데이터를 처리하는 소프트웨어는 대부분의 데이터를 트리 구조로 활용 => 이진 탐색 활용

<br><br>

## 🎄 이분 탐색 트리
1. 트리 구조 중 **가장 간단한 형태**
2. **특징**
- 부모 노드보다 왼쪽 자식 노드가 작다
- 부모 노드보다 오른쪽 자식 노드가 크다
3. 데이터를 빼고 넣는 구현은 출제 빈도가 낮음 -> 조회만 알고 있자
4. **탐색 과정**
- 루트 노드에서 시작
- 루트 값보다 작으면 왼쪽 노드 방문, 크다면 오른쪽 노드 방문
- 자식 노드가 없을 때까지 찾지 못한다면 원소가 없는 것

<br><br>

## 1️⃣ Parametric Search (대표적인 이분탐색 문제 - 1)
> 최적화 문제를 결정 문제로 바꾸어 해결하는 기법

<br>

1. **원하는 조건을 만족하는 가장 작은 알맞은 값을 찾는 문제**에 주로 이 기법을 사용
2. 이진 탐색의 원리를 이용하여 절반씩 탐색 범위를 좁힌다.
3. 원하는 조건을 만족하는가? -> 조건 만족 여부에 따라 범위를 좁혀가며 반복적으로 확인

<br><br>

## 2️⃣ LIS (대표적인 이분탐색 문제 - 2)

1. DP + 이분탐색
2. DP 파트에서 확인하기