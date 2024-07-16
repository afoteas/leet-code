class Solution:
    def mySqrtBad(self, x: int) -> int:
        temp = x//2
        while temp*temp > x:
            temp = temp//2
        while temp*temp <= x:
            temp+=1
        return temp-1

    def mySqrt(self, x: int) -> int:
        if x < 2:
            return x
        
        left, right = 1, x // 2
        while left <= right:
            mid = left + (right - left) // 2
            if mid * mid == x:
                return mid
            elif mid * mid < x:
                left = mid + 1
            else:
                right = mid - 1
        
        return right 