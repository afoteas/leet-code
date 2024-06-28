class Solution:
    def containsNearbyDuplicateSlow(self, nums: List[int], k: int) -> bool:
        if len(nums) == len(set(nums)):
            return False
        if len(nums) < k:
            k = len(nums)
        window = nums[0:k+1]
        if len(window) != len(set(window)):
            return True

        for i in range(k+1,len(nums)):
            window.pop(0)
            window.append(nums[i])
            if len(window) != len(set(window)):
                return True
        return False

    def containsNearbyDuplicate(self, nums: List[int], k: int) -> bool:
        if len(nums) == len(set(nums)):
            return False
        if len(nums) < k:
            k = len(nums)
        if len(nums[0:k+1]) != len(set(nums[0:k+1])):
            return True

        for i in range(0,len(nums)-k):
            if len(nums[i:i+k+1]) != len(set(nums[i:i+k+1])):
                return True
        return False