#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int iNum = 6;  // ���� �� 
int INF = 10000000;  // ���� �Ÿ� 

vector<pair<int, int> > vec[7];  // ������ ������ �Ÿ� 
int iDistance[7];  // �ּ� �Ÿ� ���� ���� 

void Dijkstra(int iInput){
	iDistance[iInput] = 0;  // �ڱ� �ڽŰ��� �Ÿ��� 0 
	priority_queue<pair<int, int> > pq;  // �켱���� ť ���� 
	pq.push(make_pair(0, iInput));  // �ڱ� �ڽ��� ó���� �־��ش� 
	
	while(!pq.empty()){
		int iCurrent = pq.top().second;  // ť�� ��� �ִ� ���� �Ÿ��� ���� ª�� ���� 
		int iCurrentDistance = -pq.top().first;  // ť�� ��� �ִ� ���� ���� ª�� �Ÿ� 
		pq.pop();  // ť���� ���� 
		if(iDistance[iCurrent] < iCurrentDistance)  // ���� �� ���������� �Ÿ��� ť���� �����ź��� �̹� �� �۴ٸ� 
		continue;  // �н� 
		for(int i = 0; i < vec[iCurrent].size(); ++i){  // ����Ǿ� �ִ� ������ Ž���ϸ鼭 
			int iNext = vec[iCurrent][i].first;  // ����� ���� 
			int iNextDistance = iCurrentDistance + vec[iCurrent][i].second;  // ���������� ����� �������� �Ÿ� 
			
			if(iNextDistance < iDistance[iNext]){  // ���� ���� �Ÿ��� �� ª���� ���� 
				iDistance[iNext] = iNextDistance;
				pq.push(make_pair(-iNextDistance, iNext));
			}
		}
	}
	
} 

int main(void){
	for(int i = 1; i <= iNum; ++i){  // ó�� �Ÿ��� �������� �ʱ�ȭ 
		iDistance[i] = INF;
	}
	// �׷��� ���� 
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
