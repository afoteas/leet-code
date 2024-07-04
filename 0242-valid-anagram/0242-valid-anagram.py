class Solution:
    def isAnagram1(self, s: str, t: str) -> bool:
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
        else:
            return False

    def isAnagram(self, s: str, t: str) -> bool:
        tls = list(t)
        tls.sort()
        print(tls)
        sls = list(s)
        sls.sort()
        return sls == tls