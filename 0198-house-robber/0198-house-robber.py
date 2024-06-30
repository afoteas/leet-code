class Solution:
    def rob(self, nums: List[int]) -> int:
        if len(nums) < 3:
            return max(nums)
        dp=[nums[0],nums[1],nums[0]+nums[2]]
        for i in range(3,len(nums)):
            dp=[dp[1],dp[2],max(dp[0],dp[1])+nums[i]]
        return max(dp)


        