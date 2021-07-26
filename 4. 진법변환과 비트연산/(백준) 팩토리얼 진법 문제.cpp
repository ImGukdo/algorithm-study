// https://www.acmicpc.net/problem/5692
// 백준 팩토리얼 진법 문제
// 상근이는 보통 사람들이 사는 것과는 조금 다른 삶을 사는 사람이다. 
// 상근이는 이런 사람들의 시선이 부담스럽기 때문에, 자신만의 숫자를 개발하기로 했다. 
// 바로 그 이름은 팩토리얼 진법이다. 
// 팩토리얼 진법은 각 자리에 올 수 있는 숫자는 0부터 9까지로 10진법과 거의 비슷하다. 
// 하지만, 읽는 법은 조금 다르다. 팩토리얼 진법에서는 i번 자리의 값을 ai×i!로 계산한다. 
// 즉, 팩토리얼 진법에서 719는 10진법에서 53과 같다. 그 이유는 7×3! + 1×2! + 9×1! = 53이기 때문이다.
// 팩토리얼 진법으로 작성한 숫자가 주어졌을 때, 10진법으로 읽은 값을 구하는 프로그램을 작성하시오. 

#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int iArray[6];

int Dp(int iInput){  // 팩토리얼 구하는 함수, 계속 계산하지 말고 계산할때 저장해놓는다. 
	if(iInput == 1)
	return 1;
	
	if(iInput == 2)
	return 2;
	
	if(iArray[iInput] != 0)
	return iArray[iInput];
	
	return iArray[iInput] = iInput * Dp(iInput - 1);
}


int main(void){
	vector<int> vec;
	int iTemp;
	
	while(true){  // 입력값 저장 
		scanf("%d", &iTemp);
		if(iTemp == 0)
		break;	
		vec.push_back(iTemp);	
	}	
	
	for(int i = 0; i < vec.size(); ++i){  // 입력받은 값을 탐색하면서 
		int x = vec[i];
		int iSum = 0;  
		int iCount = 4;  // 최대 5자리, 10**4승 이므로 4부터 시작 
		while(iCount >= 0){
			if(x / pow(10, iCount) != 0){  // 탐색하는 자릿수가 존재하면 
				iSum += (x / int(pow(10, iCount))) * Dp(iCount + 1);  // 계산값을 더해준다 
				x = x % int(pow(10, iCount));  // 값을 변경 
				
				if(x == 0)  // 값이 0이 되면 더이상 계산할피요가 없으니 탈출 
				break;
			}
			--iCount;
		}
		printf("%d\n", iSum);  // 값 출력 
	}
	return 0;
}
