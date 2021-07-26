// https://www.acmicpc.net/problem/2745
// ���� ������ȯ ���� 
// B���� �� N�� �־�����. �� ���� 10�������� �ٲ� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.
// 10������ �Ѿ�� ������ ���ڷ� ǥ���� �� ���� �ڸ��� �ִ�. 
// �̷� ��쿡�� ������ ���� ���ĺ� �빮�ڸ� ����Ѵ�.
// A: 10, B: 11, ..., F: 15, ..., Y: 34, Z: 35

#include <iostream>
#include <math.h>

using namespace std;

int main(void){
	string s;
	int iNum;
	cin >> s;  // B�������� ���ڿ��� �Է¹޴´�. 
	cin >> iNum;
	long long iSum = 0;
	for(int i = 0; i < s.length(); ++i){  // B�������� �ϳ��ϳ� Ž���ϸ鼭 
		int x;
		if((int)s[i] >= 65 && (int)s[i] <= 90)  // ���ĺ��̸� 
		x = (int)s[i] - 55;  // 10�������� ��ȯ 
		else
		x = (int)s[i] - 48;  // ���ڸ� ���������� ��ȯ 
		
		iSum += int(pow(iNum, s.length() - 1 - i)) * x;  // B������ 10�������� ��� 
	}	
	
	cout << iSum;
	return 0;
} 

