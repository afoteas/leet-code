class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        l=0
        r=len(nums)
        # if r==0:
        #     return [-1,-1]
        # if r==1 and nums[0] == target:
        #     return [0,0]
        while l < r:
            m = (l+r)//2
            if nums[m]<target:
                l=m+1
            elif nums[m]>target:
                r=m
            else:
                l=m-1
                r=m+1
                while l >= 0 and nums[l] == target:
                    l-=1
                while r < len(nums) and nums[r] == target:
                    r+=1
                return [l+1,r-1]
        return [-1,-1]         
                
        