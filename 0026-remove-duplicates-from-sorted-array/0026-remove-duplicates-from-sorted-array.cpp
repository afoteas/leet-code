class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0;
        int last = -101;
        while (i < nums.size())
        {
            if(last == nums[i]) {
                nums.erase(nums.begin() + i);
            } else {
                last = nums[i];
                ++i;
            }

        }
        return nums.size();
    }
};