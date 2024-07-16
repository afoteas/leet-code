class Solution:
    def isPerfectSquare(self, x: int) -> bool:
        if x < 2:
            return True
        
        left, right = 1, x // 2
        while left <= right:
            mid = left + (right - left) // 2
            if mid * mid == x:
                return True
            elif mid * mid < x:
                left = mid + 1
            else:
                right = mid - 1
        
        return False