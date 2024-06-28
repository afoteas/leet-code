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

    def climbStairs(self, n: int) -> int:
        memo = {}
        return self.climbStairsMemo(n, memo)