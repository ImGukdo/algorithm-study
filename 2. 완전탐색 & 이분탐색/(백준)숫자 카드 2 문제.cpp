// https://www.acmicpc.net/problem/10816
// ���� ���� ī�� 2 ���� 
// ���� ī��� ���� �ϳ��� ������ �ִ� ī���̴�. 
// ����̴� ���� ī�� N���� ������ �ִ�. ���� M���� �־����� ��, 
// �� ���� �����ִ� ���� ī�带 ����̰� �� �� ������ �ִ��� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.
// ù° �ٿ� ����̰� ������ �ִ� ���� ī���� ���� N(1 �� N �� 500,000)�� �־�����. 
// ��° �ٿ��� ���� ī�忡 �����ִ� ������ �־�����. ���� ī�忡 �����ִ� ���� -10,000,000���� ũ�ų� ����, 10,000,000���� �۰ų� ����.
// ��° �ٿ��� M(1 �� M �� 500,000)�� �־�����. 
// ��° �ٿ��� ����̰� �� �� ������ �ִ� ���� ī������ ���ؾ� �� M���� ������ �־�����, �� ���� �������� ���еǾ��� �ִ�.
// �� ���� -10,000,000���� ũ�ų� ����, 10,000,000���� �۰ų� ����.

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct _tagcard{  // ����ü ���� 
	int iNumber;  // ���� 
	int iIndex;  // �ε��� 
	int iCount;  // ���� 
};

bool compare(_tagcard a, _tagcard b){  // ����ü ���� �� �Լ� 
	return a.iNumber < b.iNumber;
}
bool compare2(_tagcard a, _tagcard b){  // ����ü �ε��� �� �Լ� 
	return a.iIndex < b.iIndex;
}

int main(void){
	int iNum;  // ������ �ִ� ���� ������ �Է� ���� 
	scanf("%d", &iNum);
	int iArray[iNum];  // ������ �ִ� ���ڵ��� ���� 
	for(int i = 0; i < iNum; ++i){
		scanf("%d", &iArray[i]);
	}
	int iNum2;  // ���� ���� ������ �Է� ���� 
	scanf("%d", &iNum2);
	_tagcard aaa[iNum2];  // ����ü ��ü ���� 
	for(int i = 0; i < iNum2; ++i){   
		scanf("%d", &aaa[i].iNumber);  // ���� ���� 
		aaa[i].iIndex = i;  // �ε��� ����
		aaa[i].iCount = 0;  // ���� 0���� �ʱ�ȭ 
	}
	
	sort(iArray, iArray + iNum);  // ������ �ִ� ����ī�带 ������������ ���� 
	sort(aaa, aaa + iNum2, compare);  // �� ���ڸ� ���� �������� ������������ ���� 
	int iIndex = 0;  // �� ������ ���� �ε��� ���� 

	for(int i = 0; i < iNum2; ++i){  // ���ĵ� �񱳼��ڸ� Ž�� 
		for(int j = iIndex; j < iNum; ++j){  // ���ĵ� ������ �ִ� ����ī�带 Ž�� 
			if(i > 0 && aaa[i - 1].iNumber == aaa[i].iNumber){  // �񱳼��ڰ� ���� �񱳼��ڿ� ������ 
				aaa[i].iCount = aaa[i - 1].iCount;  // ī���� ������ �Ȱ��� ���� 
				break;
			}
			
			if(aaa[i].iNumber == iArray[j])  // �񱳼��ڿ� ������ �ִ� ����ī�尡 ������ 
			++aaa[i].iCount;  // ī��Ʈ ���� 
			
			else if(iArray[j] > aaa[i].iNumber){  // ������ �ִ� ����ī�尡 �� ũ�� 
				iIndex = j;  // �� ���� �ε����� �缳���ϰ� 
				break;  //  Ż�� 
			}
		}
	}
	
	sort(aaa, aaa + iNum2, compare2);  // �� ���ڸ� �ε��� �������� �������� ���� 
	for(int i = 0; i < iNum2; ++i){
		printf("%d ", aaa[i].iCount);  // ī���� ���� ��� 
	}
	
	return 0;
}
