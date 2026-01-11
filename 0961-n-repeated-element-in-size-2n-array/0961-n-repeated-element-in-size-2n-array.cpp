
class Solution {
    
public:
    int repeatedNTimes(vector<int>& nums) {
        int len = nums.size();
        len >>=2;
        ++len;
        set<int> unique;
        for (auto& num : nums) {
            if (unique.count(num) == 0) {
                unique.insert(num);
            } else {
                return num;
            }
        }

        return 0;
    }
};