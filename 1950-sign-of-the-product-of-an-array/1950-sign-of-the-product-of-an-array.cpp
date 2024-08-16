class Solution {
public:
    int arraySign(vector<int>& nums) {
        int sign = 1;
        for (const auto& num: nums) {
            if(!num) {
                return 0;
            } else if (num < 0) {
                sign*=-1;
            }
        }
        return sign;
        
    }
};