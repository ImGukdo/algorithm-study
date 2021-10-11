// https://programmers.co.kr/learn/courses/30/lessons/42861
// 프로그래머스 섬연결하기 문제 
// n개의 섬 사이에 다리를 건설하는 비용(costs)이 주어질 때, 
// 최소의 비용으로 모든 섬이 서로 통행 가능하도록 만들 때 
// 필요한 최소 비용을 return 하도록 solution을 완성하세요.
// 다리를 여러 번 건너더라도, 도달할 수만 있으면 통행 가능하다고 봅니다.
// 예를 들어 A 섬과 B 섬 사이에 다리가 있고, 
// B 섬과 C 섬 사이에 다리가 있으면 A 섬과 C 섬은 서로 통행 가능합니다.

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 섬 노드 
struct _tagNode{
    int iNode1;  // 연결된 섬1 
    int iNode2;  // 연결된 섬2 
    int iDistance;  // 연결된 섬 사이의 거리 
};

// 두섬을 비교하는 오퍼레이터 < 정의 
bool compare(const _tagNode& a, const _tagNode& b){
    return a.iDistance < b.iDistance;  // 거리를 비교 
}
 
 // 부모 노드 찾기 
int getParent(int* pParent, int iNode){
    if(pParent[iNode] == iNode)  // 자기 자신이 부모이면 
        return iNode;  // 부모 리턴 
    return getParent(pParent, pParent[iNode]);  // 부모를 찾을때까지 제귀함수 반복 
}

// 부모 노드 정의 
void unionParent(int* pParent, int iNode1, int iNode2){
    iNode1 = getParent(pParent, iNode1);  // 부모 찾기 
    iNode2 = getParent(pParent, iNode2);  // 부모 찾기 
    
    // 부모 정의 
    if(iNode1 < iNode2)
        pParent[iNode2] = iNode1;
    else
        pParent[iNode1] = iNode2;
}

// 같은 부모인지 체크 
bool checkParent(int* pParent, int iNode1, int iNode2){
    iNode1 = getParent(pParent, iNode1);
    iNode2 = getParent(pParent, iNode2);
    if(iNode1 == iNode2)
        return true;
    return false;
}


int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    _tagNode node[costs.size()];  // 노드 생성 
    // 노드 연결 
    for(int i = 0; i < costs.size(); ++i){
        node[i].iNode1 = costs[i][0];
        node[i].iNode2 = costs[i][1];
        node[i].iDistance = costs[i][2];
        
    }
    sort(node, node + costs.size(), compare);  // 노드 정렬 
    
	// 부모 초기화 
    int iParent[n];
    for(int i = 0; i < n; ++i){
        iParent[i] = i;
    }
    
    // 작은 거리순으로 순환하지 않게 섬노드 연결 
    for(int i = 0; i < costs.size(); ++i){
        if(checkParent(iParent, node[i].iNode1, node[i].iNode2))
            continue;
        unionParent(iParent, node[i].iNode1, node[i].iNode2);
        answer += node[i].iDistance;
    }
       
    return answer;
}
