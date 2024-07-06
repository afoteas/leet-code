import numpy as np
class Solution:
    def trailingZeroes(self, n: int) -> int:
        out = 0
        while n:
            temp = n//5
            out += temp
            n = temp
        return out
    
    def trailingZeroesTheo(self, n: int) -> int:
        if n==0:
            return 0
        kr5 = 0
        for i in range(1, n+1):
            ans = i
            while ans%5 == 0:
                kr5 += 1
                ans = ans//5
        return kr5

    def trailingZeroesAAA(self, n: int) -> int:
        ans=1
        zeros=0
        if n==0:
            return 0
        for i in range(1,n+1):
            ans*=i
            while ans%10 == 0:
                zeros+=1
                ans=ans//10
        
        return zeros
    
    def trailingZeroesBad(self, n: int) -> int:
        fact = np.math.factorial(n)
        zeros = 0
        while fact%10 == 0 and fact >=10:
            zeros+=1
            fact=fact//10
        return zeros
            