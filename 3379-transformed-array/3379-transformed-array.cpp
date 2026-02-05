class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int size = nums.size();
        vector<int> ans(size);
        for(int i=0; i< size; ++i) ans.at(i) = nums.at((size + nums.at(i)%size + i)%size);
        return ans;
    }
};