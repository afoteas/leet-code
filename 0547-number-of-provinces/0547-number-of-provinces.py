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

    def findCircleNumSlow(self, M: List[List[int]]) -> int:
       
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


    def dfs(self, isConnected, visited, i) -> int:
        for j in range(len(isConnected)):
            if isConnected[i][j] == 1 and j not in visited:
                visited.add(j)
                self.dfs(isConnected, visited, j)

    def findCircleNum(self, isConnected: List[List[int]]) -> int:
        visited = set()
        num_prov = 0
        for city in range(len(isConnected)):
            if city not in visited: 
            # as long as a city is visted, then all connected cities should be considered into one province
                self.dfs(isConnected, visited, city)
                num_prov += 1 # increment when one traversal finishes
        return num_prov