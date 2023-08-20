# 🗂️ 정렬

> 데이터를 특정한 기준에 따라서 순서대로 나열

<br/>

1. 정렬 알고리즘은 정말 다양하지만, **선택 정렬, 삽입 정렬, 퀵 정렬, 계수 정렬**을 가장 많이 사용함
2. 파이썬에서 제공하는 **기본 정렬 라이브러리**를 적용하면 효율적으로 정렬 가능
3. 일반적으로 문제에서 요구하는 조건에 따라 적절한 정렬 알고리즘을 공식적으로 사용
4. 면접에서도 단골 질문!!
5. **내림차순 정렬**의 경우 오름차순 정렬에서 크기 비교를 반대로 하면 됨 or 파이썬의 뒤집기 연산 메소드 활용(O(N))

<br/><br/>

## 🤌 선택 정렬

> 매번 가장 작은 것을 선택해서 정렬되지 않은 데이터 중에서 가장 앞쪽에 있는 데이터와 위치를 바꾸는 방법

![선택정렬](https://camo.githubusercontent.com/9a1327c205d23df05eafa8b846a905cfe6d4fd531b7568ab3fa8e33f86820fc9/68747470733a2f2f6c656d696469612e6769746875622e696f2f6173736574732f696d616765732f53656c656374696f6e2d536f72742d416e696d6174696f6e2e676966)

```Python
for i in range(len(array)):
    min_index = i # 가장 작은 원소의 인덱스
    for j in range(i + 1, len(array)):
        if array[min_index] > array[j]:
            min_index = j
    array[i], array[min_index] = array[min_index], array[i] # 스와프
```

### 스와프

1. 파이썬에서는 스와프: **a, b = b, a**
2. 다른 프로그래밍 언어에서는 명시적으로 임시 저장용 변수 선언 필요

### 시간 복잡도

1. N-1번만큼 가장 작은 수를 찾아서 앞으로 보내야 함
2. N + (N-1) ... + 2 = N \* (N+1) / 2 => (N^2 + N) / 2 = **O(N^2)**
3. 간단히 계산하려면 **for문의 중첩도**를 본다 => 2중 반복문 = O(N^2)
4. 선택 정렬은 알고리즘 풀이에 쓰기엔 **느림** => 파이썬의 기본 정렬 라이브러리가 훨씬 빠름.
5. 다만, 특정한 리스트에서 가장 작은 데이터를 찾을 일이 잦기 때문에 코드 형태에 익숙해지도록 하자

<br/><br/>

## 🪡 삽입 정렬

> 데이터를 앞에서부터 하나씩 확인하며, 데이터를 적절한 위치에 삽입하는 방법

![삽입정릴](https://camo.githubusercontent.com/7a042800a27368d631cfe1552dfb4f7e06bfbb0da4fbf83ad84ae9ef841c85b4/68747470733a2f2f626c6f672e6b616b616f63646e2e6e65742f646e2f767168456d2f62747144566573496b6d6f2f544f4a5a4c776d356d6c766a6a304a4d4464614e4b302f696d672e676966)

```Python
for i in range(1, len(array)):
    for j in range(i, 0, -1): # 인덱스 i부터 1까지 1씩 감소하며 반복하는 문법
        if array[j] < array[j - 1]: # 한 칸씩 왼쪽으로 이동
            array[j], array[j - 1] = array[j - 1], array[j]
        else: # 자기보다 작은 데이터를 만나면 그 위치에서 멈춤
            break
```

### 특징

1. 데이터가 거의 정렬되어 있을 때 효과적
2. 적절한 위치에 들어가기 전에 그 앞까지의 데이터는 이미 정렬되었다고 가정
3. 정렬이 이루어진 원소는 항상 오름차순 유지 => 자기보다 작은 데이터를 만나면 더 이상 데이터를 살펴볼 필요 없이 그 자리에 삽입하면 됨.

### 시간 복잡도

1. 2중 반복문 => O(N^2)
2. 다만 **거의 정렬이 되어있는 데이터인 경우**, 최선의 경우에 O(N)
3. **정렬이 거의 되어있지 않은 경우**에는 퀵 정렬이 유리 => 상황에 맞게 사용

<br/><br/>

## 🎢 퀵 정렬

> 기준 데이터를 설정하고, 그 기준보다 큰 데이터와 작은 데이터의 위치를 바꾸는 방법

![퀵정릴](https://camo.githubusercontent.com/997174546b408a5f5ab77cd4603579ae4b8f4e8b7d7c3b47b20d1a81afb7ab9d/68747470733a2f2f76656c6f672e76656c63646e2e636f6d2f696d616765732532466b6a69393930363037253246706f737425324632383934383239372d386564332d343036612d383066652d343738343535376431323835253246717569636b5f736f72742e676966)

### 기본 퀵 정렬

```Python
def quick_sort(array, start, end):
    if start >= end: # 원소가 1개인 경우 종료
        return
    pivot = start # 피벗은 첫 번째 원소
    left = start + 1
    right = end
    while(left <= right):
        # 피벗보다 큰 데이터를 찾을 때까지 반복
        while(left <= end and array[left] <= array[pivot]):
            left += 1
        # 피벗보다 작은 데이터를 찾을 때까지 반복
        while(right > start and array[right] >= array[pivot]):
            right -= 1
        if(left > right): # 엇갈렸다면 작은 데이터와 피벗을 교체
            array[right], array[pivot] = array[pivot], array[right]
        else: # 엇갈리지 않았다면 작은 데이터와 큰 데이터를 교체
            array[left], array[right] = array[right], array[left]
    # 분할 이후 왼쪽 부분과 오른쪽 부분에서 각각 정렬 수행
    quick_sort(array, start, right - 1)
    quick_sort(array, right + 1, end)

quick_sort(array, 0, len(array) - 1)
```

### 파이썬의 장점을 살린 퀵 정렬 - 시간은 좀 더 걸리지만 간단

```python
def quick_sort(array):
    # 리스트가 하나 이하의 원소만을 담고 있다면 종료
    if len(array) <= 1:
        return array

    pivot = array[0] # 피벗은 첫 번째 원소
    tail = array[1:] # 피벗을 제외한 리스트

    left_side = [x for x in tail if x <= pivot] # 분할된 왼쪽 부분
    right_side = [x for x in tail if x > pivot] # 분할된 오른쪽 부분

    # 분할 이후 왼쪽 부분과 오른쪽 부분에서 각각 정렬을 수행하고, 전체 리스트를 반환
    return quick_sort(left_side) + [pivot] + quick_sort(right_side)
```

### 특징

1. 가장 많이 사용되는 정렬 알고리즘 (퀵, 병합 정렬이 top) - 이름부터가 '빠른' 정렬😮
2. 피벗을 설정하고 분할하는 방법에 따라 여러가지 방식의 퀵 정렬 존재
3. 우선, 가장 대표적인 **호어 분할 방식**을 따르자

### 시간 복잡도

1. **평균 복잡도는 O(NlogN)**
2. **최악의 경우 O(N^2)** => 이미 정렬되어 있는 데이터의 경우 매우 느리게 동작
3. 복잡도 증명은 복잡하므로 코테 목적의 경우 굳이 알 필요 없음

<br/><br/>

## 🧮 계수 정렬

> 특정한 값을 가지는 데이터의 개수를 '카운트'하는 방법

![계수정렬](https://blog.kakaocdn.net/dn/vurcx/btqFPrXv8rg/kFWVlJLIPZNzvVaFRZ7G51/img.gif)

```Python
# 모든 원소의 값이 0보다 크거나 같다고 가정
array = [7, 5, 9, 0, 3, 1, 6, 2, 9, 1, 4, 8, 0, 5, 2]
# 모든 범위를 포함하는 리스트 선언 (모든 값은 0으로 초기화)
count = [0] * (max(array) + 1)

for i in range(len(array)):
    count[array[i]] += 1 # 각 데이터에 해당하는 인덱스의 값 증가

for i in range(len(count)): # 리스트에 기록된 정렬 정보 확인
    for j in range(count[i]):
        print(i, end=' ') # 띄어쓰기를 구분으로 등장한 횟수만큼 인덱스 출력
```

### 특징

1. 데이터의 **크기 범위가 제한**되어 **정수 형태**로 표현 가능할 때만 사용
2. 현존하는 정렬 알고리즘 중 기수(radix) 정렬과 더불어 가장 빠름

- 기수 정렬은 계수 정렬에 비해 느리지만 처리 가능한 정수 크기가 더 큼
- 그러나 훨씬 더 복잡 -> 코테 한정 몰라도 됨

### 시간 복잡도

1. 데이터의 개수가 N이고, 최댓값이 K일 때, 시간복잡도와 공간복잡도 모두 O(N+K)
2. 데이터 크기가 한정적이고 중복된 데이터가 많을 때 효율적
3. 일반적으로 가장 작은 데이터와 가장 큰 데이터의 차이가 100만 이하일 때 효과적
4. 데이터 파악이 어렵다면 그냥 퀵 정렬 사용!

<br/><br/>

## 📝 정렬 알고리즘 총 정리

![사진](https://github.com/iQuQi/easyPlant/assets/69742775/a513725a-5062-42d1-9dd3-1d6baed94dd7)
<br/><br/>

## 💡 파이썬의 기본 정렬 라이브러리

1. 정렬 알고리즘 문제는 어느 정도 정해진 답이 있는, **즉 외워서 잘 풀 수 있는 문제**.
2. **sorted(), sort()**

- 병합 정렬과 삽입 정렬의 아이디어를 더한 하이브리드 정렬 알고리즘 방식 사용
- 퀵 정렬보다는 느리지만 **최악의 경우에도 O(NlogN) 보장**

3. **단순히 정렬을 해야하는 상황인 경우** 기본 정렬 라이브러리 사용
4. **데이터의 범위가 한정되어 있고 더 빠르게 동작해야 할 때**는 계수 정렬 사용

<br/><br/>

## ❗️ 코딩 테스트에서 정렬 알고리즘이 사용되는 경우 3가지

1. **정렬 라이브러리로 풀 수 있는 문제**
2. **정렬 알고리즘의 원리에 대해서 물어보는 문제** -> 삽입, 선택, 퀵 정렬 동작 원리를 알아야 풀 수 있음
3. **더 빠른 정렬이 필요한 문제** -> 계수 정렬 사용 or 기존 알고리즘 구조 개선

<br/><br/><br/><br/>

# ⭐️ 정렬 알고리즘 추가

## 버블정렬

```
- 인접한 두 원소를 비교하여 큰 값이 오른쪽으로 이동하도록 하는 정렬 알고리즘
- 시간 복잡도는 최악의 경우 O(n^2)
```

![버블](https://blog.kakaocdn.net/dn/bUriug/btq090GyQBk/YU1pmyrtM6gypU0kvrQ3dk/img.gif)

```python
def bubbleSort(arr):
    n = len(arr) # 배열의 크기를 측정

    # 배열의 크기만큼 반복
    for i in range(n):

        # 배열의 총 크기에서 i의 값과 1을 뺀 만큼 반복
        for j in range(0, n - i - 1):

            # 만약 현재 인덱스의 값이 다음 인덱스의 값보다 클경우 실행
            if arr[j] > arr[j + 1]:
                arr[j], arr[j + 1] = arr[j + 1], arr[j] # 서로 위치를 변환
```

## 병합정렬

```
- 분할 정복(divide and conquer) 방법을 사용하여 리스트를 정렬하는 알고리즘
- 시간 복잡도는 항상 O(nlogn)
```

![병합정렬](https://blog.kakaocdn.net/dn/do8Hzv/btqFPrQKdH9/l3H2t7nDmJImB5pB3B9fL0/img.gif)

```python
def merge_sort(arr):
    if len(arr) < 2:
        return arr

    mid = len(arr) // 2
    low_arr = merge_sort(arr[:mid])
    high_arr = merge_sort(arr[mid:])

    merged_arr = []
    l = h = 0
    while l < len(low_arr) and h < len(high_arr):
        if low_arr[l] < high_arr[h]:
            merged_arr.append(low_arr[l])
            l += 1
        else:
            merged_arr.append(high_arr[h])
            h += 1
    merged_arr += low_arr[l:]
    merged_arr += high_arr[h:]
    return merged_arr
```

## 힙정렬

```
- 힙(heap) 자료구조를 사용하여 리스트를 정렬하는 알고리즘
- 주어진 리스트를 최대 힙(max heap)으로 구성
- 그 다음으로 한 번에 하나씩 요소를 힙에서 꺼내서 배열의 뒤부터 저장
- 시간 복잡도는 항상 O(nlogn)
```

![힙정렬](https://mblogthumb-phinf.pstatic.net/MjAyMDA2MjhfMjEw/MDAxNTkzMzA2MDg4Nzc1.Wk6dwd3t967xoOv84aZyiMPqplEwef8MKCxSpQXu-70g.aab0ABPQt34a9cctRq48hQ-eAw9Jez9wHpfA9lBxm0Mg.GIF.adamdoha/max_heap_deletion_animation.gif?type=w800)

```python
def heap_sort(unsorted):
    # 리스트에 전체 길이를 받음
    n = len(unsorted)

    # // 연산자 : 몫 구하기
    # 이진트리를 구하기 때문에 전체 크기의 반만 반복
    # for문을 거꾸로 돌아감
    # 이진트리의 가장 아래서부터 heapify를 실행하여 힙 구조를 만듬

    for i in range(n // 2 - 1, -1, -1):
        heapify(unsorted, i, n)

    # 마지막 노드부터 루트노드를 기준으로 값을 스위치하면서 정렬
    for i in range(n - 1, 0, -1):
        unsorted[0], unsorted[i] = unsorted[i], unsorted[0]
        # 원래라면 힙은 1번인덱스부터 시작해야하지만 0번인덱스에 더미데이터를 넣는 것을 막기위해
        # 0을 루트로 사용한다. (아래 사진 참고)
        heapify(unsorted, 0, i)
    return unsorted
```

```python
def heapify(unsorted, index, heap_size):

    largest = index

    left_index = 2 * index
    right_index = 2 * index +1

    # 자식노드가 범위안에 드는지 확인, 자식노드가 부모노드보다 큰지 확인
    # 자식노드가 부모노드보다 크다면 인덱스 스위치

    if left_index < heap_size and unsorted[left_index] > unsorted[largest]:
        largest = left_index

    if right_index < heap_size and unsorted[right_index] > unsorted[largest]:
        largest = right_index

    # 부모노드의 인덱스값이 바뀌었다면 자식노드의 값과 스위치

    if largest != index:
        unsorted[largest], unsorted[index] = unsorted[index], unsorted[largest]
        # 재귀 함수
        heapify(unsorted, largest, heap_size)
```

## 기수정렬

```
- 비교 정렬 알고리즘이 아닌, 자리수를 기준으로 정렬하는 알고리즘
- 각 자리수를 순서대로 비교하여 정렬하는 것이 아니라, 각 자리수에 대한 빈도수를 계산하여 정렬
- 시간 복잡도는 O(dn) (d는 데이터의 자리수, n은 데이터의 개수)
- 매우 빠른 속도로 정렬하지만, 메모리를 많이 사용
```

![기수정렬](https://blog.kakaocdn.net/dn/DWH0S/btqFOYnIbCu/Q7HOAOzzvlD4xW279LqTLK/img.gif)

```python
from collections import deque

def radix_sort(nums):
    buckets = [deque() for _ in range(10)]

    max_val = max(nums)
    Q = deque(nums)
    cur_ten = 1

    while max_val >= cur_ten:
        while Q:
            num = Q.popleft()
            buckets[(num // cur_ten) % 10].append(num)

        for bucket in buckets:
            while bucket:
                Q.append(bucket.popleft())

        cur_ten *= 10

    return list(Q)
```
