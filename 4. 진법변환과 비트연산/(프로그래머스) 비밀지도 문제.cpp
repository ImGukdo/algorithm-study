// https://programmers.co.kr/learn/courses/30/lessons/17681
// 프로그래머스 비밀지도 문제
// 네오는 평소 프로도가 비상금을 숨겨놓는 장소를 알려줄 비밀지도를 손에 넣었다. 
// 그런데 이 비밀지도는 숫자로 암호화되어 있어 위치를 확인하기 위해서는 암호를 해독해야 한다. 
// 다행히 지도 암호를 해독할 방법을 적어놓은 메모도 함께 발견했다. 
// 1. 지도는 한 변의 길이가 n인 정사각형 배열 형태로, 각 칸은 "공백"(" ") 또는 "벽"("#") 두 종류로 이루어져 있다.
// 2. 전체 지도는 두 장의 지도를 겹쳐서 얻을 수 있다. 
// 각각 "지도 1"과 "지도 2"라고 하자. 지도 1 또는 지도 2 중 어느 하나라도 벽인 부분은 전체 지도에서도 벽이다. 
// 지도 1과 지도 2에서 모두 공백인 부분은 전체 지도에서도 공백이다.
// 3. "지도 1"과 "지도 2"는 각각 정수 배열로 암호화되어 있다.
// 4. 암호화된 배열은 지도의 각 가로줄에서 벽 부분을 1, 공백 부분을 0으로 부호화했을 때 
// 얻어지는 이진수에 해당하는 값의 배열이다.
// 네오가 프로도의 비상금을 손에 넣을 수 있도록, 비밀지도의 암호를 해독하는 작업을 도와줄 프로그램을 작성하라.

#include <string>
#include <vector>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    int iArray1[n * n];  // 첫번째 지도를 2진수로 변환해서 저장할 배열 
    int iArray2[n * n];  // 두번째 지도를 2진수로 변환해서 저장할 배열 
    for(int i = 0; i < n; ++i){  // 2진수로 변환 
        int j = 0;
        while(j < n){  // 행 구분  
            iArray1[(i + 1) * n - 1 - j] = arr1[i] % 2;  // 2로 나눈 나머지를 배열 행의 마지막 열부터 거꾸로 넣어준다. 
            iArray2[(i + 1) * n - 1 - j] = arr2[i] % 2;
            arr1[i] /= 2;  // 나눈 몫을 다시 값으로 가진다. 
            arr2[i] /= 2;
            ++j;
        }
    }
    string s[n];  // 암호 해독한것을 저장할 문자열 변수 
    fill(s, s + n, "");  // 초기화 
    for(int i = 0; i < n * n; ++i){
        if(iArray1[i] | iArray2[i])  // 비트 or 연산을 통해 값을 넣어준다 
        s[i / n] += "#";  // 1이면 #
        else
        s[i / n] += " ";  // 0이면 공백 
        if((i + 1) % n == 0)  // 행을 구분해서 문자열을 넣어준다. 
            answer.push_back(s[i / n]);
    }
    return answer;
}

-------------------------------------------------------------------------------------

#include <string>
#include <vector>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    int iArray[n]; // 비트연산 결과를 저장할 변수
    for(int i = 0; i < n; ++i){
        iArray[i] = (arr1[i]|arr2[i]);  // 각각의 줄을 비트합 연산을 하고 저장
    }
    for(int i = 0; i < n; ++i){
        string s = "";
        for(int j = n; j > 0; --j){
            (iArray[i]&(1<<j-1))?s+='#':s+=' ';  // 비트 연산한 결과를 다시 각 자리 수와 1을 비트곱 연산한다.
        }
        answer.push_back(s);
    }
    return answer;
}
