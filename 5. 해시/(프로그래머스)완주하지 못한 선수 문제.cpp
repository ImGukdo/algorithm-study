// https://programmers.co.kr/learn/courses/30/lessons/42576
// 프로그래머스 완주하지 못한 선수 문제 
// 수많은 마라톤 선수들이 마라톤에 참여하였습니다. 
// 단 한 명의 선수를 제외하고는 모든 선수가 마라톤을 완주하였습니다.
// 마라톤에 참여한 선수들의 이름이 담긴 배열 participant와 
// 완주한 선수들의 이름이 담긴 배열 completion이 주어질 때, 
// 완주하지 못한 선수의 이름을 return 하도록 solution 함수를 작성해주세요.


#include <string>
#include <vector>
#include <queue>

using namespace std;
long long iArray[51];  
long long Pow(int iInput){   // 해시 함수 생성 
	if(iInput == 0)
	return 1;
	
	if(iArray[iInput] != 0)
	return iArray[iInput];
	
	return iArray[iInput] = 31 * Pow(iInput - 1) % 1234567891;   
}

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    priority_queue<pair<long long, string> > pq1;  // 해시함수로 구한 값을 넣기위한 우선순위 큐 생성 
    priority_queue<pair<long long, string> > pq2;  // 해시함수로 구한 값을 넣기위한 우선순위 큐 생성 
    
	for(int i = 0; i < participant.size(); ++i){  // 참가자들의 해시값과 이름을 우선순위 큐에 넣기 
        long long iHash = 0;
		 for(int j = 0; j < participant[i].length(); ++j){
            iHash += ((int)participant[i][j] - 96) * Pow(j);	 
		    iHash %= 1234567891; 
         }
        pq1.push(make_pair(iHash, participant[i]));
	}
    for(int i = 0; i < completion.size(); ++i){  // 완주자들의 해시값과 이름을 우선순위 큐에 넣기 
        long long iHash = 0;
		 for(int j = 0; j < completion[i].length(); ++j){
            iHash += ((int)completion[i][j] - 96) * Pow(j);	 
		    iHash %= 1234567891; 
         }
        pq2.push(make_pair(iHash, completion[i]));
	}
    for(int i = 0; i < completion.size(); ++i){  // 우선순위 큐의 가장 상위의 값을 비교하면서 
        if(pq1.top().first == pq2.top().first){  // 같으면 통과 
            pq1.pop();
            pq2.pop();
            continue;
        }
        else{  // 다르면 정답에 이름을 넣어준다 
            answer = pq1.top().second;
            break;
        }
    }
    if(answer == "")  // 완주자들과 참가자들을 비교가 끝나고도 값이 없으면 
        answer = pq1.top().second;  // 남은 참가자의 이름을 넣어준다. 
    return answer;
}
