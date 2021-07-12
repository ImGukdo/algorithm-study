// https://www.acmicpc.net/problem/10816
// 백준 숫자 카드 2 문제 
// 숫자 카드는 정수 하나가 적혀져 있는 카드이다. 
// 상근이는 숫자 카드 N개를 가지고 있다. 정수 M개가 주어졌을 때, 
// 이 수가 적혀있는 숫자 카드를 상근이가 몇 개 가지고 있는지 구하는 프로그램을 작성하시오.
// 첫째 줄에 상근이가 가지고 있는 숫자 카드의 개수 N(1 ≤ N ≤ 500,000)이 주어진다. 
// 둘째 줄에는 숫자 카드에 적혀있는 정수가 주어진다. 숫자 카드에 적혀있는 수는 -10,000,000보다 크거나 같고, 10,000,000보다 작거나 같다.
// 셋째 줄에는 M(1 ≤ M ≤ 500,000)이 주어진다. 
// 넷째 줄에는 상근이가 몇 개 가지고 있는 숫자 카드인지 구해야 할 M개의 정수가 주어지며, 이 수는 공백으로 구분되어져 있다.
// 이 수도 -10,000,000보다 크거나 같고, 10,000,000보다 작거나 같다.

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct _tagcard{  // 구조체 생성 
	int iNumber;  // 숫자 
	int iIndex;  // 인덱스 
	int iCount;  // 갯수 
};

bool compare(_tagcard a, _tagcard b){  // 구조체 숫자 비교 함수 
	return a.iNumber < b.iNumber;
}
bool compare2(_tagcard a, _tagcard b){  // 구조체 인덱스 비교 함수 
	return a.iIndex < b.iIndex;
}

int main(void){
	int iNum;  // 가지고 있는 숫자 갯수를 입력 받음 
	scanf("%d", &iNum);
	int iArray[iNum];  // 가지고 있는 숫자들을 저장 
	for(int i = 0; i < iNum; ++i){
		scanf("%d", &iArray[i]);
	}
	int iNum2;  // 비교할 숫자 갯수를 입력 받음 
	scanf("%d", &iNum2);
	_tagcard aaa[iNum2];  // 구조체 객체 생성 
	for(int i = 0; i < iNum2; ++i){   
		scanf("%d", &aaa[i].iNumber);  // 숫자 저장 
		aaa[i].iIndex = i;  // 인덱스 저장
		aaa[i].iCount = 0;  // 갯수 0으로 초기화 
	}
	
	sort(iArray, iArray + iNum);  // 가지고 있는 숫자카드를 오름차순으로 정렬 
	sort(aaa, aaa + iNum2, compare);  // 비교 숫자를 숫자 기준으로 오름차순으로 정렬 
	int iIndex = 0;  // 비교 숫자의 시작 인덱스 설정 

	for(int i = 0; i < iNum2; ++i){  // 정렬된 비교숫자를 탐색 
		for(int j = iIndex; j < iNum; ++j){  // 정렬된 가지고 있는 숫자카드를 탐색 
			if(i > 0 && aaa[i - 1].iNumber == aaa[i].iNumber){  // 비교숫자가 이전 비교숫자와 같으면 
				aaa[i].iCount = aaa[i - 1].iCount;  // 카운팅 갯수를 똑같이 저장 
				break;
			}
			
			if(aaa[i].iNumber == iArray[j])  // 비교숫자와 가지고 있는 숫자카드가 같으면 
			++aaa[i].iCount;  // 카운트 증가 
			
			else if(iArray[j] > aaa[i].iNumber){  // 가지고 있는 숫자카드가 더 크면 
				iIndex = j;  // 비교 숫자 인덱스를 재설정하고 
				break;  //  탈출 
			}
		}
	}
	
	sort(aaa, aaa + iNum2, compare2);  // 비교 숫자를 인덱스 기준으로 오름차순 정렬 
	for(int i = 0; i < iNum2; ++i){
		printf("%d ", aaa[i].iCount);  // 카운팅 갯수 출력 
	}
	
	return 0;
}
