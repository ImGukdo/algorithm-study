// https://programmers.co.kr/learn/courses/30/lessons/12978
// 프로그래머스 배달 문제 
// N개의 마을로 이루어진 나라가 있습니다. 
// 이 나라의 각 마을에는 1부터 N까지의 번호가 각각 하나씩 부여되어 있습니다. 
// 각 마을은 양방향으로 통행할 수 있는 도로로 연결되어 있는데, 
// 서로 다른 마을 간에 이동할 때는 이 도로를 지나야 합니다. 
// 도로를 지날 때 걸리는 시간은 도로별로 다릅니다. 
// 현재 1번 마을에 있는 음식점에서 각 마을로 음식 배달을 하려고 합니다. 
// 각 마을로부터 음식 주문을 받으려고 하는데, 
// N개의 마을 중에서 K 시간 이하로 배달이 가능한 마을에서만 주문을 받으려고 합니다.
// 마을의 개수 N, 각 마을을 연결하는 도로의 정보 road, 
// 음식 배달이 가능한 시간 K가 매개변수로 주어질 때, 
// 음식 주문을 받을 수 있는 마을의 개수를 return 하도록 solution 함수를 완성해주세요.


#include <iostream>
#include <vector>
#include <queue>

using namespace std;
#define INF 10000000  // 무한 
vector<int> vec;  
vector<pair<int, int> > vTemp[51];
void Dijkstra(int iInput){
    vec[iInput] = 0;
    priority_queue<pair<int, int> > pq;
    pq.push(make_pair(0, iInput));
    
    while(!pq.empty()){
        int iIndex = pq.top().second;
        int iDistance = -pq.top().first;
        pq.pop();
        if(vec[iIndex] < iDistance)
            continue;
        for(int i = 0; i < vTemp[iIndex].size(); ++i){
            int iNext = vTemp[iIndex][i].first;
            int iNextDistance = vTemp[iIndex][i].second + iDistance;
            
            if(iNextDistance < vec[iNext]){
                vec[iNext] = iNextDistance;
                pq.push(make_pair(-iNextDistance, iNext));
            }
        }
    }
}
int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;
    for(int i = 0; i <=  N; ++i){  // 걸리는 시간 초기값 무한으로 설정 
        vec.push_back(INF);
    }
    
    for(int i = 0; i < road.size(); ++i){  // 각 도시에서 도시로 가는 거리를 다시 도시마다 정리해서 저장 
        vTemp[road[i][0]].push_back(make_pair(road[i][1], road[i][2]));
        vTemp[road[i][1]].push_back(make_pair(road[i][0], road[i][2]));
    }
    
    Dijkstra(1);
    for(int i = 1; i <= N; ++i){
        if(vec[i] <= K)
            ++answer;
    }
    return answer;
}
