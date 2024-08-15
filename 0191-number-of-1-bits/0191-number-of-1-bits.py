class Solution:
    def hammingWeight(self, n: int) -> int:
        return sum(int(bit) for bit in '{:032b}'.format(n))