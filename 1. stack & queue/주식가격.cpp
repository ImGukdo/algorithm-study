// https://programmers.co.kr/learn/courses/30/lessons/42584
// ���α׷��ӽ� �ֽİ��� ����
// �� ������ ��ϵ� �ֽİ����� ��� �迭 prices�� �Ű������� �־��� ��, 
// ������ �������� ���� �Ⱓ�� �� �������� return �ϵ��� 
// solution �Լ��� �ϼ��ϼ���.

#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices){
    vector<int> answer;
    for(int i = 0; i < prices.size(); ++i){  // ������ �ϳ��� Ž���ϱ� ���� �ݺ��� ����
        int iCount = 0;  // �ϳ��� ������ ������ �ʸ� ���
        for(int j = i + 1; j < prices.size(); ++j){  // ���� ��ġ ������ ���ݰ� �񱳸� ���� �ݺ��� ����
            if(prices[i] <= prices[j])  // ������ �������� �ʾ�����
                ++iCount;  // 1�� ���� �� �ݺ�
            else{
                ++iCount;  // ������ ���������� 1�� ���� �� �ݺ��� Ż��
                break;
            }
        }
        answer.push_back(iCount);  // ���� �ð��� ����
    }
    
    return answer;
}
