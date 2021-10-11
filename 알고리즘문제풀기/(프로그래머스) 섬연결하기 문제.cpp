// https://programmers.co.kr/learn/courses/30/lessons/42861
// ���α׷��ӽ� �������ϱ� ���� 
// n���� �� ���̿� �ٸ��� �Ǽ��ϴ� ���(costs)�� �־��� ��, 
// �ּ��� ������� ��� ���� ���� ���� �����ϵ��� ���� �� 
// �ʿ��� �ּ� ����� return �ϵ��� solution�� �ϼ��ϼ���.
// �ٸ��� ���� �� �ǳʴ���, ������ ���� ������ ���� �����ϴٰ� ���ϴ�.
// ���� ��� A ���� B �� ���̿� �ٸ��� �ְ�, 
// B ���� C �� ���̿� �ٸ��� ������ A ���� C ���� ���� ���� �����մϴ�.

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// �� ��� 
struct _tagNode{
    int iNode1;  // ����� ��1 
    int iNode2;  // ����� ��2 
    int iDistance;  // ����� �� ������ �Ÿ� 
};

// �μ��� ���ϴ� ���۷����� < ���� 
bool compare(const _tagNode& a, const _tagNode& b){
    return a.iDistance < b.iDistance;  // �Ÿ��� �� 
}
 
 // �θ� ��� ã�� 
int getParent(int* pParent, int iNode){
    if(pParent[iNode] == iNode)  // �ڱ� �ڽ��� �θ��̸� 
        return iNode;  // �θ� ���� 
    return getParent(pParent, pParent[iNode]);  // �θ� ã�������� �����Լ� �ݺ� 
}

// �θ� ��� ���� 
void unionParent(int* pParent, int iNode1, int iNode2){
    iNode1 = getParent(pParent, iNode1);  // �θ� ã�� 
    iNode2 = getParent(pParent, iNode2);  // �θ� ã�� 
    
    // �θ� ���� 
    if(iNode1 < iNode2)
        pParent[iNode2] = iNode1;
    else
        pParent[iNode1] = iNode2;
}

// ���� �θ����� üũ 
bool checkParent(int* pParent, int iNode1, int iNode2){
    iNode1 = getParent(pParent, iNode1);
    iNode2 = getParent(pParent, iNode2);
    if(iNode1 == iNode2)
        return true;
    return false;
}


int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    _tagNode node[costs.size()];  // ��� ���� 
    // ��� ���� 
    for(int i = 0; i < costs.size(); ++i){
        node[i].iNode1 = costs[i][0];
        node[i].iNode2 = costs[i][1];
        node[i].iDistance = costs[i][2];
        
    }
    sort(node, node + costs.size(), compare);  // ��� ���� 
    
	// �θ� �ʱ�ȭ 
    int iParent[n];
    for(int i = 0; i < n; ++i){
        iParent[i] = i;
    }
    
    // ���� �Ÿ������� ��ȯ���� �ʰ� ����� ���� 
    for(int i = 0; i < costs.size(); ++i){
        if(checkParent(iParent, node[i].iNode1, node[i].iNode2))
            continue;
        unionParent(iParent, node[i].iNode1, node[i].iNode2);
        answer += node[i].iDistance;
    }
       
    return answer;
}
