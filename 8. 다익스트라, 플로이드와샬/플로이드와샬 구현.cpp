#include <iostream>

using namespace std;

int iNum = 4;  // 정점 수 
int INF = 10000000;  // 거리 무한 

int iStore[4][4] = {  // 정점과 정점의 거리를 저장 
    {0, 5, INF, 8},
    {7, 0, 9, INF},
    {2, INF, 0, 4},
    {INF, INF, 3, 0}
};

void FloydWarshall(){
	int iResult[iNum][iNum];  // 결과를 저장한 배열 
	
	for(int i = 0; i < iNum; ++i){  // 결과 저장 변수를 초기화 
		for(int j = 0; j < iNum; ++j){
			iResult[i][j] = iStore[i][j];
		}
	}
	
	// k는 거쳐가는 노드 
	for(int k = 0; k < iNum; ++k){
		for(int i = 0; i < iNum; ++i){  // i 출발 노드 
			for(int j = 0; j < iNum; ++j){  // j 도착 노드 
				if(iResult[i][k] + iResult[k][j] < iResult[i][j])  // 거쳐가는 노드를 통하는 거리가 더 짧으면 변경 
				iResult[i][j] = iResult[i][k] + iResult[k][j];
			}
		}
	}
	
	// 결과 출력 
	for(int i = 0; i < iNum; ++i){
		for(int j = 0; j < iNum; ++j){
			cout << iResult[i][j] << " ";
		}
		cout << endl;
	}
}
int main(void){
	FloydWarshall();
	return 0;
}
