// https://programmers.co.kr/learn/courses/30/lessons/42839
// 프로그래머스 소수찾기 문제 
// 한자리 숫자가 적힌 종이 조각이 흩어져있습니다. 
// 흩어진 종이 조각을 붙여 소수를 몇 개 만들 수 있는지 알아내려 합니다.
// 각 종이 조각에 적힌 숫자가 적힌 문자열 numbers가 주어졌을 때, 
// 종이 조각으로 만들 수 있는 소수가 몇 개인지 return 하도록 solution 함수를 완성해주세요.

#include <string>
#include <vector>

using namespace std;
int iCount;  // 소수갯수 저장 
vector<int> vec;  // 내가 가지고 있는 숫자들 
bool bCheck[10];  // 탐색한 인덱스인지 체크 
vector<int> rem;  // 조합해서 만든 숫자들을 저장 

// 소수인지 아닌지 판별하는 함수, 숫자를 하나씩 늘려가며 판별하기 위해 재귀함수로 구현 
void Dfs(int iNum, int place, int index){  // 매개변수 : 조합해서 입력받은 수, 몇개의 수의 조합인지 갯수, 조합한 인덱스 
    bCheck[index] = true;  // 조합한 인덱스를 체크 
    rem.push_back(iNum);  // 조합된 숫자 저장 
    ++iCount;  // 일단 소수라고 가정하고 소수 증가 
    for(int i = 2; i * i <= iNum; ++i){  // 소수인지 판별, 조합된 숫자의 제곱근까지만 반복하여 반복을 줄임 
        if(iNum % i == 0){  // 소수라면 
            --iCount;  // 소수 감소 
            break;  // 반복문 탈출 
        }
    }
    if(place == vec.size() - 1)  // 가지고 있는 숫자 길이만큼 전부 조합했으면 
        return;  // 리턴 
    
    for(int i = 0; i < vec.size(); ++i){  // 내가 가진 숫자들을 탐색하면서 
        bool flag = false;  // 이미 조합해서 만든 숫자인지 체크 
        for(int j = 0; j < rem.size(); ++j){  // 조합한 숫자들을 탐색 
            if(rem[j] == iNum * 10 + vec[i]){  // 이미 조합된 숫자면 
                flag = true;  // 체크 
                break;
            }
        }
        if(!bCheck[i] && !flag){  // 내가 가진 숫자의 탐색한 인덱스가 아니고 이미 조합된 숫자도 아니면  
            Dfs(iNum * 10 + vec[i], place + 1, i);  // 새로 조합한 숫자, 조합된 숫자 갯수, 인덱스로 재귀함수 실행 
            bCheck[i] = false;  // 재귀함수가 종료되서 돌아오면 수행한 인덱스를 다시 탐색안한 것으로 체크 
        }
    }
}

int solution(string numbers) {
    int answer = 0;
    bool bnum[10];  // 중복된 숫자가 있는지 체크 
    fill(bnum, bnum + 10, false);  // 전부 false로 초기화 
    for(int i = 0; i < numbers.length(); ++i){  // 문자열로 받은 숫자를 정수형으로 변환하여 저장 
        vec.push_back(int(numbers[i]) - 48);
    }
    for(int i = 0; i < vec.size(); ++i){  // 내가 가진 숫자들을 탐색 
        fill(bCheck, bCheck + 10, false);  // 다시 한자리수부터 반복하기때문에 탐색한 인덱스가 없다고 초기화  
        if(vec[i] == 0 || bnum[vec[i]])  // 첫번째 숫자로 0이나  이미 수행했던 숫자면 패스 
            continue;
        if(vec[i] == 1)  // 첫번째 숫자가 1이면 소수가 아니므로 
            --iCount;  // 소수를 감소하고 시작, 소수판별함수에서 1 증가시키기 때문 
        bnum[vec[i]] = true;  // 중복 탐색을 방지하기 위해 탐색한 숫자를 체크 
        Dfs(vec[i], 0, i);  // 소수판별함수 실행 
    }
    answer = iCount;  // 계산된 소수갯수를 정답에 넣어준다. 
    return answer;
}
