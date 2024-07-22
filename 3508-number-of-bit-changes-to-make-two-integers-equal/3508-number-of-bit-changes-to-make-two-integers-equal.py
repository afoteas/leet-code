class Solution:
    def minChanges(self, n: int, k: int) -> int:
        difs = n ^ k
        if ~n & difs:
            return -1
        else:
            return bin(difs).count('1')
        