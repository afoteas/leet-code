class Solution:
    def rob1(self, nums: List[int]) -> int:
        if len(nums) < 3:
            return max(nums)
        dp=[nums[0],nums[1],nums[0]+nums[2]]
        for i in range(3,len(nums)):
            dp=[dp[1],dp[2],max(dp[0],dp[1])+nums[i]]
        return max(dp)

    def rob2(self, nums: List[int]) -> int:
        if len(nums) < 3:
            return max(nums)
        nums[2]+=nums[0]
        for i in range(3,len(nums)):
            nums[i] = max(nums[i-2],nums[i-3]) + nums[i]
        return max(nums[-2:])
        
    def rob(self, nums: List[int]) -> int:
        @cache
        def rec(i:int) -> int:
            if i < 0:
                return 0
            return max(rec(i-2) + nums[i], rec(i-1))
        return rec(len(nums)-1)
        