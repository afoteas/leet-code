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

    def singleNumber(self, nums: List[int]) -> int:
        mySet = set(nums)
        for n in mySet:
            nums.remove(n)
        # print(nums)
        # print(mySet)
        for n in mySet:
            if not n in nums:
                return n
        return 0
        