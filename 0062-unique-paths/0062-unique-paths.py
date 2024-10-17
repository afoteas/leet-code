class Solution:
    def uniquePathsTLE(self, m: int, n: int) -> int:
        dp = [[0 for _ in range(n)] for _ in range(m)]
        def uniPa(i: int, j: int):
            if i == m or j == n:
                return
            dp[i][j]+=1
            uniPa(i+1, j)
            uniPa(i, j+1)
        uniPa(0,0)
        return dp[m-1][n-1]

    def uniquePaths(self, m: int, n: int) -> int:
        dp = [[1 for _ in range(n)] for _ in range(m)]

        dp[0][0] = 1
        for i in range(1,m):
            for j in range(1,n):
                dp[i][j] = dp[i-1][j] + dp[i][j-1]

        return dp[m-1][n-1]
        