// https://programmers.co.kr/learn/courses/30/lessons/49189
// 프로그래머스 가장 먼 노드 문제
// n개의 노드가 있는 그래프가 있습니다. 각 노드는 1부터 n까지 번호가 적혀있습니다. 
// 1번 노드에서 가장 멀리 떨어진 노드의 갯수를 구하려고 합니다. 
// 가장 멀리 떨어진 노드란 최단경로로 이동했을 때 간선의 개수가 가장 많은 노드들을 의미합니다.
// 노드의 개수 n, 간선에 대한 정보가 담긴 2차원 배열 vertex가 매개변수로 주어질 때,
// 1번 노드로부터 가장 멀리 떨어진 노드가 몇 개인지를 return 하도록 solution 함수를 작성해주세요. 


#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>

using namespace std;
#define INF 100000  // 무한 
vector<pair<int, int> > vec[20001];  // 노드와 노드가 연결되어 있는지 나타내는 벡터 

void Dijkstra(int iStart, int* iResult){  // 다익스트라를 통해 1번 노드부터 각노드까지의 최소 거리를 구함 
    iResult[iStart] = 0;
    priority_queue<pair<int, int> > pq;
    pq.push(make_pair(0, iStart));
    
    while(!pq.empty()){
        int iIndex = pq.top().second;
        int iDistance = -pq.top().first;
        pq.pop();
        if(iResult[iIndex] < iDistance)
            continue;
        for(int i = 0; i < vec[iIndex].size(); ++i){
            int iNext = vec[iIndex][i].first;
            int iNextDistance = vec[iIndex][i].second + iDistance;
            
            if(iNextDistance < iResult[iNext]){
                iResult[iNext] = iNextDistance;
                pq.push(make_pair(-iNextDistance, iNext));
            }
        }
    }
}
int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    
    for(int i = 0; i < edge.size(); ++i){  // 노드의 연결상태를 노드별로 구분하여 저장 
        vec[edge[i][0]].push_back(make_pair(edge[i][1], 1));
        vec[edge[i][1]].push_back(make_pair(edge[i][0], 1));
    }
    int iResult[n + 1];  // 최소 거리를 저장할 변수 
    fill(iResult, iResult + n + 1, INF);  // 초기값을 무한으로 설정 
    Dijkstra(1, iResult);
    sort(iResult, iResult + n + 1);  // 구한 값을 정렬한다 
    for(int i = n - 1; i >= 0; --i){  // 최대값의 개수를 센다 
        if(iResult[i] == iResult[n - 1]){
            ++answer;
            continue;
        }
        break;
    }
    return answer;
}
