'''-
크기가 무한인 정사각형 모눈종이가 있다. 모눈종이의 각 정사각형은 행과 열의 쌍으로 표현할 수 있다.

이 모눈종이 전체를 양의 정수의 소용돌이 모양으로 채울 것이다. 일단 숫자 1을 0행 0열에 쓴다.
 그리고 나서 0행 1열에 숫자 2를 쓴다. 거기서 부터 소용돌이는 반시계 방향으로 시작된다. 
 다음 숫자는 다음과 같이 채우면 된다.

    -3 -2 -1  0  1  2  3
    --------------------
-3 |37 36 35 34 33 32 31
-2 |38 17 16 15 14 13 30
-1 |39 18  5  4  3 12 29
 0 |40 19  6  1  2 11 28
 1 |41 20  7  8  9 10 27
 2 |42 21 22 23 24 25 26
 3 |43 44 45 46 47 48 49
이 문제는 위와 같이 채운 것을 예쁘게 출력하면 된다. r1, c1, r2, c2가 입력으로 주어진다.
 r1, c1은 가장 왼쪽 위 칸이고, r2, c2는 가장 오른쪽 아래 칸이다.

예쁘게 출력한다는 것은 다음과 같이 출력하는 것이다.

출력은 r1행부터 r2행까지 차례대로 출력한다.
각 원소는 공백으로 구분한다.
모든 행은 같은 길이를 가져야 한다.
공백의 길이는 최소로 해야 한다.
모든 숫자의 길이(앞에 붙는 공백을 포함)는 같아야 한다.
만약 수의 길이가 가장 길이가 긴 수보다 작다면, 왼쪽에서부터 공백을 삽입해 길이를 맞춘다.
'''

r1, c1, r2, c2 = map(int, input().split())

print_arr = [[0] * (c2-c1 + 1) for _ in range(r2-r1 + 1)]
count,step, max_length = 0,1,1
now_i, now_j, now_val = 0, 0, 1

if c1 <= now_j <= c2 and r1 <= now_i <= r2:
  print_arr[now_i-r1][now_j-c1] = now_val
  count += 1



while True:
  # 늘어나는 칸수가 짝수개인경우 그만큼 왼쪽 이동 후 아래쪽 이동
  # 홀수개가 늘어가느 경우 오른쪽이동후 위쪽 이동
  
  for _ in range(step):
    if step % 2 != 0: now_j += 1
    else: now_j -= 1
    now_val += 1
    if c1 <= now_j <= c2 and r1 <= now_i <= r2:
      print_arr[now_i-r1][now_j-c1] = now_val
      count += 1
      max_length = max(max_length, len(str(now_val)))
      
  for _ in range(step): 
    if step % 2 != 0:now_i -= 1
    else: now_i += 1
    now_val += 1
    if c1 <= now_j <= c2 and r1 <= now_i <= r2:
      print_arr[now_i-r1][now_j-c1] = now_val
      count += 1
      max_length = max(max_length, len(str(now_val)))

  if count >= (c2-c1+1)*(r2-r1+1): break

  step += 1

for arr in print_arr:
  for item in arr:
    print(str(item).rjust(max_length, ' ') + ' ', end='')
  print()
    