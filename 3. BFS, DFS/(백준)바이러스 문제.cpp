// https://www.acmicpc.net/problem/2606
// ���� ���̷��� ����
// ���� ���̷����� �� ���̷����� ��Ʈ��ũ�� ���� ���ĵȴ�. 
// �� ��ǻ�Ͱ� �� ���̷����� �ɸ��� �� ��ǻ�Ϳ� ��Ʈ��ũ �󿡼� 
// ����Ǿ� �ִ� ��� ��ǻ�ʹ� �� ���̷����� �ɸ��� �ȴ�.

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> vec[101];  // �׷��� ������ ���� ���� ���� 

bool bCheck[101];  // �湮�� ��ǻ������ üũ 

int Bfs(int iStart){  // BFS �Լ� ���� 
	int iCount = 0;  // ������ ��ǻ�� ���� 
	queue<int> que;
	que.push(iStart);  // ���� ������ ��ǻ�͸� ť�� �ֱ� 
	bCheck[iStart] = true;  // ������ ��ǻ�� üũ 
	
	while(!que.empty()){  // ť�� �������� �ݺ� 
		int k = que.front();  // ť�� ���� �տ� �ִ� ���� 
		que.pop();  // ť���� ���� 
		++iCount;  // ���� �߰� 
		for(int i = 0; i < vec[k].size(); ++i){  // ������ ��ǻ�Ϳ� ����� ��ǻ�͵��� Ž�� 
			int z = vec[k][i];  // ����� ��ǻ�� 
			
			if(!bCheck[z]){  // ����üũ�� ���� ��ǻ�Ͷ�� 
				bCheck[z] = true;  // üũ�ߴٰ� ǥ�� 
				que.push(z);  // ť�� �ֱ� 
			}
		}
	}
	return iCount - 1;  // ���� ������ ��ǻ�͸� ���� ��ȯ		
}

int main(void){
	int iNum;
	scanf("%d", &iNum);
	int a;
	scanf("%d", &a);
	int b, c;
	for(int i = 0; i < a; ++i){
		scanf("%d %d", &b, &c);
		vec[b].push_back(c);
		vec[c].push_back(b);
	}  // �׷��� ���� 
	
	printf("%d", Bfs(1));  // BFS �Լ��� ���� ������ ��ǻ�� ���� ��� 
	
	return 0;
}
