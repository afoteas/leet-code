class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        n = len(nums)
        dp = [1] * n
        for i in range(n):
            for j in range(i):
                if nums[i] > nums[j] and dp[i] < dp[j] + 1:
                    # print(f"inside if, dp[i]={dp[i]},dp[j]={dp[j]}")
                    dp[i] +=1
            # print(f"i={i}, dp={dp}")
        return max(dp)


        