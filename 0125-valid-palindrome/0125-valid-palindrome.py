import re
class Solution:
    def isPalindrome(self, s: str) -> bool:
        ss=s.strip().lower()
        ts = re.sub(r'[^a-zA-Z0-9]', '', ss)
        p = 0
        pi = len(ts)
        for i in range(0,int(pi/2)):
            if ts[p+i] != ts[pi-i-1]:
                return False
        return True
                


        