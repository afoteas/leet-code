class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int previous = nums[0];
        int monotonic = 0; // 0 uninitialized, 1 increasing, 2 decreasing
        for (int num: nums) {
            if (num == previous) continue;
            if (monotonic) {
                if (num < previous && monotonic != 2) {
                    return false;
                } else if (num > previous && monotonic !=1) {
                    return false;
                }
            } else {
                monotonic = (num > previous)? 1 : 2;
            }
            previous = num;
        }
        return true;
    }
};