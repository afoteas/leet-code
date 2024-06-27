class Solution(object):
    def twoSumSlow(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        for i in range(0,len(nums)):
            for j in range(i+1,len(nums)):
                if nums[i] + nums[j] == target:
                    return [i,j]

    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        dick={}
        for i in range(0,len(nums)):
            dick[nums[i]]=i
        
        for i in range(0,len(nums)):
            comp = target - nums[i]
            if comp in dick and i != dick[comp]:
                return [i, dick[comp]]
        