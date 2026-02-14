class Solution {
public:
    bool canJump2(vector<int>& nums) {
        int gas {0};
        for(const auto& num: nums) {
            if (gas < 0) return false;
            if (num > gas) gas = num;
            gas--;
        }
        return true;
    }

    bool canJump(vector<int>& nums) {
        int maxIndex {0};
        for(int i=0; i < nums.size(); ++i) {
            if (i > maxIndex) return false;
            maxIndex=max(maxIndex, i + nums[i]);
        }
        return true;
    }
};
