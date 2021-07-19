# https://programmers.co.kr/learn/courses/30/lessons/43165
# 프로그래머스 타겟넘버 문제 
# n개의 음이 아닌 정수가 있습니다. 
# 이 수를 적절히 더하거나 빼서 타겟 넘버를 만들려고 합니다. 
# 예를 들어 [1, 1, 1, 1, 1]로 숫자 3을 만들려면 다음 다섯 방법을 쓸 수 있습니다.
# -1+1+1+1+1 = 3
# +1-1+1+1+1 = 3
# +1+1-1+1+1 = 3
# +1+1+1-1+1 = 3
# +1+1+1+1-1 = 3
# 사용할 수 있는 숫자가 담긴 배열 numbers, 타겟 넘버 target이 매개변수로 주어질 때 
# 숫자를 적절히 더하고 빼서 타겟 넘버를 만드는 방법의 수를 return 하도록 solution 함수를 작성해주세요.

iCount = 0  # 방법의 수, 전역변수
def Dfs(numbers, target, iIndex, iSum) :  # 사용한 숫자들, 타겟 넘버, 몇번째 수인지, 숫자들의 합 
    global iCount  # 전역변수 사용
    if len(numbers) == iIndex :  # 마지막 숫자까지 다 더 했으면 
        if target == iSum :  # 타겟 넘버와 같은지 체크해서 같으면
            iCount += 1  # 개수 증가 
        return  # 리턴
    
    Dfs(numbers, target, iIndex + 1, iSum + numbers[iIndex])  # 숫자를 더한다 
    Dfs(numbers, target, iIndex + 1, iSum - numbers[iIndex])  # 숫자를 뺀다

    
def solution(numbers, target):
    answer = 0
    Dfs(numbers, target, 0, 0)  # DFS 실행
    answer = iCount
    return answer
    