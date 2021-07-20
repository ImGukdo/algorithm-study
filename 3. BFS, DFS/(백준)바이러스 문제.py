# https://www.acmicpc.net/problem/2606
# 백준 바이러스 문제
# 신종 바이러스인 웜 바이러스는 네트워크를 통해 전파된다. 
# 한 컴퓨터가 웜 바이러스에 걸리면 그 컴퓨터와 네트워크 상에서 
# 연결되어 있는 모든 컴퓨터는 웜 바이러스에 걸리게 된다. 

bCheck = [False] * 101  # 방문했는지 체크
iCount = 0  # 감염된 컴퓨터 개수

def Bfs(iStart, nodes) :  # Bfs 함수 구현
    global bCheck, iCount
    bCheck[iStart] = True  # 방문했으면 체크
    lst = []  # 큐로 쓸 리스트 생성
    lst.append(iStart)  # 방문한 컴퓨터를 리스트에 넣어줌
    
    while len(lst) != 0 :  # 리스트(큐)가 빌때까지 반복하면서
        x = lst[0]  # 현재 리스트에서 제일 먼저 들어온 컴퓨터
        iCount += 1  # 감염된 컴퓨터수 증가
        if nodes.get(x) == None :  # 연결된 정점이 없으면 
            return  # 리턴
        del lst[0]  # 현재 리스트에서 제일 먼저 들어온 컴퓨터 제거
        for i in nodes.get(x) :  # 제거한 컴퓨터와 연결된 컴퓨터들을 탐색
            if not bCheck[i] :  # 방문안한 컴퓨터이면 
                bCheck[i] = True  # 방문했다고 체크
                lst.append(i)  # 리스트에 넣어준다

    return iCount - 1  # 최초 감염된 컴퓨터는 빼준다

if __name__ == "__main__" :
    num = input()
    pair = input()

    com = {}  # 그래프를 구현할 딕셔너리 선언
    for i in range(int(pair)) :  # 그래프 구현
        temp = input().split()
        if int(temp[0]) in com.keys() :
            com[int(temp[0])].append(int(temp[1]))
        else :
            com[int(temp[0])] = [int(temp[1])]
        if int(temp[1]) in com.keys() :
            com[int(temp[1])].append(int(temp[0]))
        else :
            com[int(temp[1])] = [int(temp[0])]    
    
    print(Bfs(1, com))  # Bfs 실행
