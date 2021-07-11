// https://programmers.co.kr/learn/courses/30/lessons/42586
// ���α׷��ӽ� ��ɰ��� ����
// ���α׷��ӽ� �������� ��� ���� �۾��� ���� ���Դϴ�. �� ����� ������ 100%�� �� ���񽺿� �ݿ��� �� �ֽ��ϴ�.
// ��, �� ����� ���߼ӵ��� ��� �ٸ��� ������ �ڿ� �ִ� ����� �տ� �ִ� ��ɺ��� ���� ���ߵ� �� �ְ�, 
// �̶� �ڿ� �ִ� ����� �տ� �ִ� ����� ������ �� �Բ� �����˴ϴ�.
// ���� �����Ǿ�� �ϴ� ������� �۾��� ������ ���� ���� �迭 progresses�� �� �۾��� ���� �ӵ��� 
// ���� ���� �迭 speeds�� �־��� �� �� �������� �� ���� ����� �����Ǵ����� return �ϵ��� solution �Լ��� �ϼ��ϼ���.

#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    
    while(true){  // �ݺ����� ���� ��� ��ɵ��� �Ϸ�ɶ����� �ݺ� ����
        int iCount = 0;  // ������ ����� ��
        bool bEnd = false;  // ��� ����� �����Ǿ����� üũ 
        for(int i = 0; i < progresses.size(); ++i){  // �۾� �������� Ž��
            if(progresses[i] > 0)  // �Ϸᰡ ���� �ʾ�����
            progresses[i] += speeds[i];  // ���߼ӵ���ŭ ����
        }
        for(int i = 0; i < progresses.size(); ++i){  // ���߼ӵ���ŭ ���� �� �Ϸ�ƴ��� Ž��
            if(progresses[i] < 0)  // �̹� �Ϸ� ������ ���
                continue;
            if(progresses[i] >= 100){  // �Ϸ� ������ 
                progresses[i] = -1;  // �Ϸ� �ƴٰ� -1�� ǥ��
                ++iCount;  // ���� ��ɼ� ����
                if(i == progresses.size() - 1)  // ������ ����� �Ϸ������ 
                    bEnd = true;  // while�� Ż���ϱ� ���� üũ 
                continue;  // ���� �Ϸ�Ȱ��� �ִ��� Ȯ���ϱ� ���� �ݺ� ����
            }
            break;  // �տ��ͺ��� Ž���ϸ鼭 �Ϸ�� ����� ������ Ż��, �տ� ����� �Ϸ�ž� ������ �� �ֱ� ������
        }
        if(iCount != 0)  // ������ ��ɵ��� ������
            answer.push_back(iCount);  // ���� ����
        if(bEnd)  // ������ ��ɱ��� �Ϸ������ �ݺ��� Ż��
            break;        
    }
    
    return answer;
}
