# https://programmers.co.kr/learn/courses/30/lessons/42839
# 프로그래머스 소수찾기 문제 
# 한자리 숫자가 적힌 종이 조각이 흩어져있습니다. 
# 흩어진 종이 조각을 붙여 소수를 몇 개 만들 수 있는지 알아내려 합니다.
# 각 종이 조각에 적힌 숫자가 적힌 문자열 numbers가 주어졌을 때, 
# 종이 조각으로 만들 수 있는 소수가 몇 개인지 return 하도록 solution 함수를 완성해주세요.

number = []  # 내가 가지고 있는 숫자들
iCount = 0  # 소수갯수 저장 
remember = []  # 조합해서 만든 숫자들을 저장 
bCheck = [False] * 10  # 탐색한 인덱스인지 체크

# 소수인지 아닌지 판별하는 함수, 숫자를 하나씩 늘려가며 판별하기 위해 재귀함수로 구현
def Dfs(num, place, index) :  # 매개변수 : 조합해서 입력받은 수, 몇개의 수의 조합인지 갯수, 조합한 인덱스
    global iCount  # 전역변수를 사용, 변경하기 위해 선언
    global bCheck  # 전역변수를 사용, 변경하기 위해 선언
    remember.append(num)  # 조합된 숫자 저장
    bCheck[index] = True  # 조합한 인덱스를 체크 
    iCount += 1  # 일단 소수라고 가정하고 소수 증가 
    for i in range(2, int(num**(1/2)) + 1) :  # 소수인지 판별, 조합된 숫자의 제곱근까지만 반복하여 반복을 줄임
        if num % i == 0 :  # 소수라면 
            iCount -= 1  # 소수갯수 감소
            break  # 반복문 탈출
    
    if place == len(number) - 1 :  # 가지고 있는 숫자 길이만큼 전부 조합했으면 
        return  # 리턴
    
    for i in range(0, len(number)) :  # 내가 가진 숫자들의 인덱스를 반복하면서 
        if num * 10 + number[i] in remember :  # 이미 조합해서 만든 숫자인지 체크
            continue
        if not bCheck[i] :  # 내가 가진 숫자의 탐색한 인덱스가 아니면
            Dfs(num * 10 + number[i], place + 1, i)  # 새로 조합한 숫자, 조합된 숫자 갯수, 인덱스로 재귀함수 실행
            bCheck[i] = False  # 재귀함수가 종료되서 돌아오면 수행한 인덱스를 다시 탐색안한 것으로 체크

def solution(numbers):
    answer = 0
    global iCount  # 전역변수를 사용, 변경하기 위해 선언
    global bCheck  # 전역변수를 사용, 변경하기 위해 선언
    for i in numbers :  # 문자열로 받은 숫자를 정수형으로 변환하여 저장 
        number.append(int(i))
    index_check = []  # 반복 실행을 방지하기 위해 탐색한 숫자를 저장    
    for idx, i in enumerate(number) :  # 내가 가진 숫자들을 탐색
        if i == 0 or i in index_check:  # 첫번째 숫자로 0이나 이미 수행했던 숫자면 패스
            continue
        bCheck = [False] * 10  # 다시 한자리수부터 반복하기때문에 탐색한 인덱스가 없다고 초기화 
        index_check.append(i)  # 탐색한 수를 저장
        if i == 1 :  # 첫번째 숫자가 1이면 소수가 아니므로 
            iCount -= 1  # 소수를 감소하고 시작, 소수판별함수에서 1 증가시키기 때문 
        Dfs(i, 0, idx)  # 소수판별함수 실행 
    answer = iCount  # 계산된 소수갯수를 정답에 넣어준다
    
    return answer