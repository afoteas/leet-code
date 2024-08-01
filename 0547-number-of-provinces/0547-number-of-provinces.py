class Solution:
    def findCircleNumMineNotWorking(self, isConnected: List[List[int]]) -> int:
        n = len(isConnected)
        parents = {}
        for i in range(n):
            parents[i]=i


        for i in range(n):
            for j in range(i+1,n):
                if isConnected[i][j]:
                    temp = parents[i]
                    for k in range(len(parents)):
                        if parents[k] == temp:
                            parents[k] = j
                    print(parents)

        return len(set(parents.values()))

    def findCircleNum(self, M: List[List[int]]) -> int:
       
        if not M:
            return 0
        
        n = len(M)
        visit = [False]*n
        
        def dfs(u):
            for v in range(n):
                if M[u][v] ==1 and visit[v] == False:
                    visit[v] = True
                    dfs(v)
        
        count = 0
        for i in range(n):
            if visit[i] == False:
                count += 1
                visit[i] = True
                dfs(i)
        
        return count
