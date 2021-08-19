// https://www.acmicpc.net/problem/18352
// 백준 특정 거리의 도시 찾기
// 어떤 나라에는 1번부터 N번까지의 도시와 M개의 단방향 도로가 존재한다. 
// 모든 도로의 거리는 1이다.
// 이 때 특정한 도시 X로부터 출발하여 도달할 수 있는 모든 도시 중에서, 
// 최단 거리가 정확히 K인 모든 도시들의 번호를 출력하는 프로그램을 작성하시오. 
// 또한 출발 도시 X에서 출발 도시 X로 가는 최단 거리는 항상 0이라고 가정한다. 


#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
#define INF 100000000  // 거리가 무한인것을 설정 
vector<pair<int, int> > vec[300001];  // 도시와 도시 사이의 거리들 

void Dijkstra(int iStart, int* iResult){
	iResult[iStart] = 0;  // 시작 도시에서 시작 도시로의 거리는 0 
	priority_queue<pair<int, int> > pq;  // 거리와 도시를 넣어주는 우선순위 큐 생성 
	pq.push(make_pair(0, iStart));  // 거리 0과 시작도시를 넣어준다 
	
	while(!pq.empty()){  // 큐가 빌때까지 반복하면서 
		int iIndex = pq.top().second;  // 우선순위 큐의 제일 위에 있는 원소를 통해 인덱스를 구한다 
		int iDistance = -pq.top().first;  // 거리를 구한다 
		pq.pop();  // 큐에서 제거 
		if(iResult[iIndex] < iDistance)  // 만약에 큐에서 꺼낸 값보다 이미 작다면 
		continue;  // 통과 
		
		for(int i = 0; i < vec[iIndex].size(); ++i){  // 연결되어 있는 도시들을 탐색하면서 
			int iNext = vec[iIndex][i].first;  // 연결된 도시 
			int iNextDistance = vec[iIndex][i].second + iDistance;  // 시작 도시에서 연결된 도시까지의 거리 
			
			if(iNextDistance < iResult[iNext]){  // 현재까지 구한 거리보다 작으면 
				iResult[iNext] = iNextDistance;  // 값을 변경 
				pq.push(make_pair(-iNextDistance, iNext));  // 값을 큐에 넣어준다 
			}
		} 
	}
}
int main(void){
	int iNum, iRoad, iDistance, iStart;
	scanf("%d %d %d %d", &iNum, &iRoad, &iDistance, &iStart);
	int a, b;
	for(int i = 0; i < iRoad; ++i){  // 도시들의 거리 그래프 구현 
		scanf("%d %d", &a, &b);
		vec[a].push_back(make_pair(b, 1));
	}
	int iResult[iNum + 1];  // 최소거리를 저장할 변수 
	fill(iResult, iResult + iNum + 1, INF);  // 무한값으로 초기화 
	Dijkstra(iStart, iResult);
	vector<int> vAnswer;
	for(int i = 1; i <= iNum; ++i){  // 구한 최소거리가 K(iDistance)인지 확인 
		if(iResult[i] == iDistance)
		vAnswer.push_back(i);
	}
	if(vAnswer.empty())  // K인 값이 없으면 -1 
	printf("%d", -1);
	else{  // K인 값이 있을때 
		sort(vAnswer.begin(), vAnswer.end());  // 도시들을 오름차순 정렬해준다 
		for(int i = 0; i < vAnswer.size(); ++i){
			printf("%d\n", vAnswer[i]);
		}
	}
	return 0;
}
