class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        set<int> nn(nums.begin(), nums.end());
        while (nn.count(original)) {
            original <<=1;
        }
        return original;
    }
};