#include <iostream>

using namespace std;

int INF = 10000000;  // 거리가 무한 
int iNum = 6;  // 정점의 개수 
int iStore[6][6] = {  // 정점에서 정점까지의 거리들 
    {0, 2, 5, 1, INF, INF},
    {2, 0, 3, 2, INF, INF},
    {5, 3, 0, 3, 1, 5},
    {1, 2, 3, 0, 1, INF},
    {INF, INF, 1, 1, 0, 2},
    {INF, INF, 5, INF, 2, 0}
	};
int iVisit[6];  // 방문했는지 확인 변수 
int iDistance[6];  // 정점에서 정점까지의 최소거리 저장 변수 

int GetSmallIndex(){  // 시작 정점에서 다른 정점까지의 거리중 최소인 인덱스를 찾는 함수 
	int iMin = INF;
	int iIndex;
	
	for(int i = 0; i < iNum; ++i){
		if(!iVisit[i] && iDistance[i] < iMin){
			iMin = iDistance[i];
			iIndex = i;
		}
	}
	return iIndex;
}

void Dijkstra(int iInput){
	for(int i = 0; i < iNum; ++i){  // 시작 정점을 정해서 시작 정점에서 연결되있는 정점의 거리를 넣어준다. 
		iDistance[i] = iStore[iInput][i];
	}
	iVisit[iInput] = true;  // 시작 정점을 방문했다고 체크 
	for(int i = 0; i < iNum - 2; ++i){  // 방문안한 정점수 만큼 반복, 시작점과 제일 마지막점을 뺀수 만큼 반복 
		int iCurrentIndex = GetSmallIndex();  // 방문 안한 정점중 최소 거리 인덱스를 반환해 옴 
		iVisit[iCurrentIndex] = true;  // 정점을 방문했다고 체크 
		for(int j = 0; j < iNum; ++j){
			if(!iVisit[j]){  // 방문안한 정점 중에 
				if(iDistance[iCurrentIndex] + iStore[iCurrentIndex][j] < iDistance[j])  // 최소 거리 인덱스를 거쳐서 이동한 정점까지의 거리가 더 작으면 변경 
				iDistance[j] = iDistance[iCurrentIndex] + iStore[iCurrentIndex][j];
			}
		}
	}
}
int main(void){
	Dijkstra(0);
	for(int i = 0; i < iNum; ++i){
		cout << iDistance[i] << " ";
	} 
	return 0;
}
// 선형탐색을 사용했으므로 O(N^2) 
