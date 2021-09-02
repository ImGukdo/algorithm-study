// https://programmers.co.kr/learn/courses/30/lessons/42628
// ���α׷��ӽ� ���߿켱����ť ����
// ���� �켱���� ť�� ���� ������ �� �� �ִ� �ڷᱸ���� ���մϴ�.
// ��ɾ�	���� ž(����)
// I ����	ť�� �־��� ���ڸ� �����մϴ�.
// D 1	    ť���� �ִ��� �����մϴ�.
// D -1	    ť���� �ּڰ��� �����մϴ�.
// ���� �켱���� ť�� �� ���� operations�� �Ű������� �־��� ��, 
// ��� ������ ó���� �� ť�� ��������� [0,0] ������� ������ 
// [�ִ�, �ּڰ�]�� return �ϵ��� solution �Լ��� �������ּ���. 


#include <string>
#include <vector>
#include <queue>

using namespace std;
bool bCheck[1000001];  // id �ߺ�üũ ���� 

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    priority_queue<pair<int, int> > minPq;  // �ּ������� 
    priority_queue<pair<int, int> > maxPq;  // �ִ������� 
    
    int id = 0;  // ť�� ������ ���� �ο��� id ���� 
    int iCount = 0;  // ť�� �����ִ� ������ �� 
    
    for(int i = 0; i < operations.size(); ++i){
        if(operations[i][0] == 'I'){  // ��ɾ I�̸� 
            int a = 1;
            int b = 0;
            // ť�� �־��� ���ڸ� ������ ��ȯ 
            for(int j = operations[i].size() - 1; j > 1; --j){
                if(operations[i][j] == '-'){
                    b = -b;
                    break;
                }
                b += ((int)operations[i][j] - 48) * a;
                a *= 10;
            }
            // ������ ť�� �־��ش�, �־��ٶ� id �ο�, ������ ť�� �־��ִ� ���� ���Ҵ� ���̵� ���� 
            minPq.push(make_pair(-b, id));
            maxPq.push(make_pair(b, id++));
            ++iCount;  // ���� ���� ���� 
        }
        // ��ɾ D �̰� ť�� ������� ������ 
        else if(operations[i][0] == 'D' && iCount != 0){
        	// �ּڰ� ���� 
            if(operations[i][2] == '-'){
            	// ť���� ���̵� �ߺ�üũ�� ���ش� 
                while(bCheck[minPq.top().second]){
                    minPq.pop();
                }
                // �ּ��� ť���� �ּҰ� ���� 
                bCheck[minPq.top().second] = true;
                minPq.pop();
                --iCount;
            }
            // �ִ� ���� 
            else{
            	// ť���� ���̵� �ߺ�üũ�� ���ش�
                while(bCheck[maxPq.top().second]){
                    maxPq.pop();
                }
                // // �ִ��� ť���� �ִ밪 ���� 
                bCheck[maxPq.top().second] = true;
                maxPq.pop();
                --iCount;
            }
        }
    }
    // ������ ������ 0�̸� 
    if(iCount == 0)
        answer = {0, 0};
    // ������ ������ 0�� �ƴϸ� ���� ť�� �ִ񰪰� �ּҰ��� ���Ѵ� 
    else{
    	// �ִ����� �ּ������� ���̵� �ߺ� ���� 
        while(bCheck[maxPq.top().second]){
                    maxPq.pop();
                }
        while(bCheck[minPq.top().second]){
                    minPq.pop();
                }
        // �ִ밪�� �ּҰ��� ���Ѵ� 
        answer.push_back(maxPq.top().first);
        answer.push_back(-minPq.top().first);
    }
    
    return answer;
}
