#include <iostream>

using namespace std;
// 2진수 형태로 표현하기 
void Show(int* iInput){
	for(int i = 32; i > 0; --i){
		cout << ((*iInput & (1 << i - 1)) ? 1 : 0);
	}
}
// 모든 원소 삭제하기 
void Init(int* iInput){
	*iInput = 0;
} 
// 모든 원소 포함하기 
void Full(int* iInput){
	*iInput = -1;
}
// 특정 원소를 삭제하기
void Drop(int* iInput, int iIndex){
	*iInput &= ~(1 << iIndex - 1);
} 
// 특정 원소 포함시키기
void Set(int* iInput, int iIndex){
	*iInput |= (1 << iIndex - 1);
} 
// 특정 원소 토글하기
void Toggle(int* iInput, int iIndex){
	*iInput ^= (1 << iIndex - 1);
} 
// 특정 원소의 포함 여부를 확인하기
bool IsSet(int* iInput, int iIndex){
	return *iInput & (1 << iIndex - 1);
} 
// 마지막 원소 구하기
int GetLast(int* iInput){
	return (*iInput & -*iInput);
} 
// 마지막 원소 삭제하기 
void DropLast(int* iInput){
	*iInput &= (*iInput - 1);
}
int main(void){
	int iInput;
	
	Init(&iInput);
	cout << "모든 원소 삭제 : ";  
	Show(&iInput);  // 모든 원소 삭제 : 00000000000000000000000000000000
	cout << endl;
	
	Full(&iInput);
	cout << "모든 원소 포함 : ";
	Show(&iInput);  // 모든 원소 포함 : 11111111111111111111111111111111
	cout << endl;
	
	Drop(&iInput, 5);
	cout << "5번째 인덱스 삭제 : ";
	Show(&iInput);  // 5번째 인덱스 삭제 : 11111111111111111111111111101111
	cout << endl;
	
	Set(&iInput, 5);
	cout << "5번째 인덱스 포함 : ";
	Show(&iInput);  // 5번째 인덱스 포함 : 11111111111111111111111111111111
	cout << endl;
	
	cout << "5번째 인덱스 포함 여부 : " << IsSet(&iInput, 5);  // 5번째 인덱스 포함 여부 : 1
	cout << endl; 
	
	Toggle(&iInput, 5);
	cout << "5번째 인덱스 토글 : ";
	Show(&iInput);  // 5번째 인덱스 토글 : 11111111111111111111111111101111
	cout << endl;
	
	cout << "5번째 인덱스 포함 여부 : " << IsSet(&iInput, 5) << endl;  // 5번째 인덱스 포함 여부 : 0
	
	DropLast(&iInput);
	DropLast(&iInput);
	DropLast(&iInput);
	cout << "마지막 원소 3개 삭제 : ";
	Show(&iInput);  // 5번째 인덱스 포함 여부 : 0
	cout << endl;
	
	cout << "마지막 원소 구하기 : " << GetLast(&iInput);  // 마지막 원소 구하기 : 8
	cout << endl;
	return 0;
}
