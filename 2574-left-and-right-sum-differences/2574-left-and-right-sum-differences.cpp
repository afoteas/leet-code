class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        vector<int> ret ;
        int leftSum = 0;
        int rightSum = accumulate(nums.begin(), nums.end(), 0);
        for(auto& num: nums) {
            rightSum -= num;
            ret.push_back(abs(leftSum - rightSum));
            leftSum += num;
        }
        return ret;
    }
};