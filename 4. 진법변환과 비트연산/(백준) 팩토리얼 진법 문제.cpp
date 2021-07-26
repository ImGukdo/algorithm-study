// https://www.acmicpc.net/problem/5692
// ���� ���丮�� ���� ����
// ����̴� ���� ������� ��� �Ͱ��� ���� �ٸ� ���� ��� ����̴�. 
// ����̴� �̷� ������� �ü��� �δ㽺���� ������, �ڽŸ��� ���ڸ� �����ϱ�� �ߴ�. 
// �ٷ� �� �̸��� ���丮�� �����̴�. 
// ���丮�� ������ �� �ڸ��� �� �� �ִ� ���ڴ� 0���� 9������ 10������ ���� ����ϴ�. 
// ������, �д� ���� ���� �ٸ���. ���丮�� ���������� i�� �ڸ��� ���� ai��i!�� ����Ѵ�. 
// ��, ���丮�� �������� 719�� 10�������� 53�� ����. �� ������ 7��3! + 1��2! + 9��1! = 53�̱� �����̴�.
// ���丮�� �������� �ۼ��� ���ڰ� �־����� ��, 10�������� ���� ���� ���ϴ� ���α׷��� �ۼ��Ͻÿ�. 

#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int iArray[6];

int Dp(int iInput){  // ���丮�� ���ϴ� �Լ�, ��� ������� ���� ����Ҷ� �����س��´�. 
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
	
	while(true){  // �Է°� ���� 
		scanf("%d", &iTemp);
		if(iTemp == 0)
		break;	
		vec.push_back(iTemp);	
	}	
	
	for(int i = 0; i < vec.size(); ++i){  // �Է¹��� ���� Ž���ϸ鼭 
		int x = vec[i];
		int iSum = 0;  
		int iCount = 4;  // �ִ� 5�ڸ�, 10**4�� �̹Ƿ� 4���� ���� 
		while(iCount >= 0){
			if(x / pow(10, iCount) != 0){  // Ž���ϴ� �ڸ����� �����ϸ� 
				iSum += (x / int(pow(10, iCount))) * Dp(iCount + 1);  // ��갪�� �����ش� 
				x = x % int(pow(10, iCount));  // ���� ���� 
				
				if(x == 0)  // ���� 0�� �Ǹ� ���̻� ������ǿ䰡 ������ Ż�� 
				break;
			}
			--iCount;
		}
		printf("%d\n", iSum);  // �� ��� 
	}
	return 0;
}
