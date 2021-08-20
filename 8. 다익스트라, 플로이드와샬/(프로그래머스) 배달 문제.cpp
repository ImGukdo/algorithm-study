// https://programmers.co.kr/learn/courses/30/lessons/12978
// ���α׷��ӽ� ��� ���� 
// N���� ������ �̷���� ���� �ֽ��ϴ�. 
// �� ������ �� �������� 1���� N������ ��ȣ�� ���� �ϳ��� �ο��Ǿ� �ֽ��ϴ�. 
// �� ������ ��������� ������ �� �ִ� ���η� ����Ǿ� �ִµ�, 
// ���� �ٸ� ���� ���� �̵��� ���� �� ���θ� ������ �մϴ�. 
// ���θ� ���� �� �ɸ��� �ð��� ���κ��� �ٸ��ϴ�. 
// ���� 1�� ������ �ִ� ���������� �� ������ ���� ����� �Ϸ��� �մϴ�. 
// �� �����κ��� ���� �ֹ��� �������� �ϴµ�, 
// N���� ���� �߿��� K �ð� ���Ϸ� ����� ������ ���������� �ֹ��� �������� �մϴ�.
// ������ ���� N, �� ������ �����ϴ� ������ ���� road, 
// ���� ����� ������ �ð� K�� �Ű������� �־��� ��, 
// ���� �ֹ��� ���� �� �ִ� ������ ������ return �ϵ��� solution �Լ��� �ϼ����ּ���.


#include <iostream>
#include <vector>
#include <queue>

using namespace std;
#define INF 10000000  // ���� 
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
    for(int i = 0; i <=  N; ++i){  // �ɸ��� �ð� �ʱⰪ �������� ���� 
        vec.push_back(INF);
    }
    
    for(int i = 0; i < road.size(); ++i){  // �� ���ÿ��� ���÷� ���� �Ÿ��� �ٽ� ���ø��� �����ؼ� ���� 
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
