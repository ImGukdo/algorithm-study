// �����˻��̶�� ǥ���ϸ� ������������ ���ĵ� �迭����
// Ư������ ��ġ�� ã�� �˰���
// �߰��� ���� �����Ͽ� ã���� �ϴ� ������ ũ�� ������ ���ϴ� ���

#include <iostream>

using namespace std;
int iArray[12] = {1, 3, 5, 7, 9, 11, 14, 15, 18, 19, 25, 28};  // 12���� ���Ҹ� ���� ���ĵ� �迭 

int Search(int iStart, int iEnd, int iTarget){
	if(iStart > iEnd)  // ���۰��� �������� ũ�� 
	return -1;  // -1 ��ȯ 
	int iMiddle = (iStart + iEnd) / 2;  // �߰��� ���� 
	if(iArray[iMiddle] == iTarget)  // ���� �߰����� ���ϴ� ���� ������ 
	return iMiddle;  // �ε��� ��ȯ 
	else if(iArray[iMiddle] > iTarget)  // �߰����� ��ũ�� 
	return Search(iStart, iMiddle - 1, iTarget);  // �߰������� ���� �������� �ٽ� �Լ� ȣ�� 
	else // �߰����� �� ������ 
	return Search(iMiddle + 1, iEnd, iTarget);  // �߰������� ū �������� �ٽ� �Լ� ȣ�� 
}

int main(void){
	int iResult = Search(0, 11, 7);  // �Լ�ȣ���Ͽ� ��ȯ�� ���� 
	if(iResult != -1)  // ��ȯ���� -1�� �ƴϸ� �� ���۰��� ���� ������ �˸����� 
	cout << iResult + 1 << "��° �ε������� �߰��߽��ϴ�." << endl;  // �ε��� ��ȯ 
	
	return 0;
} 
