class Solution:
    def mySqrt(self, x: int) -> int:
        temp = x//2
        while temp*temp > x:
            temp = temp//2
        while temp*temp <= x:
            temp+=1
        return temp-1
        