class Solution:
    # def countPartitionsSlow(self, nums: List[int]) -> int:
    #     ret = 0
    #     for i in range(1,len(nums)):
    #         # print(f"left: {sum(nums[:i])}")
    #         # print(f"right {sum(nums[i:len(nums)])}")
    #         if (sum(nums[:i]) - sum(nums[i:len(nums)]))%2 == 0 :
    #             ret+=1
    #     return ret


    def countPartitions(self, nums: List[int]) -> int:
        totalSum = sum(nums)
        return len(nums) - 1 if totalSum % 2 == 0 else 0