// https://programmers.co.kr/learn/courses/30/lessons/42583
// ���α׷��ӽ� �ٸ��� ������ Ʈ�� ����
// Ʈ�� ���� �밡 ���� ���������� ������ �ٸ��� ������ ������ �ǳʷ� �մϴ�. 
// ��� Ʈ���� �ٸ��� �ǳʷ��� �ּ� �� �ʰ� �ɸ����� �˾Ƴ��� �մϴ�. 
// �ٸ����� Ʈ���� �ִ� bridge_length�� �ö� �� ������, �ٸ��� weight ���ϱ����� ���Ը� �ߵ� �� �ֽ��ϴ�. 
// ��, �ٸ��� ������ ������ ���� Ʈ���� ���Դ� �����մϴ�.

#include <string>
#include <vector>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;  // 1�ʾ� �����ϸ� �ð� üũ
    int bridge = 0;  // ���� �ٸ� ���� �ִ� Ʈ������ ������
    int iIndex = 0;  // ����� Ʈ������ ������ üũ
    int time[10001];  // �� Ʈ������ �ٸ��� ����� �ð� üũ
    while(true){
        for(int i = 0; i < iIndex; ++i){  // �ٸ� ���� ����� Ʈ������ Ž��
            if(answer - time[i] > bridge_length)  // �̹� �ٸ��� ��� ������ �н�
                continue;
            else if(answer - time[i] == bridge_length)  // �ٸ��� ��� �Ҷ�
                bridge -= truck_weights[i];  // �ٸ��� Ʈ���� ���Կ��� ���ش�
        }
        
        if(weight >= bridge + truck_weights[iIndex]){  // ���� ���Ʈ���� �ٸ����� �ö� �� ������
            bridge += truck_weights[iIndex];  // �ٸ��� Ʈ���� ���Կ� �����ְ�
            time[iIndex] = answer;  // ��� �ٸ� ���� �ö� Ʈ���� ��� �ð��� ����
            ++iIndex;  // ���� Ʈ������ �ε����� ����
        }
        
        if(iIndex == truck_weights.size())  // ��� Ʈ���� ��� ������ �ݺ��� Ż��, ������ Ʈ���� �ٸ����� �ö� ����
            break;
        
        ++answer;  // 1�ʾ� ����
    }
    answer += bridge_length + 1;  // 1�ʺ��� Ʈ������ �ٸ��� ����ϱ� ������ +1��, ������ Ʈ���� �ٸ��� ����ϴ� �ð��� ������
     
    return answer;
}
