# 2차원 벽면에 기둥 혹은 보를 세울 예정
# 규칙
# 1. 기둥은 바닥 위에 있거나 보의 한쪽 끝면에 있거나 또는 다른 기둥 위에 있어야 함
# 2. 보는 한쪽 끝부분이 기둥 위에 있거나, 또는 양쪽 끝부분이 다른 보와 동시에 연결 되어 있어야 함
# 기둥과 보는 길이 1의 선분
# 명령의 순서에 따라 삭제 혹은 생성 -> 삭제 후에도 구조물이 유효한 상태인지 확인 필요 & 유효하지 않으면 명령 무시
# 모든 명령을 수행한 후 구조물의 결과물 출력하기

# ========================================

# 현재 설치된 구조물이 '가능한' 구조물인지 확인하는 함수
def possible(answer):
    for x, y, stuff in answer:
        if stuff == 0:  # 설치된 것이 '기둥'인 경우
            # '바닥 위' 혹은 '보의 한쪽 끝 부분 위' 혹은 '다른 기둥 위'라면 정상
            if y == 0 or [x - 1, y, 1] in answer or [x, y, 1] in answer or [x, y - 1, 0] in answer:
                continue
            return False  # 아니라면 거짓(False) 반환
        elif stuff == 1:  # 설치된 것이 '보'인 경우
            # '한쪽 끝부분이 기둥 위' 혹은 '양쪽 끝부분이 다른 보와 동시에 연결'이라면 정상
            if [x, y - 1, 0] in answer or [x + 1, y - 1, 0] in answer or ([x - 1, y, 1] in answer and [x + 1, y, 1] in answer):
                continue
            return False  # 아니라면 거짓(False) 반환
    return True


def solution(n, build_frame):
    answer = []
    for frame in build_frame:  # 작업(frame)의 개수는 최대 1,000개
        x, y, stuff, operate = frame
        if operate == 0:  # 삭제하는 경우
            answer.remove([x, y, stuff])  # 일단 삭제를 해본 뒤에
            if not possible(answer):  # 가능한 구조물인지 확인
                answer.append([x, y, stuff])  # 가능한 구조물이 아니라면 다시 설치
        if operate == 1:  # 설치하는 경우
            answer.append([x, y, stuff])  # 일단 설치를 해본 뒤에
            if not possible(answer):  # 가능한 구조물인지 확인
                answer.remove([x, y, stuff])  # 가능한 구조물이 아니라면 다시 제거
    return sorted(answer)  # 정렬된 결과를 반환


'''내코드
construct = set()

def rowCheck(type,x,y):
    if type == 'DELETE':
        # 삭제 명령        
        if (x,y,1) not in construct: return False
        construct.remove((x,y,1))
        # 위 col 검사 & 양옆 검사
        isFail = False
        if (x,y,0) in construct and not columnCheck('VALID',x,y): isFail = True
        if (x+1,y,0) in construct and not columnCheck('VALID',x+1,y): isFail = True
        if (x-1,y,1) in construct and not rowCheck('VALID',x-1,y): isFail = True
        if (x+1,y,1) in construct and not rowCheck('VALID',x+1,y): isFail = True
        if isFail: construct.add((x,y,1)) # 원상복구
        else: return True
    elif type == 'CREATE':
        # 생성 명령
        isFail = True
        if (x,y-1,0) in construct or (x+1,y-1, 0) in construct: 
            isFail = False # 한쪽 끝 부분이 기둥 위에 있거나
        if (x-1,y, 1) in construct and (x+1,y,1) in construct: 
            isFail = False # 양쪽 끝이 다른 보와 동시에 연결
        if not isFail: 
          construct.add((x,y,1))
          return True
    else:
        construct.remove((x,y,1))
        if rowCheck('CREATE',x,y): return True
        else: construct.add((x,y,1)) 
                
    return False
    
    
def columnCheck(type,x,y):
    if type == 'DELETE':
        # 삭제 명령
        if (x,y,0) not in construct: return False
        construct.remove((x,y,0))
        # 위 col 검사 & 양옆 row 검사
        isFail = False
        if (x,y+1,0) in construct and not columnCheck('VALID',x,y+1): isFail = True
        if (x-1,y+1,1) in construct and not rowCheck('VALID',x-1,y+1): isFail = True
        if (x,y+1,1) in construct and not rowCheck('VALID',x,y+1): isFail = True
        if isFail: construct.add((x,y,0)) # 원상복구
        else: return False
    elif type == 'CREATE':
        # 생성 명령
        isFail = True
        if y == 0: isFail = False # 바닥 위에 있거나
        if (x-1,y,1) in construct or (x,y,1) in construct : isFail = False # 보의 한쪽 끝 위에 있거나
        if (x,y-1,0) in construct: isFail = False # 또 다른 기둥 위에 있거나
        if not isFail: 
          construct.add((x,y,0))
          return True
    else: 
        construct.remove((x,y,0))
        if columnCheck('CREATE',x,y): return True
        else: construct.add((x,y,0))
        
    return False

def solution(n, build_frame):
    global construct
    construct = set()
    
    for order in build_frame:
        #print('ORDER',order)
        #print('NOW', construct)
        x = order[0]
        y = order[1]
        # 기둥
        if order[2] == 0:
            if order[3] == 0: columnCheck('DELETE',x,y)
            if order[3] == 1: columnCheck('CREATE',x,y)
        # 보
        if order[2] == 1:
            if order[3] == 0: rowCheck('DELETE',x,y)
            if order[3] == 1: rowCheck('CREATE',x,y)
               
        
    result = []

    for item in construct:
        result.append([item[0], item[1], item[2]])
                       
    result = sorted(result, key=lambda x: (x[0],x[1],x[2]))
                    
    return result
                    

'''
