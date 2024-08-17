class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> dict;

        for (size_t i = 0; i < nums.size(); ++i) {
            dict[nums[i]] = i;
        }
        for (int i=0; i < nums.size(); ++i) {
            int rest = target - nums[i];
            if (dict.find(rest) != dict.end() && dict[rest] != i) {
                return std::vector<int>{i, dict[rest]};
            }
        }
        return {};
    }

};
