class Solution {
public:
    bool isNonDecreasing(vector<int>& nums) {
        int len = nums.size();
        for (int i = 1 ; i < len; ++i) {
            if(nums[i] < nums[i-1]) {
                return false;
            }
        }
        return true;
    }

    void mergeOne(vector<int>& nums) {
        int len = nums.size();
        int ans = 0;
        int minSum = std::numeric_limits<int>::max(); 
        for (int i = 1 ; i < len; ++i) {
            if((nums[i] + nums[i-1]) < minSum) {
                minSum = (nums[i] + nums[i-1]);
                ans = i;
            }
        }
        nums[ans-1] = minSum;
        // cout << "minSum:" << minSum << endl;
        // cout << "ans:" << ans << endl;
        nums.erase(nums.begin() + ans);

    }

    int minimumPairRemoval(vector<int>& nums) {
        int ans = 0;
        while (!isNonDecreasing(nums)) {
            mergeOne(nums);
            ++ans;
        }
        return ans;
        
    }
};