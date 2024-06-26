class Solution:
    def isSubsequence(self, s: str, t: str) -> bool:
        si=0
        ti=-1
        if s== "":
            return True
        for i in range(0,len(s)):
            si=i
            while ti < len(t)-1:
                ti+=1
                if t[ti] == s[i]:
                    if si == len(s)-1:
                        return True
                    break
        return False