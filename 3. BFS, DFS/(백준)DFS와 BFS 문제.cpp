// https://www.acmicpc.net/problem/1260
// 백준 DFS와 BFS 문제
// 그래프를 DFS로 탐색한 결과와 BFS로 탐색한 결과를 출력하는 프로그램을 작성하시오. 
// 단, 방문할 수 있는 정점이 여러 개인 경우에는 정점 번호가 작은 것을 먼저 방문하고, 
// 더 이상 방문할 수 있는 점이 없는 경우 종료한다. 정점 번호는 1번부터 N번까지이다. 

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<int> vec[1001];  // 그래프를 만들기 위해 벡터 선언 
bool bCheck[1001];  // 정점을 방문했는지 체크 

void Bfs(int iStart){  // BFS 구현 함수 
	queue<int> que;  
	que.push(iStart);  // 시작 정점을 큐에 넣기 
	bCheck[iStart] = true;  // 시작 정점을 방문했다고 체크 
	
	while(!que.empty()){  // 큐가 빌때까지 반복 
		int k = que.front();  // 큐에 제일 앞에 있는 원소를 
		printf("%d ", k);  // 출력 
		que.pop();  // 제거 
		
		for(int i = 0; i < vec[k].size(); ++i){  // 정점과 연결된 정점들을 탐색 
			int z = vec[k][i];  // 연결된 정점 
			
			if(!bCheck[z]){  // 방문하지 않은 정점이라면 
				bCheck[z] = true;  //  방문했다고 체크 
				que.push(z);  // 큐에 넣기 
			}
		}
	}	
}

void Dfs(int iStart){  // DFS 구현 함수 
	bCheck[iStart] = true;  // 정점을 방문했다고 체크 
	printf("%d ", iStart);  // 출력 
	
	for(int i = 0; i < vec[iStart].size(); ++i){  // 정점과 연결된 정점을 탐색하면서 
		int k = vec[iStart][i];  // 연결된 정점 
		
		if(!bCheck[k])  // 방문하지 않은 정점이라면 
		Dfs(k);  // DFS 함수 실행 
	}
}

int main(void){
	int x, y, iStart;
	scanf("%d %d %d", &x, &y, &iStart);
	
	int a, b;
	for(int i = 0; i < y; ++i){
		scanf("%d %d", &a, &b);
		vec[a].push_back(b);
		vec[b].push_back(a);
	} // 그래프 구현 
	
	for(int i = 0; i <= 1000; ++i){
		if(vec[i].size() != 0)
		sort(vec[i].begin(), vec[i].end());
	}  // 정점의 번호가 작은것부터 방문하기 위해 오름차순으로 정렬 
	
	Dfs(iStart);  //  DFS 함수 실행 
	printf("\n");
	fill(bCheck, bCheck + 1001, false);  // 방문체크를 초기화 
	Bfs(iStart);  // BFS 함수 실행 
	
	return 0;
}
