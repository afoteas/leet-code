class Solution:
    def hammingWeight(self, n: int) -> int:
        bits = '{:032b}'.format(n)
        return sum(int(bit) for bit in bits)

        