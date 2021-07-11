// 자료구조 중 하나로 입구와 출구가 따로 있는 구조라고 생각하면 된다.
// 먼저 들어온 데이터가 입구로 들어와 출구쪽으로 이동하고
// 다음으로 들어온 데이터가 순서대로 앞의 데이터 뒤에 위치하는 구조이다.
// 가장 먼저 들어온 데이터부터 데이터를 뺄 수 있다.

#include <iostream>
#include <queue>

using namespace std;

int main(void){
	queue<int> que;  // 큐 생성 
	
	que.push(1);  // 큐에 데이터를 하나씩 넣어준다. 
	que.push(2);
	que.push(3);
	que.pop();  // 큐에 제일 앞에 있는 데이터를 제거 
	que.push(4);  // 다시 큐에 데이터를 넣는다. 
	que.pop();  // 다시 큐에 제일 앞에 있는 데이터를 제거 
	
	while(!que.empty()){  // 큐가 빌때까지 반복하면서 
		cout << que.front() << " ";  // 큐에 제일 앞에 있는 데이터를 확인, 3 4 
		que.pop();  // 제일 앞에 있는 데이터를 제거 
	}
	return 0;
}
