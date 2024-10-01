class Solution:
    def minBitFlipsFirst(self, start: int, goal: int) -> int:
        ret = 0
        while start > 0 or goal > 0:
            ret += (start & 1) ^ (goal & 1)
            start >>=1
            goal >>=1
        return ret

    def minBitFlips(self, start: int, goal: int) -> int:
        ret = 0
        xor = start ^ goal
        while xor > 0:
            ret += xor & 1
            xor >>=1
        return ret        