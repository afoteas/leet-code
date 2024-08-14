class Solution:
    def findTheDifference(self, s: str, t: str) -> str:
        for ss in s:
            t = t.replace(ss, '', 1)
        return t

        