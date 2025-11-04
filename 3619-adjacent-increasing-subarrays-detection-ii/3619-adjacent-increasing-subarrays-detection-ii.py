class Solution:
    def maxIncreasingSubarrays(self, nums: List[int]) -> int:
        k = 1
        last = nums[0]
        previous = 0
        current = 1
        for num in nums:
            if num > last:
                current += 1
            else:
                k = max([k, min(previous, current), current>>1])
                previous = current
                current = 1
            last = num
        k = max([k, min(previous, current), current>>1])
        return k


        