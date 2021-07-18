// https://www.acmicpc.net/problem/2606
// 백준 바이러스 문제
// 신종 바이러스인 웜 바이러스는 네트워크를 통해 전파된다. 
// 한 컴퓨터가 웜 바이러스에 걸리면 그 컴퓨터와 네트워크 상에서 
// 연결되어 있는 모든 컴퓨터는 웜 바이러스에 걸리게 된다.

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> vec[101];  // 그래프 구현을 위해 벡터 선언 

bool bCheck[101];  // 방문한 컴퓨터인지 체크 

int Bfs(int iStart){  // BFS 함수 구현 
	int iCount = 0;  // 감염된 컴퓨터 개수 
	queue<int> que;
	que.push(iStart);  // 최초 감염된 컴퓨터를 큐에 넣기 
	bCheck[iStart] = true;  // 감염된 컴퓨터 체크 
	
	while(!que.empty()){  // 큐가 빌때까지 반복 
		int k = que.front();  // 큐에 제일 앞에 있는 원소 
		que.pop();  // 큐에서 제거 
		++iCount;  // 개수 추가 
		for(int i = 0; i < vec[k].size(); ++i){  // 제거한 컴퓨터와 연결된 컴퓨터들을 탐색 
			int z = vec[k][i];  // 연결된 컴퓨터 
			
			if(!bCheck[z]){  // 감염체크를 안한 컴퓨터라면 
				bCheck[z] = true;  // 체크했다고 표시 
				que.push(z);  // 큐에 넣기 
			}
		}
	}
	return iCount - 1;  // 최초 감염된 컴퓨터를 빼고 반환		
}

int main(void){
	int iNum;
	scanf("%d", &iNum);
	int a;
	scanf("%d", &a);
	int b, c;
	for(int i = 0; i < a; ++i){
		scanf("%d %d", &b, &c);
		vec[b].push_back(c);
		vec[c].push_back(b);
	}  // 그래프 구현 
	
	printf("%d", Bfs(1));  // BFS 함수를 통해 감염된 컴퓨터 개수 출력 
	
	return 0;
}
