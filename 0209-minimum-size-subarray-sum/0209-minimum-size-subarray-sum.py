class Solution:
    def minSubArrayLen(self, target: int, nums: List[int]) -> int:
        l=0
        r=0
        s=nums[0]
        count = 100001
        ln=len(nums)
        while True:
            if s>=target:
                count=min(count,r-l+1)
                s-=nums[l]
                l+=1
            else:
                r+=1
                if r >= ln:
                    break
                s+=nums[r]
        if count<100001:
            return count
        else:
            return 0