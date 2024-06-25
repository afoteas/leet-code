class Solution:
    def minSubArrayLenSlow(self, target: int, nums: List[int]) -> int:
        window = []
        count = 100000
        solution = False
        for num in nums:
            window.append(num)
            if solution:
                window.pop(0)
            while sum(window) >= target:
                solution = True
                print("solution")
                if len(window) < count:
                    count = len(window)
                window.pop(0)
        if solution:
            return count
        else:
            return 0

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


        