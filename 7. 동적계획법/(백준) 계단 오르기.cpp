// https://www.acmicpc.net/problem/2579
// 백준 계단 오르기 문제
// 계단 오르기 게임은 계단 아래 시작점부터 계단 꼭대기에 위치한 도착점까지 가는 게임이다. 
// 각각의 계단에는 일정한 점수가 쓰여 있는데 계단을 밟으면 그 계단에 쓰여 있는 점수를 얻게 된다. 
// 계단 오르는 데는 다음과 같은 규칙이 있다.
// 1. 계단은 한 번에 한 계단씩 또는 두 계단씩 오를 수 있다.
// 즉, 한 계단을 밟으면서 이어서 다음 계단이나, 다음 다음 계단으로 오를 수 있다.
// 2. 연속된 세 개의 계단을 모두 밟아서는 안 된다. 단, 시작점은 계단에 포함되지 않는다.
// 3. 마지막 도착 계단은 반드시 밟아야 한다.
// 따라서 첫 번째 계단을 밟고 이어 두 번째 계단이나, 세 번째 계단으로 오를 수 있다. 
// 하지만, 첫 번째 계단을 밟고 이어 네 번째 계단으로 올라가거나, 
// 첫 번째, 두 번째, 세 번째 계단을 연속해서 모두 밟을 수는 없다.
// 각 계단에 쓰여 있는 점수가 주어질 때 이 게임에서 얻을 수 있는 
// 총 점수의 최댓값을 구하는 프로그램을 작성하시오.


#include <iostream>
#include <vector>

using namespace std;

vector<int> vec;  //  계단에 부여된 점수를 저장할 변수 
// Dp 함수의 값을 저장할 변수
// 0번째 인덱스는 한계단 전을 거치고 두계단 전은 거치지 않는다. 
// 1번째 인덱스는 두계단 전을 거치지 않는다. 
int iArray[301][2];   

void Dp(int iInput){	
	if(iArray[iInput - 1][0] == 0)  // iInput - 1 번째 계단의 값이 없으면 
	Dp(iInput - 1);  // 그 이전 계단의 값을 구한다. 
	
	if(iArray[iInput - 1][0] != 0){
		// 0인덱스 변수에는 한계단 전의 값을 더하는데 그 값이 그 이전 계단을 지나지 않은 값이여야한다
		iArray[iInput][0] = vec[iInput] + iArray[iInput - 1][1];
		
		// 1인덱스 변수에는 두계단 전의 값을 더하는데 그 값이 그 이전 계단을 거쳐서 얻은 값과 전전 계단을 거쳐 얻은 값 중에서 큰값이다.   
		iArray[iInput][1] = vec[iInput] + max(iArray[iInput - 2][0], iArray[iInput - 2][1]);
		return;
	}
} 


int main(void){
	int iNum;
	scanf("%d", &iNum);
	int iTemp; 
	for(int i = 0; i < iNum; ++i){  // 계단에 부여된 점수를 저장 
		scanf("%d", &iTemp);
		vec.push_back(iTemp);
	}
	
	// 0번째, 1번째, 2번째 계단의 값을 미리 구해놓는다.	 
	iArray[0][0] = vec[0];
	iArray[0][1] = vec[0];
	iArray[1][0] = vec[0] + vec[1];;
	iArray[1][1] = vec[1];
	iArray[2][0] = vec[2] + vec[1];
	iArray[2][1] = vec[2] + vec[0];
 
	Dp(iNum -1);  // Dp 함수 실행 
	// 한계단 전을 거친 값과 두계단 전을 거친 값중 큰 값을 출력 
	printf("%d", max(iArray[iNum -1][0], iArray[iNum - 1][1]));
	return 0;
}
