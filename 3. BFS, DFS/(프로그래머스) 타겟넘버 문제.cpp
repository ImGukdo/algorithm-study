// https://programmers.co.kr/learn/courses/30/lessons/43165
// ���α׷��ӽ� Ÿ�ٳѹ� ���� 
// n���� ���� �ƴ� ������ �ֽ��ϴ�. 
// �� ���� ������ ���ϰų� ���� Ÿ�� �ѹ��� ������� �մϴ�. 
// ���� ��� [1, 1, 1, 1, 1]�� ���� 3�� ������� ���� �ټ� ����� �� �� �ֽ��ϴ�.
// -1+1+1+1+1 = 3
// +1-1+1+1+1 = 3
// +1+1-1+1+1 = 3
// +1+1+1-1+1 = 3
// +1+1+1+1-1 = 3
// ����� �� �ִ� ���ڰ� ��� �迭 numbers, Ÿ�� �ѹ� target�� �Ű������� �־��� �� 
// ���ڸ� ������ ���ϰ� ���� Ÿ�� �ѹ��� ����� ����� ���� return �ϵ��� solution �Լ��� �ۼ����ּ���.

#include <string>
#include <vector>

using namespace std;

int iCount;  // ����� �� 
void Dfs(vector<int> numbers, int target, int iIndex, int iSum){  // ����� ���ڵ�, Ÿ�� �ѹ�, ���° ������, ���ڵ��� �� 
    if(iIndex == numbers.size()){ // ������ ���ڱ��� �� �� ������ 
        if(iSum == target)  // Ÿ�� �ѹ��� ������ üũ�ؼ� ������ 
            ++iCount;  // ���� ���� 
        return;  // ���� 
    }
    Dfs(numbers, target, iIndex + 1, iSum + numbers[iIndex]);  // ���ڸ� ���Ѵ� 
    Dfs(numbers, target, iIndex + 1, iSum - numbers[iIndex]);  // ���ڸ� ���� 
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    Dfs(numbers, target, 0, 0);  // DFS ���� 
    answer = iCount;
    return answer;
}
