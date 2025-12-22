class Solution:
    def smallestNumber(self, n: int) -> int:
        ret = 1
        # if n == 1:
        #     return 1
        while ret <= n :
            ret = ret<<1
        return ret - 1

        