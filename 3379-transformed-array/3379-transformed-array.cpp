class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int s = nums.size();
        vector<int> ans(s);
        for(int i=0; i< s; ++i) ans[i] = nums[(s + nums[i]%s + i)%s];
        return ans;
    }
};