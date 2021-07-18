// https://www.acmicpc.net/problem/1260
// ���� DFS�� BFS ����
// �׷����� DFS�� Ž���� ����� BFS�� Ž���� ����� ����ϴ� ���α׷��� �ۼ��Ͻÿ�. 
// ��, �湮�� �� �ִ� ������ ���� ���� ��쿡�� ���� ��ȣ�� ���� ���� ���� �湮�ϰ�, 
// �� �̻� �湮�� �� �ִ� ���� ���� ��� �����Ѵ�. ���� ��ȣ�� 1������ N�������̴�. 

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<int> vec[1001];  // �׷����� ����� ���� ���� ���� 
bool bCheck[1001];  // ������ �湮�ߴ��� üũ 

void Bfs(int iStart){  // BFS ���� �Լ� 
	queue<int> que;  
	que.push(iStart);  // ���� ������ ť�� �ֱ� 
	bCheck[iStart] = true;  // ���� ������ �湮�ߴٰ� üũ 
	
	while(!que.empty()){  // ť�� �������� �ݺ� 
		int k = que.front();  // ť�� ���� �տ� �ִ� ���Ҹ� 
		printf("%d ", k);  // ��� 
		que.pop();  // ���� 
		
		for(int i = 0; i < vec[k].size(); ++i){  // ������ ����� �������� Ž�� 
			int z = vec[k][i];  // ����� ���� 
			
			if(!bCheck[z]){  // �湮���� ���� �����̶�� 
				bCheck[z] = true;  //  �湮�ߴٰ� üũ 
				que.push(z);  // ť�� �ֱ� 
			}
		}
	}	
}

void Dfs(int iStart){  // DFS ���� �Լ� 
	bCheck[iStart] = true;  // ������ �湮�ߴٰ� üũ 
	printf("%d ", iStart);  // ��� 
	
	for(int i = 0; i < vec[iStart].size(); ++i){  // ������ ����� ������ Ž���ϸ鼭 
		int k = vec[iStart][i];  // ����� ���� 
		
		if(!bCheck[k])  // �湮���� ���� �����̶�� 
		Dfs(k);  // DFS �Լ� ���� 
	}
}

int main(void){
	int x, y, iStart;
	scanf("%d %d %d", &x, &y, &iStart);
	
	int a, b;
	for(int i = 0; i < y; ++i){
		scanf("%d %d", &a, &b);
		vec[a].push_back(b);
		vec[b].push_back(a);
	} // �׷��� ���� 
	
	for(int i = 0; i <= 1000; ++i){
		if(vec[i].size() != 0)
		sort(vec[i].begin(), vec[i].end());
	}  // ������ ��ȣ�� �����ͺ��� �湮�ϱ� ���� ������������ ���� 
	
	Dfs(iStart);  //  DFS �Լ� ���� 
	printf("\n");
	fill(bCheck, bCheck + 1001, false);  // �湮üũ�� �ʱ�ȭ 
	Bfs(iStart);  // BFS �Լ� ���� 
	
	return 0;
}
