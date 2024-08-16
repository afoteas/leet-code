class Solution:
    def isMonotonicSlow(self, nums: List[int]) -> bool:
        previous = nums[0]
        monotonic = 0  # 0 uninitialized, 1 increasing, 2 decreasing
        
        for num in nums:
            if num == previous:
                continue
                
            if monotonic:
                if num < previous and monotonic != 2:
                    return False
                elif num > previous and monotonic != 1:
                    return False
            else:
                monotonic = 1 if num > previous else 2
                
            previous = num
        
        return True

    def isMonotonic(self, nums: List[int]) -> bool:
        increasing = decreasing = True
        for i in range(len(nums) - 1):
            if nums[i] < nums[i + 1]:
                decreasing = False
            if nums[i] > nums[i + 1]:
                increasing = False
            if not increasing and not decreasing:
                return False
        return True