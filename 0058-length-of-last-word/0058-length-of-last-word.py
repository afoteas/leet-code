import re
class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        ss=s.rstrip().split(" ")
        return len(ss[-1])
        