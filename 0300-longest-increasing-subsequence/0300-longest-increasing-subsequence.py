class Solution:
    def lengthOfLISON(self, nums: List[int]) -> int:
        n = len(nums)
        dp = [1] * n
        for i in range(n):
            for j in range(i):
                if nums[i] > nums[j] and dp[i] < dp[j] + 1:
                    print(f"inside if, dp[i]={dp[i]},dp[j]={dp[j]}")
                    dp[i] = dp[j] + 1
            print(f"i={i}, dp={dp}")
        return max(dp)


    def lengthOfLIS(self, nums: List[int]) -> int:
        sub = []
        for x in nums:
            if len(sub) == 0 or sub[-1] < x:
                sub.append(x)
            else:
                idx = bisect_left(sub, x)  # Find the index of the first element >= x
                sub[idx] = x  # Replace that number with x
        return len(sub)
        