'''
    +---+        
    | D |        
+---+---+---+---+
| E | A | B | F |
+---+---+---+---+
    | C |        
    +---+        
주사위는 위와 같이 생겼다. 주사위의 여섯 면에는 수가 쓰여 있다. 
위의 전개도를 수가 밖으로 나오게 접는다.

A, B, C, D, E, F에 쓰여 있는 수가 주어진다.

지민이는 현재 동일한 주사위를 N3개 가지고 있다. 이 주사위를 적절히 회전시키고 쌓아서, 
NxNxN크기의 정육면체를 만들려고 한다. 이 정육면체는 탁자위에 있으므로, 5개의 면만 보인다.

N과 주사위에 쓰여 있는 수가 주어질 때, 
보이는 5개의 면에 쓰여 있는 수의 합의 최솟값을 출력하는 프로그램을 작성하시오.
'''


n = int(input())
dice = list(map(int,input().split()))
min_lists = []

if n == 1:
  dice_sum = sum(dice)
  dice_max = max(dice)
  print(dice_sum - dice_max)

else: 
  # min 구하는 과정이 중요!!!!!
  min_lists.append(min(dice[0], dice[5]))
  min_lists.append(min(dice[1], dice[4]))
  min_lists.append(min(dice[2], dice[3]))
  min_lists.sort()

  # 1, 2, 3 면의 주사위 최소값
  dice_min = [-1,-1,-1]
  dice_min[0] = min_lists[0]
  dice_min[1] = min_lists[0] + min_lists[1]
  dice_min[2] = sum(min_lists)
  
  n1 = ((n-2)*(n-2)*5+(n-2)*4)
  n2 = (2*n-3)*4
  n3 = 4
   
  total = 0 
  total += n1 * dice_min[0]
  total += n2 * dice_min[1]
  total += n3 * dice_min[2]
  
  print(total)