# https://www.acmicpc.net/problem/5692
# 백준 팩토리얼 진법 문제
# 상근이는 보통 사람들이 사는 것과는 조금 다른 삶을 사는 사람이다. 
# 상근이는 이런 사람들의 시선이 부담스럽기 때문에, 자신만의 숫자를 개발하기로 했다. 
# 바로 그 이름은 팩토리얼 진법이다. 
# 팩토리얼 진법은 각 자리에 올 수 있는 숫자는 0부터 9까지로 10진법과 거의 비슷하다. 
# 하지만, 읽는 법은 조금 다르다. 팩토리얼 진법에서는 i번 자리의 값을 ai×i!로 계산한다. 
# 즉, 팩토리얼 진법에서 719는 10진법에서 53과 같다. 그 이유는 7×3! + 1×2! + 9×1! = 53이기 때문이다.
# 팩토리얼 진법으로 작성한 숫자가 주어졌을 때, 10진법으로 읽은 값을 구하는 프로그램을 작성하시오.

if __name__ == "__main__" :
    factorial = [0, 1]  # 최대 5까지이므로 팩토리얼을 미리 계산해놓는다. 
    for i in range(2, 6) :
        factorial.append(factorial[-1] * i)
    lst = []  # 10진법으로 변환한 수 저장
    
    while True :  # 수를 입력받음
        iTemp = input()
        if iTemp == '0' :
            break
        lst.append(iTemp)

    for i in lst :  # 입력값을 탐색하면서 
        iSum = 0
        for jdx, j in enumerate(i) :  # 10진법으로 변환
            iSum += int(j) * factorial[len(i) - jdx]
        print(iSum)