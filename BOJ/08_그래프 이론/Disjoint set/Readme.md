# 👨‍👩‍👦‍👦 서로소 집합
> 공통 원소가 없는 두 집합

<br><br>

## 🔎 서로소 집합 자료구조

1. **UNION**과 **FIND** 연산으로 이루어짐
- union: 2개의 원소가 포함된 집합을 하나의 집합으로 합치는 '합집합' 연산
- find: 특정 원소가 속한 집합이 어떤 집합인지 알려주는 연산
2. **트리구조**를 사용해서 집합 표현
3. 일반적으로 **더 번호가 작은 원소가 부모 노드**가 됨
4. 코드 - ⭐️ **find의 [경로 압축] 개선 확인** ⭐️
    ```python
    # 특정 원소가 속한 집합을 찾기
    def find_parent(parent, x):
        # 루트 노드가 아니라면, 루트 노드를 찾을 때까지 재귀적으로 호출

        # 개선 전 버전 - O(VM), V는 노드개수 M은 연산수
            # if parent[x] != x:
            #    return find_parent(parent, parent[x]
            # return x

        # 개선 후 버전 -> 경로 압축 (Path Compression) - 대략 O(V+MlogV)
        if parent[x] != x:
            parent[x] = find_parent(parent, parent[x])
        return parent[x]

    # 두 원소가 속한 집합을 합치기
    def union_parent(parent, a, b):
        a = find_parent(parent, a)
        b = find_parent(parent, b)
        if a < b:
            parent[b] = a
        else:
            parent[a] = b

    # 노드의 개수와 간선(Union 연산)의 개수 입력 받기
    v, e = map(int, input().split())
    parent = [0] * (v + 1) # 부모 테이블 초기화하기

    # 부모 테이블상에서, 부모를 자기 자신으로 초기화
    for i in range(1, v + 1):
        parent[i] = i

    # Union 연산을 각각 수행
    for i in range(e):
        a, b = map(int, input().split())
        union_parent(parent, a, b)

    # 각 원소가 속한 집합 출력하기
    print('각 원소가 속한 집합: ', end='')
    for i in range(1, v + 1):
        print(find_parent(parent, i), end=' ')

    print()

    # 부모 테이블 내용 출력하기
    print('부모 테이블: ', end='')
    for i in range(1, v + 1):
        print(parent[i], end=' ')
    ```

<br><br>

## 🔄 사이클 판별

1. **무방향** 그래프에서만 적용 가능 
2. **방향** 그래프의 사이클 판별은 **dfs**로 가능하나 다루지 않음
3. **동작과정**
- 그래프에 포함되어 있는 모든 간선에 대해 union & find 
- 루트 노드가 서로 같다면 사이클 발생
4. 코드
    ```python
    # find/union,입력/초기화는 위 코드와 동일

    cycle = False # 사이클 발생 여부

    for i in range(e): # 모든 간선에 대해
        a, b = map(int, input().split())
        # 사이클이 발생한 경우 종료
        if find_parent(parent, a) == find_parent(parent, b):
            cycle = True
            break
        # 사이클이 발생하지 않았다면 합집합(Union) 연산 수행
        else:
            union_parent(parent, a, b)

    if cycle:
        print("사이클이 발생했습니다.")
    else:
        print("사이클이 발생하지 않았습니다.")
    ```