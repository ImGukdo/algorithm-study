// https://programmers.co.kr/learn/courses/30/lessons/42626
// 프로그래머스 더 맵게 문제
// 매운 것을 좋아하는 Leo는 모든 음식의 스코빌 지수를 K 이상으로 만들고 싶습니다. 
// 모든 음식의 스코빌 지수를 K 이상으로 만들기 위해 Leo는 스코빌 지수가 가장 낮은 두 개의 음식을
// 아래와 같이 특별한 방법으로 섞어 새로운 음식을 만듭니다.
// 섞은 음식의 스코빌 지수 = 가장 맵지 않은 음식의 스코빌 지수 + (두 번째로 맵지 않은 음식의 스코빌 지수 * 2)
// Leo는 모든 음식의 스코빌 지수가 K 이상이 될 때까지 반복하여 섞습니다.
// Leo가 가진 음식의 스코빌 지수를 담은 배열 scoville과 원하는 스코빌 지수 K가 주어질 때, 
// 모든 음식의 스코빌 지수를 K 이상으로 만들기 위해 섞어야 하는 최소 횟수를 return 하도록 solution 함수를 작성해주세요. 
// 모든 음식의 스코빌 지수를 K 이상으로 만들 수 없는 경우에는 -1을 return 합니다.

#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int> pq;
    
    // 현재 스코빌 지수를 최대힙구조로 만든다 
    for(int i = 0; i < scoville.size(); ++i){
        pq.push(-scoville[i]);
    }
    
    while(true){
    	// 현재 스코빌 지수가 1개면 더이상 섞기 불가 
        if(pq.size() == 1)
            break;
        // 모든 스코빌 지수가 K 이상이면 탈출 
        if(-pq.top() >= K)
            break;
        // 두 개의 음식을 섞어 새 스코빌 지수 생성    
        int x = -pq.top();
        pq.pop();
        int y = -pq.top();
        pq.pop();
        pq.push(-(x + 2 * y));
        ++answer;
    }
    
    // 스코빌 지수를 K 이상으로 만들 수 없는 경우에는 -1 아니면 구한 정답 
    -pq.top() >= K ? 1 : answer = -1;
    
    return answer;
}
