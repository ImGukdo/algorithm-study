// https://programmers.co.kr/learn/courses/30/lessons/42895
// ���α׷��ӽ� N���� ǥ�� ���� 
// �Ʒ��� ���� 5�� ��Ģ���길���� 12�� ǥ���� �� �ֽ��ϴ�.
// 12 = 5 + 5 + (5 / 5) + (5 / 5)
// 12 = 55 / 5 + 5 / 5
// 12 = (55 + 5) / 5
// 5�� ����� Ƚ���� ���� 6,5,4 �Դϴ�. �׸��� ���� ���� ���� ���� 4�Դϴ�.
// ��ó�� ���� N�� number�� �־��� ��, N�� ��Ģ���길 ����ؼ� ǥ�� �� �� �ִ� ��� �� 
// N ���Ƚ���� �ּڰ��� return �ϵ��� solution �Լ��� �ۼ��ϼ���.


#include <string>
#include <vector>

using namespace std;
int solution(int N, int number) {
    int answer = 0;
    vector<int> vec[9];  // N�� �̿��� Ƚ���� ����� �ִ� ���� ������ ���� 
    int iSum = 0;
    for(int i = 1; i <= 8; ++i){  // N�� ���������� �����Ͽ� ���� ���� �̸� �־�д�. 
        iSum *= 10;
        iSum += N;
        vec[i].push_back(iSum);
    }
    bool bCheck = false;  // while�� Ż���� ���� üũ���� 
    while(true){
        ++answer;  // N�� ������ ���� 
        for(int i = 0; i < vec[answer].size(); ++i){  // answer���� ���� ������ Ž���ϸ鼭  
            if(vec[answer][i] == number){  // ã�� number�� ������ 
                bCheck = true;
                break;  // Ż�� 
            }
            if(answer < 8){  // N�� ������ 8���� ���� ��  
                for(int j = answer; j >= 1; --j){  // ���� answer�� �Ųٷ� Ž���ϸ鼭 
                    if(answer + j <= 8){  // ���� answer�� j�� ���� 8 �����̸� 
                        for(int k = 0; k < vec[j].size(); ++k){  // j���� ���� ���� Ž���ϸ鼭 
                            if(vec[j][k] != 0)
                            vec[answer + j].push_back(vec[answer][i] / vec[j][k]);  // ��Ģ������ ���� �־��ش�. 
                            vec[answer + j].push_back(vec[answer][i] + vec[j][k]);
                            vec[answer + j].push_back(vec[answer][i] - vec[j][k]);
                            vec[answer + j].push_back(vec[answer][i] * vec[j][k]);
							if(answer != j){  // answer �� j �� ���������� ���� ��ġ�� �ٲ� ����� -, / ���� �־��ش�. 
	                            vec[answer + j].push_back(vec[j][k] - vec[answer][i]); 
	                            if(vec[answer][i] != 0)
	                            vec[answer + j].push_back(vec[j][k] / vec[answer][i]);
                        	}
                        }   
                    }
                }
            }
        }
        if(bCheck)  // ���ϴ� ���� ã������ 
            break;  // Ż�� 
        if(answer == 8){  // 8���� ���ձ��� ���� Ž���߾ ���ϴ� ���� ������ 
            answer = -1;  // -1 ���� �־��ְ� 
            break;  // Ż�� 
        }   
    }
    return answer;
}
