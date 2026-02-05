class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int size = nums.size();
        vector<int> ans(size);

        for(int i=0; i< size; ++i) {
            if (nums.at(i) > 0) {
                // int p = (i+nums.at(i))%size;
                int p = (size + nums.at(i)%size + i)%size;
                ans.at(i) = nums.at(p);
            } 
            else if(nums.at(i) < 0) {
                int p = (size + nums.at(i)%size + i)%size;
                ans.at(i) = nums.at(p);
            } 
            else {
                // ans.at(i) = nums.at(i);
                int p = (size + nums.at(i)%size + i)%size;
                ans.at(i) = nums.at(p);
            }
        }
        return ans;
    }
};