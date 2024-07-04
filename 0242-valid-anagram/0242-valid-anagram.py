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

    def isAnagram2(self, s: str, t: str) -> bool:
        return sorted(t) == sorted(s)
    
    def isAnagram3(self, s: str, t: str) -> bool:
        sd = {}
        td = {}
        for c in s:
            if c in sd:
                sd[c]+=1
            else:
                sd[c]=0
        for c in t:
            if c in td:
                td[c]+=1
            else:
                td[c]=0
        return td == sd

    def isAnagram(self, s: str, t: str) -> bool:
        
        from collections import Counter

        count_s = Counter(s)
        count_t = Counter(t)

        if count_s == count_t:
            return True
        else:
            return False