# 🔡 문자열 알고리즘

<br>

## 브루트 포스
단순한 비교. 매우 느림

![브루트포스](https://img1.daumcdn.net/thumb/R1280x0/?scode=mtistory2&fname=https%3A%2F%2Fblog.kakaocdn.net%2Fdn%2FbqLDe3%2FbtrlETGFqKJ%2FNgaNVh4GfDo8krz07QO02K%2Fimg.png)


<br><br>

## KMP(Knuth-Morris-Pratt) - ⭐️ 시간되면 공부하기
1. 불일치가 발생하기 직전까지 같았던 부분은 다시 비교하지 않고 건너뛴 후 패턴 매칭을 진행
2. 원본 문자열의 길이가 N, 탐색 문자열의 길이가 M 이라면 최종적인 시간 복잡도는 O(N + M) 
3. 예시그림
![1단계](https://img1.daumcdn.net/thumb/R1280x0/?scode=mtistory2&fname=https%3A%2F%2Fblog.kakaocdn.net%2Fdn%2FBS9PG%2FbtrlFJD0iQ9%2FxkFkNfarVSdzKGhnesmgE1%2Fimg.png)
![2단계](https://img1.daumcdn.net/thumb/R1280x0/?scode=mtistory2&fname=https%3A%2F%2Fblog.kakaocdn.net%2Fdn%2Fbc3o6f%2FbtrlGJDKXi5%2FFkPNMfmB4w34TAz3bXxGf1%2Fimg.png)
![실패함수](https://img1.daumcdn.net/thumb/R1280x0/?scode=mtistory2&fname=https%3A%2F%2Fblog.kakaocdn.net%2Fdn%2FbwHHOi%2FbtrlFb8BcBw%2FWDL2E3Ktev4nD4H15fgxJ0%2Fimg.png)
- 8칸이 아닌 4칸을 건너뛰고 다시 매치을 시작
- 몇칸을 건너뛰는지 판단하기 위해 실패 함수를 사용
- 실패함수: 찾으려는 패턴의 i번째 글자까지 중에서 일치하는 접두사와 접미사 중에서 최대의 길이를 값으로 가짐

<br>

```python
from collections import defaultdict
 
def failure_function(pattern):
    m = len(pattern)
    d = defaultdict(int)
 
    begin = 1
    matched = 0
 
    while begin + matched < m:
        if pattern[begin + matched] == pattern[matched]:
            matched += 1
            d[begin + matched - 1] = matched
        else:
            if matched == 0:
                begin += 1
            else:
                begin += matched - d[matched - 1]
                matched = d[matched - 1]
    return d
 
 
 
def KMP(word, pattern):
    table = failure_function(pattern)
    results = []
    p = 0
 
    for idx in range(len(word)):
        while p > 0 and word[idx] != pattern[p]:
            p = table[p - 1]
 
        if word[idx] == pattern[p]:
            if p == len(pattern) - 1:
                results.append(idx - len(pattern) + 2)
                p = table[p]
            else:
                p += 1
 
    return results
```

<br><br>

## Rabin-karp(라빈 카프)
> 해싱(Hashing)을 사용해서 문자열에서 특정 패턴과 일치하는지 찾아주는 알고리즘

- 문자열 패턴과 텍스트를 해시 값을 이용하여 변환 후, 패턴의 해시 값과 텍스트에서 이동하면서 추출한 문자열의 해시 값을 비교
- 해시 값이 일치하지 않을 경우에는 문자열의 길이만큼 이동하여 다시 해시 값을 비교
- 해시 값이 일치할 경우에는 문자열 패턴과 텍스트의 문자를 하나씩 비교하여 매칭 여부를 확인
  
<br><br>
