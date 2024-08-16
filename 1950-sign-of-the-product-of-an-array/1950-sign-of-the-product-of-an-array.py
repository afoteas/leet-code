class Solution:
    def arraySign(self, nums: List[int]) -> int:
        ret=1
        for num in nums:
            if num == 0:
                return 0
            elif num < 0:
                ret*=-1
        return ret
        