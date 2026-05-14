class Solution {
public:
    bool isGood(vector<int>& nums) {
        int l1 = nums.size();
        int c = 0;
        for(auto& n: nums) {
            if ( n == l1-1) c++;
        }
        if (c !=2 ) return false;
        set<int> s(nums.begin(), nums.end());
        int l2 = s.size();
        if (l1 != l2+1 ) return false;
        if (*s.begin() != 1 || *s.rbegin() != l2) return false;
        return true; 
    }
};