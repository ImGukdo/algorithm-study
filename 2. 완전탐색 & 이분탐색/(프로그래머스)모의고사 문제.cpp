// 수포자는 수학을 포기한 사람의 준말입니다. 
// 수포자 삼인방은 모의고사에 수학 문제를 전부 찍으려 합니다. 
// 수포자는 1번 문제부터 마지막 문제까지 다음과 같이 찍습니다.
// 1번 수포자가 찍는 방식: 1, 2, 3, 4, 5, 1, 2, 3, 4, 5, ...
// 2번 수포자가 찍는 방식: 2, 1, 2, 3, 2, 4, 2, 5, 2, 1, 2, 3, 2, 4, 2, 5, ...
// 3번 수포자가 찍는 방식: 3, 3, 1, 1, 2, 2, 4, 4, 5, 5, 3, 3, 1, 1, 2, 2, 4, 4, 5, 5, ...
// 1번 문제부터 마지막 문제까지의 정답이 순서대로 들은 배열 answers가 주어졌을 때, 
// 가장 많은 문제를 맞힌 사람이 누구인지 배열에 담아 return 하도록 solution 함수를 작성해주세요.

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    int a[5] = {1, 2, 3, 4, 5};  // 1번 수포자의 정답 패턴 저장 
    int b[8] = {2, 1, 2, 3, 2, 4, 2, 5};  // 2번 수포자의 정답 패턴 저장 
    int c[10] = {3, 3, 1, 1, 2, 2, 4 ,4, 5, 5};  // 3번 수포자의 정답 패턴 저장 
    int iCount[3] = {};  // 각각 수포자의 맞은 정답 갯수를 저장 
    
    for(int i = 0; i < answers.size(); ++i){  // 정답을 탐색하면서 
        if(a[i % 5] == answers[i])  // 1번 수포자의 정답과 비교 체크 
        ++iCount[0];
        if(b[i % 8] == answers[i])  // 2번 수포자의 정답과 비교 체크
        ++iCount[1];
        if(c[i % 10] == answers[i])  // 3번 수포자의 정답과 비교 체크
        ++iCount[2];
    }
    int iArray[3];  // 각각의 맞은 갯수를 복사 저장 
    for(int i = 0; i < 3; ++i){
        iArray[i] = iCount[i];
    }
    sort(iArray, iArray + 3);  // 맞은 갯수를 내림차순으로 정렬 
    for(int i = 0; i < 3; ++i){  // 가장 많이 맞은 갯수와 비교하여 
        if(iCount[i] == iArray[2])  // 가장 많이 맞은 갯수와 같으면 
            answer.push_back(i + 1);  // 몇번 수포자인지 저장 
    }
    return answer;
}
