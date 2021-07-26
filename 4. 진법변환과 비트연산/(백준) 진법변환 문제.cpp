// https://www.acmicpc.net/problem/2745
// 백준 진법변환 문제 
// B진법 수 N이 주어진다. 이 수를 10진법으로 바꿔 출력하는 프로그램을 작성하시오.
// 10진법을 넘어가는 진법은 숫자로 표시할 수 없는 자리가 있다. 
// 이런 경우에는 다음과 같이 알파벳 대문자를 사용한다.
// A: 10, B: 11, ..., F: 15, ..., Y: 34, Z: 35

#include <iostream>
#include <math.h>

using namespace std;

int main(void){
	string s;
	int iNum;
	cin >> s;  // B진법수를 문자열로 입력받는다. 
	cin >> iNum;
	long long iSum = 0;
	for(int i = 0; i < s.length(); ++i){  // B진법수를 하나하나 탐색하면서 
		int x;
		if((int)s[i] >= 65 && (int)s[i] <= 90)  // 알파벳이면 
		x = (int)s[i] - 55;  // 10진법수로 변환 
		else
		x = (int)s[i] - 48;  // 숫자면 정수형으로 변환 
		
		iSum += int(pow(iNum, s.length() - 1 - i)) * x;  // B진법을 10진법으로 계산 
	}	
	
	cout << iSum;
	return 0;
} 

