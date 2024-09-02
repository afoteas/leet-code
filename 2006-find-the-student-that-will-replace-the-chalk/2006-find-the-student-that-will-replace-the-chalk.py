class Solution:
    def chalkReplacer(self, chalk: List[int], k: int) -> int:
        i = 0
        n = len(chalk)
        k = k%sum(chalk)
        while k > 0:
            if k >= chalk[i]:
                k-=chalk[i]
            else:
                return i
            i=(i+1)%n
        return i
            

        