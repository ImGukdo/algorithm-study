// https://www.acmicpc.net/problem/10872
// ���� ���丮�� ����
// 0���� ũ�ų� ���� ���� N�� �־�����. �̶�, N!�� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.
 

#include <iostream>

using namespace std;

int fac(int iInput){  // ���丮�� ���� �Լ� 
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
