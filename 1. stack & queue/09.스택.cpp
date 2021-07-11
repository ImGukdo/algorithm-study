// 자료구조 중 하나로 입출구가 하나인 구조라고 생각하면 된다.
// 따라서 가장 마지막에 들어온 것이 가장 위에 위치하고
// 가장 위에 있는 데이터를 스택구조에서 뺄수 있다.

#include <iostream>
#include <stack>

using namespace std;

int main(void){
	stack<int> stk;  // 스택생성 
	
	stk.push(1);  // 스택에 데이터를 하나씩 넣어준다. 
	stk.push(2);
	stk.push(3);
	stk.pop();  // 스택에 제일 위에 있는 데이터 제거 
	stk.push(4);  // 다시 스택에 데이터를 넣는다. 
	stk.pop();  // 다시 스택에 제일 위에 있는 데이터를 제거 
	
	while(!stk.empty()){  // 스택이 빌때까지 반복하면서 
		cout << stk.top() << " ";  // 스택의 제일 위에 있는 데이터를 확인, 2 1
		stk.pop();  // 제일 위에 위치하는 데이터 제거 
	}
	return 0;
}
