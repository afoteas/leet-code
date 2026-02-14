class Solution {
public:
    int jump(vector<int>& nums) {
        int ans {0};
        int maxIndex {0};
        int furthest {0};
        for(int i=0; i < nums.size()-1; ++i) {
            maxIndex=max(maxIndex, i + nums[i]);
            if(i == furthest) {
                furthest = maxIndex;
                ++ans;
            }
        }
        return ans;
    }
};