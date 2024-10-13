class Solution:
    def minLength(self, s: str) -> int:
        tmp = s.replace("AB","").replace("CD","")
        while len(tmp) != len(s):
            s = tmp
            tmp = s.replace("AB","").replace("CD","")
        return len(tmp)