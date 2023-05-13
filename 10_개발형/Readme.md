
## 파이썬으로 REST API 호출 연습하기

1. JSON 모킹 사이트를 활용해서 연습가능
2. **모킹(Mocking)**: 어떠한 기능이 있는 것 처럼 흉내내어 구현한 것
3. **파싱(Parsing)**: 특정한 형식으로 저장된 데이터에 접근해서 원하는 정보만 찾아서 가공하는 작업
4. 사용 예시
      ```python
      import requests

      target = 'https://jsonplaceholder.typicode.com/users'
      response = requests.get(url = target)

      data = response.json()

      name_list = []
      for user in data:
        name_list.append(user['name'])
      ```


<br><br>
