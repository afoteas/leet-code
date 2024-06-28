class Solution:
    def containsNearbyDuplicate(self, nums: List[int], k: int) -> bool:
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