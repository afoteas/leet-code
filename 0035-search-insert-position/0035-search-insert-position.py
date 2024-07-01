class Solution:
    def searchInsertN(self, nums: List[int], target: int) -> int:
        for i in range(0,len(nums)):
            if target <= nums[i]:
                return i
        return len(nums)

    def searchInsert(self, nums: List[int], target: int) -> int:
        start = 0
        end = len(nums) - 1
        while start <= end:
            mid = start + (end-start)//2
            if nums[mid] == target:
                return mid
            elif nums[mid] > target:
                end = mid-1
            else:
                start= mid+1
        return start