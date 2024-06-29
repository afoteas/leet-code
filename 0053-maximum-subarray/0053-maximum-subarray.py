class Solution:
    def maxSubArrayN2(self, nums: List[int]) -> int:
        ret=-10000
        window=1
        while window <= len(nums):
            for i in range(0,len(nums)-window+1):
                ret=max(ret,sum(nums[i:i+window]))
            window+=1
        return ret

    def maxSubArrayDP(self, nums: List[int]) -> int:
        @cache
        def solve(i, must_pick):
            if i >= len(nums): return 0 if must_pick else -inf
            return max(nums[i] + solve(i+1, True), 0 if must_pick else solve(i+1, False))
        return solve(0, False)

    def maxSubArray(self, nums: List[int]) -> int:
        dp = [[0]*len(nums) for i in range(2)]
        dp[0][0], dp[1][0] = nums[0], nums[0]
        for i in range(1, len(nums)):
            dp[1][i] = max(nums[i], nums[i] + dp[1][i-1])
            dp[0][i] = max(dp[0][i-1], dp[1][i])
        return dp[0][-1]

    def maxSubArray(self, nums: List[int]) -> int:
        dp = [*nums]
        for i in range(1, len(nums)):
            dp[i] = max(nums[i], nums[i] + dp[i-1])
        return max(dp)