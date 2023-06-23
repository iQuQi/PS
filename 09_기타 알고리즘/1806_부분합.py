'''
10,000 이하의 자연수로 이루어진 길이 N짜리 수열이 주어진다. 
이 수열에서 연속된 수들의 부분합 중에 그 합이 S 이상이 되는 것 중, 
가장 짧은 것의 길이를 구하는 프로그램을 작
'''

# 투포인터, 부분합 유형
import sys

input = sys.stdin.readline

n, s = map(int, input().split())
arr = list(map(int, input().split()))

start, end = 0, 0
min_len = n + 1
total = 0

while start < n and end < n:
  next_len = end - start + 1
  
  if total + arr[end] < s and next_len < min_len:
      total += arr[end]
      end += 1
      
  else:
    min_len = min(min_len, next_len)
    if start == end:
      start += 1
      end += 1
    else:
      total -= arr[start]
      start += 1
      
if min_len == n + 1: min_len = 0
print(min_len)