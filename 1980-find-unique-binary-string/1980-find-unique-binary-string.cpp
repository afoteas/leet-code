class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int len = nums[0].size();
        set<int> s;
        for(auto&n:nums) {
            s.insert(stoi(n,nullptr,2));
        }
        int p=*s.begin();
        for(auto&n:s) {
            if (n>p+1) {
                return bitset<64>(p + 1).to_string().substr(64 - len);
            }
            p=n;
        }
        return bitset<64>(p + 1).to_string().substr(64 - len);
    }
};