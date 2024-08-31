class Solution:
    def shortestBridgeTimeout(self, grid: List[List[int]]) -> int:
        self.n = len(grid)
        self.res = 2*self.n
        def dfs1(i:int,j:int):
            if i<0 or j<0 or i==self.n or j==self.n or grid[i][j]  in [0,2]:
                return
            if grid[i][j] == 1:
                grid[i][j] = 2
            dfs1(i+1,j)
            dfs1(i-1,j)
            dfs1(i,j-1)
            dfs1(i,j+1)

        def dfs2(i:int,j:int,p:List[List[int]]):
            if i<0 or j<0 or i==self.n or j==self.n or grid[i][j] == 3 or len(p) > self.res or [i,j] in p:
                return
            if grid[i][j] == 2:
                grid[i][j] = 3
                dfs2(i+1,j,[])
                dfs2(i-1,j,[])
                dfs2(i,j-1,[])
                dfs2(i,j+1,[])
            elif grid[i][j] == 0:
                p.append([i,j])
                # print(f"p={p}")
                dfs2(i+1,j,list(p))
                dfs2(i-1,j,list(p))
                dfs2(i,j-1,list(p))
                dfs2(i,j+1,list(p))
            else:
                # print(f"i={i},j={j}")
                # print(f"p={p}")
                # print("i reached the other island")
                self.res = len(p)


        for i in range(self.n):
            for j in range(self.n):
                if grid[i][j] == 1:
                    dfs1(i,j)
                    dfs2(i,j,[])
                    break
            else:
                continue
            break
    
        # print(grid)
        # print(self.res)
        return self.res
        
    def shortestBridge(self, grid):
        m, n = len(grid), len(grid[0])
        start_i, start_j = next((i, j) for i in range(m) for j in range(n) if grid[i][j])
        
        
        stack = [(start_i, start_j)]
        visited = set(stack)
        while stack:
            i, j = stack.pop()
            visited.add((i, j))  
            for ii, jj in (i-1, j), (i, j-1), (i, j+1), (i+1, j):
                if 0 <= ii < m and 0 <= jj < n and grid[ii][jj] and (ii, jj) not in visited:
                    stack.append((ii, jj))
                    visited.add((ii, jj))
        
        
        ans = 0
        queue = list(visited)
        while queue:
            new_queue = []
            for i, j in queue:
                for ii, jj in (i-1, j), (i, j-1), (i, j+1), (i+1, j):
                    if 0 <= ii < m and 0 <= jj < n and (ii, jj) not in visited:
                        if grid[ii][jj] == 1:
                            return ans
                        new_queue.append((ii, jj))
                        visited.add((ii, jj))
            queue = new_queue
            ans += 1           
        