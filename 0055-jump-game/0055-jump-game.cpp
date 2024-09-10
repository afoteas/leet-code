class Solution {
public:
    bool canJump(vector<int>& nums) {
        int gas {0};
        for(const auto& num: nums) {
            if (gas < 0) return false;
            if (num > gas) gas = num;
            gas--;
        }
        return true;
    }
};
