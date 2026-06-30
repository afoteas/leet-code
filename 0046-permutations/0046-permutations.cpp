class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        // Sort first to ensure we start from the lexicographically smallest permutation
        std::sort(nums.begin(), nums.end());
        do {
            result.push_back(nums);
        } while (std::next_permutation(nums.begin(), nums.end()));
        return result;

    }
};