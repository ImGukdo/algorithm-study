#include <iostream>

using namespace std;

int iNum = 4;  // ���� �� 
int INF = 10000000;  // �Ÿ� ���� 

int iStore[4][4] = {  // ������ ������ �Ÿ��� ���� 
    {0, 5, INF, 8},
    {7, 0, 9, INF},
    {2, INF, 0, 4},
    {INF, INF, 3, 0}
};

void FloydWarshall(){
	int iResult[iNum][iNum];  // ����� ������ �迭 
	
	for(int i = 0; i < iNum; ++i){  // ��� ���� ������ �ʱ�ȭ 
		for(int j = 0; j < iNum; ++j){
			iResult[i][j] = iStore[i][j];
		}
	}
	
	// k�� ���İ��� ��� 
	for(int k = 0; k < iNum; ++k){
		for(int i = 0; i < iNum; ++i){  // i ��� ��� 
			for(int j = 0; j < iNum; ++j){  // j ���� ��� 
				if(iResult[i][k] + iResult[k][j] < iResult[i][j])  // ���İ��� ��带 ���ϴ� �Ÿ��� �� ª���� ���� 
				iResult[i][j] = iResult[i][k] + iResult[k][j];
			}
		}
	}
	
	// ��� ��� 
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
