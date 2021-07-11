# https://programmers.co.kr/learn/courses/30/lessons/42584
# 프로그래머스 주식가격 문제
# 초 단위로 기록된 주식가격이 담긴 배열 prices가 매개변수로 주어질 때, 
# 가격이 떨어지지 않은 기간은 몇 초인지를 return 하도록 
# solution 함수를 완성하세요.

def solution(prices):
    answer = []
    for i in range(0, len(prices)) :  # 가격을 하나씩 탐색하기 위해 반복문 실행
        iCount = 0  # 하나의 가격의 유지된 초를 기록
        for j in range(i + 1, len(prices)) :  # 현재 위치 이후의 가격과 비교를 위해 반복문 실행
            if prices[i] <= prices[j] :  # 가격이 떨어지지 않았으면
                iCount += 1  # 1초 증가 후 반복
            else :
                iCount += 1  # 가격이 떨어졌으면 1초 증가 후 반복문 탈출
                break
        answer.append(iCount)  # 계산된 시간을 저장
    return answer