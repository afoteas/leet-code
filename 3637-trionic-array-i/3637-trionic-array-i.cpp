class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        if(nums.size()==3) return false;
        int state = 0;
        for(int i = 1; i<nums.size(); ++i) {
            if (nums[i] == nums[i-1]) return false;
            if(state==0) //init
            {
                if(nums[i]> nums[i-1]) state = 1;
                else return false;
            }
            else if (state==1) //increasing
            {
                if (nums[i] < nums[i-1]) state = 2;
            }
            else if (state==2) //decreasing
            {
                if (nums[i] > nums[i-1]) state = 3;
            }
            else //increasing again
            {
                if (nums[i] < nums[i-1]) return false;
            }
        }
        return state == 3;
    }
};