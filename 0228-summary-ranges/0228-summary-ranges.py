class Solution:
    def summaryRanges(self, nums: List[int]) -> List[str]:
        ret = []

        lm=-2^31
        l=lm
        for i in range(0, len(nums)):
            if i == len(nums)-1 or nums[i]+1 < nums[i+1]:
                if l == lm:
                    ret.append(f'{nums[i]}')
                else:
                    ret.append(f'{l}->{nums[i]}')
                    l=lm
            elif l==lm:

                l=nums[i]
                print(f'l={l},i={i}')
        return ret


        