import functools


class Solution:
    def singleNumberBad(self, nums: List[int]) -> int:
        mySet = set(nums)
        for n in mySet:
            nums.remove(n)
        print(nums)
        print(mySet)
        for n in mySet:
            if not n in nums:
                return n
        return 0

    def singleNumberBetter(self, nums: List[int]) -> int:
        values = []
        for n in nums:
            if n in values:
                values.remove(n)
            else:
                values.append(n)
        return values[0]


    def singleNumber(self, nums: List[int]) -> int:
        return functools.reduce(lambda x, y: x ^ y, nums, 0)