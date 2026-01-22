class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> ans;
        for(const auto& num: nums) {
            bool found = false;
            // if (!num&1) {
            //     ans.push_back(-1);
            //     continue;
            // }
            for (int i=1; i < num; ++i ) {
                if((i|(i+1)) == num) {
                    ans.push_back(i);
                    found = true;
                    break;
                } 
            }
            if (!found) {
                ans.push_back(-1);
            }
        }
        
        return ans;
    }
};