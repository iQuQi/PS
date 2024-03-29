# 🔨 구현
> 머릿속에 있는 알고리즘을 (빠르게) 소스코드로 바꾸는 과정. 

<br/>

## 소개
1. 넓게보면 모든 범위의 문제 유형을 포함하는 개념
2. 보통 풀이를 떠올리는 것은 쉽지만 **소스코드로 옮기기 어려운 문제**를 구현 문제라고 함
3. 보통 사소한 조건 등을 명시해주며 문제의 길이가 꽤 긴편이나 고차원적인 사고력을 요구하지는 않으니 **겁먹지 말자**
4. **리스트 크기**가 제한량을 넘지 않도록 주의 -> 메모리 사용량 자체의 문제도 있지만 이 과정에서 일어나는 입출력 때문에 많은 시간이 소요되는 문제도 있다.

<br/>


## 문제 유형
1. 완전 탐색과 시뮬레이션 유형이 구현 유형에 해당함
- **완전 탐색**: 
    - 모든 경우의 수를 주저없이 다 계산해야하는 해결 방법
    - 반복문과 재귀함수를 적절히 사용해서 예외 케이스를 모두 확인하기
    - 일반적으로 BFS/DFS 사용
- **시뮬레이션**: 
    - 문제에서 제시한 알고리즘을 한 단계씩 차례대로 직접 수행
- **문자열**
2. 개발 문제 중에서도 **API 개발 문제**는 구현 문제임. -> 파이썬은 이러한 기능을 비교적 쉽게 구현 가능
3. 이외에도 소스코드가 매우 길거나, 까다로운 문자열을 처리하거나, 구현이 아주 까다로운 문제 등이 있다.


<br/>

## PyPy3
- 파이썬3의 문법을 그대로 지원하지만 **실행속도는 더 빠름**
- 대략 1초에 2000만번 ~ 1억번 정도의 연산 가능
- 반복문이 많을수록 파이썬과 속도 차이 ⬆
- 코딩 테스트 환경에서 PyPy3을 지원한다면 사용하도록 하자


