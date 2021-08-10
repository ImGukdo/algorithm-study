// https://programmers.co.kr/learn/courses/30/lessons/42895
// 프로그래머스 N으로 표현 문제 
// 아래와 같이 5와 사칙연산만으로 12를 표현할 수 있습니다.
// 12 = 5 + 5 + (5 / 5) + (5 / 5)
// 12 = 55 / 5 + 5 / 5
// 12 = (55 + 5) / 5
// 5를 사용한 횟수는 각각 6,5,4 입니다. 그리고 이중 가장 작은 경우는 4입니다.
// 이처럼 숫자 N과 number가 주어질 때, N과 사칙연산만 사용해서 표현 할 수 있는 방법 중 
// N 사용횟수의 최솟값을 return 하도록 solution 함수를 작성하세요.


#include <string>
#include <vector>

using namespace std;
int solution(int N, int number) {
    int answer = 0;
    vector<int> vec[9];  // N을 이용한 횟수로 만들수 있는 수를 저장할 변수 
    int iSum = 0;
    for(int i = 1; i <= 8; ++i){  // N을 연속절으로 나열하여 만든 수를 미리 넣어둔다. 
        iSum *= 10;
        iSum += N;
        vec[i].push_back(iSum);
    }
    bool bCheck = false;  // while문 탈출을 위한 체크변수 
    while(true){
        ++answer;  // N의 개수와 동일 
        for(int i = 0; i < vec[answer].size(); ++i){  // answer개로 만든 수들을 탐색하면서  
            if(vec[answer][i] == number){  // 찾는 number가 있으면 
                bCheck = true;
                break;  // 탈출 
            }
            if(answer < 8){  // N의 개수가 8보다 작을 때  
                for(int j = answer; j >= 1; --j){  // 현재 answer를 거꾸로 탐색하면서 
                    if(answer + j <= 8){  // 현재 answer와 j의 합이 8 이하이면 
                        for(int k = 0; k < vec[j].size(); ++k){  // j개로 만든 수를 탐색하면서 
                            if(vec[j][k] != 0)
                            vec[answer + j].push_back(vec[answer][i] / vec[j][k]);  // 사칙연산한 값을 넣어준다. 
                            vec[answer + j].push_back(vec[answer][i] + vec[j][k]);
                            vec[answer + j].push_back(vec[answer][i] - vec[j][k]);
                            vec[answer + j].push_back(vec[answer][i] * vec[j][k]);
			    if(answer != j){  // answer 와 j 가 같지않으면 서로 위치를 바꿔 계산한 -, / 값만 넣어준다. 
	                            vec[answer + j].push_back(vec[j][k] - vec[answer][i]); 
	                            if(vec[answer][i] != 0)
	                            vec[answer + j].push_back(vec[j][k] / vec[answer][i]);
                            }
                        }   
                    }
                }
            }
        }
        if(bCheck)  // 원하는 값을 찾았으면 
            break;  // 탈출 
        if(answer == 8){  // 8개의 조합까지 전부 탐색했어도 원하는 값이 없으면 
            answer = -1;  // -1 값을 넣어주고 
            break;  // 탈출 
        }   
    }
    return answer;
}
