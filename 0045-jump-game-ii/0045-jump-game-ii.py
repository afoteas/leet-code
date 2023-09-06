class Solution:
    def jump(self, nums: List[int]) -> int:

        i = 0
        s = 0
        l = len(nums)
        if l == 1:
            return 0
        while i < l:
            s += 1
            ms = 0
            msi = 0
            if i + nums[i]>= l-1:
                return s
            for j in range(0,nums[i]):
                ts = nums[i+j+1] + i + j 
                if ts>= l-1:
                    return s + 1
                if ms < ts:
                    ms = ts
                    msi = i + j + 1
            i = msi

        return s


