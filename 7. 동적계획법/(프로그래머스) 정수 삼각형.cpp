// https://programmers.co.kr/learn/courses/30/lessons/43105
// ���α׷��ӽ� ���� �ﰢ�� ����
// �ﰢ���� ����⿡�� �ٴڱ��� �̾����� ��� ��, 
// ���İ� ������ ���� ���� ū ��츦 ã�ƺ����� �մϴ�. 
// �Ʒ� ĭ���� �̵��� ���� �밢�� �������� �� ĭ ������ 
// �Ǵ� �������θ� �̵� �����մϴ�. 
// ���� ��� 3������ �� �Ʒ�ĭ�� 8 �Ǵ� 1�θ� �̵��� �����մϴ�.
// �ﰢ���� ������ ��� �迭 triangle�� �Ű������� �־��� ��, 
// ���İ� ������ �ִ��� return �ϵ��� solution �Լ��� �ϼ��ϼ���. 


#include <string>
#include <vector>

using namespace std;

int iArray[501][501];  // Dp�Լ��� ���� ������ ���� 

int Dp(int iIndex, int iFloor, vector<vector<int> > &triangle){
    if(iFloor == triangle.size() - 1)  // ���� �ؿ� ĭ�̸� 
        return triangle[iFloor][iIndex];  // �ڽ��� ���� ��ȯ 
    if(iArray[iFloor][iIndex] != 0)  // Dp �Լ��� ������ �ִ� ���̸� 
        return iArray[iFloor][iIndex];  // �� ��ȯ 
    return iArray[iFloor][iIndex] = triangle[iFloor][iIndex] +
        max(Dp(iIndex, iFloor + 1, triangle), Dp(iIndex + 1, iFloor + 1, triangle));  // �ڽ��� ���� �ڽ��� �ؿ� �ִ� ���� ū ���� ���Ѵ�       
}

int solution(vector<vector<int> > triangle) {
    int answer = 0;
    answer =  Dp(0, 0, triangle);
    return answer;
}
