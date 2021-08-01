// https://programmers.co.kr/learn/courses/30/lessons/42576
// ���α׷��ӽ� �������� ���� ���� ���� 
// ������ ������ �������� �����濡 �����Ͽ����ϴ�. 
// �� �� ���� ������ �����ϰ�� ��� ������ �������� �����Ͽ����ϴ�.
// �����濡 ������ �������� �̸��� ��� �迭 participant�� 
// ������ �������� �̸��� ��� �迭 completion�� �־��� ��, 
// �������� ���� ������ �̸��� return �ϵ��� solution �Լ��� �ۼ����ּ���.


#include <string>
#include <vector>
#include <queue>

using namespace std;
long long iArray[51];  
long long Pow(int iInput){   // �ؽ� �Լ� ���� 
	if(iInput == 0)
	return 1;
	
	if(iArray[iInput] != 0)
	return iArray[iInput];
	
	return iArray[iInput] = 31 * Pow(iInput - 1) % 1234567891;   
}

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    priority_queue<pair<long long, string> > pq1;  // �ؽ��Լ��� ���� ���� �ֱ����� �켱���� ť ���� 
    priority_queue<pair<long long, string> > pq2;  // �ؽ��Լ��� ���� ���� �ֱ����� �켱���� ť ���� 
    
	for(int i = 0; i < participant.size(); ++i){  // �����ڵ��� �ؽð��� �̸��� �켱���� ť�� �ֱ� 
        long long iHash = 0;
		 for(int j = 0; j < participant[i].length(); ++j){
            iHash += ((int)participant[i][j] - 96) * Pow(j);	 
		    iHash %= 1234567891; 
         }
        pq1.push(make_pair(iHash, participant[i]));
	}
    for(int i = 0; i < completion.size(); ++i){  // �����ڵ��� �ؽð��� �̸��� �켱���� ť�� �ֱ� 
        long long iHash = 0;
		 for(int j = 0; j < completion[i].length(); ++j){
            iHash += ((int)completion[i][j] - 96) * Pow(j);	 
		    iHash %= 1234567891; 
         }
        pq2.push(make_pair(iHash, completion[i]));
	}
    for(int i = 0; i < completion.size(); ++i){  // �켱���� ť�� ���� ������ ���� ���ϸ鼭 
        if(pq1.top().first == pq2.top().first){  // ������ ��� 
            pq1.pop();
            pq2.pop();
            continue;
        }
        else{  // �ٸ��� ���信 �̸��� �־��ش� 
            answer = pq1.top().second;
            break;
        }
    }
    if(answer == "")  // �����ڵ�� �����ڵ��� �񱳰� ������ ���� ������ 
        answer = pq1.top().second;  // ���� �������� �̸��� �־��ش�. 
    return answer;
}
