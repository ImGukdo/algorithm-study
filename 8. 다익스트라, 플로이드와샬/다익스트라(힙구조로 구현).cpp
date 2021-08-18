#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int iNum = 6;  // 정점 수 
int INF = 10000000;  // 무한 거리 

vector<pair<int, int> > vec[7];  // 정점과 정점의 거리 
int iDistance[7];  // 최소 거리 저장 변수 

void Dijkstra(int iInput){
	iDistance[iInput] = 0;  // 자기 자신과의 거리는 0 
	priority_queue<pair<int, int> > pq;  // 우선순위 큐 생성 
	pq.push(make_pair(0, iInput));  // 자기 자신을 처음에 넣어준다 
	
	while(!pq.empty()){
		int iCurrent = pq.top().second;  // 큐에 들어 있는 것중 거리가 제일 짧은 정점 
		int iCurrentDistance = -pq.top().first;  // 큐에 들어 있는 것중 제일 짧은 거리 
		pq.pop();  // 큐에서 뺀다 
		if(iDistance[iCurrent] < iCurrentDistance)  // 만약 그 정정까지의 거리가 큐에서 꺼낸거보다 이미 더 작다면 
		continue;  // 패스 
		for(int i = 0; i < vec[iCurrent].size(); ++i){  // 연결되어 있는 정정을 탐색하면서 
			int iNext = vec[iCurrent][i].first;  // 연결된 정점 
			int iNextDistance = iCurrentDistance + vec[iCurrent][i].second;  // 시작점부터 연결된 정점까지 거리 
			
			if(iNextDistance < iDistance[iNext]){  // 새로 구한 거리가 더 짧으면 변경 
				iDistance[iNext] = iNextDistance;
				pq.push(make_pair(-iNextDistance, iNext));
			}
		}
	}
	
} 

int main(void){
	for(int i = 1; i <= iNum; ++i){  // 처음 거리는 무한으로 초기화 
		iDistance[i] = INF;
	}
	// 그래프 생성 
	vec[1].push_back(make_pair(2, 2));
	vec[1].push_back(make_pair(3, 5));
	vec[1].push_back(make_pair(4, 1));
	
	vec[2].push_back(make_pair(1, 2));
	vec[2].push_back(make_pair(3, 3));
	vec[2].push_back(make_pair(4, 2));
	
	vec[3].push_back(make_pair(1, 5));
	vec[3].push_back(make_pair(2, 3));
	vec[3].push_back(make_pair(4, 3));
	vec[3].push_back(make_pair(5, 1));
	vec[3].push_back(make_pair(6, 5));
	
	vec[4].push_back(make_pair(1, 1));
	vec[4].push_back(make_pair(2, 2));
	vec[4].push_back(make_pair(3, 3));
	vec[4].push_back(make_pair(5, 1));
	
	vec[5].push_back(make_pair(3, 1));
	vec[5].push_back(make_pair(4, 1));
	vec[5].push_back(make_pair(6, 2));
	
	vec[6].push_back(make_pair(3, 5));
	vec[6].push_back(make_pair(5, 2));
	
	Dijkstra(1);
	
	for(int i = 1; i <= iNum; ++i){
		cout << iDistance[i] << " ";
	}
	return 0;
}
// O(N * logN)
