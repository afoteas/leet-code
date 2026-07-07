class Solution:
    def sumAndMultiply(self, n: int) -> int:
        x = 0
        s = 0
        i = 0
        while n>0: 
            if n%10 >0:
                x+= (n%10)*(10**i)
                i+=1
                s+= n%10
            n//=10
        return x*s

        