class Solution:
    def maxArea(self, height: List[int]) -> int:
        ret = 0
        l = 0
        r = len(height)-1
        while l != r:
            h = min(height[l],height[r])
            a = (r-l)*h
            ret = max(ret, a)
            if height[l] > height[r]:
                r-=1
            else:
                l+=1
        return ret
        