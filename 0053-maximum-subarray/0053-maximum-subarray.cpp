class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int s = nums.size();
        vector<int> dp(s);
        dp[0] = nums[0];
        for(int i = 1; i<s; ++i) {
            dp[i] = max(nums[i], nums[i] + dp[i-1]);
        }
        return *max_element(dp.begin(),dp.end());
    }
};