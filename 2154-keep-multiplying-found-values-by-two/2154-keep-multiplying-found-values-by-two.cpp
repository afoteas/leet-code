class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        set<int> nn(nums.begin(), nums.end());
        while (nn.count(original)) {
            original *=2;
        }
        return original;
    }
};