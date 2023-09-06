class Solution:
    def romanToInt(self, s: str) -> int:
        r_map = {'I':1,'V':5,'X':10,'L':50,'C':100,'D':500,'M':1000}
        s_map = {'I':'0','V':'I','X':'I','L':'X','C':'X','D':'C','M':'C'}
        return_sum = 0
        for i in range(len(s) -1):
            if s[i] != s[i+1] and s[i] == s_map[s[i+1]]:
                return_sum -= r_map[s[i]]
            else:
                return_sum += r_map[s[i]]
      
        return_sum += r_map[s[len(s) -1]]
        return return_sum    

        