// https://www.acmicpc.net/problem/10872
// 백준 팩토리얼 문제
// 0보다 크거나 같은 정수 N이 주어진다. 이때, N!을 출력하는 프로그램을 작성하시오.
 

#include <iostream>

using namespace std;

int fac(int iInput){  // 팩토리얼 구현 함수 
	if(iInput == 1)
	return 1;
	
	return iInput * fac(iInput - 1);
}

int main(void){
	int iNum;
	scanf("%d", &iNum);
	if(iNum == 0)
	printf("%d", 1);
	else
	printf("%d", fac(iNum));
	return 0;
}
