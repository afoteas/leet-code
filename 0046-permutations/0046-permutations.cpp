class Solution {
public:
    vector<vector<int>> permuteBuiltIn(vector<int>& nums) {
        vector<vector<int>> result;
        // Sort first to ensure we start from the lexicographically smallest permutation
        std::sort(nums.begin(), nums.end());
        do {
            result.push_back(nums);
        } while (std::next_permutation(nums.begin(), nums.end()));
        return result;

    }

    std::vector<std::vector<int>> permute(std::vector<int>& nums) {
        std::vector<std::vector<int>> allPermutations;
        backtrack(nums, 0, allPermutations);
        return allPermutations;
    }
private:
    void backtrack(std::vector<int>& nums, int start, std::vector<std::vector<int>>& result) {
        // Base case: If we have placed elements in all positions, save the permutation
        if (start == nums.size()) {
            result.push_back(nums);
            return;
        }

        // Explore all available choices for the 'start' position
        for (int i = start; i < nums.size(); ++i) {
            std::swap(nums[start], nums[i]);       // Make a choice
            backtrack(nums, start + 1, result);     // Recurse to fill the next position
            std::swap(nums[start], nums[i]);       // Backtrack (undo the choice)
        }
    }
};