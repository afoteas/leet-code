class Solution:
    def maxSubArrayN2(self, nums: List[int]) -> int:
        ret=-10000
        window=1
        while window <= len(nums):
            for i in range(0,len(nums)-window+1):
                ret=max(ret,sum(nums[i:i+window]))
            window+=1
        return ret

    def maxSubArray(self, nums: List[int]) -> int:
        @cache
        def solve(i, must_pick):
            if i >= len(nums): return 0 if must_pick else -inf
            return max(nums[i] + solve(i+1, True), 0 if must_pick else solve(i+1, False))
        return solve(0, False)
        