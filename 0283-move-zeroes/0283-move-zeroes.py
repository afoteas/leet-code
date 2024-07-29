class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        if not nums:
            return
        zeros = 0
        length = len(nums)
        i=0
        while i < (length-zeros):
            if nums[i]==0:
                temp = nums.pop(i)
                nums.append(temp)
                zeros+=1
            else:
                i+=1



        