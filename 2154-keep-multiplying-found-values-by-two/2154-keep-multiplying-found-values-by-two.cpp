class Solution {
public:
    int findFinalValueSet(vector<int>& nums, int original) {
        set<int> nn(nums.begin(), nums.end());
        while (nn.contains(original)) {
            original <<=1;
        }
        return original;
    }

    int findFinalValue(vector<int>& nums, int original) {
        while (find(nums.begin(),nums.end(),original) != nums.end()) {
            original <<=1;
        }
        return original;
    }
};