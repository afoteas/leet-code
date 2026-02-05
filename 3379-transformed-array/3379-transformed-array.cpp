class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int size = nums.size();
        vector<int> ans(size);

        for(int i=0; i< size; ++i) {
            int p = (size + nums.at(i)%size + i)%size;
            ans.at(i) = nums.at(p);
        }
        return ans;
    }
};