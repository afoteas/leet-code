import re
class Solution:
    def isPalindrome(self, s: str) -> bool:
        ts = re.sub(r'[^a-z0-9]', '', s.strip().lower())
        p = 0
        pi = len(ts)
        for i in range(0,int(pi/2)):
            if ts[p+i] != ts[pi-i-1]:
                return False
        return True
                


        