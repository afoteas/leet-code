class Solution:
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        self.area = 0
        self.m = len(grid)
        self.n = len(grid[0])
        ret = 0
        def dfs(i:int,j:int):
            if 0 <= i < self.m and 0 <= j < self.n and grid[i][j]:
                self.area+=1
                grid[i][j]=0
                dfs(i+1,j)
                dfs(i-1,j)
                dfs(i,j+1)
                dfs(i,j-1)
        
        for i in range(self.m):
            for j in range(self.n):
                if grid[i][j]==1:
                    self.area = 0
                    dfs(i,j)
                    ret = max(ret, self.area)
        
        return ret
        