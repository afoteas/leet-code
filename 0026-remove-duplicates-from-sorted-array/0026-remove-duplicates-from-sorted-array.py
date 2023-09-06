class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        count = len(nums)
        unique = list(dict.fromkeys(nums))
        nums.clear()
        nums.extend(unique)
        return len(unique)

