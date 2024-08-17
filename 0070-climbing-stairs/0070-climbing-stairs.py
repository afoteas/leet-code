class Solution:

    def climbStairsSlow(self, n: int) -> int:
        if n==1:
            return 1
        elif n==2:
            return 2
        else:
            return self.climbStairs(n-1) + self.climbStairs(n-2)

    def climbStairsMemo(self, n: int, memo: dict) -> int:
        if n in [1, 2]:
            return n
        elif n in memo:
            return memo[n]
        else:
            memo[n] = self.climbStairsMemo(n-1,memo) + self.climbStairsMemo(n-2,memo)
            return memo[n]

    def climbStairsM(self, n: int) -> int:
        memo = {}
        return self.climbStairsMemo(n, memo)
    
    def climbStairsDP(self, n: int) -> int:
        if n in [1, 2]:
            return n
        dp = {1:1,2:2}
        for i in range(3,n+1):
            dp[i]=dp[i-1] + dp[i-2]
        return dp[n]

    def climbStairs(self, n: int) -> int:
        if n in [1, 2]:
            return n
        prev=1
        curr=2
        for i in range(3,n+1):
            temp = curr
            curr = prev + curr
            prev = temp
        return curr    