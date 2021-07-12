# 이진검색이라고도 표현하며 오름차순으로 정렬된 리스트에서
# 특정값의 위치를 찾는 알고리즘
# 중간의 값을 선택하여 찾고자 하는 값과의 크고 작음을 비교하는 방법

# 1부터 1000 사이의 원하는 값을 찾는 방법

def Find(iStart, iEnd, iTarget) :  # 원하는 값을 찾는 재귀함수
    if iStart > iEnd :  # 범위값에서 시작 값이 더 크면 
        return -1  # -1 반환
    iMiddle = (iStart + iEnd) // 2  # 중간값 설정
    if iMiddle == iTarget :  # 중간값이 원하는 수와 값으면
        return iMiddle  # 중간값 반환
    elif iMiddle > iTarget :  # 중간값이 더 크면
        return Find(iStart, iMiddle - 1, iTarget)  # 증간값 보다 작은 범위에서 다시 탐색
    else :  # 중간값이 더 작으면
        return Find(iMiddle + 1, iEnd, iTarget)  # 증간값 보다 큰 범위에서 다시 탐색

iIndex = Find(1, 1001, 707)  # 1부터 1000사이에서 707이 몇번째에 위치하는지 탐색
if iIndex != -1 :  # 시작값이 끝값보다 크지 않으면
    print(iIndex)  # 찾은 인덱스 출력