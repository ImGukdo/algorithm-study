// https://programmers.co.kr/learn/courses/30/lessons/42577
// ���α׷��ӽ� ��ȭ��ȣ ��� ����
// ��ȭ��ȣ�ο� ���� ��ȭ��ȣ ��, �� ��ȣ�� �ٸ� ��ȣ�� ���ξ��� ��찡 �ִ��� Ȯ���Ϸ� �մϴ�.
// ��ȭ��ȣ�� ������ ���� ���, ������ ��ȭ��ȣ�� �������� ��ȭ��ȣ�� ���λ��Դϴ�.
// ������ : 119
// ���ؿ� : 97 674 223
// ������ : 11 9552 4421
// ��ȭ��ȣ�ο� ���� ��ȭ��ȣ�� ���� �迭 phone_book �� solution �Լ��� �Ű������� �־��� ��,
// � ��ȣ�� �ٸ� ��ȣ�� ���ξ��� ��찡 ������ false�� 
// �׷��� ������ true�� return �ϵ��� solution �Լ��� �ۼ����ּ���.

#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

map<long long, int> m;  // key�� : �ؽð�, value : �ε��� 
map<long long, int>::iterator iter;  // ������ ���� 

bool compare(string a, string b){  // ���͸� ���ڼ��� �����ͺ��� ������������ �����ϱ� ���� ���Լ� 
    return a.length() < b.length();
}
long long iArray[51];  
long long Pow(int iInput){  // �ؽð���� ������ �ŵ����� �Լ� 
	if(iInput == 0)
	return 1;
	
	if(iArray[iInput] != 0)
	return iArray[iInput];
	
	return iArray[iInput] = 31 * Pow(iInput - 1) % 1234567891;   
}
long long Hash(string s, int size){  // �ؽ� �Լ�, ���ڿ��� �ؽð����� ��� 
    long long iResult = 0;
	for(int i = 0; i < size; ++i){
        iResult += (int)s[i] * Pow(i) % 1234567891;
        iResult %= 1234567891;
    }
	return iResult;   
}

bool solution(vector<string> phone_book) {
    bool answer = true;
    sort(phone_book.begin(), phone_book.end(), compare);  // ������ ������ ���ڼ��� ���������� ���� 
    
    int x = Hash(phone_book[0], phone_book[0].length());  // ù��° ���ڿ��� �ؽð� 
    for(int i = 1; i < phone_book.size(); ++i){  // �ι�° ���ڿ����� Ž���ϸ鼭 
        int y = Hash(phone_book[i], phone_book[0].length());  // ù��° ���ڿ� ���̸�ŭ�� �ؽð� ��� 
        if(x == y){  // �ؽð��� ������ 
            answer = false;  // ���λ簡 �����Ƿ� false 
            break;  // Ż�� 
        }
        else{  // �ؽð��� �ٸ��� 
            iter = m.find(y);   
            if(iter == m.end()){  // ���� �ؽð����ε� map�� key�� ������ 
                m.insert(make_pair(y, i));  // key : �ؽð�, value : �ε��� �� �־��� 
            }
            else{  // ���� �ؽð����ε� map�� key�� ������ 
                long long a = Hash(phone_book[m[y]], phone_book[m[y]].length());  // key���� value�� �ε����� �ؼ� ���ڿ� ���̸�ŭ �ؽð��� ���� 
                long long b = Hash(phone_book[i], phone_book[m[y]].length());  // ������ ���ڿ� ���̷� �ؽð��� ���� 
                if(a == b){  // �ؽð��� ������ 
                    answer = false;  // ���λ簡 �����Ƿ� false 
                    break;  // Ż�� 
                }
            }
        }
    }

    return answer;
}
