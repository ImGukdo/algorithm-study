// https://programmers.co.kr/learn/courses/30/lessons/42583
// 프로그래머스 다리를 지나는 트럭 문제
// 트럭 여러 대가 강을 가로지르는 일차선 다리를 정해진 순으로 건너려 합니다. 
// 모든 트럭이 다리를 건너려면 최소 몇 초가 걸리는지 알아내야 합니다. 
// 다리에는 트럭이 최대 bridge_length대 올라갈 수 있으며, 다리는 weight 이하까지의 무게를 견딜 수 있습니다. 
// 단, 다리에 완전히 오르지 않은 트럭의 무게는 무시합니다.

#include <string>
#include <vector>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;  // 1초씩 증가하며 시간 체크
    int bridge = 0;  // 현재 다리 위에 있는 트럭들의 무게합
    int iIndex = 0;  // 통과할 트럭들의 순서를 체크
    int time[10001];  // 각 트럭들의 다리를 출발한 시간 체크
    while(true){
        for(int i = 0; i < iIndex; ++i){  // 다리 위를 출발한 트럭들을 탐색
            if(answer - time[i] > bridge_length)  // 이미 다리를 통과 했으면 패스
                continue;
            else if(answer - time[i] == bridge_length)  // 다리를 통과 할때
                bridge -= truck_weights[i];  // 다리위 트럭들 무게에서 빼준다
        }
        
        if(weight >= bridge + truck_weights[iIndex]){  // 다음 대기트럭이 다리위로 올라갈 수 있으면
            bridge += truck_weights[iIndex];  // 다리위 트럭들 무게에 더해주고
            time[iIndex] = answer;  // 방금 다리 위로 올라간 트럭의 출발 시간을 저장
            ++iIndex;  // 다음 트럭으로 인덱스를 변경
        }
        
        if(iIndex == truck_weights.size())  // 모든 트럭이 통과 했으면 반복문 탈출, 마지막 트럭이 다리위를 올라간 시점
            break;
        
        ++answer;  // 1초씩 증가
    }
    answer += bridge_length + 1;  // 1초부터 트럭들이 다리를 통과하기 때문에 +1초, 마지막 트럭이 다리를 통과하는 시간을 더해줌
     
    return answer;
}
