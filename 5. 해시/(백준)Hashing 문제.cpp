// https://www.acmicpc.net/problem/15829
// 백준 Hashing 문제
// APC에 온 것을 환영한다. 만약 여러분이 학교에서 자료구조를 수강했다면 해시 함수에 대해 배웠을 것이다. 
// 해시 함수란 임의의 길이의 입력을 받아서 고정된 길이의 출력을 내보내는 함수로 정의한다. 
// 해시 함수는 무궁무진한 응용 분야를 갖는데, 대표적으로 자료의 저장과 탐색에 쓰인다.
// 이 문제에서는 여러분이 앞으로 유용하게 쓸 수 있는 해시 함수를 하나 가르쳐주고자 한다. 
// 먼저, 편의상 입력으로 들어오는 문자열에는 영문 소문자(a, b, ..., z)로만 구성되어있다고 가정하자. 
// 영어에는 총 26개의 알파벳이 존재하므로 a에는 1, b에는 2, c에는 3, ..., z에는 26으로 고유한 번호를 부여할 수 있다. 
// 결과적으로 우리는 하나의 문자열을 수열로 변환할 수 있다. 예를 들어서 문자열 "abba"은 수열 1, 2, 2, 1로 나타낼 수 있다.
// abcde의 해시 값은 1 × 310 + 2 × 311 + 3 × 312 + 4 × 313 + 5 × 314 = 1 + 62 + 2883 + 119164 + 4617605 = 4739715이다.
// zzz의 해시 값은 26 × 310 + 26 × 311 + 26 × 312 = 26 + 806 + 24986 = 25818이다.
 

#include <iostream>

using namespace std;

long long iArray[51];  // 31의 거듭 제곱을 저장할 배열 
long long Pow(int iInput){  // 31의 거듭제곱을 구하는 함수 
	if(iInput == 0)
	return 1;
	
	if(iArray[iInput] != 0)
	return iArray[iInput];
	
	return iArray[iInput] = 31 * Pow(iInput - 1) % 1234567891;  // 오버플로우을 방지하기 위해 1234567891 로 나눈 나머지를 사용 
}


int main(void){
	int iNum;
	string s;
	scanf("%d", &iNum);
	cin >> s;
	long long iHash = 0;
	for(int i = 0; i < iNum; ++i){
		iHash += ((int)s[i] - 96) * Pow(i);	 // 해시값 계산 
		iHash %= 1234567891;  // 오버플로우을 방지하기 위해 1234567891 로 나눈 나머지를 사용
	}
	printf("%lld", iHash);
	return 0;
}
