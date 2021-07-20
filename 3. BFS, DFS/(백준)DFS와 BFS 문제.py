# https://www.acmicpc.net/problem/1260
# 백준 DFS와 BFS 문제
# 그래프를 DFS로 탐색한 결과와 BFS로 탐색한 결과를 출력하는 프로그램을 작성하시오. 
# 단, 방문할 수 있는 정점이 여러 개인 경우에는 정점 번호가 작은 것을 먼저 방문하고, 
# 더 이상 방문할 수 있는 점이 없는 경우 종료한다. 정점 번호는 1번부터 N번까지이다. 

bCheck = [False] * 1001  # 방문했는지 체크

def Dfs(iStart, nodes) :  # Dfs 함수 구현
    global bCheck
    bCheck[iStart] = True  # 방문했으면 체크
    print(iStart, end = " ")  # 방문한 정점 출력
    if nodes.get(iStart) == None :  # 연결된 정점이 없으면
        return  # 리턴
    for n in nodes.get(iStart) :  # 방문한 정점과 연결된 정점들을 탐색
        if not bCheck[n] :  # 방문안한 정점이면 
            Dfs(n, nodes)  # Dfs 함수 실행


def Bfs(iStart, nodes) :  # Bfs 함수 구현
    global bCheck
    bCheck[iStart] = True  # 방문했으면 체크
    lst = []  # 큐로 쓸 리스트 생성
    lst.append(iStart)  # 방문한 정점을 리스트에 넣어줌
    
    while len(lst) != 0 :  # 리스트(큐)가 빌때까지 반복하면서
        x = lst[0]  # 현재 리스트에서 제일 먼저 들어온 정점
        print(x, end = " ")  # 출력
        if nodes.get(x) == None :  # 연결된 정점이 없으면 
            return  # 리턴
        del lst[0]  # 현재 리스트에서 제일 먼저 들어온 정점 제거
        for i in nodes.get(x) :  # 제거한 정점과 연결된 정점들을 탐색
            if not bCheck[i] :  # 방문안한 정점이면 
                bCheck[i] = True  # 방문했다고 체크
                lst.append(i)  # 리스트에 넣어준다

if __name__ == "__main__" :
    vals = input().split()
    num = {}  # 그래프를 구현할 딕셔너리 선언
    for i in range(int(vals[1])) :  # 그래프 구현
        temp = input().split()
        if int(temp[0]) in num.keys() :
            num[int(temp[0])].append(int(temp[1]))
        else :
            num[int(temp[0])] = [int(temp[1])]
        if int(temp[1]) in num.keys() :
            num[int(temp[1])].append(int(temp[0]))
        else :
            num[int(temp[1])] = [int(temp[0])]    
    
    for k in num.keys() :  
        num[k].sort()  # 번호가 작은 정점부터 방문하기 위해 오름차순으로 정렬

    Dfs(int(vals[2]), num)  # Dfs 실행
    print("")
    bCheck = [False] * 1001  # Bfs 실행전 방문체크변수 초기화
    Bfs(int(vals[2]), num)  # Bfs 실행
