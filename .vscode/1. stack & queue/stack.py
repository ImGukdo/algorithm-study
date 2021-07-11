# 자료구조 stack
# 자료구조 중 하나로 입출구가 하나인 구조라고 생각하면 된다.
# 따라서 가장 마지막에 들어온 것이 가장 위에 위치하고
# 가장 위에 있는 데이터를 스택구조에서 뺄수 있다.
# 리스트로 구현

lst_stack = []  # 스택구조를 표현하기 위해 리스트를 하나 생성
lst_stack.append(1)  # 스택에 데이터를 하나씩 넣어준다.
lst_stack.append(2)
lst_stack.append(3)
lst_stack.append(4)
lst_stack.append(5)
print(lst_stack[-1])  # 스택에 제일 위에 위치하는 데이터를 확인
lst_stack.pop()  # 제일 위에 있는 데이터를 제거
print(lst_stack[-1])  # 스택에 제일 위에 위치하는 데이터를 확인

# 스택은 자료구조로 어떻게 존재하는지만 이해하고 응용할 수 있으면 된다.