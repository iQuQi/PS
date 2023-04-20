# 🤝 웹 서버와 클라이언트
> 클라이언트가 요청을 보내면 서버는 응답
<img width="638" alt="image" src="https://user-images.githubusercontent.com/69742775/233348634-1804fc23-2f8a-4358-b679-5f77a0afc96a.png">
<br>


1. 음식점에 비유하자면, 클라이언트는 **음식을 주문하는 사람(고객)**, 서버는 **음식을 접대하는 사람**
2. 클라이언트가 서버에 요청(페이지 이동, 로그인, 글 작성 등) 
3. 요청을 받은 서버가 그에 맞는 응답을 보내줌 (예) 현재 사용자가 보낸 아이디와 비밀번호가 정확히지 검사하고 그 결과를 응답으로 보내주기)
4. 응답을 받은 클라이언트는 서버의 응답(정보)을 화면에 출력 (html, js, css)

<br>

## HTTP

1. **HTTP** = HyperText Transfer Protocol = 웹 상에서 데이터를 주고 받기 위한 프로토콜
2. 보통은 웹 문서(HTML)을 주고 받는데 사용됨

    | HTTP 메서드 | 설명 | 사용예시 |
    | --------- | -------| -------|
    | GET | 특정 데이터의 조회 요청 | 특정 페이지 접속, 정보 검색
    | POST | 특정 데이터 생성 요청 | 회원가입, 글쓰기
    | PUT | 특정 데이터의 수정 요청 | 회원 정보 수정
    | DELETE | 특정 데이터 삭제 요쳥 | 회원 정보 삭제 
3. 물론 각 메서드의 설명을 따르지 않아도 기능을 구현할 수 있으나, **REST 아키텍처**에서는 설명에 맞게 프로그램을 개발하도록 권장
4. POST로 수정/삭제 요청을 모두 처리하기도 함


<br><br><br>

# 🚀 REST(Representational State Transfer) API 

> 각 자원에 대해 자원의 상태에 대한 정보를 주고받는 개발 방식 = 서버의 자원을 어떠한 방식으로 접근하도록 해야 하는지를 구체적으로 명시한 것

> HTTP 메서드를 기본 설명에 따르지 않고 여러 방향으로 구현하게 되면 문제가 되므로 기준이 되는 아키텍쳐 필요 => REST 아키텍처 등장

<br>

1. **REST 구성요소**
  - 자원(Resource): URI를 이용해서 표현
  - 행위(Verb): HTTP 메소드를 이용해서 표현
  - 표현(Representation)
2. **API** = Application Programming Interface = 프로그램이 상호작용하기 위한 인터페이스
3. **REST API** = REST 아키텍처를 따르는 API
4. **REST API 호출**
  - REST 방식을 따르고 있는 서버에 특정한 요청을 보내서 데이터를 가져오는 것
  - 3 구성요소를 포함 -> URI를 이용해서 정보의 '자원'을 '표현' & HTTP 메소드 사용

<br>

## URL vs URI
1. URI
- 특정 리소스를 식별하는 통합 자원 식별자(Uniform Resource Identifier)를 의미
- 웹 기술에서 사용하는 논리적 또는 물리적 리소스를 식별하는 고유한 문자열 시퀀스
2. URL 
- 흔히 웹 주소라고도 함
- 컴퓨터 네트워크 상에서 리소스가 어디 있는지 알려주기 위한 규약 
- URI의 서브셋
<img width="277" alt="image" src="https://user-images.githubusercontent.com/69742775/233353587-2b97abb8-efe4-44fd-8e78-ac6b996d5460.png">

<br>

## JSON (JavaScript Object Notation)
> 데이터를 주고받는 데 사용하는 데이터 형식 표준

1. REST API를 사용할 때 일반적으로 사용하는 데이터 형식
2. 이름대로, 자바스크립트에서 객체를 만들때 사용하는 표현식과 동일한 형태
3. 키-값 쌍으로 이루어짐 -- 사전 자료형과 흡사
4. 파이썬에서는 JSON 기본 라이브러리 제공
- import json
- 인코딩 = 파이썬 기본 자료형을 JSON 객체로 변환하는 작업 => json.dumps(data)
- 디코딩 = JSON 객체를 파이썬 기본 자료형으로 변환하는 작업 => json.loads(data)
- JSON 객체를 파일(확장자 json)로 저장하기
  ```python
  # 예시
  with open('user.json', 'w', encoding ='utf-8') as file:
    json.dump(user, file, indent = 4)
  ```

<br>

## 파이썬으로 REST API 호출 연습하기

1. JSON 모킹 사이트를 활용해서 연습가능
2. 모킹(Mocking): 어떠한 기능이 있는 것 처럼 흉내내어 구현한 것
3. 파싱(Parsing): 특정한 형식으로 저장된 데이터에 접근해서 원하는 정보만 찾아서 가공하는 작업
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
