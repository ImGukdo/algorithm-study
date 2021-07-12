# 브루트 포스 라고도 불리며 컴퓨터의 빠른 계산 성능을 활용하여
# 가능한 모든 경우의 수를 탐색하는 효율성 관점에서 최악의 방법

# 1부터 9까지 수를 가진 리트스가 있을 때
lst = [5, 8, 7, 6, 3, 1, 2, 9, 4]

# 원하는 숫자 예를 들어 3을 찾는 방법은
index = -1
for idx, i in enumerate(lst) :  # 리스트를 지정한 순서로 탐색하면서
    if i == 3 :  # 원하는 숫자를 찾으면
        index = idx
        break  # 종료

print(lst[index])  # 원하는 숫자 3 출력




