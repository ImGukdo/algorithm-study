// https://programmers.co.kr/learn/courses/30/lessons/49189
// ���α׷��ӽ� ���� �� ��� ����
// n���� ��尡 �ִ� �׷����� �ֽ��ϴ�. �� ���� 1���� n���� ��ȣ�� �����ֽ��ϴ�. 
// 1�� ��忡�� ���� �ָ� ������ ����� ������ ���Ϸ��� �մϴ�. 
// ���� �ָ� ������ ���� �ִܰ�η� �̵����� �� ������ ������ ���� ���� ������ �ǹ��մϴ�.
// ����� ���� n, ������ ���� ������ ��� 2���� �迭 vertex�� �Ű������� �־��� ��,
// 1�� ���κ��� ���� �ָ� ������ ��尡 �� �������� return �ϵ��� solution �Լ��� �ۼ����ּ���. 


#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>

using namespace std;
#define INF 100000  // ���� 
vector<pair<int, int> > vec[20001];  // ���� ��尡 ����Ǿ� �ִ��� ��Ÿ���� ���� 

void Dijkstra(int iStart, int* iResult){  // ���ͽ�Ʈ�� ���� 1�� ������ ���������� �ּ� �Ÿ��� ���� 
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
    
    for(int i = 0; i < edge.size(); ++i){  // ����� ������¸� ��庰�� �����Ͽ� ���� 
        vec[edge[i][0]].push_back(make_pair(edge[i][1], 1));
        vec[edge[i][1]].push_back(make_pair(edge[i][0], 1));
    }
    int iResult[n + 1];  // �ּ� �Ÿ��� ������ ���� 
    fill(iResult, iResult + n + 1, INF);  // �ʱⰪ�� �������� ���� 
    Dijkstra(1, iResult);
    sort(iResult, iResult + n + 1);  // ���� ���� �����Ѵ� 
    for(int i = n - 1; i >= 0; --i){  // �ִ밪�� ������ ���� 
        if(iResult[i] == iResult[n - 1]){
            ++answer;
            continue;
        }
        break;
    }
    return answer;
}
