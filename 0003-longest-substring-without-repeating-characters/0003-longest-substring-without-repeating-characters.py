class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        temp = {}
        start = 0
        length = 0
        for i, c in enumerate(s):
            if c in temp and temp[c] >= start:
                start = temp[c] + 1
            temp[c] = i
            length = max(length, i-start+1)
        return length

        