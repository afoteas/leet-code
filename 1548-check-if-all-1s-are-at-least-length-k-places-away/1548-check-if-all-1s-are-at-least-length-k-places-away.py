class Solution:
    def kLengthApart(self, nums: List[int], k: int) -> bool:
        prev = -1
        index = 0
        for num in nums:
            if num:
                if prev >= 0:
                    if index - prev <= k:
                        return False
                    else:
                        prev = index
                else:
                    prev = index
            index += 1
        return True

        