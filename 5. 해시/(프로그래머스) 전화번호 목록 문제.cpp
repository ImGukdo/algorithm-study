// https://programmers.co.kr/learn/courses/30/lessons/42577
// 프로그래머스 전화번호 목록 문제
// 전화번호부에 적힌 전화번호 중, 한 번호가 다른 번호의 접두어인 경우가 있는지 확인하려 합니다.
// 전화번호가 다음과 같을 경우, 구조대 전화번호는 영석이의 전화번호의 접두사입니다.
// 구조대 : 119
// 박준영 : 97 674 223
// 지영석 : 11 9552 4421
// 전화번호부에 적힌 전화번호를 담은 배열 phone_book 이 solution 함수의 매개변수로 주어질 때,
// 어떤 번호가 다른 번호의 접두어인 경우가 있으면 false를 
// 그렇지 않으면 true를 return 하도록 solution 함수를 작성해주세요.

#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

map<long long, int> m;  // key값 : 해시값, value : 인덱스 
map<long long, int>::iterator iter;  // 접근자 생성 

bool compare(string a, string b){  // 벡터를 글자수가 적은것부터 오름차순으로 정렬하기 위한 비교함수 
    return a.length() < b.length();
}
long long iArray[51];  
long long Pow(int iInput){  // 해시계산을 도와줄 거듭제곱 함수 
	if(iInput == 0)
	return 1;
	
	if(iArray[iInput] != 0)
	return iArray[iInput];
	
	return iArray[iInput] = 31 * Pow(iInput - 1) % 1234567891;   
}
long long Hash(string s, int size){  // 해시 함수, 문자열을 해시값으로 계산 
    long long iResult = 0;
	for(int i = 0; i < size; ++i){
        iResult += (int)s[i] * Pow(i) % 1234567891;
        iResult %= 1234567891;
    }
	return iResult;   
}

bool solution(vector<string> phone_book) {
    bool answer = true;
    sort(phone_book.begin(), phone_book.end(), compare);  // 폰북의 값들을 글자수가 적은순으로 정렬 
    
    int x = Hash(phone_book[0], phone_book[0].length());  // 첫번째 문자열의 해시값 
    for(int i = 1; i < phone_book.size(); ++i){  // 두번째 문자열부터 탐색하면서 
        int y = Hash(phone_book[i], phone_book[0].length());  // 첫번째 문자열 길이만큼의 해시값 계산 
        if(x == y){  // 해시값이 같으면 
            answer = false;  // 접두사가 있으므로 false 
            break;  // 탈출 
        }
        else{  // 해시값이 다르면 
            iter = m.find(y);   
            if(iter == m.end()){  // 현재 해시값으로된 map의 key가 없으면 
                m.insert(make_pair(y, i));  // key : 해시값, value : 인덱스 를 넣어줌 
            }
            else{  // 현재 해시값으로된 map의 key가 있으면 
                long long a = Hash(phone_book[m[y]], phone_book[m[y]].length());  // key값의 value를 인덱스로 해서 문자열 길이만큼 해시값을 구함 
                long long b = Hash(phone_book[i], phone_book[m[y]].length());  // 동일한 문자열 길이로 해시값을 구함 
                if(a == b){  // 해시값이 같으면 
                    answer = false;  // 접두사가 있으므로 false 
                    break;  // 탈출 
                }
            }
        }
    }

    return answer;
}
