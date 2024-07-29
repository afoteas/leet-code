import numpy
class Solution:
    def productExceptSelfTimeout(self, nums: List[int]) -> List[int]:
        ret = []
        prod = 1
        size = len(nums)
        for i in range(size):
            temp = nums.pop(0)
            ret.append(int(prod*numpy.prod(nums)))
            prod*=temp
        return ret


    def productExceptSelf(self, nums: List[int]) -> List[int]:
        ret = []
        prod = 1
        size = len(nums)
        left = []
        right = []
        for num in nums:
            prod*=num
            left.append(prod)
        prod = 1
        for num in nums[::-1]:
            prod*=num
            right.append(prod)
        print(left)
        print(right)
        for i in range(size):
            if i == 0:
                ret.append(right[size-2])
            elif i == (size-1):
                ret.append(left[size-2])
            else:
                ret.append(left[i-1]*right[size-2-i])
  
        return ret

        