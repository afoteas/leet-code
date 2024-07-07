class Solution:
    def findPeakElementOn(self, nums: List[int]) -> int:
        for i in range(1,len(nums)-1):
            if nums[i-1] < nums[i] and nums[i] > nums [i+1]:
                return i
        if nums[0] > nums[-1]:
            return 0
        else:
            return len(nums)-1

    def findPeakElement(self, nums: List[int]) -> int:
        if len(nums) <= 1:
            return 0
        i = 0
        j = len(nums) - 1

        while i < j:
            mid = (i+j) // 2

            if nums[mid] > nums[mid+1]:
                j = mid
            else:
                i = mid + 1
            

        return i
        