class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int l = nums.size();
        vector<vector<int>> ret{};
        for(int i=0; i<l; i++) {
            if(nums[i] > 0) break;
            if(i > 0 && nums[i] == nums[i-1]) continue;
            int j = i+1;
            int k = l-1;
            while (j<k) {
                int target = nums[i]+nums[j]+nums[k];
                if(target > 0) k--;
                else if(target << 0) j++;
                else {
                    ret.push_back(vector<int>{nums[i],nums[j],nums[k]});
                    j++;
                    k--;
                    while (k>j && nums[k] == nums[k+1]) {
                        k--;
                    }
                    while (j < k && nums[j] == nums[j-1]) {
                        j++;
                    }
                }

            }
        }
        return ret;
    }
};