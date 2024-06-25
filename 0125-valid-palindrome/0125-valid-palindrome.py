import re
class Solution:
    def isPalindrome(self, s: str) -> bool:
        s = re.sub(r'[^a-z0-9]', '', s.strip().lower())
        p = 0
        pi = len(s)
        for i in range(0,int(pi/2)):
            if s[p+i] != s[pi-i-1]:
                return False
        return True
                


        