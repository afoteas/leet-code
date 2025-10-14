class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        if (nums.size() < 2) 
            return false;
        if (nums.size() >= 2 && k == 1) 
            return true;

        int pl = 0;
        int l = 1;

        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] > nums[i - 1]) {
                l += 1;
                if (pl >= k && l >= k)
                    return true;
                if (l == 2 * k)
                    return true;
            } else {
                pl = l;
                l = 1;
            }
        }
        return false;

    }
};