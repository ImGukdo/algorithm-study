#include <iostream>

using namespace std;
// 2���� ���·� ǥ���ϱ� 
void Show(int* iInput){
	for(int i = 32; i > 0; --i){
		cout << ((*iInput & (1 << i - 1)) ? 1 : 0);
	}
}
// ��� ���� �����ϱ� 
void Init(int* iInput){
	*iInput = 0;
} 
// ��� ���� �����ϱ� 
void Full(int* iInput){
	*iInput = -1;
}
// Ư�� ���Ҹ� �����ϱ�
void Drop(int* iInput, int iIndex){
	*iInput &= ~(1 << iIndex - 1);
} 
// Ư�� ���� ���Խ�Ű��
void Set(int* iInput, int iIndex){
	*iInput |= (1 << iIndex - 1);
} 
// Ư�� ���� ����ϱ�
void Toggle(int* iInput, int iIndex){
	*iInput ^= (1 << iIndex - 1);
} 
// Ư�� ������ ���� ���θ� Ȯ���ϱ�
bool IsSet(int* iInput, int iIndex){
	return *iInput & (1 << iIndex - 1);
} 
// ������ ���� ���ϱ�
int GetLast(int* iInput){
	return (*iInput & -*iInput);
} 
// ������ ���� �����ϱ� 
void DropLast(int* iInput){
	*iInput &= (*iInput - 1);
}
int main(void){
	int iInput;
	
	Init(&iInput);
	cout << "��� ���� ���� : ";  
	Show(&iInput);  // ��� ���� ���� : 00000000000000000000000000000000
	cout << endl;
	
	Full(&iInput);
	cout << "��� ���� ���� : ";
	Show(&iInput);  // ��� ���� ���� : 11111111111111111111111111111111
	cout << endl;
	
	Drop(&iInput, 5);
	cout << "5��° �ε��� ���� : ";
	Show(&iInput);  // 5��° �ε��� ���� : 11111111111111111111111111101111
	cout << endl;
	
	Set(&iInput, 5);
	cout << "5��° �ε��� ���� : ";
	Show(&iInput);  // 5��° �ε��� ���� : 11111111111111111111111111111111
	cout << endl;
	
	cout << "5��° �ε��� ���� ���� : " << IsSet(&iInput, 5);  // 5��° �ε��� ���� ���� : 1
	cout << endl; 
	
	Toggle(&iInput, 5);
	cout << "5��° �ε��� ��� : ";
	Show(&iInput);  // 5��° �ε��� ��� : 11111111111111111111111111101111
	cout << endl;
	
	cout << "5��° �ε��� ���� ���� : " << IsSet(&iInput, 5) << endl;  // 5��° �ε��� ���� ���� : 0
	
	DropLast(&iInput);
	DropLast(&iInput);
	DropLast(&iInput);
	cout << "������ ���� 3�� ���� : ";
	Show(&iInput);  // 5��° �ε��� ���� ���� : 0
	cout << endl;
	
	cout << "������ ���� ���ϱ� : " << GetLast(&iInput);  // ������ ���� ���ϱ� : 8
	cout << endl;
	return 0;
}
