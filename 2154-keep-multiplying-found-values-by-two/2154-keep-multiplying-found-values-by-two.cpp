class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        set<int> nn(nums.begin(), nums.end());
        while (nn.contains(original)) {
            original <<=1;
        }
        return original;
    }
};