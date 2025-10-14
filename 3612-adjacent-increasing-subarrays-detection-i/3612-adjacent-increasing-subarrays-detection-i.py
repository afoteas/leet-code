class Solution:
    def hasIncreasingSubarrays(self, nums: List[int], k: int) -> bool:
        if len(nums) < 2: 
            return False
        if len(nums) >= 2 and k == 1: 
            return True
        pl = 0
        l = 1
        for i in range(1,len(nums)):
            if nums[i] > nums[i-1]:
                l += 1
                if pl >= k and l >= k:
                    return True
                if l == 2*k:
                    return True
            else:
                pl = l
                l = 1
        return False



        