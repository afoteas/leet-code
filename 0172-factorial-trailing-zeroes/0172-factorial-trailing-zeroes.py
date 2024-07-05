import numpy as np
class Solution:
    def trailingZeroesSlow(self, n: int) -> int:
        ans=1
        zeros=0
        if n==0:
            return 0
        for i in range(1,n+1):
            ans*=i
            while ans%(10**(zeros+1)) == 0:
                zeros+=1
        
        return zeros
    
    def trailingZeroes(self, n: int) -> int:
        fact = np.math.factorial(n)
        zeros = 0
        while fact%10 == 0 and fact >=10:
            zeros+=1
            fact=fact//10
        return zeros
            
