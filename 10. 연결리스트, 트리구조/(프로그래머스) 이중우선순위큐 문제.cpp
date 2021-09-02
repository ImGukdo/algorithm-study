// https://programmers.co.kr/learn/courses/30/lessons/42628
// 프로그래머스 이중우선순위큐 문제
// 이중 우선순위 큐는 다음 연산을 할 수 있는 자료구조를 말합니다.
// 명령어	수신 탑(높이)
// I 숫자	큐에 주어진 숫자를 삽입합니다.
// D 1	    큐에서 최댓값을 삭제합니다.
// D -1	    큐에서 최솟값을 삭제합니다.
// 이중 우선순위 큐가 할 연산 operations가 매개변수로 주어질 때, 
// 모든 연산을 처리한 후 큐가 비어있으면 [0,0] 비어있지 않으면 
// [최댓값, 최솟값]을 return 하도록 solution 함수를 구현해주세요. 


#include <string>
#include <vector>
#include <queue>

using namespace std;
bool bCheck[1000001];  // id 중복체크 변수 

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    priority_queue<pair<int, int> > minPq;  // 최소힙구조 
    priority_queue<pair<int, int> > maxPq;  // 최대힙구조 
    
    int id = 0;  // 큐에 넣을때 마다 부여할 id 변수 
    int iCount = 0;  // 큐에 남아있는 원소의 수 
    
    for(int i = 0; i < operations.size(); ++i){
        if(operations[i][0] == 'I'){  // 명령어가 I이면 
            int a = 1;
            int b = 0;
            // 큐에 넣어줄 숫자를 정수로 변환 
            for(int j = operations[i].size() - 1; j > 1; --j){
                if(operations[i][j] == '-'){
                    b = -b;
                    break;
                }
                b += ((int)operations[i][j] - 48) * a;
                a *= 10;
            }
            // 각각의 큐에 넣어준다, 넣어줄때 id 부여, 각각의 큐에 넣어주는 현재 원소는 아이디가 같다 
            minPq.push(make_pair(-b, id));
            maxPq.push(make_pair(b, id++));
            ++iCount;  // 원소 갯수 증가 
        }
        // 명령어가 D 이고 큐가 비어있지 않으면 
        else if(operations[i][0] == 'D' && iCount != 0){
        	// 최솟값 삭제 
            if(operations[i][2] == '-'){
            	// 큐에서 아이디 중복체크를 해준다 
                while(bCheck[minPq.top().second]){
                    minPq.pop();
                }
                // 최소힙 큐에서 최소값 제거 
                bCheck[minPq.top().second] = true;
                minPq.pop();
                --iCount; // 원소 갯수 감소
            }
            // 최댓값 삭제 
            else{
            	// 큐에서 아이디 중복체크를 해준다
                while(bCheck[maxPq.top().second]){
                    maxPq.pop();
                }
                // // 최대힙 큐에서 최대값 제거 
                bCheck[maxPq.top().second] = true;
                maxPq.pop();
                --iCount;  // 원소 갯수 감소
            }
        }
    }
    // 원소의 갯수가 0이면 
    if(iCount == 0)
        answer = {0, 0};
    // 원소의 갯수가 0이 아니면 현재 큐의 최댓값과 최소값을 구한다 
    else{
    	// 최대힙과 최소힙에서 아이디 중복 제거 
        while(bCheck[maxPq.top().second]){
                    maxPq.pop();
                }
        while(bCheck[minPq.top().second]){
                    minPq.pop();
                }
        // 최대값과 최소값을 구한다 
        answer.push_back(maxPq.top().first);
        answer.push_back(-minPq.top().first);
    }
    
    return answer;
}
