'''
민혁이는 소셜 네트워크 사이트에서 친구를 만드는 것을 좋아하는 친구이다. 
우표를 모으는 취미가 있듯이, 민혁이는 소셜 네트워크 사이트에서 친구를 모으는 것이 취미이다.

어떤 사이트의 친구 관계가 생긴 순서대로 주어졌을 때, 
두 사람의 친구 네트워크에 몇 명이 있는지 구하는 프로그램을 작성하시오.

친구 네트워크란 친구 관계만으로 이동할 수 있는 사이를 말한다.
'''
import sys
input = sys.stdin.readline

def find_parent(friend, x):
  px = friend[x]['parent']
  
  if px != x: # 루트 노드가 아닐경우 
    friend[x]['parent'] = find_parent(friend,px)
    
  return friend[x]['parent']



def union_parent(friend,a,b):
  pa = find_parent(friend,a)
  pb = find_parent(friend,b)
  
  if pa > pb: 
    friend[pb]['parent'] = pa
    friend[pa]['count'] += friend[pb]['count']
    return friend[pa]['count']
    
  elif pb > pa: 
    friend[pa]['parent'] = pb
    friend[pb]['count'] += friend[pa]['count']
    return friend[pb]['count']



T = int(input())
for t in range(T):
  F = int(input())
  friend = {}

  for f in range(F):
    a,b = input().rstrip().split()
    
    if a not in friend.keys(): 
      friend[a] = {'parent':a,'count':1}
    if b not in friend.keys(): 
      friend[b] = {'parent':b,'count':1}

    if find_parent(friend,a) != find_parent(friend,b):
      print(union_parent(friend,a,b))
    else:
      pa = find_parent(friend,a)
      print(friend[pa]['count'])    

    
    