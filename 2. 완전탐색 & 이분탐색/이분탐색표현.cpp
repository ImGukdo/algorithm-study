// 이진검색이라고도 표현하며 오름차순으로 정렬된 배열에서
// 특정값의 위치를 찾는 알고리즘
// 중간의 값을 선택하여 찾고자 하는 값과의 크고 작음을 비교하는 방법

#include <iostream>

using namespace std;
int iArray[12] = {1, 3, 5, 7, 9, 11, 14, 15, 18, 19, 25, 28};  // 12개의 원소를 가진 정렬된 배열 

int Search(int iStart, int iEnd, int iTarget){
	if(iStart > iEnd)  // 시작값이 끝값보다 크면 
	return -1;  // -1 반환 
	int iMiddle = (iStart + iEnd) / 2;  // 중간값 설정 
	if(iArray[iMiddle] == iTarget)  // 만약 중간값이 원하는 값과 같으면 
	return iMiddle;  // 인덱스 반환 
	else if(iArray[iMiddle] > iTarget)  // 중간값이 더크면 
	return Search(iStart, iMiddle - 1, iTarget);  // 중간값보다 작은 범위에서 다시 함수 호출 
	else // 중간값이 더 작으면 
	return Search(iMiddle + 1, iEnd, iTarget);  // 중간값보다 큰 범위에서 다시 함수 호출 
}

int main(void){
	int iResult = Search(0, 11, 7);  // 함수호출하여 반환값 저장 
	if(iResult != -1)  // 반환값이 -1이 아니면 즉 시작값과 끝값 설정이 알맞으면 
	cout << iResult + 1 << "번째 인덱스에서 발견했습니다." << endl;  // 인덱스 반환 
	
	return 0;
} 
