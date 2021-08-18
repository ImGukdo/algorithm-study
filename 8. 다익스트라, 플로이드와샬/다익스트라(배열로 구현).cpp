#include <iostream>

using namespace std;

int INF = 10000000;  // �Ÿ��� ���� 
int iNum = 6;  // ������ ���� 
int iStore[6][6] = {  // �������� ���������� �Ÿ��� 
    {0, 2, 5, 1, INF, INF},
    {2, 0, 3, 2, INF, INF},
    {5, 3, 0, 3, 1, 5},
    {1, 2, 3, 0, 1, INF},
    {INF, INF, 1, 1, 0, 2},
    {INF, INF, 5, INF, 2, 0}
	};
int iVisit[6];  // �湮�ߴ��� Ȯ�� ���� 
int iDistance[6];  // �������� ���������� �ּҰŸ� ���� ���� 

int GetSmallIndex(){  // ���� �������� �ٸ� ���������� �Ÿ��� �ּ��� �ε����� ã�� �Լ� 
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
	for(int i = 0; i < iNum; ++i){  // ���� ������ ���ؼ� ���� �������� ������ִ� ������ �Ÿ��� �־��ش�. 
		iDistance[i] = iStore[iInput][i];
	}
	iVisit[iInput] = true;  // ���� ������ �湮�ߴٰ� üũ 
	for(int i = 0; i < iNum - 2; ++i){  // �湮���� ������ ��ŭ �ݺ�, �������� ���� ���������� ���� ��ŭ �ݺ� 
		int iCurrentIndex = GetSmallIndex();  // �湮 ���� ������ �ּ� �Ÿ� �ε����� ��ȯ�� �� 
		iVisit[iCurrentIndex] = true;  // ������ �湮�ߴٰ� üũ 
		for(int j = 0; j < iNum; ++j){
			if(!iVisit[j]){  // �湮���� ���� �߿� 
				if(iDistance[iCurrentIndex] + iStore[iCurrentIndex][j] < iDistance[j])  // �ּ� �Ÿ� �ε����� ���ļ� �̵��� ���������� �Ÿ��� �� ������ ���� 
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
// ����Ž���� ��������Ƿ� O(N^2) 
