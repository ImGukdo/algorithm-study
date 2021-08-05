// https://www.acmicpc.net/problem/10829
// ���� ������ ��ȯ ����
// �ڿ��� N�� �־�����. N�� �������� �ٲ㼭 ����ϴ� ���α׷��� �ۼ��Ͻÿ�. 


#include <iostream>
#include <vector>
using namespace std;
vector<int> vec; // �������� ������ ���� 

void binary(long long iInput){
	if(iInput / 2 == 0){  // 2�� ���̻� ������ ���ٸ� 
		if(iInput % 2 == 1)  // �� ���� 1�̸� 
		vec.push_back(1);  // 1�� �־��ش� 
		return;
	}
	vec.push_back(iInput % 2);  // 2�� ���� �������� �־��ش� 
	binary(iInput / 2);  // 2�� ���� ���� �ٽ� �Ű������� �ؼ� ����Լ��� �����Ѵ�. 
}


int main(void){
	long long iNum;  
	scanf("%lld", &iNum);  // 10������ �Է¹޴´� 
	binary(iNum);  // 2���� ���ϴ� �Լ� ���� 
	for(int i = vec.size() - 1; i >= 0; --i){  // ���͸� ���� �ڿ������� Ž���ϸ鼭 
		printf("%d", vec[i]);  // ��� 
	}
	return 0;
}
