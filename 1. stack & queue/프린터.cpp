// https://programmers.co.kr/learn/courses/30/lessons/42587
// 프로그래머스 프린터 문제
// 일반적인 프린터는 인쇄 요청이 들어온 순서대로 인쇄합니다. 
// 그렇기 때문에 중요한 문서가 나중에 인쇄될 수 있습니다. 
// 이런 문제를 보완하기 위해 중요도가 높은 문서를 먼저 인쇄하는 프린터를 개발했습니다. 
// 이 새롭게 개발한 프린터는 아래와 같은 방식으로 인쇄 작업을 수행합니다.
// 1. 인쇄 대기목록의 가장 앞에 있는 문서(J)를 대기목록에서 꺼냅니다.
// 2. 나머지 인쇄 대기목록에서 J보다 중요도가 높은 문서가 한 개라도 존재하면 J를 대기목록의 가장 마지막에 넣습니다.
// 3. 그렇지 않으면 J를 인쇄합니다.
// 예를 들어, 4개의 문서(A, B, C, D)가 순서대로 인쇄 대기목록에 있고 중요도가 2 1 3 2 라면 C D A B 순으로 인쇄하게 됩니다.
// 내가 인쇄를 요청한 문서가 몇 번째로 인쇄되는지 알고 싶습니다. 위의 예에서 C는 1번째로, A는 3번째로 인쇄됩니다.
// 현재 대기목록에 있는 문서의 중요도가 순서대로 담긴 배열 priorities와 내가 인쇄를 요청한 문서가 
// 현재 대기목록의 어떤 위치에 있는지를 알려주는 location이 매개변수로 주어질 때, 
// 내가 인쇄를 요청한 문서가 몇 번째로 인쇄되는지 return 하도록 solution 함수를 작성해주세요.


#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;  // 내가 요청한 문서의 인쇄 순서
    vector<int> vec = priorities;  // 우선순위를 복사해서 저장 
    sort(vec.begin(), vec.end());  // 우선순위 복사한 것을 오름차순으로 정렬 
    int iCount = vec.size() - 1; // 인쇄 순서를 표시, 오름차순으로 정렬했기 때문에 우선순위가 높은것부터 탐색하기 위해 가장 마지막 인덱스로 설정 
    bool bCheck = false;  // 내 인쇄 문서인지 확인
    while(true){
        for(int i = 0; i < priorities.size(); ++i){  // 우선순위를 탐색
            if(priorities[i] == vec[iCount]){  // 가장 우선순위라면
                priorities[i] = -1;  // 인쇄를 했다고 체크
                --iCount;  // 다음 우선순위로 변경 
                if(i == location){  // 내가 요청한 문서라면
                    bCheck = true;  // while문 탈출하기 위해 체크
                    break;  // for문 탈출
                }
            }
        }
        if(bCheck)  // 내 문서가 인쇄됐으면 탈출
            break;
    }
    answer = vec.size() - iCount - 1;  // 내 문서가 인쇄된 순서 저장 
    
    
    return answer;
}
