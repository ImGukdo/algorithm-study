// https://www.acmicpc.net/problem/10829
// 백준 이진수 변환 문제
// 자연수 N이 주어진다. N을 이진수로 바꿔서 출력하는 프로그램을 작성하시오. 


#include <iostream>
#include <vector>
using namespace std;
vector<int> vec; // 이진수를 저장할 백터 

void binary(long long iInput){
	if(iInput / 2 == 0){  // 2로 더이상 나눌수 없다면 
		if(iInput % 2 == 1)  // 그 수가 1이면 
		vec.push_back(1);  // 1을 넣어준다 
		return;
	}
	vec.push_back(iInput % 2);  // 2로 나눈 나머지를 넣어준다 
	binary(iInput / 2);  // 2로 나눈 값을 다시 매개변수로 해서 재귀함수를 실행한다. 
}


int main(void){
	long long iNum;  
	scanf("%lld", &iNum);  // 10진수를 입력받는다 
	binary(iNum);  // 2진수 구하는 함수 실행 
	for(int i = vec.size() - 1; i >= 0; --i){  // 백터를 가장 뒤에서부터 탐색하면서 
		printf("%d", vec[i]);  // 출력 
	}
	return 0;
}
