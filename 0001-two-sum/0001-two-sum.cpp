class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> dict;

        for (size_t i = 0; i < nums.size(); ++i) {
            dict[nums[i]] = i;
        }
        for (int i=0; i < nums.size(); ++i) {
            int rest = target - nums[i];
            // printf("rest %d, dict[rest] = %d\n", rest, dict[rest]);
            if (dict.find(rest) != dict.end() && dict[rest] != i) {
                return std::vector<int>{i, dict[rest]};
            }
        }
        return std::vector<int> {};
    }

};


    // def twoSum(self, nums, target):
    //     dick={}
    //     for i in range(0,len(nums)):
    //         dick[nums[i]]=i
        
    //     for i in range(0,len(nums)):
    //         comp = target - nums[i]
    //         if comp in dick and i != dick[comp]:
    //             return [i, dick[comp]]