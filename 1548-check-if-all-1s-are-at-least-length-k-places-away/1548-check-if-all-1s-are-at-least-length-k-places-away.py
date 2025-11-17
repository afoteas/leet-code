class Solution:
    def kLengthApart(self, nums: List[int], k: int) -> bool:
        prev = -1
        for i, num in enumerate(nums):
            if num:
                if prev >= 0:
                    if i - prev <= k:
                        return False
                    else:
                        prev = i
                else:
                    prev = i
        return True

        