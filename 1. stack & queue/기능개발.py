# https://programmers.co.kr/learn/courses/30/lessons/42586
# 프로그래머스 기능개발 문제
# 프로그래머스 팀에서는 기능 개선 작업을 수행 중입니다. 각 기능은 진도가 100%일 때 서비스에 반영할 수 있습니다.
# 또, 각 기능의 개발속도는 모두 다르기 때문에 뒤에 있는 기능이 앞에 있는 기능보다 먼저 개발될 수 있고, 
# 이때 뒤에 있는 기능은 앞에 있는 기능이 배포될 때 함께 배포됩니다.
# 먼저 배포되어야 하는 순서대로 작업의 진도가 적힌 정수 배열 progresses와 각 작업의 개발 속도가 
# 적힌 정수 배열 speeds가 주어질 때 각 배포마다 몇 개의 기능이 배포되는지를 return 하도록 solution 함수를 완성하세요.

def solution(progresses, speeds):
    answer = []
    while True :  # 반복문을 통해 모든 기능들이 완료될때까지 반복 수행
        for i in range(0, len(progresses)) :  # 작업 진도들을 탐색
            if progresses[i] != -1 :  # 완료가 되지 않았으면
                progresses[i] += speeds[i]  # 개발속도만큼 진행
        iCount = 0  # 배포할 기능의 수 
        for i in range(0, len(progresses)) :  # 개발속도만큼 진행 후 완료됐는지 탐색
            if progresses[i] < 0 :  # 이미 완료 됐으면 통과
                continue
            elif progresses[i] >= 100 :  # 완료 됐으면 
                progresses[i] = -1  # 완료 됐다고 -1로 표시
                iCount += 1  # 배포 기능수 증가
                continue  # 다음 완료된것이 있는지 확인하기 위해 반복 수행
            break  # 앞에것부터 탐색하면서 완료된 기능이 없으면 탈출, 앞에 기능이 완료돼야 배포할 수 있기 때문에

        if iCount != 0 :  # 배포할 기능들이 있으면 
            answer.append(iCount)  # 수량 저장
        if progresses[-1] == -1 :  # 마지막 기능까지 완료됐으면 반복문 탈출
            break
    return answer