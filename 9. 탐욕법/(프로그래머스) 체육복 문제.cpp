// https://programmers.co.kr/learn/courses/30/lessons/42862
// 프로그래머스 체육복 문제
// 점심시간에 도둑이 들어, 일부 학생이 체육복을 도난당했습니다. 
// 다행히 여벌 체육복이 있는 학생이 이들에게 체육복을 빌려주려 합니다. 
// 학생들의 번호는 체격 순으로 매겨져 있어, 
// 바로 앞번호의 학생이나 바로 뒷번호의 학생에게만 체육복을 빌려줄 수 있습니다. 
// 예를 들어, 4번 학생은 3번 학생이나 5번 학생에게만 체육복을 빌려줄 수 있습니다. 
// 체육복이 없으면 수업을 들을 수 없기 때문에 
// 체육복을 적절히 빌려 최대한 많은 학생이 체육수업을 들어야 합니다.
// 전체 학생의 수 n, 체육복을 도난당한 학생들의 번호가 담긴 배열 lost, 
// 여벌의 체육복을 가져온 학생들의 번호가 담긴 배열 reserve가 매개변수로 주어질 때, 
// 체육수업을 들을 수 있는 학생의 최댓값을 return 하도록 solution 함수를 작성해주세요. 

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool bCheck[31];  // 여벌 가진 학생이 도난 당한 것을 체크하는 변수 
int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    sort(lost.begin(), lost.end());  // 도난 당한 학생들을 오름차순으로 정렬 
    sort(reserve.begin(), reserve.end());  // 여벌 가진 학생을 오름차순으로 정렬 
    
    int j = 0;  // lost의 인덱스 설정 
    for(int i = 0; i < reserve.size(); ++i){
        if(j >= lost.size())  // lost 인덱스 범위를 벗어나면 탈출 
            break;
        if(reserve[i] == lost[j]){  // 도난 당한 학생과 여벌을 가진 학생이 같으면 
            bCheck[lost[j]] = true;  // 그 학생을 체크 
            ++answer;  
            ++j;
        }
        else if(reserve[i] > lost[j]){  // 도난 당한 학생 번호보다 여벌을 가진 학생번호가 크면 
            ++j;  // 도난 당한 학생 번호 증가 
            --i;  // 여벌 가진 학생 대기 
        }
    }
    j = 0;  // reserve 의 인덱스 설정 
    for(int i = 0; i < lost.size(); ++i){  
        if(j >= reserve.size())  // reserve 인덱스 범위를 벗어나면 탈출 
            break;
        if(bCheck[lost[i]])  // 도난 당한 학생이 여벌이 있으면 패스 
            continue;
        if(bCheck[reserve[j]]){  // 여벌있는 학생이 도난 당했으면 패스 
            ++j;
            --i;
            continue;
        }
        
        if(lost[i] == reserve[j] - 1 || lost[i] == reserve[j] + 1){  // 도난 당한 학생의 +1 또는 -1의 학생이 여벌이 있으면 
            ++answer;
            ++j;
        }
        else if(reserve[j] < lost[i]){  // 여벌을 가진 학생번호 보다 도난 당한 학생 번호가 크면 
            ++j;  // 여벌 가진 학생 번호 증가 
            --i;  // 도난 당한 학생 번호 대기 
        }
    }
    answer += n - lost.size();  // 전체 학생 - 도난 당한 학생 + 여벌 빌린 학생 
    return answer;
}
