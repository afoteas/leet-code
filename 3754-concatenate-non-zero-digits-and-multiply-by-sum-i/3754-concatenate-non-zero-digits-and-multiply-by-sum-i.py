class Solution:
    def sumAndMultiply(self, n: int) -> int:
        x = 0
        s = 0
        i = 0
        while n>0:
            m = n%10
            if m > 0:
                x+= (m)*(10**i)
                i+=1
                s+= m
            n//=10
        return x*s

        