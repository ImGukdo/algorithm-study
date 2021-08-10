// https://programmers.co.kr/learn/courses/30/lessons/43105
// 프로그래머스 정수 삼각형 문제
// 삼각형의 꼭대기에서 바닥까지 이어지는 경로 중, 
// 거쳐간 숫자의 합이 가장 큰 경우를 찾아보려고 합니다. 
// 아래 칸으로 이동할 때는 대각선 방향으로 한 칸 오른쪽 
// 또는 왼쪽으로만 이동 가능합니다. 
// 예를 들어 3에서는 그 아래칸의 8 또는 1로만 이동이 가능합니다.
// 삼각형의 정보가 담긴 배열 triangle이 매개변수로 주어질 때, 
// 거쳐간 숫자의 최댓값을 return 하도록 solution 함수를 완성하세요. 


#include <string>
#include <vector>

using namespace std;

int iArray[501][501];  // Dp함수의 값을 저장할 변수 

int Dp(int iIndex, int iFloor, vector<vector<int> > &triangle){
    if(iFloor == triangle.size() - 1)  // 가장 밑에 칸이면 
        return triangle[iFloor][iIndex];  // 자신의 값을 반환 
    if(iArray[iFloor][iIndex] != 0)  // Dp 함수로 구한적 있는 값이면 
        return iArray[iFloor][iIndex];  // 값 반환 
    return iArray[iFloor][iIndex] = triangle[iFloor][iIndex] +
        max(Dp(iIndex, iFloor + 1, triangle), Dp(iIndex + 1, iFloor + 1, triangle));  // 자신의 값과 자신의 밑에 있는 값중 큰 값과 더한다       
}

int solution(vector<vector<int> > triangle) {
    int answer = 0;
    answer =  Dp(0, 0, triangle);
    return answer;
}
