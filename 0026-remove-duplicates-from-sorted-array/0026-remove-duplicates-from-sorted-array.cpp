class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0;
        int last = -101;
        while (i < nums.size())
        {
            cout << "last = " << last << ", nums[i]= " << nums[i] << endl;
            if(last == nums[i]) {
                cout << "erase: " << i << endl;
                nums.erase(nums.begin() + i);
            } else {
                last = nums[i];
                ++i;
            }

        }
        return nums.size();
    }
};