class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        lenNums = len(nums)
        i=2
        j=0
        while i < lenNums - j:
            if nums[i-2] == nums[i]:
                del nums[i]
                j += 1
            else:
                i += 1

        return i
            