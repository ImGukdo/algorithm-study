// https://www.acmicpc.net/problem/18352
// ���� Ư�� �Ÿ��� ���� ã��
// � ���󿡴� 1������ N�������� ���ÿ� M���� �ܹ��� ���ΰ� �����Ѵ�. 
// ��� ������ �Ÿ��� 1�̴�.
// �� �� Ư���� ���� X�κ��� ����Ͽ� ������ �� �ִ� ��� ���� �߿���, 
// �ִ� �Ÿ��� ��Ȯ�� K�� ��� ���õ��� ��ȣ�� ����ϴ� ���α׷��� �ۼ��Ͻÿ�. 
// ���� ��� ���� X���� ��� ���� X�� ���� �ִ� �Ÿ��� �׻� 0�̶�� �����Ѵ�. 


#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
#define INF 100000000  // �Ÿ��� �����ΰ��� ���� 
vector<pair<int, int> > vec[300001];  // ���ÿ� ���� ������ �Ÿ��� 

void Dijkstra(int iStart, int* iResult){
	iResult[iStart] = 0;  // ���� ���ÿ��� ���� ���÷��� �Ÿ��� 0 
	priority_queue<pair<int, int> > pq;  // �Ÿ��� ���ø� �־��ִ� �켱���� ť ���� 
	pq.push(make_pair(0, iStart));  // �Ÿ� 0�� ���۵��ø� �־��ش� 
	
	while(!pq.empty()){  // ť�� �������� �ݺ��ϸ鼭 
		int iIndex = pq.top().second;  // �켱���� ť�� ���� ���� �ִ� ���Ҹ� ���� �ε����� ���Ѵ� 
		int iDistance = -pq.top().first;  // �Ÿ��� ���Ѵ� 
		pq.pop();  // ť���� ���� 
		if(iResult[iIndex] < iDistance)  // ���࿡ ť���� ���� ������ �̹� �۴ٸ� 
		continue;  // ��� 
		
		for(int i = 0; i < vec[iIndex].size(); ++i){  // ����Ǿ� �ִ� ���õ��� Ž���ϸ鼭 
			int iNext = vec[iIndex][i].first;  // ����� ���� 
			int iNextDistance = vec[iIndex][i].second + iDistance;  // ���� ���ÿ��� ����� ���ñ����� �Ÿ� 
			
			if(iNextDistance < iResult[iNext]){  // ������� ���� �Ÿ����� ������ 
				iResult[iNext] = iNextDistance;  // ���� ���� 
				pq.push(make_pair(-iNextDistance, iNext));  // ���� ť�� �־��ش� 
			}
		} 
	}
}
int main(void){
	int iNum, iRoad, iDistance, iStart;
	scanf("%d %d %d %d", &iNum, &iRoad, &iDistance, &iStart);
	int a, b;
	for(int i = 0; i < iRoad; ++i){  // ���õ��� �Ÿ� �׷��� ���� 
		scanf("%d %d", &a, &b);
		vec[a].push_back(make_pair(b, 1));
	}
	int iResult[iNum + 1];  // �ּҰŸ��� ������ ���� 
	fill(iResult, iResult + iNum + 1, INF);  // ���Ѱ����� �ʱ�ȭ 
	Dijkstra(iStart, iResult);
	vector<int> vAnswer;
	for(int i = 1; i <= iNum; ++i){  // ���� �ּҰŸ��� K(iDistance)���� Ȯ�� 
		if(iResult[i] == iDistance)
		vAnswer.push_back(i);
	}
	if(vAnswer.empty())  // K�� ���� ������ -1 
	printf("%d", -1);
	else{  // K�� ���� ������ 
		sort(vAnswer.begin(), vAnswer.end());  // ���õ��� �������� �������ش� 
		for(int i = 0; i < vAnswer.size(); ++i){
			printf("%d\n", vAnswer[i]);
		}
	}
	return 0;
}
