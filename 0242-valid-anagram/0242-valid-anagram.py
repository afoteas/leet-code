class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        tl = list(t)
        if len(s) != len(t):
            return False
        for c in s:
            if c in tl:
                tl.remove(c)
            else:
                return False
        if len(tl) == 0:
            return True
        